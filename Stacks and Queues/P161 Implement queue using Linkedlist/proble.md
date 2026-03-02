Implement a First-In-First-Out (FIFO) queue using a singly linked list. The implemented queue should support the following operations: push, pop, peek, and isEmpty.


Implement the LinkedListQueue class:


void push(int x): Adds element x to the end of the queue.

int pop(): Removes and returns the front element of the queue.

int peek(): Returns the front element of the queue without removing it.

boolean isEmpty(): Returns true if the queue is empty, false otherwise.

Example 1

Input:

["LinkedListQueue", "push", "push", "peek", "pop", "isEmpty"]

[[], [3], [7], [], [], []]

Output:[null, null, null, 3, 3, false]

Explanation:

LinkedListQueue queue = new LinkedListQueue();

queue.push(3);

queue.push(7);

queue.peek(); // returns 3

queue.pop(); // returns 3

queue.isEmpty(); // returns false

Example 2

Input:

["LinkedListQueue", "push", "pop", "isEmpty"]

[[], [2], [], []]

Output: [null, null, 2, true]

Explanation:

LinkedListQueue queue = new LinkedListQueue();

queue.push(2);

queue.pop(); // returns 2

queue.isEmpty(); // returns true

Constraints

    1 <= numbers of calls made <= 100
    1 <= x <= 100