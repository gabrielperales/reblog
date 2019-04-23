module Styles = {
  open Css;

  let button =
    style([
      backgroundColor(hsl(240, 100, 95)),
      borderRadius(px(4)),
      boxShadow(~y=px(2), ~blur=px(5), hsla(240, 100, 10, 0.1)),
      color(Theme.primaryColor),
      cursor(`pointer),
      fontFamily(Theme.primaryFontFamily),
      display(inlineBlock),
      maxWidth(px(150)),
      padding2(em(0.5), em(1.0)),
    ]);
};

let s = React.string;

[@react.component]
let make = (~label, ~className="", ~onClick) =>
  <div
    className={Js.Array.joinWith(" ", [|Styles.button, className|])} onClick>
    {s(label)}
  </div>;
