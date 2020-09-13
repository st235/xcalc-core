# xcalc-core

The core part of a XCalc project - free open source arithmetic grammar parser

### Grammar rules

```text
statement -> calculation

calculation -> sum
sum -> product (('+' product)|('-' product))*
product -> factor (('*' factor)|('/' factor))*
factor -> short_product | power | term
short_product -> number terminal
power -> term '^' factor
term -> prefix_unary | suffix_unary
terminals -> group | function | variable | number
prefix_unary -> ('+'|'-'|'e') (suffix_unary | terminals)
suffix_unary -> terminals ('!'|'%')
group -> '(' sum ')'
function -> variable '(' sum ')'

number -> any decimal number with dot separator, also dot-first notation (ie '.9') acceptable 
variable -> starts with one or multiple alphabetic character then zero or more numeral. regexp: ([a-z]|[A-Z])+([0-9])*

---
'character' - character literal
|           - logical conjunction
*           - Kleene operator
```

### License

```text
MIT License

Copyright (c) 2020 Alexander Dadukin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
