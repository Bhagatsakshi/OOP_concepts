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


//USING VIRTUAL FUNCTION 

#include<iostream>
using namespace std;
class ExamResultAnalyzer
{
public:
    virtual void enterTestResult(int result)=0;
    virtual void displaySummary()=0;
};

class InteractiveExamResultAnalyzer:public ExamResultAnalyzer 
{
private:
    int passedCount=0;
    int failedCount=0;

public:
    void enterTestResult(int result) override 
   {
        if (result==1) 
        {
            passedCount++;
        } else if (result==2) 
        {
            failedCount++;
        } else {
            cout<<"Invalid input: Result must be 1 (passed) or 2 (failed)." <<endl;
        }
    }
    void displaySummary() override {
        cout<<"Summary of Exam Results:"<<endl;
        cout<<"Number of students who passed: "<<passedCount<<endl;
        cout<<"Number of students who failed: "<<failedCount<<endl;
        if(passedCount>8)
        {
            cout<<"Raise tuition."<<endl;
        }
    }
};
int main() {
    InteractiveExamResultAnalyzer analyzer;
    for (int i=0;i<10;i++) {
        int result;
        cout<<"Enter result (1 for passed, 2 for failed): ";
        cin>>result;
        analyzer.enterTestResult(result);
    }
    analyzer.displaySummary();
    return 0;
}

//USING FRIEND FUNCTION 

#include <iostream>
using namespace std;
class ExamResultAnalyzer 
{
private:
    int passCount=0;
    int failCount=0;

public:
    void enterTestResult(int result) 
{
        if (result==1) {
            passCount++;
        } else if (result==2) {
            failCount++;
        } else {
            cout<<"Invalid input: Result must be 1 (passed) or 2 (failed)."<<endl;
        }
    }

    friend void displaySummary(const ExamResultAnalyzer& analyzer);
};

void displaySummary(const ExamResultAnalyzer& analyzer)
{
    cout<<"Summary of Exam Results:" <<endl;
    cout<<"Number of students who passed: "<<analyzer.passCount<<endl;
    cout<<"Number of students who failed: "<<analyzer.failCount<<endl;

    if (analyzer.passCount>8)
    {
        cout<<"Raise tuition."<<endl;
    }
}

int main() {
    ExamResultAnalyzer analyzer;
    for (int i=0;i<10;i++) 
    {
        int result;
        cout<<"Enter result (1 for passed, 2 for failed): ";
        cin>>result;
        analyzer.enterTestResult(result);
    }
    displaySummary(analyzer);
    return 0;
}
