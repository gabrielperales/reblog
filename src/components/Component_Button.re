module Styles = {
  open Css;

  let button =
    style([
      backgroundColor(hsl(240, 100, 95)),
      border(px(0), `none, `transparent),
      borderRadius(px(4)),
      boxShadow(~y=px(2), ~blur=px(5), hsla(240, 100, 10, 0.1)),
      color(Theme.primaryColor),
      cursor(`pointer),
      fontFamily(Theme.primaryFontFamily),
      fontSize(em(1.0)),
      display(inlineBlock),
      maxWidth(px(150)),
      padding2(em(0.5), em(1.0)),
    ]);
};

let s = React.string;

[@react.component]
let make = (~label, ~href=?, ~onClick=?, ~className="") => {
  let classes = Js.Array.joinWith(" ", [|Styles.button, className|]);
  switch (href, onClick) {
  | (_, Some(onClick)) =>
    <button className=classes onClick> {s(label)} </button>
  | (Some(href), _) =>
    <Component_Link className=classes href> {s(label)} </Component_Link>
  | (_, _) => React.null
  };
};
