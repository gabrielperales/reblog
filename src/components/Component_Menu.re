open Entities;

module Styles = {
  open Css;

  let navWrapper = style([marginTop(em(0.5)), width(pct(100.0))]);

  let menuBtn =
    style([
      float(`right),
      marginRight(em(0.5)),
      media("(min-width: " ++ Theme.tablet ++ " )", [display(`none)]),
    ]);

  let nav =
    style([
      marginTop(`zero),
      listStyleType(`none),
      backgroundColor(white),
      padding(`zero),
      media("(min-width: " ++ Theme.tablet ++ " )", [display(`flex)]),
    ]);

  let navItem = index =>
    style([
      display(`none),
      padding(em(0.5)),
      marginTop(em(0.5)),
      transition(~duration=200, ~delay=200 + 100 * index, "transform"),
      transform(translate3d(px(-2000), px(0), px(0))),
      zIndex(100 - index),
      media(
        "(min-width: " ++ Theme.tablet ++ " )",
        [
          display(`block),
          marginTop(`zero),
          transform(translate3d(px(0), px(0), px(0))),
        ],
      ),
    ]);

  let showItem =
    style([
      important(display(`block)),
      important(transform(translate3d(px(0), px(0), px(0)))),
    ]);
};

let s = React.string;

[@react.component]
let make = (~links: list(Link.t)=[]) => {
  let (showMenu, setShowMenu) = React.useState(() => false);

  let toggleMenu = _ => {
    setShowMenu(v => !v);
    ();
  };

  <nav className=Styles.navWrapper>
    <Component_Button
      className=Styles.menuBtn
      label="Menu"
      onClick=toggleMenu
    />
    <ul className=Styles.nav>
      {
        links
        |> List.mapi((index, {path, text}: Link.t) =>
             <li
               key=path
               className={
                 Js.Array.joinWith(
                   " ",
                   [|
                     Styles.navItem(index),
                     showMenu ? Styles.showItem : "",
                   |],
                 )
               }>
               <Component_Link href=path> {s(text)} </Component_Link>
             </li>
           )
        |> List.append([<Component_Logo key="/" />])
        |> Array.of_list
        |> React.array
      }
    </ul>
  </nav>;
};
