#include <iostream>
#include "student.h" // เรียกใช้คลาส Student

using namespace std; 
void showMenu();


int main() {
    Student student;
    int choice = 0;
    
    do {
        showMenu();
        cin >> choice;
        cout << "========================\n";

        switch (choice) {
            case 1:
                cout << "enter student info\n";
                cout << "========================\n";
                student.enterInfo();
                break;
            case 2:
                student.displayInfo();
                cout << "========================\n";
                break;
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                // เคลียร์ input buffer หากผู้ใช้ใส่ข้อมูลผิดพลาด
                cin.clear();
                cin.ignore(10000, '\n');
                break;
        }

    } while (choice != 3);

    return 0;
}

void showMenu() {
    cout << "========================\n";
    cout << "menu\n";
    cout << "========================\n";
    cout << "1: enter student info\n";
    cout << "2: display student info\n";
    cout << "3: exit\n";
    cout << "enter choice : ";
}