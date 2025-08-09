#include <iostream>
#include <string>

using namespace std;

int main() // ฟังก์ชันหลักของโปรแกรม
{
    cout << "Please enter a simple expression \n "; // ขอให้ผู้ใช้ป้อนนิพจน์ทางคณิตศาสตร์
    cout << "( number operator number )";           // แสดงข้อความตัวอย่างรูปแบบนิพจน์ที่ถูกต้อง

    int LeftOperand, RightOperand; // ประกาศตัวแปรสำหรับเก็บตัวเลขที่ป้อนเข้ามา
    char Operator;                 // ประกาศตัวแปรสำหรับเก็บเครื่องหมายทางคณิตศาสตร์

    cin >> LeftOperand >> Operator >> RightOperand; // รับค่าตัวเลขและเครื่องหมายจากผู้ใช้

    int Result; // ประกาศตัวแปรสำหรับเก็บผลลัพธ์ของการคำนวณ

    if (operter == '+')
        Result = LeftOperand + RightOperand; // ถ้าเครื่องหมายเป็นบวก ให้คำนวณผลลัพธ์โดยการบวก
    else if (Operator == '-')
        Result = LeftOperand - RightOperand; // ถ้าเครื่องหมายเป็นลบ ให้คำนวณผลลัพธ์โดยการลบ
    else if (Operator == '*')
        Result = LeftOperand * RightOperand; // ถ้าเครื่องหมายเป็นคูณ ให้คำนวณผลลัพธ์โดยการคูณ
    else if (Operator == '/')
        Result = LeftOperand / RightOperand; // ถ้าเครื่องหมายเป็นหาร ให้คำนวณผลลัพธ์โดยการหาร
    else{                                                 
      // if(Operator != '+' && Operator != '-' && Operator != '*' && Operator != '/') {
        cout << "is unrecognized operation." << endl; // แสดงข้อความผิดพลาดสำหรับเครื่องหมายที่ไม่ถูกต้อง
        return 1;                                     // ออกจากโปรแกรมด้วยรหัสผิดพลาด
    }

    /*
    switch (Operator)  // ใช้ switch-case เพื่อตรวจสอบเครื่องหมายที่ผู้ใช้ป้อน
    {                                               // ใช้ switch-case เพื่อตรวจสอบเครื่องหมายที่ผู้ใช้ป้อน
    case '+':                                       // ถ้าเครื่องหมายเป็นบวก
        Result = LeftOperand + RightOperand;        // คำนวณผลลัพธ์โดยการบวก
        break;                                      // ออกจาก switch-case
    case '-':                                       // ถ้าเครื่องหมายเป็นลบ
        Result = LeftOperand - RightOperand;        // คำนวณผลลัพธ์โดยการลบ
        break;                                      // ออกจาก switch-case
    case '*':                                       // ถ้าเครื่องหมายเป็นคูณ
        Result = LeftOperand * RightOperand;        // คำนวณผลลัพธ์โดยการคูณ
        break;                                      // ออกจาก switch-case
    case '/':                                       // ถ้าเครื่องหมายเป็นหาร
        Result = LeftOperand / RightOperand;        // คำนวณผลลัพธ์โดยการหาร
        break;                                      // ออกจาก switch-case
    default:                                        // ถ้าเครื่องหมายไม่ถูกต้อง
        cout << "is unrecognized operation." << endl; // แสดงข้อความผิดพลาดสำหรับเครื่องหมายที่ไม่ถูกต้อง
        return 1;                                   // ออกจากโปรแกรมด้วยรหัสผิดพลาด
    }
        */

    cout << LeftOperand << " " << Operator << " "
         << RightOperand << " = " << Result << endl; // แสดงผลลัพธ์ของการคำนวณ
    return 0;
}
