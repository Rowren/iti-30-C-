#include <iostream>    // ใช้สำหรับการรับข้อมูลจากคีย์บอร์ด (cin) และแสดงผลบนหน้าจอ (cout)
#include <fstream>     // ใช้สำหรับการอ่านและเขียนไฟล์ (input/output file stream)
#include <vector>      // ใช้สำหรับประกาศและใช้งานโครงสร้างข้อมูลแบบลิสต์ (Dynamic Array)
#include <string>      // ใช้จัดการข้อความ เช่น ตัวแปร string, การเชื่อมต่อข้อความ, การเปรียบเทียบ
#include <ctime>       // ใช้สำหรับจัดการวันและเวลา เช่น การดึงวันที่ปัจจุบัน
#include <iomanip>     // ใช้จัดรูปแบบการแสดงผล เช่น setw(), setprecision(), fixed
#include <algorithm>   // ใช้ฟังก์ชันอัลกอริทึมสำเร็จรูป เช่น sort(), remove_if(), find()
#include <sstream>     // ใช้สำหรับแปลงข้อมูลระหว่าง string และชนิดข้อมูลอื่น เช่น int, double (String Stream)


using namespace std;

// โครงสร้างข้อมูลอุปกรณ์
struct Equipment {
    string code;
    string name;
    string category;
    int totalQuantity;
    int availableQuantity;
    string status;
};

// โครงสร้างข้อมูลการยืม-คืน
struct BorrowRecord {
    string recordId;
    string studentId;
    string equipmentCode;
    string borrowDate;
    string returnDate;
    string status;
    string condition;
    double fine;
};

// โครงสร้างข้อมูลรายงานความเสียหาย
struct DamageReport {
    string reportId;
    string equipmentCode;
    string studentId;
    string description;
    string reportDate;
    double fine;
    string paidStatus;
};

// คลาสระบบจัดการอุปกรณ์
class EquipmentSystem {
private:
    vector<Equipment> equipmentList;
    vector<BorrowRecord> borrowRecords;
    vector<DamageReport> damageReports;
    string equipmentFile = "equipment.txt";
    string borrowFile = "borrow.txt";
    string damageFile = "damage.txt";

    // โหลดข้อมูลจากไฟล์
    void loadData() {
        // โหลดข้อมูลอุปกรณ์
        ifstream eqFile(equipmentFile);
        if (eqFile.is_open()) {
            string line;
            while (getline(eqFile, line)) {
                stringstream ss(line);
                Equipment eq;
                ss >> eq.code >> eq.name >> eq.category 
                   >> eq.totalQuantity >> eq.availableQuantity >> eq.status;
                equipmentList.push_back(eq);
            }
            eqFile.close();
        }
        
        // โหลดข้อมูลการยืม
        ifstream brFile(borrowFile);
        if (brFile.is_open()) {
            string line;
            while (getline(brFile, line)) {
                stringstream ss(line);
                BorrowRecord br;
                ss >> br.recordId >> br.studentId >> br.equipmentCode
                   >> br.borrowDate >> br.returnDate >> br.status >> br.condition >> br.fine;
                borrowRecords.push_back(br);
            }
            brFile.close();
        }
        
        // โหลดข้อมูลความเสียหาย
        ifstream dmFile(damageFile);
        if (dmFile.is_open()) {
            string line;
            while (getline(dmFile, line)) {
                stringstream ss(line);
                DamageReport dr;
                ss >> dr.reportId >> dr.equipmentCode >> dr.studentId
                   >> dr.description >> dr.reportDate >> dr.fine >> dr.paidStatus;
                damageReports.push_back(dr);
            }
            dmFile.close();
        }
    }

    // บันทึกข้อมูลลงไฟล์
    void saveData() {
        // บันทึกข้อมูลอุปกรณ์
        ofstream eqFile(equipmentFile);
        for (const auto& eq : equipmentList) {
            eqFile << eq.code << " " << eq.name << " " << eq.category << " "
                   << eq.totalQuantity << " " << eq.availableQuantity << " " << eq.status << endl;
        }
        eqFile.close();
        
        // บันทึกข้อมูลการยืม
        ofstream brFile(borrowFile);
        for (const auto& br : borrowRecords) {
            brFile << br.recordId << " " << br.studentId << " " << br.equipmentCode << " "
                   << br.borrowDate << " " << br.returnDate << " " << br.status << " "
                   << br.condition << " " << br.fine << endl;
        }
        brFile.close();
        
        // บันทึกข้อมูลความเสียหาย
        ofstream dmFile(damageFile);
        for (const auto& dr : damageReports) {
            dmFile << dr.reportId << " " << dr.equipmentCode << " " << dr.studentId << " "
                   << dr.description << " " << dr.reportDate << " " << dr.fine << " "
                   << dr.paidStatus << endl;
        }
        dmFile.close();
    }

