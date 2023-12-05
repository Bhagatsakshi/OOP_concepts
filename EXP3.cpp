//USING INHERITANCE

#include<iostream>
using namespace std;
class Result 
{
public:
  Result(int score): score_(score) {}
  virtual bool passed() const { return score_==1; }
  virtual void displayScore() const { cout << score_; }
private:
  int score_;
};
class PassingResult : public Result {
public:
  PassingResult(int score) : Result(score) {}
  bool passed() const override { return true; }
  void displayScore() const override { cout << "Passed"; }
};
class FailingResult : public Result {
public:
  FailingResult(int score) : Result(score) {}
  bool passed() const override { return false; }
  void displayScore() const override { 
cout << "Failed"; 
}
};
int main() {
  int passed=0,failed=0;
  for (int i=0;i<10;++i) {
    cout << "Enter result: ";
    int score;
    cin>>score;
    Result*result;
    if (score==1) {
      passed++;
      result=new PassingResult(score);
    }
   else if(score==2) {
      failed++;
      result=new FailingResult(score);
    }
  else {
     cout << "Invalid score. Please enter 1 or 2."<<endl;
      --i;
      continue;
    }
    cout<<"Result: ";
    result->displayScore();
    cout<<endl;
    delete result;
  }
 cout<<"Passed: "<<passed<<endl;
 cout<<"Failed:  "<<failed<<endl;
  if(passed>8) 
  {
    cout<<"Raise tuition."<<endl;
  }
  return 0;
}

//USING EXCEPTION HANDLING

#include <iostream>
using namespace std;
struct InvalidScoreException:exception 
{
  const char* what() const noexcept override { return "Invalid score. Please enter 1 or 2."; }
};
int main() {
  int passed=0,failed=0;
  for (int i=0;i<10;++i) 
{
    try {
      cout<<"Enter result: ";
      int score;
      cin>>score;
      if(score!=1&&score!=2)
      {
        throw InvalidScoreException();
      }
      passed+=(score==1);
      failed+=(score==2);
     cout<<"Result: ";
      if(score==1)
      {
      cout<<"Passed";
      } 
     else 
      {
        cout<<"Failed";
      }
      cout<<endl;
    } catch(const exception& e) 
    {
      cout<<e.what() <<endl;
      --i;
    }
  }
 cout<<"Passed: "<<passed<<endl;
 cout<<"Failed: "<< failed<<endl;
  if(passed>8)
  {
    cout<<"Raise tuition."<<endl;
  }
  return 0;
}
