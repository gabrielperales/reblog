module Styles = {
  open Css;

  let header =
    style([
      alignItems(center),
      backgroundColor(white),
      display(`flex),
      flexShrink(0),
      height(Theme.navbarHeight),
      margin(`zero),
      marginLeft(auto),
      marginRight(auto),
      width(`percent(100.0)),
      position(`fixed),
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
  <div className=Styles.header>
    <div className=Styles.innerContainer> <div> children </div> </div>
  </div>;
