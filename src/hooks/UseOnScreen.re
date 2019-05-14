open Webapi.Dom;

module IntersectionObserver = {
  type t;

  type intersectionObserverEntry = {
    .
    //readonly attribute DOMHighResTimeStamp time;
    //readonly attribute DOMRectReadOnly? rootBounds;
    //readonly attribute DOMRectReadOnly boundingClientRect;
    //readonly attribute DOMRectReadOnly intersectionRect;
    "isIntersecting": bool,
    "intersectionRatio": float,
    "target": Element.t
  };

  [@bs.deriving abstract]
  type intersectionObserver = {
    [@bs.optional] root: Element.t,
    [@bs.optional] rootMargin: string,
    [@bs.optional] thresholds: array(float),
  };


  [@bs.new] external make: (
    (list(intersectionObserverEntry) => unit), 
    intersectionObserver,
    ) => t = "IntersectionObserver";

  [@bs.send] external observe: (t, Element.t) => unit = "observe";

  [@bs.send] external unobserve: (t, Element.t) => unit = "unobserve";
};

let make: (React.Ref.t(Js.Nullable.t('a)), ~rootMargin: string=?, ~justOnce: bool=?, unit) => bool =
(reactRef, ~rootMargin="0px", ~justOnce=false, ()) => {
  let (isIntersecting, setIntersecting) = React.useState(() => false);
  let (executed, setExecuted) = React.useState(() => false);

  React.useEffect(
    () => {
      let maybeElement = React.Ref.current(reactRef);
      let observer = IntersectionObserver.make(([entry, ..._]) => {
        if (justOnce && !executed) {
          setIntersecting(_ => entry##isIntersecting);
          if (entry##isIntersecting) setExecuted(_ => true);
        }
        if (!justOnce) setIntersecting(_ => entry##isIntersecting);
        ();
      }, IntersectionObserver.intersectionObserver(~rootMargin, ()));

      switch (maybeElement |> Js.Nullable.toOption) {
        | Some(element) => {
          IntersectionObserver.observe(observer, element);
          Some(() => {
            IntersectionObserver.unobserve(observer, element);
            ();
          });
        }
        | _ => None
      }
    }
  ); 

  isIntersecting;
};
