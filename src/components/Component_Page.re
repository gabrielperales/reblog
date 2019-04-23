module Styles = {
  open Css;

  let content =
    style([
      paddingTop(Theme.navbarHeight),
      maxWidth(Theme.maxWidth),
      marginLeft(`auto),
      marginRight(`auto),
    ]);

  let title =
    style([
      textAlign(`center),
      fontFamily(Theme.primaryFontFamily),
      marginTop(px(150)),
    ]);

  let image =
    style([
      display(`block),
      marginTop(px(20)),
      maxWidth(`percent(70.0)),
      marginLeft(`auto),
      marginRight(`auto),
    ]);
};

let s = React.string;

[@react.component]
let make = (~title, ~image="", ~breadcrumbs=[], ~children=ReasonReact.null) =>
  <div>
    <Component_Navbar>
      <Component_Breadcrumbs breadcrumbs />
    </Component_Navbar>
    <div className=Styles.content>
      {
        if (image != "") {
          <img className=Styles.image src=image />;
        } else {
          ReasonReact.null;
        }
      }
      <h1 className=Styles.title> {s(title)} </h1>
      <div> children </div>
    </div>
    <Component_Footer />
  </div>;
