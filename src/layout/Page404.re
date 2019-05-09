open Components;

let image: string = [%bs.raw
  {| require('../imgs/undraw_page_not_found_su7k.svg') |}
];

let s = React.string;

[@react.component]
let make = () => <Page title="Error 404: Not Found" image />;
