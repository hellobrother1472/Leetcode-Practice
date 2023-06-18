#include <bits/stdc++.h>
using namespace std;

// There is a necessity to use the single pointer to refer to all the objects of the different classes. So, we create the pointer to the base class that refers to all the derived objects. But, when base class pointer contains the address of the derived class object, always executes the base class function. This issue can only be resolved by using the 'virtual' function.
// The main purpose of a pure virtual destructor is to make a class abstract without forcing derived classes to override any specific methods.It is a way to indicate that the class should not be instantiated directly, but only through derived classes.It's important to note that even if a destructor is declared as pure virtual, it still needs to have an implementation. This means that the derived classes can use the default implementation provided in the base class, but they need to explicitly call it if they want to use it.
// An abstract class is a class which has pure virtual function.

class Abstract{
public:
    virtual void func() = 0; // This is a pure virtual function.
};

class A{
private:
    int c = 3;
protected:
    int b = 2;
public:
    int a = 1;
    A(){}
    // Copy constructor
    A(A&obj){
        cout << "copy constructer is called" << endl;
    }
    A& operator=(A&obj){
        cout << "Assignment operator is called" << endl;
    }
    friend void friendFunc(A& obj); // Friend Function. Get access to whole class private,public,protected.
    void func1(){
        cout << "this is function 1" << endl;
    }
    void func2();
    virtual void func3(){
        cout << "this is a virtual function";
    }
    virtual void func4(); // This is the pure virtual function or do-nothing function.
};

void A :: func2(){ // Function outside of the class.
    cout << "This if func 2" << endl;
}

// class B :  A{ // In this way everything inherited will be made private in B.
//     public:
//     int printb() {
//         return b;
//     }
// };

class B : public A{ // In this way they keep same like public remians public and protected remains protected.
    public:
    void func3(){
        cout << "overrriden func3 in child class"<<endl;
    }
    int printb() {
        return b;
    }
};

void friendFunc(A& obj) { // This is the friend function.
    cout << obj.a << " " << obj.b << " " << obj.c;
}

// Operator overloading

class Complex{
private:
    int real,img;
public:
    // Constructor overloading
    Complex(){
        this->real = 0;
        this->img = 0;
    }
    Complex(int real,int img){
        this->real = real;
        this->img = img;
    }

    // Operator overloading
    Complex operator+(Complex&obj){
        Complex res;
        res.img = this->img + obj.img;
        res.real = this->real + obj.real;
    }
};


int main(){
    // Abstract obj;
    A obj1;
    A obj4;
    B obj2;
    A* obj5 = &obj2;
    obj4 = obj1; // Assignment operator is called 
    A obj3 = obj1; // Copy constructor is called.
    // cout << obj1.a << endl;
    // cout << obj2.printb() << endl;
    friendFunc(obj1);
    
    obj1.func3();
    obj2.func3();
    obj5->func3();
    return 0;
}