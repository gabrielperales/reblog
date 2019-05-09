open Webapi.Dom;

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

type intersectionObserver = {
  .
  "root": Element.t,
  "rootMargin": string,
  "thresholds": array(float),
};

[@bs.module "react-hook-intersection-observer"] [@bs.val]
external make:
  (
    ~root: React.Ref.t(Js.Nullable.t('a)),
    ~target: React.Ref.t(Js.Nullable.t('a)),
    ~onIntersect: (array(intersectionObserverEntry), intersectionObserver) => unit,
    ~threshold: float=?,
    ~rootMargin: string=?,
    unit
  ) =>
  unit =
  "useIntersectionObserver";
