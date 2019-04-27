import '../../node_modules/highlight.js/styles/github.css';
import React from 'react';
import MarkdownToJsx from 'markdown-to-jsx';
import Highlight from "react-highlight";

const defaultOptions = {
  overrides: {
    code: {
      component: Highlight,
    },
  },
};

const Markdown = (props) =>
  <MarkdownToJsx options={defaultOptions} {...props}/>;


module.exports = Markdown;
