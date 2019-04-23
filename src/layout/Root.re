open Components;

let imgBundle: string = [%bs.raw
  {| require('../imgs/undraw_File_bundle_xl7g.svg') |}
];

let imgLanguages: string = [%bs.raw
  {| require('../imgs/undraw_code_typing_7jnv.svg') |}
];

module Styles = {
  open Css;

  let root =
    style([display(`flex), flexDirection(`column), height(vh(100.0))]);

  let hero =
    style([
      alignItems(center),
      display(`flex),
      fontFamily(Theme.primaryFontFamily),
      fontSize(px(50)),
      height(`percent(100.0)),
      justifyContent(center),
      marginLeft(auto),
      marginRight(auto),
      maxWidth(Theme.maxWidth),
      width(`percent(100.0)),
    ]);

  let uoc =
    style([
      backgroundColor(black),
      color(white),
      padding(em(0.25)),
      fontWeight(`bold),
      media("(min-width: " ++ Theme.tablet ++ " )", [fontSize(em(2.0))]),
    ]);

  let title =
    style([
      fontSize(em(0.5)),
      fontWeight(`light),
      marginLeft(em(0.25)),
      media("(min-width: " ++ Theme.tablet ++ " )", [fontSize(em(1.5))]),
    ]);

  let wrapper =
    style([
      maxWidth(Theme.maxWidth),
      marginLeft(auto),
      marginRight(auto),
      marginBottom(px(50)),
    ]);

  let ilustration =
    style([
      display(`block),
      maxWidth(px(200)),
      marginLeft(`auto),
      marginRight(`auto),
      media(
        "(min-width: " ++ Theme.tablet ++ " )",
        [float(`left), marginRight(em(3.0)), maxWidth(px(280))],
      ),
    ]);

  let readMoreBtn = style([marginTop(px(50)), float(`right)]);
};

let s = React.string;

[@react.component]
let make = () =>
  <div>
    <div className=Styles.root>
      <div className=Styles.hero>
        <div className=Styles.uoc> {s("UOC")} </div>
        <h1 className=Styles.title> {s("Modern frotend development")} </h1>
      </div>
    </div>
    <div className=Styles.wrapper>
      <Article title="Module Bundlers">
        <img className=Styles.ilustration src=imgBundle />
        <p>
          {
            s(
              "Module bundlers are advanced tools which takes pieces of code, "
              ++ "modules and assets and bundles them into a single file, usually"
              ++ " for use in the browser. Some of these tools are ",
            )
          }
          <Link href="http://browserify.org/" externalLink=true>
            {s("Browserify")}
          </Link>
          {s(", ")}
          <Link href="https://webpack.js.org/" externalLink=true>
            {s("Webpack")}
          </Link>
          {s(", ")}
          <Link href="https://rollupjs.org/" externalLink=true>
            {s("Rollup")}
          </Link>
          {s(" and ")}
          <Link href="https://parceljs.org/" externalLink=true>
            {s("Parcel")}
          </Link>
          {s(".")}
        </p>
        <Button
          className=Styles.readMoreBtn
          label="Read More"
          onClick={Utils.goTo("module-bundlers")}
        />
      </Article>
      <Article title="Frontend languages">
        <img className=Styles.ilustration src=imgLanguages />
        <p>
          {
            s(
              "Nowadays, JavaScript still being the only language able to run in "
              ++ "the browser. That's the reason why it is getting such big attraction"
              ++ " and big companies are looking for ways of improve the development"
              ++ " process with news languages who compiles to JavaScript. Some of them are ",
            )
          }
          <Link href="https://www.typescriptlang.org/" externalLink=true>
            {s("TypeScript")}
          </Link>
          {s(", ")}
          <Link href="https://flow.org/" externalLink=true>
            {s("Flow")}
          </Link>
          {s(" (which is just an static type checker), ")}
          <Link href="https://elm-lang.org/" externalLink=true>
            {s("Elm")}
          </Link>
          {s(" and ")}
          <Link href="https://reasonml.github.io/" externalLink=true>
            {s("ReasonML")}
          </Link>
          {s(".")}
        </p>
        <Button
          className=Styles.readMoreBtn
          onClick={Utils.goTo("frontend-languages")}
          label="Read More"
        />
      </Article>
    </div>
    <Footer />
  </div>;
