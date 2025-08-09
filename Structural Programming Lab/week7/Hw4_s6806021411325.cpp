#include <iostream>
#include <string>

using namespace std;

void doprocess1(int Number, char character);// Function for 

int main()
{
    int Number;      // เก็บจำนวนบรรทัดที่จะพิมพ์
    char character;  // เก็บตัวอักษรที่จะใช้พิมพ์

    cout << "Input number line : "; // แสดงข้อความให้ผู้ใช้ป้อนตัวเลข
    cin >> Number;                  // รับค่าจากผู้ใช้

    cout << "Input Character : "; // แสดงข้อความให้ผู้ใช้ป้อนตัวอักษร
    cin >> character;             // รับค่าจากผู้ใช้

    if ((Number >= 0) && (Number <= 20)) // ตรวจสอบว่าค่าอยู่ในช่วง 0 ถึง 20 หรือไม่
    {
        doprocess1(Number, character);  //เรียกใช้ Function for 
    }
    else
    {
        cout << "Number line over limit.\n"; // แจ้งเตือนเมื่อค่าเกินขอบเขต
    }

    return 0;
}

// Function for 
void doprocess1(int Number, char character)
{
     string sum = ""; // เก็บข้อความสะสม เริ่มต้นเป็นค่าว่าง
     
    for (int i = 1; i <= Number; i++) // วนลูปตามจำนวนบรรทัดที่กำหนด
    {
        sum += character;    // เพิ่มตัวอักษรเข้าใน string sum
        cout << sum << endl; // แสดงข้อความสะสม
    }
}
