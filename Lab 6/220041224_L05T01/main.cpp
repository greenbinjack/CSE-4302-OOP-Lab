#include "Student.h"

using namespace std;

int main() {
    srand (time (0));
    Student students[NumOfStudents];

    for (int i = 0; i < 2; i++) {
        cout << "Editing information for student " << i + 1 << endl;
        students[i].EditInformationByKeyboard();
    }

    for (int i = 0; i < NumOfStudents; i++) {
        students[i].generateID();
        students[i].generateInformationRandom();
    }

    ShowAllAlphabetically(students);

    return 0;
}
