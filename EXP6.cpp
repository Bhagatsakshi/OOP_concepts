//USING INHERITANCE 

#include <iostream>
using namespace std;
class A {
private:
  int x;
public:
  A(int x) : x(x)
 {}
  void swap(A& other) {
    swap(x, other.x);
  }
  void print() {
    cout << "x: "<<x<<endl;
  }
};
class B : public A 
{
private:
  int y;
public:
  B(int x, int y):A(x), y(y)
 {}
  void swap(B& other) {
    A::swap(other); 
    swap(y,other.y);
  }
  void print() {
    A::print();
    cout << "y: "<<y<<endl;
  }
};
int main() {
  A a(10);
  B b(20,30);
  cout <<"Before swapping:"<<endl;
  a.print();
  b.print();

  a.swap(b);
  cout <<"After swapping:"<<endl;
  a.print();
  b.print();

  return 0;
}
//USING EXCEPTION HANDLING 

#include <iostream>
using namespace std;
class InvalidSwapException : public exception {
public:
    InvalidSwapException()
 {
    cout<<"Invalid swap operation attempted."<<endl;
    }
};

class Data
 {
private:
    int value;
public:
    Data(int value) : value(value) 
{}
    void swap(Data& other) 
{
        if(other.value==value)
 {
      throw InvalidSwapException();
      }
        int temp=value;
        value=other.value;
        other.value=temp;
    }
    void print() const 
{
        cout<<"Value: "<<value<<endl;
  }
};
int main() 
{
    try 
{
        Data a(10);
        Data b(20);
        cout<<"Before swapping:"<<endl;
        a.print();
        b.print();

        a.swap(b);
        cout<<"After swapping:"<<endl;
        a.print();
        b.print();
    } 
catch (InvalidSwapException& e) 
   {
    cout<<e.what()<<endl;
    }
    return 0;
}

//USING FRIEND FUNCTION 

#include<iostream>
using namespace std;
class Data {
private:
    int value;
public:
    Data(int value) : value(value) 
{}
    friend void swap(Data& a,Data& b)
  {
        int temp=a.value;
        a.value=b.value;
        b.value=temp;
    }
    void print() const {
        cout<<"Value: "<<value<<endl;
    }
};
int main()
 {
    Data a(10);
    Data b(20);
    cout<<"Before swapping:"<<endl;
    a.print();
    b.print();
    swap(a,b);
   cout<<"After swapping:"<<endl;
    a.print();
    b.print();
    return 0;
}


//USING FRIEND FUNCTION 
#include<iostream>
using namespace std;
class Data
{
private:
    int value;
public:
    Data(int value):value(value) 
{}
    virtual void swapValues(Data& other)=0;
    void print() const {
        cout<<"Value: "<<value<<endl;
    }
};
class DataImpl:public Data
 {
public:
    DataImpl(int value) : Data(value) 
{}
    void swapValues(Data& other) override
 {
        int temp=value;
        value=other.value;
        other.value=temp;
    }
};
class DataDerived : public Data {
public:
    DataDerived(int value) : Data(value)
 {}

    void swapValues(Data& other) override {
        cout<<"Swapping values in DataDerived"<<endl;
        int temp=value;
        value=other.value;
        other.value=temp;
    }
};
int main()
 {
    DataImpl a(10);
    DataDerived b(20);
    cout<<"Before swapping:"<<endl;
    a.print();
    b.print();
    Data& d1=a; 
    Data& d2=b; 
    d1.swapValues(d2);
    cout<<"After swapping:"<<endl;
    a.print();
    b.print();
    return 0;
}
