#include <iostream>
using namespace std;

int main()
{
    int A[5];
    int B[5] = {1, 2, 3, 4, 5};
    int C[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char D[] = {'H', 'e', 'e', 'l', 'l', 'o', '\n'};
    char E[] = "hello\0";
    int *AddressB;
    // E = "test"; // error: assignment of read-only location 'E'
    A[4] = 0;
    A[5] = 0;

    cout << sizeof(long long) << " " << sizeof(long long) * 5 << " ";
    cout << "address of B[0]" << &B[0] << endl;
    AddressB = &B[0];
    cout << *AddressB << endl;
    cout << "address of B[1]" << &B[1] << endl;
    AddressB = &B[1];
    cout << *AddressB << endl;
    cout << "address of B[2]" << &B[2] << endl;
    AddressB = &B[2];
    cout << *AddressB << endl;
    cout << "address of B[5]" << &B[5] << endl;
    AddressB = &B[5];
    cout << *AddressB << endl;

    for (int i = 0; i < 5; i++) // ใช่เมื่อเรารู้ขนาดของ array
    {
        cout << "index = " << i << " = " << B[i] << endl;
    }
    
    int idx = 0;
    for(char data:E){ // ใช่เมื่อเราไม่รู้ขนาดของ array
        cout << idx << " : " << data << " " << E[idx] << endl;
        idx++; 
    }

    for (int i = 0 ; i < sizeof(B)/sizeof(int); i++){ // ใช่เมื่อเรารู้ขนาดของ array
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}