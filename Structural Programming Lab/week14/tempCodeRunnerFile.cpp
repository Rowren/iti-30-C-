
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void GetandWrite(ofstream &OutFile);
void ReadandDisplay(ifstream &InFile);
string CalGrade(int score);
void FindandDisplay(ifstream &Infile);

int main()
{
    string Filename;
    ifstream Infile;
    ofstream Outfile;

    cout << "Enter file name : ";
    cin >> Filename;
    cout << endl;

    /*
         Outfile.open(Filename.c_str(), ios_base::app);
         cout << "Now open file "
              << Filename << " for write.  \n";
         GetandWrite(Outfile);
         cout << "Now close file " << Filename << "\n\n\n" ;
         Outfile.close();
    */

    Infile.open(Filename);
    cout << "Now open file " << Filename << " for read.  \n";
    ReadandDisplay(Infile);
    FindandDisplay(Infile);
    cout << "Now close file " << Filename << "\n\n\n";
    Infile.close();

    return 0;
}
void GetandWrite(ofstream &OutFile)
{
    string Id, Name, Surname;
    int Score;

    for (int n = 1; n <= 3; n++)
    {
        cout << "\nStudent No : " << n << endl;
        cout << "Enter Id: ";
        cin >> Id;
        cout << "Enter Name : ";
        cin >> Name;
        cout << "Enter Surname : ";
        cin >> Surname;
        cout << "Enter Score : ";
        cin >> Score;

        OutFile << Id << " "
                << Name << " "
                << Surname << " "
                << Score << endl;
    }
}

void ReadandDisplay(ifstream &InFile)
{
    string Id, Name, Surname;
    int Score;
    cout << setfill('=') << setw(60) << "=" << setfill(' ') << endl; // แสดงเส้นคั่น
    cout << right
         << setw(10) << "ID"
         << setw(10) << "Name"
         << setw(10) << "Surname"
         << setw(19) << "Score Grade"
         << endl;

    for(;;)
    {
        InFile >> Id >> Name >> Surname >> Score;
        if (InFile.eof() == true) break; // เช็คสถานะ eof ว่าถึงจุดสิ้นสุดไฟล์หรือยัง


        cout << right
             << setw(10) << Id
             << setw(10) << Name
             << setw(10) << Surname
             << setw(10) << Score
             << setw(5) << CalGrade(Score)

             << endl;
    }
    cout << setfill('=') << setw(60) << "=" << setfill(' ') << endl; // แสดงเส้นคั่น
    cout << endl;
}

void FindandDisplay(ifstream &Infile)
{
    string Id, Name, Surname;
    int Score;
    int findNumber = 4;
    int counter = 0;
    Infile.clear();                 // เคลียร์สถานะ eof
    Infile.seekg(0, ios_base::beg); // เลื่อนตำแหน่งไปจุดเริ่มต้นของไฟล์
    cout << "Counter : " << endl;
    for (;;)
    {
        Infile >> Id >> Name >> Surname >> Score;
        if (Infile.eof() == true) break; // เช็คสถานะ eof ว่าถึงจุดสิ้นสุดไฟล์หรือยัง
        if (Score == findNumber)
        {
            if (counter == 0)
            {
                cout << "Found this score : " << Score << " in the records" << endl;
                cout << "get by : " << endl; 
            }
            cout << Id << " " << Name << " " << Surname << " " << Score << endl;
            counter ++;
        }
    }
    if(counter == 0){
        cout << "Nobody get this score \"" << findNumber << "\" in the records" << endl;
    }else{
        cout << "total = " << counter << " records";
    }
    cout << endl;
}

string CalGrade(int Score)
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
