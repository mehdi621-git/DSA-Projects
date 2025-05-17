This C++ program is a Currency Exchange Tracker designed to help users manage and convert between different currencies.
It uses a struct Currency to store each currency's symbol, name, and exchange rate relative to USD.
The program can handle up to 100 different currencies using a fixed-size array and keeps track of how many have been added using a counter. 
Users interact with the program through a menu-driven interface that allows them to perform various operations such as adding new currencies, updating exchange rates, converting amounts from one currency to another, sorting currencies by name or rate,
and displaying the full list of available currencies.
The conversion process involves converting the amount to USD using the source currency rate, and then from USD to the target currency. 
The program also provides search functionality, using both binary and linear search — it first tries a binary search on the currency symbol (after sorting by name) and then falls back to a linear search on the currency name. 
Sorting operations use the bubble sort algorithm for simplicity. The system handles user input carefully, clearing any extra input to avoid unexpected behavior.
Overall, the program provides a simple but functional simulation of a currency exchange system and demonstrates key programming concepts including structures, arrays, sorting, searching, and menu-based control flow.
