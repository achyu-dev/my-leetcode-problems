You are given a valid postfix expression as a string, where:

    Operands are single lowercase English letters ('a' to 'z')
    Operators are binary: '+', '-', '*', '/'
    The expression contains no spaces and is guaranteed to be valid.


Write a function to convert the postfix expression into a prefix expression, also as a string without spaces.

Example 1

Input: expression = "ab+"

Output: "+ab"

Explanation: Postfix → Prefix

Example 2

Input: expression = "abc*+d-"

Output: "-+a*bcd"

Constraints

    1 <= len(postfix) <= 1000
    The postfix expression is valid (no need to validate correctness)
    Operands are lowercase letters (a-z)
    Operators are binary: +, -, *, /