#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>

using namespace std;

const int NumOfStudents = 100;

struct Course {
    double quizMark[4];
    double mid, finale, attendance;
};

class Student {
private:
    string name;
    string dept;
    string program;
    string section;
    int admission_year;
    string address;
    double gpa;
    string ID;
    static int AvailableIds[NumOfStudents];

    int random_value (int mn, int mx) {
        return rand() % (mx - mn + 1) + mn;
    }

public:
    Student();

    string Getname();
    void Setname(string val);
    string Getdept();
    void Setdept(string val);
    string Getprogram();
    void Setprogram(string val);
    string getID() const;
    void setID(string val);
    string Getsection();
    void Setsection(string val);
    int Getadmission_year();
    void Setadmission_year(int val);
    string Getaddress();
    void Setaddress(string val);
    double Getgpa();
    void Setgpa(double val);

    void generateID();
    double calculateGPA(Course course);
    void EditInformationByKeyboard();
    void generateInformationRandom();
};

void ShowAllAlphabetically(Student ar[]);

#endif // STUDENT_H
