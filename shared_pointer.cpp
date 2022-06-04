#include <iostream>
using namespace std;
// Reference counter class
class Counter{
 private:
    unsigned int m_counter;
 public:
    Counter(): m_counter(0){}
    Counter(const Counter&) = delete;             // deleting copy constructor for Counter
    Counter& operator=(const Counter &) = delete; // deleting = operator for Counter
    
    // Destructor
    ~Counter() {
        m_counter = 0;
    }
    
    void reset() {
        m_counter = 0;
    }
    
    unsigned int get() {
        return m_counter;
    }
    
    // Overload post/pre increment    //
    void operator++(){
        m_counter++;
    }
    
    void operator++(int){
        m_counter++;
    }
    
    // Overload post/pre decrement
    void operator--(){
        m_counter--;
    }
    
    void operator--(int){
        m_counter--;
    }
    
    // Overloading << operator
    friend ostream& operator<<(ostream& os,
                                const Counter& counter) {
        os << "Counter value : " << counter.m_counter << endl;
        return os;
    }
};

// Shared pointer class
template <typename T>
class Shared_ptr{
  private:
    // Shared pointer
    T *m_ptr;
    // Reference counter
    Counter *m_counter;
    
  public:
    // Constructor
    explicit Shared_ptr (T *ptr = nullptr) {
        m_ptr = ptr;
        m_counter = new Counter();
        if(ptr) {
            (*m_counter)++;
        }
    }
    
    // Copy Constructor
    Shared_ptr (Shared_ptr<T>& sp){
        
        m_ptr = sp.m_ptr;
        m_counter = sp.m_counter;
        (*m_counter)++;
    }
    
    // Reference Count
    unsigned int useCount(){
        return m_counter->get();
    }
    
    // Get the pointer
    T* get(){
        return m_ptr;
    }
    
    // Overload * operator
    T& operator*(){
        return *m_ptr;
    }
    
    // // Overload -> operator
    // T* operator->(){
    //     return m_ptr;
    // }
    
    // Destructor
    ~Shared_ptr(){
        
        if(m_counter->get() == 0) {
            delete m_counter;
            delete m_ptr;
        }else{
            (*m_counter)--;
        }
    }
    
    friend ostream& operator<<(ostream& os,
                               Shared_ptr<T>& sp)
    {
        os << "Address pointed : " << sp.get() << endl;
        os << *(sp.m_counter) << endl;
        return os;
    }
};

int main(){
    Shared_ptr<int>ptr1(new int(151));
    cout << "--- Shared pointers ptr1 ---\n";
    *ptr1 = 100;
    // cout << " ptr1's value is now: " << *ptr1 << endl;
    cout << ptr1 << endl; 
    {
        Shared_ptr<int>ptr2 = ptr1;
        cout << "--- Shared pointers ptr1, ptr2 ---\n";
        cout << ptr1 << " ";
        cout << ptr2 << endl;

        {
            Shared_ptr<int>ptr3(ptr2);
            cout << "--- Shared pointers ptr1, ptr2, ptr3 ---\n";
            cout << ptr1<< " ";
            cout << ptr2<< " ";
            cout << ptr3<< endl; 

        }
        cout << "--- Shared pointers ptr1, ptr2 ---\n";
        cout << ptr1<< " ";
        cout << ptr2<< endl;

    }
    cout << "--- Shared pointers ptr1 ---\n";
    cout << ptr1;

    
    return 0;
}
