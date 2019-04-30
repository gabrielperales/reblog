module Styles = {
  open Css;

  let readMoreBtn = style([marginTop(px(50)), float(`right)]);
};

let s = React.string;

[@react.component]
let make =
    (
      ~title: string,
      ~image: string="",
      ~articles: list(Entities.Article.t)=[],
    ) => {
  let articles =
    articles
    |> List.map(({title, slug, content}: Entities.Article.t) =>
         <Component_Article title key=title>
           <Component_Markdown>
             {Js.String.slice(~from=0, ~to_=400, content) ++ "..."}
           </Component_Markdown>
           <Component_Button
             className=Styles.readMoreBtn
             label="Read more"
             href={"/" ++ slug}
           />
         </Component_Article>
       )
    |> Array.of_list;

  <Component_Page title image> {React.array(articles)} </Component_Page>;
};
