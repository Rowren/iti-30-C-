#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char month[][10] = {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"};

    int xy = sizeof(month) / sizeof(month[0][0]);
    int y = sizeof(month[0]) / sizeof(month[0][0]);
    int x = xy / y;

    // reverse print
    // for (int i = x - 1; i >= 0; i--)
    // {
    //     cout << "month[" << setw(2) << i << "] = "
    //          << month[i] << endl;
    // }

    // // normal print
    // cout << "------------------------" << endl;
    // for (int i = 0; i < x; i++)
    // {
    //     cout << "month[" << setw(2) << i << "] = "
    //          << month[i] << endl;
    // }

    // print with setw and setfill
    // for  (int i = x - 1; i >= 0; i--)
    // {
    //     cout << setw(10) << setfill('#') << month[i] << endl;
    // }

    for (int i = x - 1; i >= 0; i--)
    {
        cout << i << " : " << setw(2);
        for (int j = 0; j < y; j++)
        {
            //cout << month[i][j];
            cout << hex << setw(4) << (int)month[i][j] ;
        }
        cout << endl;
        
    }


    return 0;
}
