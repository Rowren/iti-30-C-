#include <iostream>
#include <iomanip>
using namespace std ;

int main(){
    int X[10];
    int Y[]= {10,20,30,40,50,60,70,80,90,100};
    const int Array_Size = 10;
    int Z[Array_Size] ;
    
    //init
    for(int i= 0 ; i<10; i++) X[i] = 0;
    X[1] = 2;
    //show
    for (int i = 0 ; i < Array_Size; i++) {
            Z[i] =  2 + 2 * i; 
            cout << Z[i] << " " ;
    }

    cout << endl ;
    cout << ": Subscript : Array X : Array Y : Array Z :" << endl ;
    cout << setfill('=') << setw(43) << "=" << endl;
    cout << setfill(' ') ;
    for (int i = 0; i < Array_Size; i++){
        cout << ":"
             << setw(6) << i << "    :"
             << setw(6) << X[i] << "    :"
             << setw(6) << Y[i] << "    :"
             << setw(6) << Z[i] << "    :" << endl ;
    }
    cout << setfill('=') << setw(43) << "=" << endl;
    return 0 ;
}