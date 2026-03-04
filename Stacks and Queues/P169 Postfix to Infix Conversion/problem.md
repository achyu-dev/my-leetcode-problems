You are given a valid postfix expression as a string, where:


    Operands are single lowercase English letters ('a' to 'z')


    Operators are binary: '+', '-', '*', '/'


The expression contains no spaces and is guaranteed to be syntactically valid.

Write a function to convert the given postfix expression into a valid infix expression.


Use parentheses to clearly represent the evaluation order of the expression.

Example 1

Input: "ab+"

Output: "(a+b)"

Explanation:

     postfix : a b +
     infix  : (a + b)

Example 2

Input: "abc*+"

Output: "(a+(b*c))"

Constraints

    1 ≤ postExp.length ≤ 16000
    postExp consists only of lowercase letters (a‒z) as operands and the four binary operators + - * /.
    The given postfix expression is guaranteed valid (every operator has exactly two operands).