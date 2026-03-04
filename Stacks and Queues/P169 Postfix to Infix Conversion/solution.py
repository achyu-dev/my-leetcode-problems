class Solution:
    def precedence(self, op):
        if (op == '^'):
            return 3
        elif (op == '*' or op == '/'):
            return 2
        elif (op == '+' or op == '-'):
            return 1
        else:
            return -1
        
    def post_to_infix(self, post_exp: str) -> str:
        stack = []
        for ch in post_exp:
            if ch.isalnum():
                stack.append(ch)
            else:
                op1 = stack.pop()
                op2 = stack.pop()

                if len(op1) > 1 and self.precedence(op1[-2]) < self.precedence(ch):
                    op1 = '(' + op1 + ')'

                if len(op2) > 1 and self.precedence(op2[-2]) < self.precedence(ch):
                    op2 = '(' + op2 + ')'

                stack.append(op2 + ch + op1)
        return stack[-1]

# Example usage:
solution = Solution()
postfix_expression = "abc*+"
infix_expression = solution.post_to_infix(postfix_expression)
print(infix_expression)
