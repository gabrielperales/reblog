open Entities;

module Styles = {
  open Css;

  let nav = style([display(`flex), listStyleType(`none)]);

  let item =
    style([
      after([
        contentRule("/"),
        marginLeft(em(0.5)),
        marginRight(em(0.5)),
      ]),
      lastChild([after([contentRule("")])]),
    ]);
};

let s = React.string;

[@react.component]
let make = (~breadcrumbs: list(Breadcrumb.t)=[]) => {
  let home: Breadcrumb.t = {path: "/", text: "Home"};

  let links = List.append([home], breadcrumbs);

  <nav>
    <ul className=Styles.nav>
      {
        links
        |> List.map(({path, text}: Breadcrumb.t) =>
             <li key=path className=Styles.item>
               <Component_Link href=path> {s(text)} </Component_Link>
             </li>
           )
        |> Array.of_list
        |> React.array
      }
    </ul>
  </nav>;
};
