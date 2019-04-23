module Styles = {
  open Css;

  let section = style([marginBottom(px(150))]);

  let sectionTitle =
    style([
      borderBottom(px(5), `solid, Theme.primaryLightestColor),
      fontFamily(Theme.primaryFontFamily),
      fontSize(em(1.75)),
      fontWeight(`bold),
      paddingBottom(em(1.0)),
      textAlign(`right),
      paddingRight(em(0.5)),
      media("(min-width: " ++ Theme.tablet ++ " )", [marginRight(`auto)]),
    ]);

  let sectionContent =
    style([
      fontSize(em(1.2)),
      lineHeight(em(2.0)),
      padding(em(0.5)),
      after([
        contentRule(""),
        display(`table),
        clear(both),
        padding(`zero),
      ]),
    ]);
};

let s = React.string;

[@react.component]
let make = (~title, ~className="", ~children=ReasonReact.null) =>
  <article className=Styles.section>
    <h2 className=Styles.sectionTitle> {s(title)} </h2>
    <div className=Styles.sectionContent> children </div>
  </article>;
