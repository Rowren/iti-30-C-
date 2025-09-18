    #include <iostream>
    #include <iomanip>
    #include <time.h>
    using namespace std;

    int main()
    {

        int chairman;       // กำหนดจำนวนผู้สมัคร
        int MaxStudent = 500; // กำหนดจำนวนนักเรียนที่มาใช้สิทธิ์
        int Vote[MaxStudent]; // กำหนดอาเรย์เก็บคะแนนโหวต
        int sumVote = 0, notVote = 0;  // ตัวแปรเก็บจำนวนผู้มาใช้สิทธิ์และไม่มาใช้สิทธิ์

        cout << "Enter number student chairman : "; // รับจำนวนผู้สมัคร
        cin >> chairman; // รับจำนวนผู้สมัคร

        int Score[chairman] = {0}; // กำหนดอาเรย์เก็บคะแนนโหวตให้เท่ากับจำนวนผู้สมัครและกำหนดค่าเริ่มต้นเป็น 0

        // random votes for 500 students
        srand(time(0)); // กำหนดค่าเริ่มต้นของตัวสร้างเลขสุ่ม
        for (int i = 0; i < MaxStudent; i++) // วนลูปสุ่มคะแนนโหวตให้กับนักเรียน 500 คน
        {
            Vote[i] = rand() % (chairman + 1); // สุ่มคะแนนโหวตตั้งแต่ 0 ถึง จำนวนผู้สมัคร
            if (Vote[i] == 0) // ถ้าคะแนนโหวตเป็น 0 แสดงว่าไม่มาใช้สิทธิ์
            {
                notVote++; // เพิ่มจำนวนผู้ไม่มาใช้สิทธิ์
            }
            else // ถ้าคะแนนโหวตไม่เป็น 0 แสดงว่า มาใช้สิทธิ์
            {
                Score[Vote[i] - 1]++; // เพิ่มคะแนนโหวตให้กับผู้สมัครที่ได้รับคะแนน
                sumVote++; // เพิ่มจำนวนผู้มาใช้สิทธิ์
            }
        }

        // sumary of votes
        cout << "Number of right student : " << MaxStudent << endl; // แสดงจำนวนนักเรียนทั้งหมด
        cout << "Number of Votes : " << sumVote << " = " 
            << fixed << setprecision(1)
            << (float(sumVote) / MaxStudent * 100.0) << "%" << endl; // แสดงจำนวนผู้มาใช้สิทธิ์และเปอร์เซ็นต์
        cout << "Number of not Votes : " << notVote << " = "
            << fixed << setprecision(1)
            << (float(notVote) / MaxStudent * 100.0) << "%" << endl;  // แสดงจำนวนผู้ไม่มาใช้สิทธิ์และเปอร์เซ็นต์


        // results table
        cout << "\nResult of election chairman\n"; // แสดงผลการเลือกตั้ง
        cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl; // แสดงเส้นคั่น
        cout << left << setw(10) << "No." 
            << setw(10) << "Votes"
            << "Percent(%)" << endl;  // แสดงหัวตาราง
        cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;  // แสดงเส้นคั่น
        for (int i = 0; i < chairman; i++){ // วนลูปแสดงผลการเลือกตั้ง
                cout << left << setw(10) << i+1
                    << setw(10) << Score[i]
                    << fixed << setprecision(2) 
                    << (float(Score[i]) / sumVote * 100.0) << endl;  // แสดงผลการเลือกตั้งและเปอร์เซ็นต์
            }
        cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl; // แสดงเส้นคั่น
        cout << left << setw(10) << "Total" << setw(10) << sumVote << "100.00" << endl; // แสดงผลรวมคะแนนโหวตทั้งหมด

        return 0;
    }