open Hooks;

[@react.component]
let make = (~className="", ~intersectClassName="", ~children) => {
  let divRef = React.useRef(Js.Nullable.null);

  let onIntersect = (_, el) => {
    let thresholds = el##thresholds;
    Array.map(
      el => {
        Js.log("threshold" ++ string_of_float(el));
        ();
      },
      thresholds,
    );
    Js.log(el##rootMargin);
    ();
  };

  useIntersectionObserver(~root=divRef, ~target=divRef, ~onIntersect, ());

  let classes = Js.Array.joinWith(" ", [|className, intersectClassName|]);

  <div ref={ReactDOMRe.Ref.domRef(divRef)} className=classes> children </div>;
};
