#include <iostream>

using namespace std;

int main()
{
    for ( int i = 0; i < 20; i++ ) { 
        if( i == 4 || i == 9 ) continue; 
        if(i == 15 ) break;              
        cout << i << endl; 
    }

    return 0;
}