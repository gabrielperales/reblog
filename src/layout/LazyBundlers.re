module type T = (module type of Bundlers);

[@bs.val] external component: (module T) = "undefined";

module Lazy: T = {
  include (val component);
  let image = "";
  let articles = [];
  let make = ReLoadable.lazy_(() => DynamicImport.import("./Bundlers.bs.js"));
  let default = make;
};