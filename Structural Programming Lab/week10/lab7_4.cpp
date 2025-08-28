#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{
    int Data[10];
    // srand (11); // ค่าเหมือนเดิมทุกครั้งที่รัน
    srand(time(0)); // ค่าเปลี่ยนทุกครั้งที่รันตามเวลา

    for (int i = 0; i < 10; i++)
    {
        Data[i] = rand() % 20 + 1; // 0 - 32767 1-30
        // 1-30
        cout << Data[i] << " ";
    }
    cout << "Elements Value Histogram" << endl
         << endl;
    // for ( int i = 0; i < 10 ; i++){
    //     cout << setw(5) << i << " " << setw(4) << Data[i] << " ";
    //     for(int k = 1; k <= Data[i]; k++){
    //        cout << "*";
    //     }
    //     cout << endl ;
    // }

    for (int i = 0; i < 20; i++)
    {
        for (int k = 0; k < 10; k++)
        {
            if( Data[k] >= 20 - i ){
            cout << setw(3) << " * " ;
            }
            else cout << setw(3) << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << setw(2) << Data[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << setw(2) << i + 1 << " ";
    }

    cout << endl;

    return 0;
}
