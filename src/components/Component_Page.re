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
let make =
    (
      ~title="",
      ~image="",
      ~breadcrumbs=[],
      ~navLinks=[],
      ~children=React.null,
    ) =>
  <div>
    <BsReactHelmet defaultTitle="Learning ReasonML">
      {
        String.length(title) > 0 ?
          <title> {s("Learning ReasonML | " ++ title)} </title> : React.null
      }
    </BsReactHelmet>
    <Component_Navbar> <Component_Menu links=navLinks /> </Component_Navbar>
    <div className=Styles.content>
      {
        if (image != "") {
          <Component_Image
            className=Styles.image
            alt={"featured image/ilustration of " ++ title}
            src=image
          />;
        } else {
          React.null;
        }
      }
      <Component_Breadcrumbs breadcrumbs />
      {
        String.length(title) > 0 ?
          <h1 className=Styles.title> {s(title)} </h1> : React.null
      }
      <div> children </div>
    </div>
    <Component_Footer />
  </div>;
