module Styles = {
  open Css;

  let link =
    style([
      color(Theme.primaryLighterColor),
      fontFamily(Theme.primaryFontFamily),
      textDecoration(`none),
      cursor(`pointer),
      paddingLeft(px(4)),
      paddingRight(px(4)),
      hover([fontWeight(`semiBold)]),
    ]);
};

let s = React.string;

[@react.component]
let make = (~href, ~externalLink=false, ~className="", ~children) => {
  let handleClick = e =>
    if (!externalLink) {
      ReactEvent.Mouse.preventDefault(e);
      Utils.goTo(href, e);
    };

  <a
    href
    className={Js.Array.joinWith(" ", [|Styles.link, className|])}
    target="_blank"
    onClick=handleClick>
    children
  </a>;
};
