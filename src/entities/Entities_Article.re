type t = {
  slug: string,
  title: string,
  content: string,
  image: string,
  category: string,
};

type data = {
  slug: string,
  title: string,
  image: option(string),
  category: string,
};

type file = {
  data,
  content: string,
};

let files: Js.Dict.t(Js.Json.t) = [%bs.raw
  {| require("../../articles/*.md") |}
];

let decodeFile = (json: Js.Json.t): t => {
  let decodeData = (json: Js.Json.t) =>
    Json.Decode.{
      slug: json |> field("slug", string),
      title: json |> field("title", string),
      image: json |> optional(field("image", string)),
      category: json |> field("category", string),
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
    content: obj.content,
  };
};

let existsBySlug = (slug: string) =>
  List.exists((article: t) => slug == article.slug);

let findBySlug = (slug: string) =>
  List.find((article: t) => slug == article.slug);

let filterByCategory = (category: string, l: list(t)): list(t) =>
  List.filter((article: t) => category == article.category, l);

let articles: list(t) =
  Js.Dict.values(files) |> Array.to_list |> List.map(decodeFile);

let languages: list(t) = filterByCategory("languages", articles);

let bundlers: list(t) = filterByCategory("bundlers", articles);
