#include <iostream>
#include <string>

#define PI 3.13159

using namespace std;

int main()
{
    string choice;
    bool circle;
    float radius, area, length, width;

    cout << "Do you want to cal Circle Area? (y)";
    cin >> choice;
    circle = (choice == "y" || choice == "Y" ? true : false);

    if (circle)
    {
        cout << "Cal Circle Area" << endl
             << "Enter radius: ";
        cin >> radius;
        area = PI * radius * radius;
        cout << "Area of Circle: " << area << endl;
    }
    else
    {
        cout << "Cal Rectangle Area" << endl
             << "Enter length and width: ";
        cin >> length >> width;
        area = length * width;
        cout << "Area of Rectangle: " << area << endl;
    }

    return 0;
}
