//USING INHERITANCE

#include<iostream>
using namespace std;
class Power {
public:
  double value;
  int expo;
  Power(double value, int expo=2):value(value), expo(expo) 
  {}
  double calculate()
  {
    if(expo==0) 
    return 1;
    if(expo==1) 
    return value;
    Power result(value,expo-1);
    return value*result.calculate();
  }
};
int main() {
  double number;
  int power;
  cout<<"Enter a number: ";
  cin>>number;
  cout<<"Enter power (default 2): ";
  cin>>power;
  Power p(number,power);
  cout<<"Result: "<<p.calculate()<<endl;
  return 0;
}

//USING EXPECTION HANDLING

#include<iostream>
using namespace std;
double POWER(double value,int expo=2) {
  try {
    if(expo<0) 
    throw invalid_argument("Exponent cannot be negative.");
    if(value==0 && expo==0) 
    throw domain_error("0 raised to power 0 is undefined.");
    if(expo==0)
    return 1;
    if(expo==1) 
    return value;
    return value*POWER(value,expo-1);
  } 
  catch(const exception& e) {
   cerr << "Error: " << e.what()<<endl;
    return 0;
  }
}
int main() {
  double number;
  int power;
  cout<<"Enter a number: ";
  cin>>number;
  cout<<"Enter power(default 2): ";
  cin>>power;
  cout<< "Result: "<<POWER(number,power)<<endl;
  return 0;
}


//USING VIRTUAL FUNTION
#include<iostream>
using namespace std;
class Power 
{
public:
  virtual double calculate(double value,int expo)=0;
};
class BasicPower:public Power 
{
public:
  double calculate(double value,int expo) 
  override{
    if(expo==0) 
    return 1;
    if(expo==1) 
    return value;
    return value*calculate(value,expo-1);
  }
};
int main() {
  double number;
  int power;
  cout<<"Enter a number: ";
  cin>>number;
  cout<<"Enter power (default 2): ";
  cin>>power;
  Power*p=new BasicPower();
  cout<<"Result: " << p->calculate(number, power)<<endl;
  delete p;
  return 0;
}


//USING FRIEND FUNTION
#include<iostream>
using namespace std;
class Number 
{
  double value;
public:
  Number(double value) : value(value) 
  {}
  friend double POWER(const Number& n,int expo=2) 
  {
    if(expo==0) 
    return 1;
    if(expo==1) 
    return n.value;
    return n.value*POWER(n, expo-1);
  }
};
int main() 
{
  double number;
  int power;
  cout<<"Enter a number: ";
  cin>>number;
  cout<<"Enter power (default 2): ";
  cin>>power;
  Number num(number);
  cout<<"Result: " << POWER(num, power)<<endl;
  return 0;
}

