Implement a Last-In-First-Out (LIFO) stack using a singly linked list. The implemented stack should support the following operations: push, pop, top, and isEmpty.


Implement the LinkedListStack class:


void push(int x): Pushes element x onto the stack.

int pop(): Removes and returns the top element of the stack.

int top(): Returns the top element of the stack without removing it.

boolean isEmpty(): Returns true if the stack is empty, false otherwise.

Example 1

Input:

["LinkedListStack", "push", "push", "pop", "top", "isEmpty"]

[[], [3], [7], [], [], []]


Output: [null, null, null, 7, 3, false]

Explanation:

LinkedListStack stack = new LinkedListStack();

stack.push(3);

stack.push(7);

stack.pop(); // returns 7

stack.top(); // returns 3

stack.isEmpty(); // returns false

Example 2

Input:

["LinkedListStack", "isEmpty"]

[[]]


Output: [null, true]

Explanation:

LinkedListStack stack = new LinkedListStack();

stack.isEmpty(); // returns true