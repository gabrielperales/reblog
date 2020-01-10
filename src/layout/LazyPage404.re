module type T = (module type of Page404);

[@bs.val] external component: (module T) = "undefined";

module Lazy: T = {
  include (val component);
  let image = "";
  let make = ReLoadable.lazy_(() => DynamicImport.import("./Page404.bs.js"));
  let default = make;
};