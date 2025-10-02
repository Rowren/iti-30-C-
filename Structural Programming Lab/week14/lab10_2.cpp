#include <iostream> // สำหรับการรับ-ส่งข้อมูลมาตรฐาน
#include <cctype>   // สำหรับฟังก์ชัน tolower
#include <fstream>  // สำหรับการจัดการไฟล์
#include <string>   // สำหรับการใช้ string
#include <iomanip>  // สำหรับการจัดรูปแบบการแสดงผล

using namespace std;

int Menu(); // ฟังก์ชันแสดงเมนูและรับตัวเลือกเมนู

void GetandWrite(ofstream &OutFile);                         // ฟังก์ชันรับข้อมูลและเขียนลงไฟล์
void ReadandDisplay(ifstream &InFile);                       // ฟังก์ชันอ่านข้อมูลจากไฟล์และแสดงผล
void FindandDisplay(ifstream &Infile, int findNumber);       // ฟังก์ชันค้นหานักเรียนตามคะแนนและแสดงผล
void FindandDisplayScore(ifstream &Infile, string FindName); // ฟังก์ชันค้นหานักเรียนตามชื่อและแสดงผล

string CalGrade(int score); // ฟังก์ชันคำนวณเกรดจากคะแนน

int main() // ฟังก์ชันหลักของโปรแกรม
{
    string Filename, FindName; // ตัวแปรเก็บชื่อไฟล์ และชื่อนักเรียนที่ต้องการค้นหา
    int findNumber;            // ตัวแปรเก็บคะแนนที่ต้องการค้นหา
    ifstream Infile;           // ตัวแปรสำหรับอ่านไฟล์
    ofstream Outfile;          // ตัวแปรสำหรับเขียนไฟล์

    int Choose;

    for (;;) // ใช้ลูป for เพื่อแสดงเมนูซ้ำๆ จนกว่าจะเลือกออก
    {
        Choose = Menu(); // เรียกเมนูใหม่ทุกครั้ง

        switch (Choose)
        {
        case 1: // กรณีเลือกเมนู 1 (บันทึกข้อมูล)
            cout << "Enter file name : ";
            cin >> Filename; // รับชื่อไฟล์
            cout << endl;
            Outfile.open(Filename.c_str(), ios_base::app); // เปิดไฟล์ในโหมดเพิ่มข้อมูล
            cout << "Now open file "
                 << Filename << " for write.\n";               // แจ้งว่าเปิดไฟล์สำเร็จ
            GetandWrite(Outfile);                              // เรียกฟังก์ชันรับข้อมูลและเขียนลงไฟล์
            cout << "Now close file " << Filename << "\n\n\n"; // แจ้งว่าปิดไฟล์สำเร็จ
            Outfile.close();                                   // ปิดไฟล์
            break;

        case 2: // กรณีเลือกเมนู 2 (รายงานข้อมูล)
            cout << "Enter file name : ";
            cin >> Filename;                                          // รับชื่อไฟล์
            Infile.open(Filename);                                    // เปิดไฟล์ในโหมดอ่าน
            cout << "Now open file " << Filename << " for read.\n\n"; // แจ้งว่าเปิดไฟล์สำเร็จ
            ReadandDisplay(Infile);                                   // เรียกฟังก์ชันอ่านข้อมูลจากไฟล์และแสดงผล
            cout << "Now close file " << Filename << "\n\n\n";        // แจ้งว่าปิดไฟล์สำเร็จ
            Infile.close();                                           // ปิดไฟล์
            break;

        case 3: // กรณีเลือกเมนู 3 (ค้นหาตามคะแนน)
            cout << "Enter file name : ";
            cin >> Filename;
            Infile.open(Filename);                                    // เปิดไฟล์ในโหมดอ่าน
            cout << "Now open file " << Filename << " for read.\n\n"; // แจ้งว่าเปิดไฟล์สำเร็จ
            ReadandDisplay(Infile);                                   // เรียกฟังก์ชันอ่านข้อมูลจากไฟล์และแสดงผล

            cout << "Enter Score to Searching : ";
            cin >> findNumber;                                 // รับคะแนนที่ต้องการค้นหา
            FindandDisplay(Infile, findNumber);                // เรียกฟังก์ชันค้นหานักเรียนตามคะแนนและแสดงผล
            cout << "Now close file " << Filename << "\n\n\n"; // แจ้งว่าปิดไฟล์สำเร็จ
            Infile.close();                                    // ปิดไฟล์
            break;

        case 4:
            cout << "Enter file name : ";
            cin >> Filename; // รับชื่อไฟล์
            cout << endl;
            Infile.open(Filename);                                  // เปิดไฟล์ในโหมดอ่าน
            cout << "Now open file " << Filename << " for read.\n"; // แจ้งว่าเปิดไฟล์สำเร็จ
            ReadandDisplay(Infile);                                 // เรียกฟังก์ชันอ่านข้อมูลจากไฟล์และแสดงผล

            cout << "Enter name to Searching : ";
            cin >> FindName; // รับชื่อนักเรียนที่ต้องการค้นหา
            for (char &n : FindName)
            {
                n = tolower(n); // ใช้ tolower สำหรับ char
            }
            FindandDisplayScore(Infile, FindName);             // เรียกฟังก์ชันค้นหานักเรียนตามชื่อและแสดงผล
            cout << "Now close file " << Filename << "\n\n\n"; // แจ้งว่าปิดไฟล์สำเร็จ
            Infile.close();                                    // ปิดไฟล์
            break;

        case 0: // กรณีเลือกเมนู 0 (ออกจากโปรแกรม)
            cout << "Exit program.\n";
            return 0; // ออกจาก loop และจบโปรแกรม

        default:
            cout << "Invalid input try again. \n"; // กรณีเลือกเมนูไม่ถูกต้อง
        }
    }
}

