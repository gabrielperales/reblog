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
    style([display(`flex), flexDirection(`column), height(vh(60.0))]);

  let hero =
    style([
      alignItems(center),
      display(`flex),
      fontFamily(Theme.primaryFontFamily),
      fontSize(px(30)),
      height(pct(100.0)),
      justifyContent(center),
      marginLeft(auto),
      marginRight(auto),
      maxWidth(Theme.maxWidth),
      width(pct(100.0)),
      media("(min-width: " ++ Theme.tablet ++ " )", [fontSize(px(40))]),
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
let make = (~navLinks) =>
  <Page navLinks>
    <div className=Styles.root>
      <div className=Styles.hero>
        <FadeInUpOnScreen>
          <h1> {s("Learning ReasonML")} </h1>
        </FadeInUpOnScreen>
      </div>
    </div>
    <div className=Styles.wrapper>
      <FadeInUpOnScreen>
        <Article title="Module Bundlers">
          <img
            alt="ilustration of a girl and a document tree"
            className=Styles.ilustration
            src=imgBundle
          />
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
            href="/module-bundlers"
          />
        </Article>
      </FadeInUpOnScreen>
      <FadeInUpOnScreen>
        <Article title="Frontend languages">
          <img
            alt="ilustration of people with coding symbols"
            className=Styles.ilustration
            src=imgLanguages
          />
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
            href="/frontend-languages"
            label="Read More"
          />
        </Article>
      </FadeInUpOnScreen>
    </div>
  </Page>;

let default = make;