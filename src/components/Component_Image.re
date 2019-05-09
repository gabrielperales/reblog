module Styles = {
  open Css;
};

[@react.component]
let make = (~className="", ~alt="", ~src) => {
  let imageRef = React.useRef(Js.Nullable.null);
  let (width, setWitdh) = React.useState(() => 0);
  let (height, setHeight) = React.useState(() => 0);
  let (style, setStyle) = React.useState(() => ReactDOMRe.Style.make());

  React.useEffect1(
    () => {
      let r = ReactDOMRe.Ref.domRef(imageRef);

      let getDimensions: ReactDOMRe.Ref.t => (int, int) = [%bs.raw
        {|
      function(json) {
        return [json.current.width, json.current.height];
      }
    |}
      ];

      let (width, height) = getDimensions(r);

      let newStyle =
        ReactDOMRe.Style.make(
          ~height=string_of_int(height) ++ "px",
          ~width=string_of_int(width) ++ "px",
          (),
        );

      setStyle(_ => newStyle);

      None;
    },
    [|imageRef|],
  );

  let classes = Js.Array.joinWith(" ", [|className|]);

  <img
    className=classes
    ref={ReactDOMRe.Ref.domRef(imageRef)}
    alt
    src
    style
  />;
};
