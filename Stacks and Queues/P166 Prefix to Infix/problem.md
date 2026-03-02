You are given a valid arithmetic expression in prefix notation. Your task is to convert it into a fully parenthesized infix expression.

Prefix notation (also known as Polish notation) places the operator before its operands. In contrast, infix notation places the operator between operands.


Your goal is to convert the prefix expression into a valid fully parenthesized infix expression.

Example 1

Input: expression = "+ab"

Output: "(a+b)"

Example 2

Input: expression = "*+ab-cd"

Output: "((a+b)*(c-d))"

Constraints

    1 <= expression.length <= 104
    Expression contains Valid binary operators: +, -, *, /, ^
    Expression contains Valid operands: lowercase letters (a-z) or digits (0-9)
    Expression contains The input is guaranteed to be a valid prefix expression.