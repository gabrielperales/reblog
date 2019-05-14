module Styles = {
  open Css;

  let navbar =
    style([
      alignItems(center),
      backgroundColor(white),
      display(`flex),
      flexShrink(0),
      margin(`zero),
      marginLeft(auto),
      marginRight(auto),
      width(`percent(100.0)),
      position(`fixed),
      zIndex(99999),
      media(
        "(min-width: " ++ Theme.tablet ++ " )",
        [height(Theme.navbarHeight)],
      ),
    ]);

  let innerContainer =
    style([
      display(`flex),
      justifyContent(spaceBetween),
      margin(`zero),
      marginLeft(auto),
      marginRight(auto),
      maxWidth(Theme.maxWidth),
      width(`percent(100.0)),
    ]);
};

let s = React.string;

[@react.component]
let make = (~children) =>
  <header className=Styles.navbar>
    <div className=Styles.innerContainer> children </div>
  </header>;
