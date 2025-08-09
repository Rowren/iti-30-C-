#include <iostream> // นำเข้าไลบรารี iostream เพื่อใช้ฟังก์ชันการป้อนและแสดงผลข้อมูล
using namespace std; // ใช้เพื่อไม่ต้องเขียน std:: ทุกครั้ง

void doprocess1(long Number); // ประกาศฟังก์ชันหาค่า factorial ด้วย while แบบนับเพิ่ม (++)
void doprocess2(long Number); // ประกาศฟังก์ชันหาค่า factorial ด้วย while แบบนับลด (--)
void doprocess3(long Number); // ประกาศฟังก์ชันหาค่า factorial ด้วย for แบบนับเพิ่ม (++)
void doprocess4(long Number); // ประกาศฟังก์ชันหาค่า factorial ด้วย for แบบนับลด (--)

int main()
{
    int Number;
    bool Flag = true; // ใช้ควบคุมการวนลูปตรวจสอบค่าอินพุต

    // วนลูปเพื่อรับค่าตัวเลขจากผู้ใช้ (0-20)
    do
    {
        cout << "\nInput number Factorial (0-20)? : ";  // แสดงข้อความให้ผู้ใช้ป้อนตัวเลข
        cin >> Number;  // รับค่าจากผู้ใช้
        if ((Number >= 0) && (Number <= 20))  // ตรวจสอบว่าค่าอยู่ในช่วงที่กำหนดหรือไม่
            Flag = false; // ถ้าอยู่ในช่วงที่ถูกต้องให้หยุดลูป
        else
            cout << "Number Value over limit.\n"; // แจ้งเตือนเมื่อค่าเกินขอบเขต
    } while (Flag); // วนซ้ำจนกว่าจะได้ค่าที่ถูกต้อง

    // เรียกใช้ฟังก์ชันทั้ง 4 แบบ
    cout << "\n--- doprocess1 (while ++) ---\n";
    doprocess1(Number);

    cout << "\n--- doprocess2 (while --) ---\n";
    doprocess2(Number);

    cout << "\n--- doprocess3 (for ++) ---\n";
    doprocess3(Number);

    cout << "\n--- doprocess4 (for --) ---\n";
    doprocess4(Number);

    return 0;
}

// function while ++ 
void doprocess1(long Number)
{
    long long Fac = 1L;
    int Count = 1; 

    if (Number > 0) {
        cout << Count; 
        Fac *= Count;
        Count++;
    }

    while (Count <= Number) 
    {
        cout << " X " << Count;
        Fac *= Count;
        Count++;
    }
    cout << "\nFactorial of " << Number << " = " << Fac << endl;
}

// function while -- 
void doprocess2(long Number)
{
    long long Fac = 1L;
    int Count = Number;

    if (Number > 0) {
        cout << Count;
        Fac *= Count;
        Count--;
    }

    while (Count >= 1)
    {
        cout << " X " << Count;
        Fac *= Count;
        Count--;
    }
    cout << "\nFactorial of " << Number << " = " << Fac << endl;
}

// function for ++ 
void doprocess3(long Number)
{
    long long Fac = 1L;

    if (Number > 0) {
        cout << 1;
        Fac *= 1;
    }

    for (int Count = 2; Count <= Number; Count++)
    {
        cout << " X " << Count;
        Fac *= Count;
    }
    cout << "\nFactorial of " << Number << " = " << Fac << endl;
}

// function for -- 
void doprocess4(long Number)
{
    long long Fac = 1L;

    if (Number > 0) {
        cout << Number;
        Fac *= Number;
    }

    for (int Count = Number - 1; Count >= 1; Count--)
    {
        cout << " X " << Count;
        Fac *= Count;
    }
    cout << "\nFactorial of " << Number << " = " << Fac << endl;
}
