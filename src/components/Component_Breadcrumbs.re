open Entities;

module Styles = {
  open Css;

  let nav =
    style([
      display(`flex),
      listStyleType(`none),
      padding(`zero),
      marginTop(em(1.0)),
    ]);

  let item =
    style([
      before([
        contentRule("/"),
        marginLeft(em(0.5)),
        marginRight(em(0.5)),
      ]),
    ]);
};

let s = React.string;

[@react.component]
let make = (~breadcrumbs: list(Link.t)=[]) =>
  <nav>
    <ul className=Styles.nav>
      {
        breadcrumbs
        |> List.map(({path, text}: Link.t) =>
             <li key=path className=Styles.item>
               <Component_Link href=path> {s(text)} </Component_Link>
             </li>
           )
        |> Array.of_list
        |> React.array
      }
    </ul>
  </nav>;
