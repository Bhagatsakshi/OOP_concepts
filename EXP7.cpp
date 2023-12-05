//USING INHERITANCE & VIRTUAL FUNCTION

#include <iostream>
#include <string>
using namespace std;
class User {
protected:
  string name;
  int age;
  double income;
  string city;
  bool hasFourWheeler;

public:
  User(const string& name, int age, double income, const string& city, bool hasFourWheeler)
      : name(name), age(age), income(income), city(city), hasFourWheeler(hasFourWheeler) {}
  virtual bool checkEligibility() const = 0; 
};

class EligibleUser : public User {
public:
  EligibleUser(const string& name, int age, double income, const string& city, bool hasFourWheeler)
      : User(name, age, income, city, hasFourWheeler) {}

  bool checkEligibility() const override {
    return (18 <= age && age <= 55) && (50000 <= income && income <= 100000) &&
           (city == "Pune" || city == "Mumbai" || city == "Bangalore" || city == "Chennai") &&
           hasFourWheeler;
  }
};

int main() {
  std::string name, city;
  int age;
  double income;
  bool hasFourWheeler;

  cout << "Enter name: ";
  getline(cin, name);
  cout << "Enter age: ";
  cin >> age;
  cout << "Enter income: ";
  cin >> income;
  cout << "Enter city: ";
  getline(cin, city);
  cout << "Do you have a 4-wheeler (y/n): ";
  cin >> hasFourWheeler;

  try {
    EligibleUser user(name, age, income, city, hasFourWheeler);
    if (user.checkEligibility()) {
      cout << "Congratulations, " << name << ", you are eligible!" <<endl;
    } else {
      throw runtime_error("User does not meet all eligibility criteria.");
    }
  } catch (const exception& e) {
    cerr << "Error: " << e.what() << endl;
  }

  return 0;
}

//EXCEPTION HANDLING

#include <iostream>
#include <string>
using namespace std;
int main() {
  int age;
  double income;
  string city;
  bool hasFourWheeler;
  try {
    cout << "Enter age: ";
    cin >> age;
    if (age < 18 || age > 55) {
      throw invalid_argument("Invalid age");
    }
  } catch (const exception& e) {
    cerr << "Error: " << e.what() <<endl;
    return 1;
  }

  try {
    cout << "Enter income: ";
    cin >> income;
    if (income < 50000 || income > 100000) {
      throw invalid_argument("Invalid income");
    }
  } catch (const exception& e) {
    cerr << "Error: " << e.what() <<endl;
    return 1;
  }
  try
  {
  cout << "have four wheeler ? ";
    cin >> hasFourWheeler;
   if(!hasFourWheeler) {
      throw invalid_argument("Invalid");
    }
  }
   catch(const exception& e) {
    cerr << "Error: " << e.what() << endl;
    return 1;
  }
  return 0;
}

//FRIEND FUNCTION

#include<iostream>
#include<string>
using namespace std;
class User 
{
private:
  int age;
  double income;
  string city;
  int vehicle;
public:
  class InvalidDataException 
  {
  public:
    InvalidDataException(const string &msg):err_message(msg)
    {}
    string getErrorMessage() 
    const { 
        return err_message;
        }
  private:
    string err_message;
  };
  friend void inputData(User &user);
  int getAge() const { return age; }
  double getIncome() const { return income; }
  string getCity() const { return city; }
  int getVehicle() const { return vehicle; }
};

void inputData(User &user) {
  cout<<"Enter age: ";
  cin>>user.age;
  if(user.age<18||user.age>55) {
    throw User::InvalidDataException("Invalid age");
  }
  cout<<"Enter income: ";
  cin>>user.income;
  if(user.income<50000||user.income>100000) {
    throw User::InvalidDataException("Invalid income");
  }
  cout<<"Enter city: ";
  cin.ignore();
  getline(cin,user.city);
  if(user.city!="Pune"&&user.city!="Mumbai"&&
      user.city!="Bangalore"&&user.city!="Chennai") {
    throw User::InvalidDataException("Invalid city");
  }
  cout<<"Enter vehicle type (1-2-wheeler, 2-4-wheeler): ";
  cin>>user.vehicle;
  if(user.vehicle!=2) {
    throw User::InvalidDataException("Invalid vehicle");
  }
}
int main()
{
  User user;
  try {
    inputData(user);
    cout<<"User data accepted successfully!"<<endl;
  } catch(User::InvalidDataException& e) {
    cerr<< "Error: "<<e.getErrorMessage()<<endl;
  }
  return 0;
}
