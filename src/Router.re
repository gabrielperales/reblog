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
  | ["module-bundlers"] => 
      <React.Suspense fallback={<div> (ReasonReact.string("Loading...")) </div>}>
        <LazyBundlers.Lazy breadcrumbs navLinks />
      </React.Suspense>
  | ["frontend-languages"] => 
      <React.Suspense fallback={<div> (ReasonReact.string("Loading...")) </div>}>
        <LazyLanguages.Lazy breadcrumbs navLinks />
      </React.Suspense>
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
  | [] => 
    <React.Suspense fallback={<div> (ReasonReact.string("Loading...")) </div>}>
      <LazyRootPage.Lazy navLinks />
    </React.Suspense>
  | _ => 
    <React.Suspense fallback={<div> (ReasonReact.string("Loading...")) </div>}>
      <LazyPage404.Lazy />
    </React.Suspense>
  };
};
