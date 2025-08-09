#include <iostream>
using namespace std;

int main()
{
    int A, B;
    cout << "Enter value A andB : "; //"<<"insertion
    cin >> A >> B;                   // ">>"extraction
    if (A == B)
        cout << "A and B values are equal" << endl;
    if (A > B)
        cout << "A values > values B" << endl;
    if (A < B)
        cout << "A values < values B" << endl;

    return 0;
}