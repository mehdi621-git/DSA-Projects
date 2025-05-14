"Command History Manager"
A simple C++ console-based project that mimics command-line history and undo functionality using `stack`, `queue`, `struct`, and `linear search`.

Features:
-> Add new command entries
 ->View command history in the order they were added (FIFO)
 ->Undo the most recent command (LIFO)
 ->Search for a command by keyword
 ->Exit the program gracefully
 
 DSA Concepts Used:
 Structs:for storing command data (ID + command text)
Stack: (std::stack) to implement undo functionality
Queue:(std::queue) to maintain history order
Linear search: (string::find) to search for keywords in commands

How it Works:

-> User is shown a menu with options to:
1-Add command
2-View history
3-Undo command
4-Search command
5-Exit
-> When a command is added:
    It is pushed to the `undoStack`
    Also enqueued in `historyQueue`
Viewing history copies the queue into a temporary one for safe display
-> Undoing a command:
   - Pops it from the stack
   - Recreates the queue without the popped command
-> Searching goes through the queue using a linear search for matching keywords
