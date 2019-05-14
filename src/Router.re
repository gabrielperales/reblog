open Components;

[@react.component]
let make = () => {
  open Entities;
  let url = ReasonReactRouter.useUrl();

  let articles = Article.articles;
  let home: Link.t = {path: "/", text: "Home"};
  let breadcrumbs: list(Link.t) = [home];
  let navLinks: list(Link.t) = [
    {path: "/module-bundlers", text: "Bundlers"},
    {path: "/frontend-languages", text: "Languages"},
  ];

  switch (url.path) {
  | ["module-bundlers"] => <Bundlers breadcrumbs navLinks />
  | ["frontend-languages"] => <Languages breadcrumbs navLinks />
  | [slug] when Article.existsBySlug(slug, articles) =>
    let {title, image, content}: Article.t =
      Article.findBySlug(slug, articles);

    let breadcrumbs: list(Link.t) =
      switch (slug) {
      | x when Article.existsBySlug(x, Article.bundlers) => [
          home,
          {path: "/module-bundlers", text: "Bundlers"},
        ]
      | x when Article.existsBySlug(x, Article.languages) => [
          home,
          {path: "/frontend-languages", text: "Languages"},
        ]
      | _ => []
      };

    <ArticleDetailPage title image content breadcrumbs navLinks />;
  | [] => <Root navLinks />
  | _ => <Page404 />
  };
};
