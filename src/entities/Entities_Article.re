type t = {
  slug: string,
  title: string,
  content: string,
  image: string,
};

let existsBySlug = (slug: string) =>
  List.exists((article: t) => slug == article.slug);

let findBySlug = (slug: string) =>
  List.find((article: t) => slug == article.slug);

let typescriptContent = {js|
TypeScript is an open-source programming language developed and maintained by Microsoft. It is a strict syntactical superset of JavaScript, and adds optional static typing to the language.

TypeScript is designed for development of large applications and transcompiles to JavaScript. As TypeScript is a superset of JavaScript, existing JavaScript programs are also valid TypeScript programs. TypeScript may be used to develop JavaScript applications for both client-side and server-side (Node.js) execution.

There are multiple options available for transcompilation. Either the default TypeScript Checker can be used, or the Babel compiler can be invoked to convert TypeScript to JavaScript.

TypeScript supports definition files that can contain type information of existing JavaScript libraries, much like C++ header files can describe the structure of existing object files. This enables other programs to use the values defined in the files as if they were statically typed TypeScript entities. There are third-party header files for popular libraries such as jQuery, MongoDB, and D3.js. TypeScript headers for the Node.js basic modules are also available, allowing development of Node.js programs within TypeScript.

The TypeScript compiler is itself written in TypeScript and compiled to JavaScript. It is licensed under the Apache 2.0 License.

TypeScript is included as a first-class programming language in Microsoft Visual Studio 2013 Update 2 and later, beside C# and other Microsoft languages. An official extension allows Visual Studio 2012 to support TypeScript as well.

Anders Hejlsberg, lead architect of C# and creator of Delphi and Turbo Pascal, has worked on the development of TypeScript
|js};

let flowContent = {js|
Flow is a static type checker for your JavaScript code. It does a lot of work to make you more productive. Making you code faster, smarter, more confidently, and to a bigger scale.

Flow checks your code for errors through static type annotations. These types allow you to tell Flow how you want your code to work, and Flow will make sure it does work that way.

Because Flow understands JavaScript so well, it doesn’t need many of these types. You should only ever have to do a minimal amount of work to describe your code to Flow and it will infer the rest. A lot of the time, Flow can understand your code without any types at all.

You can also adopt Flow incrementally and easily remove it at anytime, so you can try Flow out on any codebase and see how you like it.
|js};

let elmContent = {js|
Elm is a functional language that compiles to JavaScript. It competes with projects like React as a tool for creating websites and web apps. Elm has a very strong emphasis on simplicity, ease-of-use, and quality tooling.

This guide will:

Teach you the fundamentals of programming in Elm.
Show you how to make interactive apps with The Elm Architecture.
Emphasize principles and patterns that generalize to programming in any language.
By the end I hope you will not only be able to create great web apps in Elm, but also understand the core ideas and patterns that make Elm nice to use.

If you are on the fence, I can safely guarantee that if you give Elm a shot and actually make a project in it, you will end up writing better JavaScript and React code. The ideas transfer pretty easily!
|js};

let reasonmlContent = {js|
Reason is not a new language; it's a new syntax and toolchain powered by the battle-tested language, OCaml. Reason gives OCaml a familiar syntax geared toward JavaScript programmers, and caters to the existing NPM/Yarn workflow folks already know.

In that regard, Reason can almost be considered as a solidly statically typed, faster and simpler cousin of JavaScript, minus the historical crufts, plus the features of ES2030 you can use today, and with access to both the JS and the OCaml ecosystem!

Reason compiles to JavaScript thanks to our partner project, BuckleScript, which compiles OCaml/Reason into readable JavaScript with smooth interop. Reason also compiles to fast, barebone assembly, thanks to OCaml itself.
|js};

let flowImage: string = [%bs.raw {| require('../imgs/flowtype.svg') |}];
let typescriptImage: string = [%bs.raw
  {| require('../imgs/typescript.svg') |}
];
let reasonImage: string = [%bs.raw {| require('../imgs/reason.svg') |}];

let languages: list(t) = [
  {
    slug: "typescript",
    title: "TypeScript",
    content: typescriptContent,
    image: typescriptImage,
  },
  {slug: "flow", title: "Flow", content: flowContent, image: flowImage},
  {slug: "elm", title: "Elm", content: elmContent, image: ""},
  {
    slug: "reasonml",
    title: "ReasonML",
    content: reasonmlContent,
    image: reasonImage,
  },
];

let webpackContent = {js|
Webpack (stylised webpack) is an open-source JavaScript module bundler. It is a module bundler primarily for JavaScript, but it can transform front-end assets like HTML, CSS, even images if the corresponding plugins are included. Webpack takes modules with dependencies and generates static assets representing those modules.

Webpack takes the dependencies and generates a dependency graph allowing web developers to use a modular approach for their web application development purposes. It can be used from the command line, or can be configured using a config file which is named webpack.config.js. This file is used to define loaders, plugins, etc., for a project. (Webpack is highly extensible via loaders which allow developers to write custom tasks that they want to perform when bundling files together.) A tool named createapp.dev simplifies the process of creating this config file.

Node.js is required for installing Webpack.

Webpack provides code on demand using the moniker code splitting. The Technical Committee 39 for ECMAScript is working on standardization of a function that loads additional code: proposal-dynamic-import.
|js};

let parcelContent = {js|
🚀 Blazing fast bundle times
Parcel uses worker processes to enable multicore compilation, and has a filesystem cache for fast rebuilds even after a restart.

📦 Bundle all your assets
Parcel has out of the box support for JS, CSS, HTML, file assets, and more - no plugins needed.

🐠 Automatic transforms
Code is automatically transformed using Babel, PostCSS, and PostHTML when needed - even node_modules.

✂️ Zero config code splitting
Using the dynamic import() syntax, Parcel splits your output bundles so you only load what is needed on initial load.

🔥 Hot module replacement
Parcel automatically updates modules in the browser as you make changes during development, no configuration needed.

🚨 Friendly error logging
Parcel prints syntax highlighted code frames when it encounters errors to help you pinpoint the problem.
|js};

let webpackImage: string = [%bs.raw {| require('../imgs/webpack.svg') |}];
let parcelImage: string = [%bs.raw {| require('../imgs/parcel.png') |}];

let bundlers: list(t) = [
  {
    slug: "webpack",
    title: "Webpack",
    content: webpackContent,
    image: webpackImage,
  },
  {
    slug: "parcel",
    title: "Parcel",
    content: parcelContent,
    image: parcelImage,
  },
];

let articles: list(t) = List.append(languages, bundlers);
