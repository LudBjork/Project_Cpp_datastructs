#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

/*  
Defining a node type structure, which refers
*/
struct Node { 
    int value;
    Node* next;

    Node(int n){
        value = n;
        next = nullptr;
    }

    Node(int n, Node* forwards){
        value = n;
        next = forwards;
    }
};

class CircLinkedList{
private:
    Node* head;
    Node* tail;
    int size;


public:
/*
    Define a new circular linked list as empty
*/
    CircLinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    CircLinkedList(int n){
        for (int i=1; i<=n; i++){
            append(i);
        }
    }

    void append(int n){
        if (head == nullptr){
            head = new Node(n);
            tail = head;
            head->next = head;
            size = 1;
            return; 
        }
        Node* current;
        current = tail;
        tail->next = new Node(n);
        tail = tail->next;
        tail->next = head;
        size += 1;
    }

    int& operator[](int n){
        Node* current; 
        current = head; 
        for (int i=0; i<n; i++){
            current = current->next;
        }
        return current->value;
    }

    void print(){
        Node* current = head;
        cout << "[ ";
        while (current->next != nullptr){
            cout << current->value;
            cout <<  ", ";
            current = current->next;
            if (current->next == head){
                break;
            }
        }
        cout << current->value << " ...]" <<endl;
    }
};

int main(){
    CircLinkedList L(10);
    L.print();
    return 0;
}
