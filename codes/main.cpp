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
template <typename T>
void addVehicle(vector<T>& vt, const string& typeName) {
    cout << "\nNhap thong tin " << typeName << ": " << endl;
    T xe;
    cin >> xe;

    vt.push_back(xe);
    cout << "Da them " << typeName << " thanh cong\n" << endl;
}
template <typename T>
void deleteVehicle(vector<T>& vt) {
    if (vt.size() == 0) {
        cout << "vector rong, khong the thuc hien xoa\n" << endl;
        return;
    }
    bool isDelete = false;
    while (!isDelete) {
        int choice;
        cout << "Nhap vi tri vector can xoa (1 -> " << vt.size() << ", hoac -1 de quay ve main menu): ";
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
}
template <typename T>
void displayVehicleVector(const vector<T>& vt){
    if (vt.size() == 0) {
        cout << "vector rong, khong the hien thi\n" << endl;
        return;
    }
    for (size_t i = 0; i < vt.size(); i++){
        cout << "Du lieu tai vector " << i << ": " << endl;
        cout << vt[i] << endl;
    }
}
template <typename T>
void changeVectorInfo(vector<T>& vt, string typeName){
    if (vt.size() == 0){
        cout << "vector rong, khong the chinh sua";
        return;
    }
    bool isChange = false;
    while (!isChange){
        cout << "Nhap vi tri can sua chua (tu 1 -> " << vt.size() << ", hoac -1 de quay ve main menu): ";
        int location;
        cin >> location;

        if (cin.fail() || location < -1 || static_cast<size_t>(location) > vt.size()) { 
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
        cout << "Du lieu duoc thay doi thanh cong" << "\n\n";
        isChange = true;
    }
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

int main() {
    vector<XeOto> vtXeOto;
    vector<XeMay> vtXeMay;
    vector<XeTai> vtXeTai;

    int inputMainMenu, inputSubMenu;
    bool loopSwitch = true;
    while (loopSwitch){
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
                        addVehicle(vtXeOto, "Xe Oto");
                        break;
                    }
                    case 2: { // Them xe may
                        addVehicle(vtXeMay, "Xe May");
                        break;
                    } 
                    case 3: { // hem xe tai
                        addVehicle(vtXeTai, "Xe Oto");
                        break;
                    }
                    case 4:{
                        cout << "Quay ve main menu\n" << endl;
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
                        deleteVehicle(vtXeOto);
                        break;
                    }

                    case 2: { // Xoa xe May
                        deleteVehicle(vtXeMay);
                        break;
                    }

                    case 3: { // xoa xe Tai
                        deleteVehicle(vtXeTai);
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
                break;
            }

            case 3:{
                cout << endl;
                displayMenu3();
                cin >> inputSubMenu;

                switch(inputSubMenu){
                    case 1: {
                        changeVectorInfo(vtXeOto, "Xe Oto");
                        break;
                    }
                    case 2: {
                        changeVectorInfo(vtXeMay, "Xe May");
                        break;
                    }
                    case 3: {
                        changeVectorInfo(vtXeTai, "Xe Tai");
                        break;
                    }
                    case 4: {
                        cout << "Quay ve main menu\n" << endl;
                        break;
                    }
                    default:{   
                        cout << "Lua chon khong hop le\n" << endl;
                        break;
                    }
                }
                break;
            }

            case 4:{
                cout << endl;
                displayMenu4();
                cin >> inputSubMenu;  cout << endl;

                switch (inputSubMenu){
                    case 1: { //Hien thi vector Xe Oto
                        displayVehicleVector(vtXeOto);
                        break;
                    }
                    case 2: { //Hien thi vector Xe May
                        displayVehicleVector(vtXeMay);
                        break;
                    }
                    case 3: { //Hien thi vector Xe Tai
                        displayVehicleVector(vtXeTai);
                        break;
                    }
                    case 4: { 
                        cout << "Quay ve main menu\n" << endl;
                        break;
                    }
                    default:{   
                        cout << "Lua chon khong hop le\n" << endl;
                        break;
                    }
                }
                break;
            }

            case 5:{
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