Given a valid arithmetic expression in infix notation, return its equivalent prefix (Polish) notation.


The expression can contain:


    lowercase letters a–z as operands


    the four binary operators + - * /


    and round parentheses ( ) that enforce evaluation order


    No whitespace appears in the input.


The input is guaranteed to be syntactically correct (parentheses are balanced, every operator has two operands, etc.).

Example 1

Input: "(a+b)*c"

Output: "*+abc"

Explanation:

Infix  : (a + b) * c

Prefix : * + a b c

Example 2

Input: "a+b*c"

Output: "+a*bc"

Explanation:

Infix : a + (b * c)

Prefix : + a * b c

Constraints

    1 ≤ infix.length ≤ 1000
    infix contains only characters {a–z, +, -, *, /, (, )}.
    The expression is valid.