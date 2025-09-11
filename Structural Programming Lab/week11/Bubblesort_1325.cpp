    #include <iostream>
    #include <iomanip>
    using namespace std;

    void DisplayArray(int arr[], int size, int idx);
    void BubbleSort(int arr[], int size);

    int main()
    {
        const int size = 8;       
        int data[size];

        cout << "Enter " << size << " integers: ";
        for (int i = 0; i < size; i++) {
            cin >> data[i];
        }

        cout << "Check for size Array : " << size << endl;
        BubbleSort(data, size);

        return 0;
    }

    void DisplayArray(int arr[], int size, int idx)
    {
        cout << "[";
        for (int i = 0; i < size; i++) {
            if (i == idx || i == idx + 1)
                cout << "[" << arr[i] << "]";
            else
                cout << " " << arr[i] << " ";
        }
        cout << "]" << endl;
    }

   void BubbleSort(int arr[], int size)
{
    int roundCount = 0;

    for (int i = 0; i < size - 1; i++) {
        bool sorted = true;   // เริ่มรอบใหม่ sorted = true

        for (int j = 0; j < size - i - 1; j++) {
            roundCount++;     // นับรอบจริง

            cout << "i = " << i + 1 << setw(3)
                 << " j = " << j << setw(3) << " ";
            DisplayArray(arr, size, j);

            if (arr[j] > arr[j + 1]) {
                // swap arr[j] กับ arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                sorted = false;  // มีการสลับ → sorted = false
            }
        }

        if (sorted) break;  // ถ้าไม่สลับเลย → จบการทำงาน
    }

    cout << "\nTotal Round = " << roundCount << endl;
}



