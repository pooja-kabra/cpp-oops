#include <iostream>
using namespace std;

/* LINKED LIST - MAKING MEMBER FUNCTIONS OF LIST CLASS FRIENDS OF NODE CLASS
   List is built on Node. Hence List needs to know internals of Node
   void List::append(Node *) needs internals of Node - hence member friend function is used
   void List::display() needs internals of Node - hence member friend function is used
   We can do better with friend classes
*/
class Node; // Forward declaration
class List{
 private:
    Node *head;
    Node *tail;
 public:
    List(Node *h = 0):
        head(h), tail(h){}
    void display();
    void append(Node *p);
};

class Node{
 private:
    int info;
    Node *next;
 public:
    Node(int i): info(i), next(0){}
    friend void List::display();
    friend void List::append(Node *);
};

void List::display() {
    Node *ptr = head;
    while (ptr){
        cout << ptr->info << " ";
        ptr = ptr->next;
    }
}

void List::append(Node *p){
    if(!head) 
        head = tail = p;
    else{
        tail->next = p;
        tail = tail->next;

    }    
}

int main(){
    List l;                   // Init null list
    Node n1(1), n2(2), n3(3); // Few nodes
    l.append(&n1);            // Add nodes to the list
    l.append(&n2);
    l.append(&n3);
    l.display();              // Show list
    
    return 0;
}
