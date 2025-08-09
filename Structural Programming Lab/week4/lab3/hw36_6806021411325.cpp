/* 6806021411325 นายธนธรณ์ บุษเกตุ*/
#include <iostream> //นำเข้าไลบรารี iostream เพื่อใช้ในการรับและแสดงผลข้อมูล
using namespace std;    //เรียกใช้ไลบรารี iostream และใช้ namespace std

int main() { //ฟังก์ชันหลักของโปรแกรม
    int startKm, endKm; //ประกาศตัวแปร startKm และ endKm สำหรับเก็บค่ากิโลเมตรเริ่มต้นและสิ้นสุด
    int hour, minute, second; //ประกาศตัวแปร hour, minute, second สำหรับเก็บเวลาที่ใช้ในการเดินทาง
    cout << "Car Velocity Calculation Program" << endl; //แสดงข้อความหัวเรื่อง
    cout << "Enter start kilometer : "; //ขอให้ผู้ใช้ป้อนกิโลเมตรเริ่มต้น
    cin >> startKm; //รับค่าจากผู้ใช้และเก็บไว้ในตัวแปร startKm
    cout << "Enter end kilometer : "; //ขอให้ผู้ใช้ป้อนกิโลเมตรสิ้นสุด
    cin >> endKm; //รับค่าจากผู้ใช้และเก็บไว้ในตัวแปร endKm
    cout << "Enter time used(hour minute second) : "; //ขอให้ผู้ใช้ป้อนเวลาที่ใช้ในการเดินทาง
    cin >> hour >> minute >> second; //รับค่าจากผู้ใช้และเก็บไว้ในตัวแปร hour, minute, second
    
    //คำนวณระยะทางที่เดินทางและความเร็วเฉลี่ย
    int distance = endKm - startKm; //คำนวณระยะทางที่เดินทางโดยการลบกิโลเมตรเริ่มต้นจากกิโลเมตรสิ้นสุด
    int totalSeconds = hour * 3600 + minute * 60 + second; //คำนวณเวลาทั้งหมดเป็นวินาทีโดยการแปลงชั่วโมงเป็นวินาทีและนาทีเป็นวินาที
    double totalHours = totalSeconds / 3600.0;  //แปลงเวลาทั้งหมดเป็นชั่วโมงโดยการหารจำนวนวินาทีด้วย 3600.0
    double avgVelocity = distance / totalHours; //คำนวณความเร็วเฉลี่ยโดยการหารระยะทางด้วยเวลาทั้งหมดในชั่วโมง

    cout << "Car traveled " << distance << " kilometers in "    // แสดงผลระยะทางที่เดินทาง
         << hour << " hrs " << minute << " min " << second << " sec." << endl; // แสดงผลเวลาที่ใช้ในการเดินทาง
    cout << "Average velocity was " << avgVelocity << " kph." << endl; // แสดงผลความเร็วเฉลี่ยที่คำนวณได้
    return 0;// คืนค่า 0 เพื่อบ่งชี้ว่าการทำงานของโปรแกรมสำเร็จ
}//จบโปรแกรม