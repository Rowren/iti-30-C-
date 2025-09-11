#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int A[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    int B[5][2][3] = {
        {{1, 2, 3}, {1, 2, 3}},
        {{1, 2, 3}, {1, 2, 3}},
        {{1, 2, 3}, {1, 2, 3}},
        {{1, 2, 3}, {1, 2, 3}},
        {{1, 2, 3}, {1, 2, 3}}};
    int C[][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}};

    cout << C[2][2] << " " << C[3][1] << endl; // 11

    int xy = sizeof(C) / sizeof(C[0][0]);
    int x = xy / (sizeof(C[0]) / sizeof(C[0][0]));
    int y = xy / x;

    cout << "size of C = " << xy << endl
         << "X : " << x << endl
         << "Y : " << y << endl;

    for (int i = 0; i < x; i++)
    {
        cout << "i = " << i << " : j =  ";
        for (int j = 0; j < y; j++)
        {
            cout <<  "|[" << setw(2) << C[i][j] << "]| "; 
        }
        
        cout << endl;
    }

    return 0;
}