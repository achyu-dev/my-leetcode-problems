class MyQueue:

    def __init__(self):
        self.stack = []

    def push(self, x: int) -> None:
        def push_bottom(stack, val):
            if not stack:
                stack.append(val)
            else:
                top = stack.pop()
                push_bottom(stack, val)
                stack.append(top)

        push_bottom(self.stack, x)

    def pop(self) -> int:
        return self.stack.pop()

    def peek(self) -> int:
        return self.stack[-1]

    def empty(self) -> bool:
        return len(self.stack) == 0


if __name__ == "__main__":
    obj = MyQueue()
    obj.push(1)
    obj.push(2)
    print(obj.peek())  # return 1
    print(obj.pop())   # return 1
    print(obj.empty()) # return False
    obj.push(3)
    print(obj.pop())   # return 2
    print(obj.pop())   # return 3
    print(obj.empty()) # return True