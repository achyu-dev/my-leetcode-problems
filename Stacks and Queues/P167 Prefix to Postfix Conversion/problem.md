You are given a valid prefix expression consisting of binary operators and single-character operands. Your task is to convert it into a valid postfix expression.


Prefix (Polish) notation places the operator before operands.

Postfix (Reverse Polish) notation places the operator after operands.

Example 1

Input: expression = "+ab"

Output: "ab+"

Example 2

Input: expression = "*+ab-cd"

Output: "ab+cd-*"

Constraints

    1 <= expression.length <= 104
    Expression contains only valid prefix characters (a-z, 0-9, +, -, *, /, ^)
    Expression is guaranteed to be a valid prefix expression