    // สร้างรหัสบันทึก
    string generateRecordId() {
        return "R" + to_string(borrowRecords.size() + 1);
    }

    // วันที่ปัจจุบัน
    string getCurrentDate() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        return to_string(1900 + ltm->tm_year) + "-" + 
               to_string(1 + ltm->tm_mon) + "-" + 
               to_string(ltm->tm_mday);
    }

    // ตรวจสอบว่าอุปกรณ์ว่างหรือไม่
    bool isEquipmentAvailable(const string& code) {
        for (const auto& eq : equipmentList) {
            if (eq.code == code && eq.availableQuantity > 0 && eq.status == "Normal") {
                return true;
            }
        }
        return false;
    }

    // ค้นหาอุปกรณ์ด้วยรหัส
    Equipment* findEquipment(const string& code) {
        for (auto& eq : equipmentList) {
            if (eq.code == code) {
                return &eq;
            }
        }
        return nullptr;
    }

public:
    EquipmentSystem() {
        loadData();
    }

    // เพิ่มอุปกรณ์ใหม่
    void addEquipment() {
        Equipment newEq;
        cout << "\n=== Add New Equipment ===" << endl;
        cout << "Equipment Code: "; 
        cin >> newEq.code;
        cout << "Equipment Name: "; 
        cin.ignore();
        getline(cin, newEq.name);
        cout << "Equipment Category: "; 
        getline(cin, newEq.category);
        cout << "Total Quantity: "; 
        cin >> newEq.totalQuantity;
        cout << "Available Quantity: "; 
        cin >> newEq.availableQuantity;
        newEq.status = "Normal";
        
        equipmentList.push_back(newEq);
        saveData();
        cout << "Equipment added successfully!" << endl;
    }

    // ลบอุปกรณ์
    void deleteEquipment() {
        string code;
        cout << "\n=== Delete Equipment ===" << endl;
        cout << "Enter equipment code to delete: "; 
        cin >> code;
        
        auto it = remove_if(equipmentList.begin(), equipmentList.end(),
            [&](const Equipment& eq) { return eq.code == code; });
        
        if (it != equipmentList.end()) {
            equipmentList.erase(it, equipmentList.end());
            saveData();
            cout << "Equipment deleted successfully!" << endl;
        } else {
            cout << "Equipment not found!" << endl;
        }
    }

    // อัปเดตข้อมูลอุปกรณ์
    void updateEquipment() {
        string code;
        cout << "\n=== Update Equipment ===" << endl;
        cout << "Enter equipment code: "; 
        cin >> code;
        
        Equipment* eq = findEquipment(code);
        if (eq != nullptr) {
            cout << "New name: "; 
            cin.ignore();
            getline(cin, eq->name);
            cout << "New category: "; 
            getline(cin, eq->category);
            cout << "New total quantity: "; 
            cin >> eq->totalQuantity;
            cout << "New available quantity: "; 
            cin >> eq->availableQuantity;
            cout << "New status: "; 
            cin >> eq->status;
            
            saveData();
            cout << "Equipment updated successfully!" << endl;
        } else {
            cout << "Equipment not found!" << endl;
        }
    }

    // แสดงอุปกรณ์ทั้งหมด
    void displayEquipment() {
        cout << "\n=== Equipment List ===" << endl;
        cout << left << setw(10) << "Code" << setw(20) << "Name" 
             << setw(15) << "Category" << setw(10) << "Total" 
             << setw(10) << "Available" << setw(10) << "Status" << endl;
        cout << string(75, '-') << endl;
        
        for (const auto& eq : equipmentList) {
            cout << left << setw(10) << eq.code << setw(20) << eq.name 
                 << setw(15) << eq.category << setw(10) << eq.totalQuantity
                 << setw(10) << eq.availableQuantity << setw(10) << eq.status << endl;
        }
    }

    // ยืมอุปกรณ์
    void borrowEquipment() {
        string studentId, equipmentCode;
        cout << "\n=== Borrow Equipment ===" << endl;
        cout << "Student/Staff ID: "; 
        cin >> studentId;
        cout << "Equipment Code: "; 
        cin >> equipmentCode;
        
        if (!isEquipmentAvailable(equipmentCode)) {
            cout << "Equipment not available or doesn't exist!" << endl;
            return;
        }
        
        Equipment* eq = findEquipment(equipmentCode);
        if (eq != nullptr) {
            BorrowRecord newRecord;
            newRecord.recordId = generateRecordId();
            newRecord.studentId = studentId;
            newRecord.equipmentCode = equipmentCode;
            newRecord.borrowDate = getCurrentDate();
            newRecord.returnDate = "";
            newRecord.status = "Borrowed";
            newRecord.condition = "Normal";
            newRecord.fine = 0.0;
            
            borrowRecords.push_back(newRecord);
            eq->availableQuantity--;
            saveData();
            
            cout << "Equipment borrowed successfully! Record ID: " << newRecord.recordId << endl;
        }
    }

    // คืนอุปกรณ์
    void returnEquipment() {
        string recordId, condition;
        double fine = 0.0;
        
        cout << "\n=== Return Equipment ===" << endl;
        cout << "Borrow Record ID: "; 
        cin >> recordId;
        
        for (auto& br : borrowRecords) {
            if (br.recordId == recordId && br.status == "Borrowed") {
                cout << "Equipment condition (Normal/Damaged/Lost): "; 
                cin >> condition;
                
                if (condition == "Damaged") {
                    cout << "Enter fine amount: "; 
                    cin >> fine;
                    
                    // Report damage
                    DamageReport damageReport;
                    damageReport.reportId = "D" + to_string(damageReports.size() + 1);
                    damageReport.equipmentCode = br.equipmentCode;
                    damageReport.studentId = br.studentId;
                    damageReport.description = "Equipment damaged during borrowing";
                    damageReport.reportDate = getCurrentDate();
                    damageReport.fine = fine;
                    damageReport.paidStatus = "Unpaid";
                    damageReports.push_back(damageReport);
                } else if (condition == "Lost") {
                    cout << "Enter compensation amount: "; 
                    cin >> fine;
                    
                    // Report loss
                    DamageReport lossReport;
                    lossReport.reportId = "D" + to_string(damageReports.size() + 1);
                    lossReport.equipmentCode = br.equipmentCode;
                    lossReport.studentId = br.studentId;
                    lossReport.description = "Equipment lost during borrowing";
                    lossReport.reportDate = getCurrentDate();
                    lossReport.fine = fine;
                    lossReport.paidStatus = "Unpaid";
                    damageReports.push_back(lossReport);
                }
                
                br.returnDate = getCurrentDate();
                br.status = "Returned";
                br.condition = condition;
                br.fine = fine;
                
                Equipment* eq = findEquipment(br.equipmentCode);
                if (eq != nullptr) {
                    if (condition == "Normal") {
                        eq->availableQuantity++;
                    } else if (condition == "Damaged") {
                        eq->status = "Damaged";
                    } else if (condition == "Lost") {
                        eq->totalQuantity--;
                        if (eq->totalQuantity < 0) eq->totalQuantity = 0;
                        if (eq->availableQuantity > eq->totalQuantity) 
                            eq->availableQuantity = eq->totalQuantity;
                    }
                }
                
                saveData();
                cout << "Equipment returned successfully!" << endl;
                return;
            }
        }
        cout << "Borrow record not found!" << endl;
    }

    // รายงานความเสียหาย
    
    void reportDamage() {
        DamageReport newReport;
        cout << "\n=== Report Damaged/Lost Equipment ===" << endl;
        cout << "Equipment Code: "; 
        cin >> newReport.equipmentCode;
        cout << "Student/Staff ID: "; 
        cin >> newReport.studentId;
        cout << "Damage description: "; 
        cin.ignore();
        getline(cin, newReport.description);
        cout << "Fine amount: "; 
        cin >> newReport.fine;
        
        newReport.reportId = "D" + to_string(damageReports.size() + 1);
        newReport.reportDate = getCurrentDate();
        newReport.paidStatus = "Unpaid";
        
        damageReports.push_back(newReport);
        
        Equipment* eq = findEquipment(newReport.equipmentCode);
        if (eq != nullptr) {
            eq->status = "Damaged";
        }
        
        saveData();
        cout << "Damage report submitted successfully! Report ID: " << newReport.reportId << endl;
    }

    // จัดการค่าปรับ - ฟังก์ชันใหม่
    void manageFinePayment() {
        string reportId;
        cout << "\n=== Manage Fine Payment ===" << endl;
        cout << "Enter Damage Report ID: "; 
        cin >> reportId;
        
        for (auto& dr : damageReports) {
            if (dr.reportId == reportId) {
                cout << "Report ID: " << dr.reportId << endl;
                cout << "Equipment Code: " << dr.equipmentCode << endl;
                cout << "Student/Staff ID: " << dr.studentId << endl;
                cout << "Description: " << dr.description << endl;
                cout << "Fine Amount: " << dr.fine << " Baht" << endl;
                cout << "Current Payment Status: " << dr.paidStatus << endl;
                
                char choice;
                cout << "Mark as paid? (y/n): "; 
                cin >> choice;
                
                if (choice == 'y' || choice == 'Y') {
                    dr.paidStatus = "Paid";
                    saveData();
                    cout << "Fine payment recorded successfully!" << endl;
                } else {
                    cout << "Operation cancelled." << endl;
                }
                return;
            }
        }
        cout << "Damage report not found!" << endl;
    }

    // แสดงรายงานค่าปรับทั้งหมด
    void displayAllFines() {
        cout << "\n=== All Fine Reports ===" << endl;
        cout << left << setw(10) << "Report ID" << setw(12) << "Eq. Code" 
             << setw(15) << "Student ID" << setw(25) << "Description" 
             << setw(12) << "Report Date" << setw(10) << "Fine" << setw(12) << "Status" << endl;
        cout << string(96, '-') << endl;
        
        double totalFines = 0.0;
        double unpaidFines = 0.0;
        
        for (const auto& dr : damageReports) {
            string shortDesc = (dr.description.length() > 23) ? 
                              dr.description.substr(0, 20) + "..." : dr.description;
            cout << left << setw(10) << dr.reportId << setw(12) << dr.equipmentCode
                 << setw(15) << dr.studentId << setw(25) << shortDesc
                 << setw(12) << dr.reportDate << setw(10) << dr.fine 
                 << setw(12) << dr.paidStatus << endl;
            
            totalFines += dr.fine;
            if (dr.paidStatus == "Unpaid") {
                unpaidFines += dr.fine;
            }
        }
        
        cout << string(96, '-') << endl;
        cout << "Total Fines: " << totalFines << " Baht" << endl;
        cout << "Unpaid Fines: " << unpaidFines << " Baht" << endl;
        cout << "Paid Fines: " << (totalFines - unpaidFines) << " Baht" << endl;
    }

    // ค้นหาอุปกรณ์
    void searchEquipment() {
        string keyword;
        cout << "\n=== Search Equipment ===" << endl;
        cout << "Enter equipment code or name: "; 
        cin >> keyword;
        
        cout << left << setw(10) << "Code" << setw(20) << "Name" 
             << setw(15) << "Category" << setw(10) << "Total" 
             << setw(10) << "Available" << setw(10) << "Status" << endl;
        cout << string(75, '-') << endl;
        
        bool found = false;
        for (const auto& eq : equipmentList) {
            if (eq.code.find(keyword) != string::npos || 
                eq.name.find(keyword) != string::npos) {
                cout << left << setw(10) << eq.code << setw(20) << eq.name 
                     << setw(15) << eq.category << setw(10) << eq.totalQuantity
                     << setw(10) << eq.availableQuantity << setw(10) << eq.status << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "No equipment found matching your search!" << endl;
        }
    }

    // สร้างรายงาน
    void generateReports() {
        int choice;
        cout << "\n=== Generate Reports ===" << endl;
        cout << "1. Equipment Inventory Report" << endl;
        cout << "2. Borrow/Return History Report" << endl;
        cout << "3. Damaged/Lost Equipment Report" << endl;
        cout << "4. Fine Report" << endl;
        cout << "Select: "; 
        cin >> choice;
        
        switch (choice) {
            case 1: {
                displayEquipment();
                break;
            }
            case 2: {
                cout << "\n=== Borrow/Return History Report ===" << endl;
                cout << left << setw(10) << "Record ID" << setw(15) << "Borrower ID" 
                     << setw(12) << "Eq. Code" << setw(12) << "Borrow Date" 
                     << setw(12) << "Return Date" << setw(10) << "Status" << setw(10) << "Condition" << endl;
                cout << string(81, '-') << endl;
                
                for (const auto& br : borrowRecords) {
                    cout << left << setw(10) << br.recordId << setw(15) << br.studentId
                         << setw(12) << br.equipmentCode << setw(12) << br.borrowDate
                         << setw(12) << (br.returnDate.empty() ? "-" : br.returnDate)
                         << setw(10) << br.status << setw(10) << br.condition << endl;
                }
                break;
            }
            case 3: {
                cout << "\n=== Damaged/Lost Equipment Report ===" << endl;
                cout << left << setw(10) << "Report ID" << setw(12) << "Eq. Code" 
                     << setw(15) << "Reporter ID" << setw(25) << "Description" 
                     << setw(12) << "Report Date" << setw(10) << "Fine" << setw(12) << "Status" << endl;
                cout << string(96, '-') << endl;
                
                for (const auto& dr : damageReports) {
                    string shortDesc = (dr.description.length() > 23) ? 
                                      dr.description.substr(0, 20) + "..." : dr.description;
                    cout << left << setw(10) << dr.reportId << setw(12) << dr.equipmentCode
                         << setw(15) << dr.studentId << setw(25) << shortDesc
                         << setw(12) << dr.reportDate << setw(10) << dr.fine 
                         << setw(12) << dr.paidStatus << endl;
                }
                break;
            }
            case 4: {
                displayAllFines();
                break;
            }
            default: {
                cout << "Invalid selection!" << endl;
                break;
            }
        }
    }

    // เมนูจัดการค่าปรับ - เมนูใหม่
    void fineManagementMenu() {
        int choice;
        do {
            cout << "\n=== Fine Management ===" << endl;
            cout << "1. Display All Fines" << endl;
            cout << "2. Manage Fine Payment" << endl;
            cout << "3. Generate Fine Report" << endl;
            cout << "0. Back to Main Menu" << endl;
            cout << "Select: "; 
            cin >> choice;
            
            switch (choice) {
                case 1: displayAllFines(); break;
                case 2: manageFinePayment(); break;
                case 3: {
                    cout << "\n=== Fine Report ===" << endl;
                    displayAllFines();
                    break;
                }
                case 0: return;
                default: cout << "Invalid selection!" << endl;
            }
        } while (choice != 0);
    }

    // เมนูจัดการอุปกรณ์
    void equipmentManagementMenu() {
        int choice;
        do {
            cout << "\n=== Equipment Management ===" << endl;
            cout << "1. Add Equipment" << endl;
            cout << "2. Delete Equipment" << endl;
            cout << "3. Update Equipment" << endl;
            cout << "4. Display Equipment" << endl;
            cout << "0. Back to Main Menu" << endl;
            cout << "Select: "; 
            cin >> choice;
            
            switch (choice) {
                case 1: addEquipment(); break;
                case 2: deleteEquipment(); break;
                case 3: updateEquipment(); break;
                case 4: displayEquipment(); break;
                case 0: return;
                default: cout << "Invalid selection!" << endl;
            }
        } while (choice != 0);
    }

    // เมนูหลัก
    void displayMainMenu() {
        cout << "\n=========================================" << endl;
        cout << "   University Sports Equipment System" << endl;
        cout << "=========================================" << endl;
        cout << "1. Equipment Management" << endl;
        cout << "2. Borrow Equipment" << endl;
        cout << "3. Return Equipment" << endl;
        cout << "4. Fine Management" << endl;  // เพิ่มเมนูจัดการค่าปรับ
        cout << "5. Report Damage/Loss" << endl;
        cout << "6. Search Equipment" << endl;
        cout << "7. Generate Reports" << endl;
        cout << "8. Display All Equipment" << endl;
        cout << "0. Exit System" << endl;
        cout << "Select: ";
    }

    // เริ่มการทำงานของระบบ
    void run() {
        int choice;
        
        cout << "Welcome to University Sports Equipment System" << endl;
        
        do {
            displayMainMenu();
            cin >> choice;
            
            switch (choice) {
                case 1: 
                    equipmentManagementMenu(); 
                    break;
                case 2: 
                    borrowEquipment(); 
                    break;
                case 3: 
                    returnEquipment(); 
                    break;
                case 4: 
                    fineManagementMenu();
                    break;
                case 5: 
                    reportDamage(); 
                    break;
                case 6: 
                    searchEquipment(); 
                    break;
                case 7: 
                    generateReports(); 
                    break;
                case 8: 
                    displayEquipment(); 
                    break;
                case 0: 
                    cout << "Thank you for using our service! Press any key to exit." << endl;
                    break;
                default: 
                    cout << "Invalid selection! Please try again." << endl;
            }
        } while (choice != 0);
    }
};

// ฟังก์ชันหลัก
int main() {
    EquipmentSystem system;
    system.run();
    return 0;
}