open Css;

let animated = style([animationDuration(500), animationFillMode(both)]);

let delay = millisecs => style([animationDelay(millisecs)]);

let fadeInUpAnimation =
  keyframes([
    (0, [opacity(0.0), transform(translate3d(px(0), px(150), px(0)))]),
    (100, [opacity(1.0), transform(translate3d(px(0), px(0), px(0)))]),
  ]);

let fadeInUp = style([animationName(fadeInUpAnimation)]);
