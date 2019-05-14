let logo: string = [%bs.raw {| require('../imgs/lre.logo.png') |}];
let logo1_5x: string = [%bs.raw {| require('../imgs/lre.logo.1.5x.png') |}];
let logo2x: string = [%bs.raw {| require('../imgs/lre.logo.2x.png') |}];

module Styles = {
  open Css;

  let logo =
    style([
      display(`flex),
      fontSize(em(0.75)),
      alignItems(`center),
      selector("img", [marginRight(em(0.5))]),
    ]);
};

let s = React.string;

[@react.component]
let make = (~className="") => {
  let className = Js.Array.joinWith(" ", [|className, Styles.logo|]);

  <Component_Link href="/" className>
    <img
      src=logo
      srcSet={logo ++ ", " ++ logo1_5x ++ " 1.5x, " ++ logo2x ++ " 2x"}
      alt="Learning ReasonML logo"
    />
    <div> {s("Learning ReasonML")} </div>
  </Component_Link>;
};
