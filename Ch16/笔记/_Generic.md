### 16.6.7 泛型选择——`_Generic`

关键词：`——Generic`

泛型选择表达式：根据表达式的类型选择一个值。

`_Generic(x, int: 0, float: 1, double: 2, default: 3)`

- `_Generic` 后面的圆括号中包含多个用逗号隔开的项。
- 第1项是一个表达式。
- 后面的每一项由一个类型（标签）、一个冒号和一个值组成。
- 第1个项的类型匹配哪个标签，整个表达式的值就是该标签后面的值。
- 如果没有与类型匹配的标签，表达式的值就是 `default:` 后面的值。
- 泛型选择表达式和`switch`语句类似，前者用表达式的类型匹配标签，后者用表达式的值匹配标签。

