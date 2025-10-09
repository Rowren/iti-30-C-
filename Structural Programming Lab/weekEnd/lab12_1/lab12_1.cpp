#include <iostream>
#include "time.h"

using namespace std;

int main() {
    Time t1;
    t1.hour = 20;
    cout << "Hour: " << t1.hour << endl;
    // t1.minute = 30; // ไม่สามารถเข้าถึงได้เนื่องจาก minute เป็น private
    t1.setMinute(50);
    cout << "Minute: " << t1.getMinute() << endl;

    t1.setGrade(75);
    cout << "Grade: " << t1.getGrade() << endl;

    return 0;
}