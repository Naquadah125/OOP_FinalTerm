#include <iostream>
#include <limits>
#include <vector>
#include "PhuongTien.cpp"
#include "XeOto.cpp"
#include "XeMay.cpp"
#include "XeTai.cpp"
using namespace std;

// Để clear input khi người dùng nhập sai 
void clearInput(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
template <typename T> //thêm xe
void addVehicle(vector<T>& vt, const string& typeName) {
    cout << "\nNhap thong tin " << typeName << ": " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Làm sạch buffer trước khi nhập
    T xe;
    cin >> xe;

    vt.push_back(xe);
    cout << "Da them " << typeName << " thanh cong\n" << endl;

    cout << "Nhan Enter de tiep tuc..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
template <typename T> //xóa xe
void deleteVehicle(vector<T>& vt) {
    if (vt.size() == 0) {
        cout << "vector rong, khong the thuc hien xoa\n" << endl;
        cout << "Nhan Enter de tiep tuc..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }
    bool isDelete = false;
    while (!isDelete) {
        int choice;
        cout << "Nhap vi tri vector can xoa (1 den " << vt.size() << ", hoac -1 de quay ve main menu): ";
        cin >> choice;
                                        // giúp cho kiểu dữ liệu của choice == vt.size
        if (cin.fail() || choice < 1 || static_cast<size_t>(choice) > vt.size()) {
            cout << "Loi nhap lieu, vui long nhap lai hoac -1 de quay ve main menu\n" << endl;
            clearInput();
            continue;
        }
        if (choice == -1) {
            cout << "Quay ve main menu\n" << endl;
            break;
        }
        vt.erase(vt.begin() + (static_cast<size_t>(choice) - 1));
        cout << "Da xoa thanh cong\n" << endl;
        isDelete = true;
    }

    cout << "Nhan Enter de tiep tuc..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
template <typename T> //hiển thị tổng số xe
void displayVehicleVector(const vector<T>& vt){
    if (vt.size() == 0) {
        cout << "vector rong, khong the hien thi\n" << endl;
        cout << "Nhan Enter de tiep tuc..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }
    cout << endl;
    for (size_t i = 0; i < vt.size(); i++){
        cout << "Du lieu tai vector " << i << ": " << endl;
        cout << vt[i] << endl;
    }

    cout << "Nhan Enter de tiep tuc..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
template <typename T> //thay đổi thông số xe tại vị trí X trên vector
void changeVectorInfo(vector<T>& vt, string typeName){
    if (vt.size() == 0){
        cout << "vector rong, khong the chinh sua\n" << endl;
        cout << "Nhan Enter de tiep tuc..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }
    bool isChange = false;
    while (!isChange){
        cout << "Nhap vi tri can sua chua (tu 1 den " << vt.size() << ", hoac -1 de quay ve main menu): ";
        int location;
        cin >> location;

        if (cin.fail() || (location < 1 && location != -1) || static_cast<size_t>(location) > vt.size()) { 
            cout << "Loi nhap lieu, vui long nhap lai hoac -1 de quay ve main menu\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (location == -1) {
            cout << "Quay ve main menu\n" << endl;
            break;
        }


        cout << "Nhap cac du lieu de thay doi lop " << typeName << ":\n";
        cin >> vt[location - 1];
        cout << "Du lieu duoc thay doi thanh cong\n" << endl;
        isChange = true;
    }

    cout << "Nhan Enter de tiep tuc..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void displayMainMenu() {
    cout << ">>=========== M E N U ===========<<" << endl;
    cout << "1. Nhap thong tin xe" << endl;
    cout << "2. Xoa thong tin xe" << endl;
    cout << "3. Chinh sua thong tin xe" << endl;
    cout << "4. Hien thi thong tin" << endl;
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
void displayMenu3() {
    cout << "1. Chinh sua thong tin xe Oto" << endl;
    cout << "2. Chinh sua thong tin xe May" << endl;
    cout << "3. Chinh sua thong tin xe Tai" << endl;
    cout << "4. Quay lai" << endl;
    cout << "\nNhap lua chon: ";
}
void displayMenu4() {
    cout << "1. Hien thi thong tin xe Oto" << endl;
    cout << "2. Hien thi thong tin xe May" << endl;
    cout << "3. Hien thi thong tin xe Tai" << endl;
    cout << "4. Quay lai" << endl;
    cout << "\nNhap lua chon: ";
}
// Hàm xử lý menu thêm (case 1)
void handleAddMenu(vector<XeOto>& vtXeOto, vector<XeMay>& vtXeMay, vector<XeTai>& vtXeTai) {
    bool validInput = false;
    int inputSubMenu;
    while (!validInput) {
        cout << endl;
        displayMenu1();
        cin >> inputSubMenu;

        if (cin.fail()) {
            cout << "Loi, xin vui long thu lai" << endl;
            clearInput();
            continue;
        }

        switch (inputSubMenu) {
            case 1: {
                addVehicle(vtXeOto, "Xe Oto");
                validInput = true;
                break;
            }
            case 2: {
                addVehicle(vtXeMay, "Xe May");
                validInput = true;
                break;
            }
            case 3: {
                addVehicle(vtXeTai, "Xe Tai");
                validInput = true;
                break;
            }
            case 4: {
                cout << "Quay ve main menu\n" << endl;
                validInput = true;
                break;
            }
            default: {
                cout << "Lua chon khong hop le\n";
                continue;
            }
        }
    }
}
// Hàm xử lý menu xóa (case 2)
void handleDeleteMenu(vector<XeOto>& vtXeOto, vector<XeMay>& vtXeMay, vector<XeTai>& vtXeTai) {
    bool validInput = false;
    int inputSubMenu;
    while (!validInput) {
        cout << endl;
        displayMenu2();
        cin >> inputSubMenu;

        if (cin.fail()) {
            cout << "Loi, xin vui long thu lai" << endl;
            clearInput();
            continue;
        }

        switch (inputSubMenu) {
            case 1: {
                deleteVehicle(vtXeOto);
                validInput = true;
                break;
            }
            case 2: {
                deleteVehicle(vtXeMay);
                validInput = true;
                break;
            }
            case 3: {
                deleteVehicle(vtXeTai);
                validInput = true;
                break;
            }
            case 4: {
                cout << "Quay ve main menu\n" << endl;
                validInput = true;
                break;
            }
            default: {
                cout << "Lua chon khong hop le\n";
                continue;
            }
        }
    }
}
// Hàm xử lý menu chỉnh sửa (case 3)
void handleEditMenu(vector<XeOto>& vtXeOto, vector<XeMay>& vtXeMay, vector<XeTai>& vtXeTai) {
    bool validInput = false;
    int inputSubMenu;
    while (!validInput) {
        cout << endl;
        displayMenu3();
        cin >> inputSubMenu;

        if (cin.fail()) {
            cout << "Loi, xin vui long thu lai" << endl;
            clearInput();
            continue;
        }

        switch (inputSubMenu) {
            case 1: {
                changeVectorInfo(vtXeOto, "Xe Oto");
                validInput = true;
                break;
            }
            case 2: {
                changeVectorInfo(vtXeMay, "Xe May");
                validInput = true;
                break;
            }
            case 3: {
                changeVectorInfo(vtXeTai, "Xe Tai");
                validInput = true;
                break;
            }
            case 4: {
                cout << "Quay ve main menu\n" << endl;
                validInput = true;
                break;
            }
            default: {
                cout << "Lua chon khong hop le\n";
                continue;
            }
        }
    }
}
// Hàm xử lý menu hiển thị (case 4)
void handleDisplayMenu(vector<XeOto>& vtXeOto, vector<XeMay>& vtXeMay, vector<XeTai>& vtXeTai) {
    bool validInput = false;
    int inputSubMenu;
    while (!validInput) {
        cout << endl;
        displayMenu4();
        cin >> inputSubMenu;

        if (cin.fail()) {
            cout << "Loi, xin vui long thu lai" << endl;
            clearInput();
            continue;
        }

        switch (inputSubMenu) {
            case 1: {
                displayVehicleVector(vtXeOto);
                validInput = true;
                break;
            }
            case 2: {
                displayVehicleVector(vtXeMay);
                validInput = true;
                break;
            }
            case 3: {
                displayVehicleVector(vtXeTai);
                validInput = true;
                break;
            }
            case 4: {
                cout << "Quay ve main menu\n" << endl;
                validInput = true;
                break;
            }
            default: {
                cout << "Lua chon khong hop le\n";
                continue;
            }
        }
    }
}

int main() {
    vector<XeOto> vtXeOto;
    vector<XeMay> vtXeMay;
    vector<XeTai> vtXeTai;

    int inputMainMenu;
    bool loopSwitch = true;
    while (loopSwitch) {
        displayMainMenu();
        cin >> inputMainMenu;

        if (cin.fail()) {
            cout << "Loi, xin vui long thu lai\n\n";
            clearInput();
            continue;
        }

        switch (inputMainMenu) {
            case 1: {
                handleAddMenu(vtXeOto, vtXeMay, vtXeTai);
                break;
            }
            case 2: {
                handleDeleteMenu(vtXeOto, vtXeMay, vtXeTai);
                break;
            }
            case 3: {
                handleEditMenu(vtXeOto, vtXeMay, vtXeTai);
                break;
            }
            case 4: {
                handleDisplayMenu(vtXeOto, vtXeMay, vtXeTai);
                break;
            }
            case 5: {
                cout << "Ket thuc chuong trinh" << endl;
                loopSwitch = false;
                break;
            }
            default: {
                cout << "du lieu khong hop le" << endl;
                break;
            }
        }
    }
    return 0;
}