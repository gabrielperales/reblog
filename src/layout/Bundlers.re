open Components;

let image: string = [%bs.raw
  {| require('../imgs/undraw_programming_2svr.svg') |}
];

let articles = Entities.Article.bundlers;

[@react.component]
let make = (~breadcrumbs=[], ~navLinks=[]) =>
  <ArticleListPage
    title="Module Bundlers"
    breadcrumbs
    navLinks
    image
    articles
  />;
