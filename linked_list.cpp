#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

/*  
Defines a node for our linked list with pointers to 
previous node and next node. 
Each Node object contains an int value. 
*/
struct Node{
  int value;
  Node* next;
  Node* prev;

/*
  Defines a Node object which points to no other node with the int value n.
*/
  Node(int n){
    value = n;
    next = nullptr;
    prev = nullptr;
  }

/*
  Defines a Node object with pointers to previous and next node, 
  as well as storing a value int n.
*/
  Node(int n, Node* p, Node* c){
    value = n;
    next = p;
    prev = c;
  }
};

/*
  Defines a LinkedList by connecting nodes together, 
  where start of list is the Node head, 
  and the end of the list is Node tail.
*/
class LinkedList{
private:
  Node* head;
  Node* tail;
  int size;

  Node* get_node(int index) {
    if (index < 0 or index >= size) {
        throw range_error("IndexError: Index out of range");
    }
    Node* current = head;
    for (int i=0; i<index; i++) {
        current = current->next;
    }
    return current;
  }


public:

/*
Defines an empty LinkedList object
which (for now) points to nowhere.
*/
  LinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
  }

  LinkedList(vector<int> list){
    head = nullptr; 
    tail = nullptr;
    size = 0;
    for (int i: list){
      append(i);
    }
  }

  ~LinkedList() {
    Node* current;
    Node* next;
    
    current = head;
    
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
  }

/*
Starting at head, iterates through LinkedList's nodes
until current points to nullptr.

parameters: none

returns: int count, number of elements in LinkedList object.
*/
  int length(){
    Node* current = head;
    int count = 0;
    while (current != nullptr){
      count++;
      current = current -> next;
    }
  return count;
  }

/*
Defines head as a node with value int val if head points to nullptr

parameter: int val, the value we want to add to a LinkedList object.

returns: none
*/
  void append(int val){
    if (head == nullptr){
      head = new Node(val);
      tail = head;
      size += 1;
      return;
    }
    Node* current;
    current = tail;
    tail = new Node(val);
    current->next = tail;
    tail->prev = current;
    size += 1;
  }

/*
Prints the contents of a LinkedList object in the format
[a, b, c, d, e, f]

parameters: none

returns: none
*/
  void print(){
    Node* current = head;
    cout << "[";
    while (current -> next != nullptr){
      cout << current->value;
      cout << ", ";
      current = current->next;
    }
    cout << current->value << "]" << endl;
  }

  int& operator[](int index){
    return get_node(index)->value;
  }

  void push_front(int val){
    head = new Node(val, head, nullptr);
    size += 1; 
  }

  void insert(int val, int index){
    if (index == size){
      append(val); 
    } else if (index == 0){
      push_front(val);
    } else {
      Node* prev = get_node(index - 1);
      Node* next = prev->next;
      prev->next = new Node(val, next, prev);
      size += 1;
    }
  }


  void remove(int index){
    if (index == 0){
      head = head -> next;
      head -> prev = nullptr;
      size -= 1;
      return ;
    }else if (index == size - 1){
      tail = tail -> prev;
      tail -> next = nullptr;
      size -= 1;
    }else {
      Node* before = get_node(index - 1); 
      Node* after = get_node(index + 1);
      before -> next = after;
      after -> prev = before;
      size -= 1;
      return ;
    }
  }


  int pop(int index){
    Node* current = get_node(index);
    remove(index);
    return current -> value;
  }

  int pop(){
    Node* current = get_node(size - 1);
    remove(size - 1);
    return current -> value;
  }
};

void tester(){
  LinkedList test({1,2,3,4,5,1,2,3});
  cout << "The list to begin with:" << endl;
  test.print();
  // tests append
  test.append(4);
  cout << "appends '4'" << endl;
  test.print();
  // tests insert
  test.insert(100, 0);
  cout << "inserts '100' to index '0' " << endl;
  test.print();
  // tests remove
  test.remove(5);
  cout << "removes element at index '5' " << endl;
  test.print();
  // tests pop at given index
  cout <<"Pops element at index '7': " << test.pop(7) << endl;
  test.print();
  // tests pop overload
  cout << "Pops last element: "<< test.pop() << endl;
  test.print();
  
}



int main(){
  tester();
  return 0;
}
