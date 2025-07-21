#include <iostream>
#include <iomanip>
#include <vector>
#include "PhuongTien.cpp"
#include "XeOto.cpp"
#include "XeMay.cpp"
#include "XeTai.cpp"
using namespace std;

void clearInput(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
// Hàm chung để xử lý thêm xe, giảm nested trong main
template <typename T>
void addVehicle(vector<T>& vt, const string& typeName) {
    cout << "\nNhap thong tin " << typeName << ": " << endl;
    T xe;
    cin >> xe;
    vt.push_back(xe);
    cout << "Da them " << typeName << " thanh cong\n" << endl;
}

// Hàm chung để xử lý xóa xe (từ câu trả lời trước)
template <typename T>
void deleteVehicle(vector<T>& vt, const string& typeName) {
    if (vt.size() == 0) {
        cout << "vector rong, khong the thuc hien xoa\n" << endl;
        return;
    }
    bool isDelete = false;
    while (!isDelete) {
        int choice;
        cout << "Nhap vi tri vector can xoa (1 den " << vt.size() << ", hoac -1 de quay ve main menu): ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Loi nhap lieu, vui long nhap lai hoac -1 de quay ve main menu\n" << endl;
            clearInput();
            continue;
        }
        if (choice == -1) {
            cout << "Quay ve main menu\n" << endl;
            break;
        }
        if (choice < 1 || choice > vt.size()) {
            cout << "Vi tri do khong ton tai, vui long nhap lai hoac -1 de quay ve main menu\n" << endl;
            continue;
        }
        vt.erase(vt.begin() + (choice - 1));
        cout << "Da xoa thanh cong\n" << endl;
        isDelete = true;
    }
}

void displayMainMenu() {
    cout << ">>=========== M E N U ===========<<" << endl;
    cout << "1. Nhap thong tin xe" << endl;
    cout << "2. Xoa thong tin xe" << endl;
    cout << "3. Chinh sua thong tin xe" << endl;
    cout << "4. Hien thi tat ca thong tin" << endl;
    cout << "5. Exit" << endl;
    cout << "\nNhap lua chon: ";
}

void displayMenu1() {
    cout << "1. Nhap thong tin xe Oto" << endl;
    cout << "2. Nhap thong tin xe May" << endl;
    cout << "3. Nhap thong tin xe Tai" << endl;
    cout << "4. Quay lai" << endl;
    cout << "\nNhap lua chon: ";
}

void displayMenu2() {
    cout << "1. Xoa thong tin xe Oto" << endl;
    cout << "2. Xoa thong tin xe May" << endl;
    cout << "3. Xoa thong tin xe Tai" << endl;
    cout << "4. Quay lai" << endl;
    cout << "\nNhap lua chon: ";
}

int main() {
    vector<XeOto> vtXeOto;
    vector<XeMay> vtXeMay;
    vector<XeTai> vtXeTai;

    int inputMainMenu, inputSubMenu;
    while (true){
        displayMainMenu();
        cin >> inputMainMenu;

        if (cin.fail()){
            cout << "Loi, xin vui long thu lai\n\n";
            clearInput();
        }

        switch (inputMainMenu){
            case 1: {
                cout << endl;
                displayMenu1();
                cin >> inputSubMenu;

                switch (inputSubMenu){
                    case 1: { // Them xe oto
                        break;
                    }
                    case 2: { // Them xe may
                        break;
                    } 
                    case 3: { // hem xe tai
                        break;
                    }
                    default: {
                        cout << "Lua chon khong hop le: " << endl;
                        break;
                    }
                }
                break;
                
            }

            case 2: {
                cout << endl;
                displayMenu2();
                cin >> inputSubMenu;

                switch (inputSubMenu){
                    case 1: { // xoa Xe oto
                        break;
                    }

                    case 2: { // Xoa xe May
                        break;
                    }

                    case 3: { // xoa xe Tai
                        break;
                    }
                    case 4: {
                        cout << "Quay ve main menu\n" << endl;
                        break;
                    }
                    default: {
                        cout << "Lua chon khong hop le\n" << endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}