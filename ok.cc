#include <iostream>
using namespace std;


class B {
public:
        B(int* ptr) :int_ptr(ptr) {};

        int *int_ptr;
};

class A {
public:
        A() :ptr(nullptr) {};
        A(B* ptr) :B_ptr(ptr) {};
        A(A* ptr) :ptr(ptr) {};
        A(int* ptr) :int_ptr(ptr) {};

        B* B_ptr;
        A* ptr;
        int* int_ptr; 

};

void access(A* z) {
   cout << z->ptr << endl;
}

int main() {

        int *c = new int(3);
        
        A *z_ptr;

        A *z = new A;
        z_ptr = z;

        B *a = new B(c);

        A *A_PTR = new A(a);
        A *w = new A(A_PTR);
 
        cout << A_PTR->B_ptr << endl;

        delete a;

        delete z; 
  
        delete c; 

        cout << A_PTR->B_ptr->int_ptr << endl;
        
        cout << *(A_PTR->B_ptr->int_ptr) << endl;      //UAF where B_ptr is freed

        //cout << z->ptr << endl;           //UAF where z is freed
        
        access(z_ptr);
        
        return 0;
}
