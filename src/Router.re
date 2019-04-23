open Components;

[@react.component]
let make = () => {
  open Entities;
  let url = ReasonReactRouter.useUrl();

  let articles = Article.articles;

  switch (url.path) {
  | ["module-bundlers"] => <Bundlers />
  | ["frontend-languages"] => <Languages />
  | [slug] when Article.existsBySlug(slug, articles) =>
    let {title, image, content}: Article.t =
      Article.findBySlug(slug, articles);

    let breadcrumbs: list(Breadcrumb.t) =
      switch (slug) {
      | x when Article.existsBySlug(slug, Article.bundlers) => [
          {path: "module-bundlers", text: "Bundlers"},
        ]
      | x when Article.existsBySlug(slug, Article.languages) => [
          {path: "frontend-languages", text: "Languages"},
        ]
      | _ => []
      };

    <ArticleDetailPage title image content breadcrumbs />;
  | [] => <Root />
  | _ => <Page404 />
  };
};
