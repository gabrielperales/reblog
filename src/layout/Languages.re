open Components;

let image: string = [%bs.raw
  {| require('../imgs/undraw_code_review_l1q9.svg') |}
];

let s = React.string;

let articles = Entities.Article.languages;

[@react.component]
let make = (~breadcrumbs=[], ~navLinks) =>
  <ArticleListPage
    title="Frontend languages"
    breadcrumbs
    navLinks
    image
    articles
  />;
