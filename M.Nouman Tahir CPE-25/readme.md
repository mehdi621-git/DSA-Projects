This C++ program is a simple Task Scheduler that allows users to manage and organize tasks effectively. 
It uses a structure named Task to store information about each task, including its description, priority (with 1 as high, 2 as medium, and 3 as low), deadline, and completion status. 
The program maintains an array of tasks and provides a menu-driven interface for user interaction. 
A special feature allows the user to execute the next most important pending task based on priority.
Internally, the program uses basic array operations and sorting (bubble sort) to manage the list of tasks. 
The overall design is straightforward and suitable for beginner-level understanding of struct usage, arrays, loops, conditional logic, and user input handling in C++.
The user interacts with the program through a menu-based interface presented in the menu() function.
Options include adding a task, viewing tasks sorted by either priority or deadline, searching for tasks using keywords, marking tasks as completed, deleting tasks, and executing the next highest-priority pending task.
The addTask() function collects task details from the user and appends them to the task array.
The displayByPriority() and displayByDeadline() functions use bubble sort to organize and present tasks in a user-friendly format.
The markCompleted() function allows users to mark a task as completed based on a keyword match in the description, 
while searchTask() helps locate and display task details similarly.
If a user wishes to remove a task, deleteTask() shifts the array elements accordingly to maintain the list.
A standout feature is executeNextTask(), which intelligently finds the next most important task that has not been completed, based on the highest priority, and gives the user the option to mark it done. 
The entire system runs within a loop in the menu() function, ensuring continuous interaction until the user chooses to exit. 
