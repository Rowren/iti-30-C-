#include <iostream>      // ใช้สำหรับรับค่าและแสดงผลทางหน้าจอ
#include <iomanip>       // ใช้สำหรับกำหนดรูปแบบการแสดงผลเลขทศนิยม

using namespace std;     // เรียกการใช้งาน libary

int main() //ฟังชั่นการทำงานหลัก
{ // เปิดบล็อกของฟังก์ชัน main
        cout << "Program Calculate Area Circle.\n"; // แสดงข้อความแนะนำโปรแกรม

    double radius; // ประกาศตัวแปรชนิดทศนิยมสำหรับเก็บรัศมีวงกลม

    cout << "Circle radius (real number) ? "; // ขอให้ผู้ใช้ป้อนรัศมี
    cin >> radius; // รับค่ารัศมีจากผู้ใช้

    double area = 3.1415 * radius * radius; // คำนวณพื้นที่วงกลม (πr^2)
    double circumference = 2 * 3.1415 * radius; // คำนวณเส้นรอบวง (2πr)

    cout << fixed << setprecision(4); // กำหนดให้แสดงผลทศนิยม 4 ตำแหน่ง

    cout << "Area of circle with radius " << radius << " is " << area << endl; // แสดงพื้นที่
    cout << "Circumference is " << circumference << endl; // แสดงเส้นรอบวง

    return 0; // จบโปรแกรม
}// ปิดบล็อกของฟังก์ชัน main