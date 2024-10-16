#include "Student.h"

int Student::AvailableIds[NumOfStudents] = {0};

Student::Student() : name("John Doe"), dept("CSE"), program("CSE"), section("2"), admission_year(2022), gpa(0.0) {}

string Student::Getname() { return name; }
void Student::Setname(string val) { name = val; }
string Student::Getdept() { return dept; }
void Student::Setdept(string val) { dept = val; }
string Student::Getprogram() { return program; }
void Student::Setprogram(string val) { program = val; }
string Student::getID() const { return ID; }
void Student::setID(string val) { ID = val; }
string Student::Getsection() { return section; }
void Student::Setsection(string val) { section = val; }
int Student::Getadmission_year() { return admission_year; }
void Student::Setadmission_year(int val) { admission_year = val; }
string Student::Getaddress() { return address; }
void Student::Setaddress(string val) { address = val; }
double Student::Getgpa() { return gpa; }
void Student::Setgpa(double val) { gpa = val; }

void Student::generateID() {
    string year = to_string(Getadmission_year() % 100);
    string dept_and_program = "";

    if (Getdept() == "CSE") {
        dept_and_program = (program == "CSE") ? "41" : "42";
    } else if (Getdept() == "EEE") {
        dept_and_program = "21";
    } else if (Getdept() == "ME") {
        dept_and_program = "11";
    } else if (Getdept() == "CEE") {
        dept_and_program = "51";
    } else if (Getdept() == "BTM") {
        dept_and_program = "61";
    }

    int lastTwoDigit;
    do {
        lastTwoDigit = random_value(0, 99);
    } while (AvailableIds[lastTwoDigit]);
    AvailableIds[lastTwoDigit] = 1;

    ID = year + "00" + dept_and_program + Getsection() + (lastTwoDigit < 10 ? "0" : "") + to_string(lastTwoDigit);
}

double Student::calculateGPA(Course course) {
    double totalQuiz = (course.quizMark[0] + course.quizMark[1] + course.quizMark[2] + course.quizMark[3]) - min({course.quizMark[0], course.quizMark[1], course.quizMark[2], course.quizMark[3]});
    double total = (totalQuiz + course.mid + course.finale + course.attendance) / 100.0 * 3.0;
    return total;
}

void Student::EditInformationByKeyboard() {
    string name, dept, program, section, address;
    int admissionYear;

    cout << "Enter student name: ";
    getline(cin, name);
    Setname(name);

    cout << "Enter department: ";
    getline(cin, dept);
    Setdept(dept);

    cout << "Enter program: ";
    getline(cin, program);
    Setprogram(program);

    cout << "Enter section: ";
    getline(cin, section);
    Setsection(section);

    cout << "Enter admission year (2020-2023): ";
    cin >> admissionYear;
    Setadmission_year(admissionYear);

    cout << "Enter address: ";
    cin.ignore();
    getline(cin, address);
    Setaddress(address);
}

void Student::generateInformationRandom() {
    Course new_course;
    new_course.quizMark[0] = random_value(0, 15);
    new_course.quizMark[1] = random_value(0, 15);
    new_course.quizMark[2] = random_value(0, 15);
    new_course.quizMark[3] = random_value(0, 15);
    new_course.mid = random_value(0, 75);
    new_course.finale = random_value(0, 150);
    new_course.attendance = random_value(0, 10);

    Setgpa(calculateGPA(new_course));
}

void ShowAllAlphabetically (Student students[]) {
    sort(students, students + NumOfStudents, [](const Student& a, const Student& b) {
        return a.getID() < b.getID();
    });

    for (int i = 0; i < NumOfStudents; i++) {
        cout << students[i].Getname() << ' ' << students[i].getID() << ' ' << students[i].Getgpa() << endl;
    }
}
