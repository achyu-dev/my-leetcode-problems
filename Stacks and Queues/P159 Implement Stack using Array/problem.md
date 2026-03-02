Implement a Last-In-First-Out (LIFO) stack using an array. The implemented stack should support the following operations: push, pop, peek, and isEmpty.


Implement the ArrayStack class:


void push(int x): Pushes element x onto the stack.

int pop(): Removes and returns the top element of the stack.

int top(): Returns the top element of the stack without removing it.

boolean isEmpty(): Returns true if the stack is empty, false otherwise.




Please note that this section might seem a bit difficult without prior knowledge on what stacks is, we will soon try to add basics concepts for your ease! If you know the concepts already please go ahead to give a shot to the problem. Cheers!

Example 1

Input: ["ArrayStack", "push", "push", "top", "pop", "isEmpty"]

[[], [5], [10], [], [], []]

Output: [null, null, null, 10, 10, false]

Explanation:

ArrayStack stack = new ArrayStack();

stack.push(5);

stack.push(10);

stack.top(); // returns 10

stack.pop(); // returns 10

stack.isEmpty(); // returns false

Example 2

Input: ["ArrayStack","isEmpty", "push", "pop", "isEmpty"]

[[], [], [1], [], []]

Output: [null, true, null, 1, true]

Explanation: 

ArrayStack stack = new ArrayStack();

stack.push(1);

stack.pop(); // returns 1

stack.isEmpty(); // returns true

Constraints

    1 <= numbers of calls made <= 100
    1 <= x <= 100