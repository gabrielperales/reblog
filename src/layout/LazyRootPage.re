
module type T = (module type of RootPage);

[@bs.val] external component: (module T) = "undefined";

module Lazy: T = {
  let logo: string = [%bs.raw {| require('../imgs/lre.logo.png') |}];
  let logo1_5x: string = [%bs.raw {| require('../imgs/lre.logo.1.5x.png') |}];
  let logo2x: string = [%bs.raw {| require('../imgs/lre.logo.2x.png') |}]
  let image: string = [%bs.raw {| require('../imgs/markus-spiske.jpg') |}];

  include (val component);
  let make = ReLoadable.lazy_(() => DynamicImport.import("./RootPage.bs.js"));
  let default = make;
};