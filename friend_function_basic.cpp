#include <iostream>
using namespace std;

/* FRIEND FUNCTION - BASIC NOTION */
class MyClass { 
 private:
    int data_;
    
 public:
    MyClass(int i): data_(i){}
    
    friend void display(const MyClass &a); // Okay
};

void display(const MyClass& a){  // global function
    cout << "data = " << a.data_ ;
}

int main(){
    MyClass obj(10);
    
    display(obj);
    
    return 0;

}


    
  
  
      


