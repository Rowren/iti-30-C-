#include <iostream>

using namespace std; // ใช้ namespace std เพื่อให้เรียก cout, cin ได้โดยไม่ต้องพิมพ์ std::
void doprocess1(int score, char &grade); // function cal grade


int main()
{
    int score;  // ตัวแปรเก็บคะแนนที่ผู้ใช้ป้อน
    char grade; // ตัวแปรเก็บเกรดเป็นตัวอักษร

    cout << "Enter Your Score :"; // แสดงข้อความให้ผู้ใช้ป้อนคะแนน
    cin >> score; // รับค่าคะแนนจากผู้ใช้

    // ตรวจสอบว่าคะแนนอยู่นอกช่วง 0-100 หรือไม่
    if (score < 0 || score > 100)
    {
        cout << "Invalid score!" << endl; // ถ้าไม่อยู่ในช่วง ให้แจ้งว่า Invalid score
    }
    else
    {
        doprocess1(score, grade); // ถ้าคะแนนถูกต้อง ให้เรียกฟังก์ชัน doprocess1 เพื่อคำนวณเกรด
    }

    return 0; // จบการทำงานของโปรแกรม
}

// function cal grade
void doprocess1(int score, char &grade)
{
    // เงื่อนไขกำหนดเกรดตามช่วงคะแนน
    if (score >= 90 && score <= 100)
    {
        grade = 'A';
    }
    else if (score >= 80) // ไม่ต้องเช็ค <= เพราะถูกกรองแล้ว
    {
        grade = 'B';
    }
    else if (score >= 70)
    {
        grade = 'C';
    }
    else if (score >= 60)
    {
        grade = 'D';
    }
    else // ถ้าคะแนนต่ำกว่า 60
    {
        grade = 'F';
    }
    
    // แสดงคะแนนและเกรดออกทางหน้าจอ
    cout << "Your Score " << score << " Grade " << grade << endl;
}