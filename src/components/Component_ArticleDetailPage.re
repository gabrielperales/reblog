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
    ]);

  let paragraph = style([fontSize(em(1.25)), lineHeight(em(2.0))]);
};

let s = React.string;

[@react.component]
let make = (~title, ~content, ~breadcrumbs, ~image) => {
  let paragraphs: array(React.element) =
    content
    |> Js.String.split("\n\n")
    |> Array.map(text => <p className=Styles.paragraph> {s(text)} </p>);

  <Component_Page title image breadcrumbs>
    <article className=Styles.wrapper> {React.array(paragraphs)} </article>
  </Component_Page>;
};