int Menu() // ฟังก์ชันแสดงเมนูและรับตัวเลือกเมนู
{
    int Choose; // ตัวแปรเก็บตัวเลือกเมนู
    // แสดงเมนู
    cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl; // แสดงเส้นคั่น
    cout << setw(20) << right << ": Main Menu :" << endl;            // แสดงหัวข้อเมนู
    cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl; // แสดงเส้นคั่น
    cout << ": 1. record data\n";                                    // 1. บันทึกข้อมูล
    cout << ": 2. report data\n";                                    // 2. รายงานข้อมูล
    cout << ": 3. find by score\n";                                  // 3. ค้นหาตามคะแนน
    cout << ": 4. find by name\n";                                   // 4. ค้นหาตามชื่อ
    cout << ": 0. exit program\n";                                   // 0. ออกจากโปรแกรม
    cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl; // แสดงเส้นคั่น
    cout << "Select your choice : ";                                 // แสดงข้อความให้ผู้ใช้เลือกเมนู
    cin >> Choose;                                                   // รับตัวเลือกเมนู
    return Choose;                                                   // ส่งค่าตัวเลือกเมนูกลับไปยัง main
}

void GetandWrite(ofstream &OutFile) // ฟังก์ชันรับข้อมูลและเขียนลงไฟล์
{
    string Id, Name, Surname;
    int Score;

    for (int n = 1; n <= 3; n++) // รับข้อมูลนักเรียน 3 คน
    {
        cout << "\nStudent No : " << n << endl;
        cout << "Enter Id: ";
        cin >> Id; // รับรหัสนักเรียน
        cout << "Enter Name : ";
        cin >> Name; // รับชื่อนักเรียน
        cout << "Enter Surname : ";
        cin >> Surname; // รับนามสกุลนักเรียน
        cout << "Enter Score : ";
        cin >> Score; // รับคะแนนนักเรียน

        OutFile << Id << " "
                << Name << " "
                << Surname << " "
                << Score << endl; // เขียนข้อมูลลงไฟล์
    }
}

void ReadandDisplay(ifstream &InFile) // ฟังก์ชันอ่านข้อมูลจากไฟล์และแสดงผล
{
    string Id, Name, Surname;
    int Score;
    cout << setfill('=') << setw(60) << "=" << setfill(' ') << endl; // แสดงเส้นคั่น
    cout << right
         << setw(10) << "ID"
         << setw(10) << "Name"
         << setw(10) << "Surname"
         << setw(19) << "Score Grade"
         << endl; // แสดงหัวตาราง

    for (;;) // ใช้ลูป for เพื่ออ่านข้อมูลจากไฟล์จนกว่าจะถึงจุดสิ้นสุดไฟล์
    {
        InFile >> Id >> Name >> Surname >> Score; // อ่านข้อมูลจากไฟล์
        if (InFile.eof() == true)
            break; // เช็คสถานะ eof ว่าถึงจุดสิ้นสุดไฟล์หรือยัง

        cout << right
             << setw(10) << Id
             << setw(10) << Name
             << setw(10) << Surname
             << setw(10) << Score
             << setw(5) << CalGrade(Score)
             << endl; // แสดงข้อมูลนักเรียนพร้อมเกรด
    }
    cout << setfill('=') << setw(60) << "=" << setfill(' ') << endl; // แสดงเส้นคั่น
    cout << endl;
}

