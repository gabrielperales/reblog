module Styles = {
  open Css;

  let markdown =
    style([
      selector("img", [width(pct(100.0))]),
      selector("p", [fontSize(em(1.25)), lineHeight(em(2.0))]),
    ]);

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
};

let s = React.string;

[@react.component]
let make = (~title, ~content, ~breadcrumbs, ~navLinks, ~image) =>
  <Component_Page title image breadcrumbs navLinks>
    <article className=Styles.wrapper>
      <Component_FadeInUpOnScreen>
        <Component_Markdown className=Styles.markdown>
          content
        </Component_Markdown>
      </Component_FadeInUpOnScreen>
    </article>
  </Component_Page>;
