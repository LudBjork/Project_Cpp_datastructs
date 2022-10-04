#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

/* 
    -   The class ArrayList defines an array by either providing
        the number of elements the array should contain, or by
        providing a vector<int> object. 
*/
class ArrayList {
private:
    int *array;
    int init_cap; 
    int growth = 2;
    int *resized_array;
    int size = 0;

/* 
    resized_array has twice the capasity of array.
    resized_array contains the same ints as array.

    Deallocates array and replaces it with resized_array.
*/
    void resize(){
        resized_array = new int[growth * init_cap];
        for (int i=0; i < size; i++){
            resized_array[i] = array[i];
        }
    delete[] array;
    array = resized_array;
    }

public: 
/* 
    Constructor with parameter int n. 
    Defines an ArrayList object via. parameter int n.
    n defines the initial capasity of the ArrayList object. 
*/
    ArrayList(int n){
        init_cap = n;
        array = new int[init_cap];
    }

/* 
    Defines an ArrayList object via. a vector<int> object, 
    a 'list' containing only integers. 

    The capasity is set to 100 initially.

    Then we use the append() method to replace the vector
    with an ArrayList object.
*/
    ArrayList(vector<int> vector){
        init_cap = 100;
        array = new int[init_cap];
        for (int i: vector){
            append(i);
        }
    }

/*
    Deallocates the array after usage. 
    This way, we optimalise our program for effiency.
*/
    ~ArrayList(){
        delete[] array;
    }

/*
    Iterates through the ArrayList object array 
    as long as the counter is smaller than size. 
    
    parameters: none

    returns: int counter, length of the ArrayList object 
*/
    int length(){
        int counter = 0;
        for (int i=0; i < size; i++){
            counter++;
        }
        return counter;
    }

/*  
    Sets n as the final element of the list
    , and increases the size by 1.

    parameter: int n
    returns: none
*/
    void append(int n){
        if (size >= init_cap) {
            resize();
        }
        array[size] = n;
        size = size + 1;
    }

/*  
    Prints all the elements in the ArrayList object array
    on the same line in the terminal. 

    parameters: none

    returns: none
*/
    void print(){
        for (int i=0; i < size; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }

/*  -   if index non-compatable with list, 
        throw out_of_range("index error").
    
    -   otherwise, move elements one index up

    -   NOTE: You must have defined elements 
              in an ArrayList object!

    parameters:

    int val | the value to insert

    int index | the index you insert the value val at. 

    returns: none
*/
    void insert(int val, int index){
        if (index > size){
            throw out_of_range("Index error in insert");

        } else if (index == size){
            append(val);

        } else {
           int *dupe = new int[init_cap + 1];
           for (int i=0; i<index; i++){
               dupe[i] = array[i];
           }
           dupe[index] = val; 
           for (int i=index+1; i<=size; i++){
               dupe[i] = array[i-1];
           }
           delete[] array;
           array = dupe;
           size = size + 1;
        }

    }

/*
    Removes an element of an ArrayList object.

    parameter: index (of an element in the list)

    returns: none
*/
    void remove(int index){
        if (index >= size){
            throw out_of_range("Index Error in remove function");
        } else{
        int *dupe = new int[init_cap];

        for (int i=0; i<index; i++){
            dupe[i] = array[i]; 
        }

        for (int i=index+1; i<=size; i++){
            dupe[i-1] = array[i]; 
        }

        delete[] array;
        array = dupe;
        size = size - 1;

        if (size < 1/4 * init_cap){
            shrink_to_fit();
        }
        }
    }

/*  
    Removes an element from a list and returns the removed element.
    parameter:  int index,

                Which element of the ArrayList object to remove, 
                based off its index
    returns:    int, 

                element
*/
    int pop(int index){
        int element = array[index];
        remove(index);
        return element;
    }
/*
    Does the same as code above, but removes the last element of 
    an ArrayList object if index not specified. 

    parameter:  none

    returns:    element,
                array[size-1]

*/
    int pop(){
        int element = array[size-1];
        remove(size-1);
        return element;
    }

/*
    Reduces capasity of the list to match the actual size
    as much as possible.

    parameters: none

    returns: none 
*/
    void shrink_to_fit(){
        init_cap = 1;
        while (init_cap <= size){
            init_cap = 2 * init_cap;        
        }
        int *dupe = new int[init_cap];
        delete[] array;
        array = dupe;
    }

/*
A function that retrieves the capasity of an ArrayList object

parameter: none 

returns: the capasity of array
*/
    int get_cap(){
        int n = init_cap;
        return n;
    }

/*  
    Overrides what [ ] means for ArrayList objects. 
    ArrayList objects will now only allow a positive index. 
*/
    int& operator[] (int i){
        if (i >= 0 && i < size){
            return array[i];
        } else{
            throw out_of_range("Index Error");
        }
    }

};

/*  
    A method that checks if some n is a prime number.
    Returns true if n is prime, false otherwise. 


    parameter: int n

    returns: boolean

    Note: 
    Since input type is int, sufficiently large n 
      will force return true, even for non-prime numbers.
*/
bool is_prime(int n){
    if (n <= 1){
        return false;
    } else {
        for (int i=2; i < n; i++){
            if ((n % i) == 0){
                return false;
            } else {
                return true;
            }
        }
    return false;
    }
}

/*  
    Appends only prime numbers to ArrayList object test_list.
    Here, we have used an implementation of is_prime(). 
    
    When called prints: 
    >> 11 7 3 23 47 51 53 19 23
*/
void prime_tester(){
    ArrayList test_list(11);
    int inputs[14] = {-1, 2, 40, 11, 7, 3, 23, 47, 51, 53, 19, 23};
    int i = 0;
    while (i < 14){
        if (is_prime(inputs[i]) == true){
            test_list.append(inputs[i]);
            i++;
        }
        else {
            i++;
        }
    }
    test_list.print();
}

int main(){
    ArrayList list({1,2,90,100,23}); 
    cout << list.get_cap() << endl;
    list.shrink_to_fit();
    cout << list.get_cap() << endl;
    list.pop();
    list.pop();
    list.pop();
    list.shrink_to_fit();
    cout << list.get_cap() << endl;
    return 0;
}
