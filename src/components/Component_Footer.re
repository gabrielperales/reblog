module Styles = {
  open Css;

  let footer =
    style([
      display(block),
      backgroundColor(Theme.primaryLightestColor),
      height(px(200)),
    ]);

  let footerContent =
    style([
      color(Theme.primaryDarkerColor),
      maxWidth(Theme.maxWidth),
      marginLeft(`auto),
      marginRight(`auto),
      paddingTop(px(120)),
      textAlign(`center),
    ]);
};

let s = React.string;

[@react.component]
let make = () =>
  <div className=Styles.footer>
    <div className=Styles.footerContent>
      {
        s(
          "Website built by Gabriel Perales. Universitat Oberta de Catalunya. 2019.",
        )
      }
    </div>
  </div>;
