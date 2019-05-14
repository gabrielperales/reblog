[@react.component] [@bs.module]
external make:
  (
    ~forceInline: bool=?,
    ~forceBlock: bool=?,
    ~className: string=?,
    ~children: string
  ) =>
  React.element =
  "./Markdown";
