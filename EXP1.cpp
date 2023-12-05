//USING INHERITANCE

#include <iostream>
using namespace std;
class Number 
{
  public:
  double value;
  Number(double val): 
  value(val)
  {
  }
};
class Average:public Number
{
public:
  Average(double a,double b,double c,double d,double e) : 
  Number(a+b+c+d+e) 
  {
    average = value/5;
  }

  double getAvg() 
  { 
      return average; 
      
  }

private:
  double average;
};
int main() 
{
  Average avg(1, 2, 3, 4, 5);
  cout<< "Average: "<<avg.getAvg()<<endl;
  return 0;
}

//USING EXCEPTION HANDLING

#include<iostream>
using namespace std;
int main()
{ 
int num1,num2,num3,num4,num5;
float average;
cout<<"\n Enter five numbers: ";
cin>>num1>>num2>>num3>>num4>>num5;
try
{
  if(num1<0||num2<0||num3<0||num4<0||num5<0) 
    {
      throw invalid_argument("\n Negative numbers are not allowed");
    }
    average=(num1+num2+num3+num4+num5)/5;
    cout<<"\n The average of the numbers is: "<< average<<endl;
}
catch (const invalid_argument& e)
{
        cerr<<"\n Invalid input: "<<e.what()<<endl;
}
return 0;
}

//USING VIRTUAL FUNCTION

#include<iostream>
using namespace std;
class NumbCalculator 
{
public:
  virtual double getAvg(double a, double b, double c, double d, double e) = 0;
};
class SimpleCalculator : public NumbCalculator {
public:
  double getAvg(double a, double b, double c, double d, double e) override {
    return (a+b+c+d+e)/5;
  }
};
int main() 
{
  SimpleCalculator calc;
  double average = calc.getAvg(1, 2, 3, 4, 5);
  cout<<"Average: "<< average<<endl;
  return 0;
}

//USING FRIEND FUNCTION

#include<iostream>
using namespace std;
class Number
{
  double value;
public:
  Number(double val):value(val) 
  {}
  friend double getAvg( Number& a,  Number& b,  Number& c,  Number& d,  Number& e);
};
double getAvg(Number& a, Number& b, Number& c, Number& d,Number& e) 
{
  return (a.value+b.value+c.value+d.value+e.value)/5;
}
int main() {
  Number num1(1),num2(2),num3(3),num4(4),num5(5);
  double average=getAvg(num1,num2,num3,num4,num5);
  cout<<"Average: "<< average<<endl;
  return 0;
}
