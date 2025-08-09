#include<iostream>// ใช้สำหรับรับค่าและแสดงผลทางหน้าจอ
using namespace std ; // เรียกการใช้งาน libary
int main() //ฟังชั่นการทำงานหลัก
{ //  เปิดบล็อกของฟังก์ชัน main
    int length ; //ประกาศตัวแปล
    int widht;  //ประกาศตัวแปล

    cout << "Program Calculate Area Rectangle." << endl; // แสดงข้อความ Program Calculate Area Rectangle.
    // ใส่ค่า length and width
    cout << "Enter Length : " ; //แสดงข้อความให้ใส่ Length
    cin >> length ; //ใส่ค่า length
    cout << "Enter Width : " ; //แสดงข้อความให้ใส่ width
    cin >> widht; //ใส่ค่า width
    // Calculate Area Rectangle
    cout << "Area of Rectangle " ; // แสดงข้อความ Area of Rectangle
    cout << "= " << length * widht << endl; //แสดงข้อความ = และแสดงผลลัพธ์ของ  length * widht 
    return 0; // คืนค่าให้เป็น 0 เมือจบโปรแกรม
} // ปิดบล็อกของฟังก์ชัน main