void FindandDisplay(ifstream &Infile, int findNumber) // ฟังก์ชันค้นหานักเรียนตามคะแนนและแสดงผล
{
    string Id, Name, Surname;
    int Score;
    int counter = 0;

    Infile.clear();            // เคลียร์สถานะ EOF
    Infile.seekg(0, ios::beg); // กลับไปอ่านตั้งแต่ต้นไฟล์

    while (Infile >> Id >> Name >> Surname >> Score) // อ่านแบบ while-loop
    {
        if (Score == findNumber) // ถ้าคะแนนตรงกับที่ค้นหา
        {
            if (counter == 0) // ถ้าเป็นการพบคะแนนครั้งแรก
            {
                cout << "Found this score : " << Score << " in the records\n"; // แจ้งว่าพบคะแนน
                cout << "-------------------------------------\n";
            }
            cout << "ID = " << Id
                 << " | Name = " << Name << " " << Surname
                 << " | Score = " << Score << '\n'; // แสดงข้อมูลนักเรียนที่พบ
            counter++;                              // เพิ่มตัวนับจำนวนครั้งที่พบ
        }
    }

    if (counter == 0) // ถ้าไม่พบคะแนนที่ค้นหาเลย
    {
        cout << "Nobody got the score \"" << findNumber << "\" in the records.\n"; // แจ้งว่าไม่พบคะแนน
    }
    else
    {
        cout << "-------------------------------------\n";
        cout << "Total = " << counter << " records\n"; // แสดงจำนวนครั้งที่พบคะแนน
    }
    cout << endl;
}

void FindandDisplayScore(ifstream &Infile, string FindName) // ฟังก์ชันค้นหานักเรียนตามชื่อและแสดงผล
{
    string Id, Name, Surname;
    int Score;

    int counter = 0;
    Infile.clear();                 // เคลียร์สถานะ eof
    Infile.seekg(0, ios_base::beg); // เลื่อนตำแหน่งไปจุดเริ่มต้นของไฟล์

    for (;;)
    {
        Infile >> Id >> Name >> Surname >> Score; // อ่านข้อมูลจากไฟล์
        if (Infile.eof() == true)
            break; // เช็คสถานะ eof ว่าถึงจุดสิ้นสุดไฟล์หรือยัง
        for (char &n : FindName)
        {
            n = towlower(n);
        } // แปลงชื่อที่ต้องการค้นหาเป็นตัวพิมพ์เล็ก
        for (char &n : Name)
        {
            n = towlower(n);
        } // แปลงชื่อในไฟล์เป็นตัวพิมพ์เล็ก
        if (Name == FindName) // ถ้าชื่อในไฟล์ตรงกับชื่อที่ค้นหา
        {
            if (counter == 0) // ถ้าเป็นการพบชื่อครั้งแรก
            {
                cout << "Found this score : " << Score << " in the records\n";
                cout << "-------------------------------------\n";
            } // แจ้งว่าพบชื่อ
            cout << "ID = " << Id
                 << " | Name = " << Name << " " << Surname
                 << " | Score = " << Score << '\n'; // แสดงข้อมูลนักเรียนที่พบ
            counter++;                              // เพิ่มตัวนับจำนวนครั้งที่พบ
        }
    }
    if (counter == 0) // ถ้าไม่พบชื่อที่ค้นหาเลย
    {
        cout << "Nobody got the score \"" << FindName << "\" in the records.\n"; // แจ้งว่าไม่พบชื่อ
    }
    else
    {
        cout << "-------------------------------------\n";
        cout << "Total = " << counter << " records\n"; // แสดงจำนวนครั้งที่พบชื่อ
    }
    cout << endl;
}

string CalGrade(int Score) // ฟังก์ชันคำนวณเกรดจากคะแนน
{
    if (Score >= 80)
        return "A";
    else if (Score >= 75)
        return "B+";
    else if (Score >= 70)
        return "B";
    else if (Score >= 65)
        return "C+";
    else if (Score >= 60)
        return "C";
    else if (Score >= 55)
        return "D+";
    else if (Score >= 50)
        return "D";
    else
        return "F";
}
