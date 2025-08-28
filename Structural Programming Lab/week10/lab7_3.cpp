#include <iostream>
using namespace std;

int main(){
    int A[]= {1,2,3,4,5,5,6,7,8,9,10};
    const int Array_Size = 10;
    int Sum = 0;

    // for (int i = 0 ; i < Array_Size; i++){
    //     Sum = Sum + A[i];
    //     cout << A[i] << " " << Sum << endl;
    // }
    for (int i:A ){
        Sum = Sum + i;
        cout << i << " " << Sum << endl;
    }
    cout << "Total of Array Elements : " << Sum << endl;
    return 0;
}