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
};

let s = React.string;

[@react.component]
let make = (~children) => <div className=Styles.header> children </div>;
