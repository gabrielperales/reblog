let goTo = (path, _) => {
  %bs.raw
  {| window.scrollTo(0, 0) |};
  ReasonReactRouter.push(path);
};
