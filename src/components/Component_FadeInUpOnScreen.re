open Hooks;

module Styles = {
  open Css;

  let hidden = style([opacity(0.0)]);
};

let defaultClassName = Styles.hidden;

let defaultOnScreenClassName =
  Js.Array.joinWith(
    " ",
    [|Animations.animated, Animations.delay(100), Animations.fadeInUp|],
  );

[@react.component]
let make =
    (
      ~className=defaultClassName,
      ~onScreenClassName=defaultOnScreenClassName,
      ~justOnce=false,
      ~children,
    ) => {
  let divRef = React.useRef(Js.Nullable.null);

  let onScreen = useOnScreen(divRef, ~justOnce, ());

  let classes =
    Js.Array.joinWith(
      " ",
      onScreen ? [|className, onScreenClassName|] : [|className|],
    );

  <div ref={ReactDOMRe.Ref.domRef(divRef)} className=classes> children </div>;
};
