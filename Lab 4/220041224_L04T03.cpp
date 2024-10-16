#include <bits/stdc++.h>
using namespace std;

class Employee {
private:
    string EmpName;
    int ID, Age;
    float Salary;
    string getStatus () {
        if (Age <= 25) {
            return (Salary <= 20000) ? "Low" : "Moderate";
        } else {
            if (Salary <= 21000) return "Low";
            else if (Salary <= 60000) return "Moderate";
            else return "High";
        }
    }
public:
    Employee (string _name, int _id, int _age, float _salary) : EmpName (_name), ID (_id), Age (_age), Salary (_salary) {}
    string getEmpName () {
        return EmpName;
    }
    string getEmpName () const {
        return EmpName;
    }
    int getId () {
        return ID;
    }
    int getAge () {
        return Age;
    }
    float getSalary () {
        return Salary;
    }
    void FeedInfo () {
        EmpName = "saom bin khaled";
        ID = 220041224;
        Age = 20;
        Salary = 900000.0;
    }
    void showInfo () {
        cout << "Name: " << getEmpName () << endl;
        cout << "ID: " << getId () << endl;
        cout << "Age: " << getAge () << endl;
        cout << "Salary: " << getSalary () << endl;
        cout << "Status: " << getStatus () << endl;
    }
};

int main () {
    Employee e ("hsgfbjhs", 3432, 23, 37645.3958);
    e.showInfo ();
    e.FeedInfo ();
    e.showInfo ();

    return 0;
}
