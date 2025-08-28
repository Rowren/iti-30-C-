// 6806021411325 นายธนธรณ์ บุษเกตุ 14/8/2568 11:22

#include <iostream>  // ใช้สำหรับการรับค่า (cin) และแสดงผล (cout)
#include <string>    // ใช้สำหรับตัวแปรชนิด string
#include <iomanip>   // ใช้สำหรับจัดรูปแบบการแสดงผล เช่น setw()
using namespace std; // ทำให้สามารถเรียกใช้ชื่อคลาส/ฟังก์ชันมาตรฐานได้โดยไม่ต้องใส่ std::

void Calendar();      // ประกาศฟังก์ชัน Calendar (ยังไม่เขียนเนื้อหา)
void Calgrade();      // ประกาศฟังก์ชัน Calgrade (ยังไม่เขียนเนื้อหา)
void power_number();  // ประกาศฟังก์ชัน power_number (ยังไม่เขียนเนื้อหา)

int main()  // จุดเริ่มต้นของโปรแกรม
{
    char Choice;  // ตัวแปรเก็บค่าที่ผู้ใช้เลือกเมนู

    for (;;)   // ลูปแบบไม่รู้จบ (จะหยุดเมื่อเจอ break)
    {
        cout << "====================" << endl;   // แสดงเส้นขอบ
        cout << "menu" << endl;                  // แสดงข้อความ "menu"
        cout << "====================" << endl;   // แสดงเส้นขอบ
        cout << "1 Calendar         [1/9/c]" << endl;  // แสดงเมนู 1
        cout << "2 Grade            [2/G/g]" << endl;  // แสดงเมนู 2
        cout << "3 Power Number     [3/S/N]" << endl;  // แสดงเมนู 3
        cout << "0 Exit             [0/E/X/I/T]" << endl; // แสดงเมนูออก
        cout << "Select Menu : ";  // ให้ผู้ใช้เลือกเมนู
        cin >> Choice;             // รับค่าที่ผู้ใช้ป้อน

        if (Choice == '1' || Choice == '9' || Choice == 'c')  // ถ้าผู้ใช้เลือก 1 หรือ 9 หรือ c
        {
            Calendar();  // เรียกใช้ฟังก์ชัน Calendar
            return 0;    // จบโปรแกรม
        }
        else if (Choice == '2' || Choice == 'G' || Choice == 'g') // ถ้าเลือก 2, G หรือ g
        {
            Calgrade();  // เรียกใช้ฟังก์ชัน Calgrade
            return 0;    // จบโปรแกรม
        }
        else if (Choice == '3' || Choice == 'S' || Choice == 'N') // ถ้าเลือก 3, S หรือ N
        {
            power_number();  // เรียกใช้ฟังก์ชัน power_number
            return 0;        // จบโปรแกรม
        }
        else if (Choice == '0' || Choice == 'E' || Choice == 'X' || Choice == 'I' || Choice == 'T') // ถ้าเลือกตัวใดตัวหนึ่ง
        {
            cout << "--------------------" << endl;  // แสดงเส้น
            cout << "Exit Program \n";              // แสดงข้อความออกจากโปรแกรม
            cout << "--------------------" << endl;  // แสดงเส้น
            break;  // ออกจากลูป for (;;)
        }
        else
        {
            cout << "Please Menu Again \n\n";  // ถ้าป้อนผิด แสดงข้อความให้เลือกใหม่
        }
    }
    return 0;  // คืนค่าจบการทำงาน
}

void Calendar()  // ฟังก์ชันแสดงปฏิทิน
{
    cout << "Calendar AUGUST 2568\n";        // หัวข้อปฏิทิน
    cout << "SU  MO  TU  WE  TH  FR  SA\n"; // แสดงชื่อวันทั้งสัปดาห์

    for (int i = 0; i < 6; i++) {      // วนลูป 6 แถว (6 สัปดาห์)
        for (int j = 1; j <= 7; j++) { // วนลูป 7 คอลัมน์ (7 วันใน 1 สัปดาห์)
            int num = i * 7 + j - 5;   // สูตรหาหมายเลขวัน เริ่มต้นจากวันอาทิตย์
            if (num < 1 || num > 31)   // ถ้าวันน้อยกว่า 1 หรือมากกว่า 31
                cout << left << setw(4) << "X"; // แสดง X แทน
            else
                cout << left << setw(4) << num; // ถ้าวันถูกต้อง แสดงตัวเลข
        }
        cout << endl; // ขึ้นบรรทัดใหม่เมื่อครบ 7 วัน
    }
}

void Calgrade()  // ฟังก์ชันคำนวณเกรด
{
    int score;    // เก็บคะแนน
    string name;  // เก็บชื่อ
    char grade;   // เก็บเกรดตัวอักษร

    cout << "Enter Name : "; // รับชื่อ
    cin >> name;             
    cout << "Enter Score : "; // รับคะแนน
    cin >> score;

    if (score < 0 || score > 100)  // ตรวจสอบว่าคะแนนถูกต้องหรือไม่
    {
        cout << "Invalid score!" << endl; // ถ้าผิด แสดงข้อความเตือน
        return;                           // จบฟังก์ชัน
    }

    if (score >= 90 && score <= 100)   // ถ้าคะแนน 90-100
    {
        grade = 'S'; // ได้เกรด S
    }
    else if (score >= 80) // ถ้าคะแนน 80-89
    {
        grade = 'A';
    }
    else if (score >= 70) // ถ้าคะแนน 70-79
    {
        grade = 'B';
    }
    else if (score >= 60) // ถ้าคะแนน 60-69
    {
        grade = 'C';
    }
    else if (score >= 35) // ถ้าคะแนน 35-59
    {
        grade = 'D';
    }
    else                  // ถ้าน้อยกว่า 35
    {
        grade = 'F';
    }

    cout << name << " Score " << score << " Grade " << grade << endl; // แสดงผลชื่อ คะแนน และเกรด
}

void power_number()  // ฟังก์ชันหาค่ากำลังของเลข
{
    int num;  // ตัวเลขฐาน (2-12)

    // ลูปรับค่าจนกว่าจะกรอกเลขในช่วง 2-12
    do {
        cout << "Enter Power Number (2-12) : "; // ให้กรอกเลข
        cin >> num;

        if (num < 2 || num > 12) // ถ้ากรอกผิด
            cout << "Try Again" << endl; // แสดงข้อความให้ลองใหม่

    } while (num < 2 || num > 12); // เงื่อนไขการวน

    // วนลูปยกกำลัง 1 ถึง 10
    for (int i = 1; i <= 10; i++)
    {
        long long result = 1;  // ตัวแปรเก็บผลลัพธ์ (ใช้ long long เผื่อค่ามีขนาดใหญ่)
        for (int j = 0; j < i; j++) // คูณตัวเองตามจำนวนรอบ
        {
            result *= num; // คูณค่าฐานทีละรอบ
        }
        cout << num << "^" << i << "\t= " << result << endl; // แสดงผล เช่น 2^3 = 8
    }
}
