---
title: ReasonML
slug: reasonml
category: languages
---

Types without hassle

Powerful, safe type inference means you rarely have to annotate types, but everything gets checked for you.

Easy JavaScript interop

Use packages from NPM/Yarn with minimum hassle, or even drop in a snippet of raw JavaScript while you're learning!

Flexible & Fun

Make websites, animations, games, servers, cli tools, and more! Take a look at these examples to get inspired.

```reasonml
type schoolPerson = Teacher | Director | Student(string);

let greeting = person =>
  switch (person) {
  | Teacher => "Hey Professor!"
  | Director => "Hello Director."
  | Student("Richard") => "Still here Ricky?"
  | Student(anyOtherName) => "Hey, " ++ anyOtherName ++ "."
  };
```
