module Styles = {
  open Css;

  let markdown =
    style([
      selector("img", [display(`none)]),
      selector("p", [fontSize(em(1.25)), lineHeight(em(2.0))]),
    ]);

  let readMoreBtn = style([marginTop(px(50)), float(`right)]);
};

let s = React.string;

[@react.component]
let make =
    (
      ~title: string,
      ~image: string="",
      ~breadcrumbs: list(Entities.Link.t)=[],
      ~navLinks: list(Entities.Link.t)=[],
      ~articles: list(Entities.Article.t)=[],
    ) => {
  let articles =
    articles
    |> List.map(({title, date, slug, content}: Entities.Article.t) =>
         <Component_FadeInUpOnScreen>
           <Component_Article title date key=title>
             <Component_Markdown className=Styles.markdown>
               {Js.String.slice(~from=0, ~to_=900, content) ++ "..."}
             </Component_Markdown>
             <Component_Button
               className=Styles.readMoreBtn
               label="Read more"
               href={"/" ++ slug}
             />
           </Component_Article>
         </Component_FadeInUpOnScreen>
       )
    |> Array.of_list;

  <Component_Page title breadcrumbs navLinks image>
    {React.array(articles)}
  </Component_Page>;
};
