#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char name1[20] = "aaaa";
    char name2[20] = "bbbb";

    cout << "Enter String 1:";
    cin >> name1;
    cout << "Enter String 2:";
    cin >> name2;

    cout << (strcmp(name1, name2) == 0 ? "true" : "false") << endl;

    int sw;

    sw = strcmp(name1, name2);
    switch (sw){
        case 0:
            cout << "A = B ";
            break;
        case 1:
            cout << "A < B ";
            break;
        case -1:
            cout << "A > B ";
            break;
        default:cout << "Exception Error";
    }
    return 0;
}