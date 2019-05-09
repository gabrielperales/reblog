module Styles = {
  open Css;

  let section = style([marginBottom(px(150))]);

  let sectionTitle =
    style([
      borderBottom(px(5), `solid, Theme.primaryLightestColor),
      fontFamily(Theme.primaryFontFamily),
      fontSize(em(1.75)),
      fontWeight(`bold),
      paddingBottom(em(1.0)),
      textAlign(`right),
      paddingRight(em(0.5)),
      media("(min-width: " ++ Theme.tablet ++ " )", [marginRight(`auto)]),
    ]);

  let date =
    style([
      color(Theme.primaryLighterColor),
      fontSize(em(0.75)),
      padding(em(1.)),
    ]);

  let sectionContent =
    style([
      fontSize(em(1.2)),
      lineHeight(em(2.0)),
      padding(em(0.5)),
      after([
        contentRule(""),
        display(`table),
        clear(both),
        padding(`zero),
      ]),
    ]);
};

let s = React.string;

[@react.component]
let make = (~title, ~date=?, ~className="", ~children=ReasonReact.null) => {
  let toString = f => f |> int_of_float |> string_of_int;
  let inc = f => f +. 1.0;
  let to2digits = s =>
    switch (String.length(s)) {
    | 0 => "00"
    | 1 => "0" ++ s
    | _ => s
    };

  let dateString =
    switch (date) {
    | Some(date) =>
      let day = date |> Js.Date.getUTCDate |> inc |> toString |> to2digits;

      let month = date |> Js.Date.getUTCMonth |> inc |> toString |> to2digits;

      let year = date |> Js.Date.getUTCFullYear |> toString;

      day ++ " / " ++ month ++ " / " ++ year;
    | None => ""
    };

  <article className=Styles.section>
    <h2 className=Styles.sectionTitle> {s(title)} </h2>
    {
      String.length(dateString) != 0 ?
        <div className=Styles.date> {s(dateString)} </div> : React.null
    }
    <div className=Styles.sectionContent> children </div>
  </article>;
};
