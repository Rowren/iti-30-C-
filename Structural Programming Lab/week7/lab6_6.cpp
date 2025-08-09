#include <iostream>

using namespace std;

int main()
{
    unsigned long Sum = 0L;
    int n, i =1;
    cout << "Please Enter Value n to find  summation  of n*n :";
    cin >> n;
    do{
        Sum += i * i;
        cout << "Sum = " << Sum << endl;
        i++;
        cout << "i = " << i << endl;
    }while (i <= n);
    cout << "Sum = " << Sum << endl;
    
    return 0;
}