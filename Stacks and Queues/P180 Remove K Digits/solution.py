def removeKdigits(num: str, k: int) -> str:
    stack = []

    for digit in num:
        while stack and k > 0 and stack[-1] > digit:
            stack.pop()
            k -= 1
        stack.append(digit)

    # if removals left
    while k > 0:
        stack.pop()
        k -= 1

    result = "".join(stack).lstrip('0')

    return result if result else "0"

# Example usage:
num = "1432219"
k = 5
print(removeKdigits(num, k))