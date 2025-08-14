// 6806021411325 นายธนธรณ์ บุษเกตุ 14/8/2568 11:22

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void Calendar();
void Calgrade();
void power_number();

int main()
{
    char Choice;

    for (;;)
    {
        cout << "====================" << endl;
        cout << "menu" << endl;
        cout << "====================" << endl;
        cout << "1 Calendar         [1/9/c]" << endl;
        cout << "2 Grade            [2/G/g]" << endl;
        cout << "3 Power Number     [3/S/N]" << endl;
        cout << "0 Exit             [0/E/X/I/T]" << endl;
        cout << "Select Menu : ";
        cin >> Choice;

        if (Choice == '1' || Choice == '9' || Choice == 'c')
        {
            Calendar();
            return 0;
        }
        else if (Choice == '2' || Choice == 'G' || Choice == 'g')
        {
            Calgrade();
            return 0;
        }
        else if (Choice == '3' || Choice == 'S' || Choice == 'N')
        {
            power_number();
            return 0;
        }
        else if (Choice == '0' || Choice == 'E' || Choice == 'X' || Choice == 'I' || Choice == 'T')
        {
            cout << "--------------------" << endl;
            cout << "Exit Program \n";
            cout << "--------------------" << endl;
            break;
        }
        else
        {
            cout << "Please Menu Again \n\n";
        }
    }
    return 0;
}

void Calendar()
{
    cout << "Calendar AUGUST 2568\n";
    cout << "SU  MO  TU  WE  TH  FR  SA\n";

    for (int i = 0; i < 6; i++) {      // รอบนอก 6 สัปดาห์
        for (int j = 1; j <= 7; j++) { // รอบใน 7 วัน
            int num = i * 7 + j - 4;   // สูตรคำนวณตัวเลขวัน
            if (num < 1 || num > 31)
                cout << left << setw(4) << "X";
            else
                cout << left << setw(4) << num;
        }
        cout << endl;
    }
}

void Calgrade()
{
    int score;
    string name;
    char grade;

    cout << "Enter Name : ";
    cin >> name;
    cout << "Enter Score : ";
    cin >> score;

    if (score < 0 || score > 100)
    {
        cout << "Invalid score!" << endl;
        return;
    }

    if (score >= 90 && score <= 100)
    {
        grade = 'S';
    }
    else if (score >= 80)
    {
        grade = 'A';
    }
    else if (score >= 70)
    {
        grade = 'B';
    }
    else if (score >= 60)
    {
        grade = 'C';
    }
    else if (score >= 35)
    {
        grade = 'D';
    }
    else
    {
        grade = 'F';
    }

    cout << name << " Score " << score << " Grade " << grade << endl;
}

void power_number() 
{
    int num;

    // วนจนกว่าจะกรอกเลขถูกต้อง
    do {
        cout << "Enter Power Number (2-12) : ";
        cin >> num;

        if (num < 2 || num > 12)
            cout << "Try Again" << endl;

    } while (num < 2 || num > 12);

    // คำนวณยกกำลัง
    for (int i = 1; i <= 10; i++)
    {
        long long result = 1;
        for (int j = 0; j < i; j++)
        {
            result *= num;
        }
        cout << num << "^" << i << "\t= " << result << endl;
    }
} 
