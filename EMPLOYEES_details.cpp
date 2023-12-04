//USING INHERITANCE

#include <iostream>
using namespace std;
class Person 
{
public:
  string name;
  int age;
  void getName() {
    cout<<"Enter name: ";
    cin>>name;
  }
  void getAge() {
    cout<<"Enter age: ";
    cin>>age;
  }
};
class Employee:public Person {
public:
  double salary;
  void getSalary() {
    cout<<"Enter salary: ";
    cin>>salary;
  }
  void display() 
  {
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Salary: "<<salary<<endl;
  }
};
int main() 
{
  Employee emp[5];
  for(int i=0;i<5;++i) 
  {
    emp[i].getName();
    emp[i].getAge();
    emp[i].getSalary();
  }
  cout<<"Employee details:"<<endl;
  for (int i=0; i<5;++i)
  {
    emp[i].display();
  }
  return 0;
}

//USING EXPECTION HANDLING

#include<iostream>
using namespace std;
class Employee {
public:
  string name;
  int age;
  double salary;
  void setDetails() {
    try 
    {
      cout<<"Enter name: ";
      cin>>name;
      cout<<"Enter age: ";
      cin>>age;
      cout<<"Enter salary: ";
      cin>>salary;
     if(age<0) 
     {
        throw invalid_argument("Age cannot be negative!");
      }
      if(salary<0)
      {
        throw invalid_argument("Salary cannot be negative!");
      }
    } 
    catch(const invalid_argument& e) 
    {
      cout<<e.what()<<endl;
      setDetails();
    }
  }
  void getAge() {
    cout<<"Enter age: ";
    cin>>age;
  }
  void display() 
  {
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Salary: "<<salary<<endl;
  }
};
int main() 
{
  Employee emp[5];
  for(int i=0;i<5;++i)
  {
    emp[i].setDetails();
  }
  cout<< "Employee details:"<<endl;
  for (int i=0;i<5;++i)
  {
    emp[i].display();
  }
  return 0;
}

//USING VIRTUAL FUNTION

#include <iostream>
using namespace std;
class Employee {
public:
  virtual void getData()
  {
    cout<<"Enter name: ";
    getline(cin, name);
    cout<<"Enter age: ";
    cin>>age;
    cout<<"Enter salary: ";
    cin>>salary;
  }
protected:
  string name;
  int age;
  float salary;
};
int main() {
  Employee emps[5];
  for (int i=0;i<5;++i) 
  {
    emps[i].getData();
  }
  return 0;
}

//USING FRIEND FUNCTION

#include <iostream>
using namespace std;
class Employee {
private:
  string name; 
  int age;
  float salary;
public:
  friend void getData(Employee& emp);
protected:
  string getName() 
  { 
      return name; 
      
  }
  int getAge()
  {
      return age; 
      
  }
  float getSalary() 
  {
      return salary;
}
};
void getData(Employee& emp) {
   cout<<"Enter name: ";
   getline(cin, emp.name);
   cout<<"Enter age: ";
   cin>>emp.age;
   cout<<"Enter salary: ";
   cin>>emp.salary;
}
int main() 
{
  Employee emps[5];
  for (int i=0;i<5;++i) 
  {
    getData(emps[i]);
  }
}
