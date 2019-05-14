module Styles = {
  open Css;
};

[@react.component]
let make = (~className="", ~alt="", ~src) => {
  let classes = Js.Array.joinWith(" ", [|className|]);

  <img className=classes alt src />;
};
