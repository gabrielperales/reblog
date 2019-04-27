module Styles = {
  open Css;

  let wrapper =
    style([
      maxWidth(px(640)),
      marginTop(px(100)),
      marginRight(`auto),
      marginLeft(`auto),
      marginBottom(px(300)),
      padding(em(0.5)),
      media("(min-width: " ++ Theme.tablet ++ " )", [padding(`zero)]),
      selector("p", [fontSize(em(1.25)), lineHeight(em(2.0))]),
    ]);
};

let s = React.string;

[@react.component]
let make = (~title, ~content, ~breadcrumbs, ~image) =>
  <Component_Page title image breadcrumbs>
    <article className=Styles.wrapper>
      <Component_Markdown> content </Component_Markdown>
    </article>
  </Component_Page>;
