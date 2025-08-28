#include <iostream>
using namespace std;

void ModifyArray(int Temp[]);
void ModifyElement(int Temp);

int main(){
    int Data[] = {1,2,3,4,5};
    for (int data : Data){
        cout << data << " ";
    }
    cout << endl;
    
    ModifyArray(Data);
    
    for (int data :Data){
        cout << data << " ";
    }

    cout << endl;

    ModifyElement(Data[3]);
    for (int data :Data){
        cout << data << " ";
    }

    cout << endl;

    return 0 ;
}

void ModifyArray(int Temp[]){ // array is passed pass-by-reference
    for (int j = 0; j < 5; j++){
        Temp[j] *= 2;
    }
}

void ModifyElement(int Temp){ // array element is passed pass-by-value ถ้าอยากเปลี่ยนต้องใช้ &
    Temp *= 2;
}