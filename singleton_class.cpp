#include <iostream>
#include<vector>
using namespace std;

class Printer{  /* THIS IS A SINGLETON PRINTER -- ONLY ONE INSTANCE ! */
    bool blackAndWhite_;
    bool bothSided_;
    
    Printer(bool bw=false, bool bs=true): blackAndWhite_(bw), bothSided_(bs){
        cout << "Printer Constructed" << endl; // private, so printer cannot be constructed!
    }
    static Printer *myPrinter_;
    
 public:
    ~Printer() {
        cout << "Printer destructed" << endl; 
    }
    
    static const Printer& printer(bool bw=false, bool bs= false){ // Access the printer
        if(!myPrinter_){
            myPrinter_=new Printer(bw, bs);
        }
        return myPrinter_;
    }
    
    void print(int nP) const{
        cout<< "Printing " << nP << " pages" << endl;
    }
    
};

Printer *Printer::myPrinter_ = nullptr;

int main(){
    
    Printer::printer().print(10);
    Printer::printer().print(20);
    
    Printer::printer().~Printer();
    
    return 0;
}


    
  
  
      


