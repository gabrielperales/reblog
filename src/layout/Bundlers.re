open Components;

let image: string = [%bs.raw
  {| require('../imgs/undraw_programming_2svr.svg') |}
];

let articles = Entities.Article.bundlers;

[@react.component]
let make = () => <ArticleListPage title="Module Bundlers" image articles />;
