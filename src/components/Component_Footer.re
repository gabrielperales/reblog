let image: string = [%bs.raw {| require('../imgs/markus-spiske.jpg') |}];

module Styles = {
  open Css;

  let footer =
    style([
      display(block),
      backgroundColor(Theme.primaryLightestColor),
      height(px(200)),
    ]);

  let titleSize = px(20);

  let footerContent =
    style([
      color(Theme.primaryDarkerColor),
      maxWidth(Theme.maxWidth),
      display(`flex),
      height(pct(100.0)),
      flexDirection(`column),
      justifyContent(`spaceAround),
      marginLeft(`auto),
      marginRight(`auto),
      lineHeight(titleSize),
      media(
        "(min-width: " ++ Theme.tablet ++ " )",
        [
          flexDirection(`row),
          justifyContent(`spaceBetween),
          alignItems(`center),
        ],
      ),
    ]);

  let commentWrapper =
    style([
      padding(em(0.25)),
      media(
        "(min-width: " ++ Theme.tablet ++ " )",
        [padding2(`zero, em(0.25))],
      ),
    ]);

  let comment =
    style([
      margin(`zero),
      marginBottom(em(0.5)),
      fontFamily(Theme.primaryFontFamily),
    ]);

  let bubble =
    style([
      width(px(50)),
      height(px(50)),
      backgroundSize(`cover),
      backgroundImage(`url(image)),
    ]);
};

let bubble =
  ReactDOMRe.Style.make(
    ~clipPath=
      "polygon(0% 0%, 100% 0%, 100% 75%, 75% 75%, 75% 100%, 50% 75%, 0% 75%)",
    (),
  );

let s = React.string;

[@react.component]
let make = () =>
  <footer className=Styles.footer>
    <div className=Styles.footerContent>
      <Component_Logo />
      <div className=Styles.commentWrapper>
        <h4 className=Styles.comment> {s("Leave us a comment")} </h4>
        <div className=Styles.bubble style=bubble />
      </div>
    </div>
  </footer>;
