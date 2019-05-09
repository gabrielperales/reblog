type t = {
  slug: string,
  title: string,
  content: string,
  image: string,
  category: string,
  date: Js.Date.t,
};

type data = {
  slug: string,
  title: string,
  image: option(string),
  category: string,
  date: Js.Date.t,
};

type file = {
  data,
  content: string,
};

let files: Js.Dict.t(Js.Json.t) = [%bs.raw
  {| require("../../articles/*.md") |}
];

let decodeFile: Js.Json.t => t =
  json => {
    let decodeData = (json: Js.Json.t) =>
      Json.Decode.{
        slug: json |> field("slug", string),
        title: json |> field("title", string),
        image: json |> optional(field("image", string)),
        category: json |> field("category", string),
        date: json |> field("date", string) |> Js.Date.fromString,
      };

    let obj =
      Json.Decode.{
        data: json |> field("data", decodeData),
        content: json |> field("content", string),
      };

    {
      slug: obj.data.slug,
      title: obj.data.title,
      image: Belt.Option.getWithDefault(obj.data.image, ""),
      category: obj.data.category,
      date: obj.data.date,
      content: obj.content,
    };
  };

let existsBySlug: (string, list(t)) => bool =
  slug => List.exists((article: t) => slug == article.slug);

let findBySlug: (string, list(t)) => t =
  slug => List.find((article: t) => slug == article.slug);

let filterByCategory: (string, list(t)) => list(t) =
  (category, l) =>
    List.filter((article: t) => category == article.category, l);

let orderByDate: list(t) => list(t) =
  List.sort((article1: t, article2: t) =>
    Pervasives.compare(
      Js.Date.valueOf(article1.date),
      Js.Date.valueOf(article2.date),
    )
  );

let articles: list(t) =
  Js.Dict.values(files)
  |> Array.to_list
  |> List.map(decodeFile)
  |> orderByDate;

let languages: list(t) = filterByCategory("languages", articles);

let bundlers: list(t) = filterByCategory("bundlers", articles);
