#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>

using namespace std;

int write_file(string Filename);
int read_file(string Filename);
int read_file2(string Filename);

int main()
{
    string Filename;
    ifstream InFile;  // open file
    ofstream OutFile; // write file
    int Value;

    srand(time(0));
    cout << "Enter file name :";
    cin >> Filename;
    cout << endl;

    // write_file(Filename);
    read_file(Filename);

    return 0;
}

int write_file(string Filename)
{
    ofstream OutFile; // write file
    int Value;
    // open output file for write data
    OutFile.open(Filename); // open file
    cout << "Now open file "
         << Filename << " for write \n"; // file name

    for (int n = 0; n <= 10; n++)
    {
        Value = rand() % 100;     // random 0 - 99
        cout << setw(5) << Value; // output Value
        // write Value (intgeter number) to output file
        OutFile << Value << " ";
    }
    cout << endl;
    OutFile.close(); // close output file
    cout << "Now close file " << Filename << ".\n\n";
}

int read_file(string Filename)
{
    ifstream InFile;
    int Value;
    // open input file for read data
    InFile.open(Filename);
    cout << "Now open file " << Filename << "for read." << endl;
    // Read name from input file

    while (InFile.eof())
    {

        InFile >> Value;
        cout << setw(5) << Value;
    }
    cout << endl;
    InFile.close(); // close input file
    cout << "Now close file " << Filename << "\n\n";
}

int read_file2(string Filename)
{
    ifstream InFile;
    int Value;
    // open input file for read data
    InFile.open(Filename);
    cout << "Now open file " << Filename << "for read." << endl;
    // Read name from input file
    for (;;)
    {

        if (InFile.eof() == true)
            break;
        InFile >> Value;
        cout << setw(5) << Value;
    }
    cout << endl;
    InFile.close(); // close input file
    cout << "Now close file " << Filename << "\n\n";
}
