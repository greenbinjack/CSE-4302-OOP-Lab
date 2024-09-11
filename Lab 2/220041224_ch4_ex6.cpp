#include <iostream>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

int main () {
    // input
    char ch;
    cout << "Enter employee type (first letter only) laborer, secretary, manager, accountant, executive, researcher): ";
    cin >> ch;
    // conversion to enum type
    etype post;
    switch (ch) {
    case 'l' :
        post = laborer;
        break;
    case 's' :
        post = secretary;
        break;
    case 'm' :
        post = manager;
        break;
    case 'a' :
        post = accountant;
        break;
    case 'e' :
        post = executive;
        break;
    case 'r' :
        post = researcher;
        break;
    default:
        cout << "Invalid Input!!" << endl;
        exit (0);
    }
    // output
    cout << "Employee type is ";
    switch (post) {
    case laborer :
        cout << "Laborer" << endl;
        break;
    case secretary :
        cout << "Secretary" << endl;
        break;
    case manager :
        cout << "Manager" << endl;
        break;
    case accountant :
        cout << "Accountant" << endl;
        break;
    case executive :
        cout << "Executive" << endl;
        break;
    case researcher :
        cout << "Researcher" << endl;
        break;
    }

    return 0;
}
