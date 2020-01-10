# REblog

Won't be cool to have a static blog written in ReasonML? So this is a proof of concept to achieve that using Reason React, Parcel and some Parcel plugins to load markdown files and also for generating those static files.

## Things to improve

- [x] Add syntax highlight for code blocks inside posts
- [x] Prerender css
- [x] Code splitting
- [ ] Navigation between articles
- [ ] Navbar/navigation menu
- [ ] Add a way to add custom pages (about, concat, ect...)
- [ ] Pagination
- [ ] Show latest post on index
- [ ] Progressive image loading / automate thumbnail creation?

## Install dependencies

```bash
npm install
```

## Build production static files

```bash
npm run build
```

This command produces the production build, it will be placed inside the `/dist` folder.

## Run in development mode

```bash
npm start
```
