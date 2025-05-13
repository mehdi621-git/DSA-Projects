Name Sorter Tool Problem Statement The 31-Name Sorter Tool is designed to organize a list of user-entered names into alphabetical order.
Users enter between 20 and 50 names, and the program sorts them from A to Z. 
This is useful for applications like class rosters or contact lists where sorting by name is needed.
Internally, the tool compares names lexicographically (alphabetical order) .
For example, using functions like strcmp or C++ string comparison operators – so that "Alice" comes before "Bob"By implementing Merge Sort, the tool ensures efficient sorting regardless of input order Algorithm Explanation Merge Sort works by recursively dividing the list of names into halves, sorting each half, and then merging them in order. 
Initially, the full list (e.g. 31 names) is split into two sublists (e.g. 15 and 16 names). 
Each sublist is further split until each piece contains only one name. 
Then, the merge process begins: pairs of single-name lists are merged by comparing their names lexicographically . 
At each merge step, the smallest (alphabetically first) name from the fronts of the two lists is added to the merged list. 
This merging continues up the recursion until the entire list is reassembled as one sorted list. 
This divide-and-conquer strategy guarantees a time complexity of O(n log n) , making it efficient even for the maximum of 50 names.
