# IMPORTANT: This was a collaborative project between me and a fellow student. Sadly, as the original repository is private and is not administered by me, I cannot share   the totality of the project work, but only the final product.

# H20_project2_ludvikbj_thashiat
Project 2 for ludvikbj (ludvikbj@mail.uio.no) and thashiat (thashiat@mail.uio.no)

Link to repo: https://github.uio.no/IN1910/H20_project2_ludvikbj_thashiat.git

Files compiled in Ubuntu Terminal via. WSL as: g++ "filename".cpp -o "filename"

For example, when compiling array_list.cpp, we typed "g++ array_list.cpp -o array_list" into a WSL terminal with Ubuntu 20.04.

====================================================================================================
Part 3: Comparing the ArrayList and the LinkedList

Use of Big-oh notation to define the algorithms-data usage power and run time,
Files in test: linked_list.cpp, array_list.cpp

Get element i by index: 
=
This is O(1) constant for both types of objects. We only need to go through the list until we reach element i.


Insert at front: 
=
For ArrayList objects we will have O(n) when we try to insert at front (because of resize), while O(1) elsewhere, while for LinkedList objects, we will have have O(1) always. This is becouse we only adding a new node to the front of the sequence.


Insert at back (aka append): 
=
For ArrayList objects we will have O(n) when we are going to resize, while O(1) elsewhere, while for LinkedList objects, we will have have O(1) always. 


Insert into middle of list: 
=
For both LinkedList and ArrayList this will take O(n). The run time between the objects is a linear function of the number of elements.


Remove element from front: 
=

ArrayList:  Iterates through all elements to re-allocate the slots one index back. This 'costs' O(n) 

LinkedList: Retrieves the node after and before the index directly, and does iterate a loop, so it 'costs' O(1).


Remove element from back:
=

ArrayList: Same as front 

LinkedList: Same as front

Remove element from middle:
=
ArrayList: Same as front

LinkedList: Same as front

Print:  
=
For both LinkedList and ArrayList this will take O(n). Both objects uses -loops for implementing the print-sequence.  



====================================================================================================

Task 4.G:
=

The answer is 68.
