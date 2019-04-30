---
title: Parcel
slug: parcel
category: bundlers
---

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

Hello World
Start with the entry HTML file for your application. Parcel follows the dependencies from there to build your whole app.

✏️ index.html

```html
<html>
<body>
	<script src="./index.js"></script>
</body>
</html>
```

🛠 index.js

```javascript

// import another component
import main from './main';

main();
```

🛠 main.js

```javascript
// import a CSS module
import classes from './main.css';

export default () => {
	console.log(classes.main);
};
```

💅 main.css

```css
.main {
  /* Reference an image file */
  background: url('./images/background.png');
  color: red;
}
```
          
Run parcel index.html to start a dev server. Importing JavaScript, CSS, images, and more just works! 👌
