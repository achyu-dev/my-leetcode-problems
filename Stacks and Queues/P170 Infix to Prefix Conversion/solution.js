class Solution {
  precedence(c) {
    if (c === "^") return 3;
    else if (c === "*" || c === "/") return 2;
    else if (c === "+" || c === "-") return 1;
    else return -1;
  }

  // function to check if a character is an operator
  isOperator(c) {
    return ["+", "-", "*", "/", "^"].includes(c);
  }

  // function to check if operator is right-associative
  isRightAssociative(c) {
    return c === "^";
  }

  infixToPrefix(infix) {
    const stack = [];
    let res = "";
    for (let i = infix.length - 1; i >= 0; i--) {
      const c = infix[i];
      if (/[a-zA-Z0-9]/.test(c)) {
        res += c;
      } else if (c === ")") {
        stack.push(c);
      } else if (c === "(") {
        while (stack.length && stack[stack.length - 1] !== ")") {
          res += stack.pop();
        }
        stack.pop(); // Pop the ')'
      } else if (this.isOperator(c)) {
        while (
          (stack.length &&
            this.precedence(c) < this.precedence(stack[stack.length - 1])) ||
          (this.precedence(c) === this.precedence(stack[stack.length - 1]) &&
            !this.isRightAssociative(c))
        ) {
          res += stack.pop();
        }
        stack.push(c);
      }
    }
    while (stack.length) {
      res += stack.pop();
    }

    return res.split("").reverse().join("");
  }
}

// Example usage:
const solution = new Solution();
const infix = "A+B*C";
const prefix = solution.infixToPrefix(infix);
console.log(prefix);
