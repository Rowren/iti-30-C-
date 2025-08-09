#include <iostream>
using namespace std;

int main()
{
    char choice;
    cout << "Enter Color code : ";
    cin >> choice;
    cout << "Your Choice is  " << choice <<" = ";
    switch (choice)  
    {
    case   'R': cout << "RED";
        break;  //!break มันจะทำงานเหมือน returnถ้าไม่มี break มันจะทำงานต่อไปเรื่อยๆโดยไม่สนใจเงื่อนไขแล้วนะจะทำงานจนกว่าจะเจอ break หรือจบ switch
    case   'W': cout << "WHITE";
        break;
    case   'B': cout << "BLUE";
        break;
    case   'G': cout << "GREEN";
        break;
    default: cout << "I Dont't Know";
        break;
    }
    return 0;
}
