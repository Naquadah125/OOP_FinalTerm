#include <iostream>
#include "PhuongTien.cpp"
#include "XeOto.cpp"
#include "XeMay.cpp"
#include "XeTai.cpp"
using namespace std;

void TestPhiBaoTri() {
    // Test XeOto
    cout << "=== Test PhiBaoTri XeOto ===" << endl;
    XeOto oto1("51H-12345", "Toyota", 2020, 7, "Sedan"); // < 10 chỗ
    cout << "So cho ngoi: 7, Phi bao tri: " << oto1.formatNumber(oto1.TinhPhiBaoTri()) << " vnd/nam" << endl;
    XeOto oto2("51H-67890", "Honda", 2021, 15, "Minibus"); // 10-24 chỗ
    cout << "So cho ngoi: 15, Phi bao tri: " << oto2.formatNumber(oto2.TinhPhiBaoTri()) << " vnd/nam" << endl;
    XeOto oto3("51H-54321", "Ford", 2019, 30, "Bus"); // 25-39 chỗ
    cout << "So cho ngoi: 30, Phi bao tri: " << oto3.formatNumber(oto3.TinhPhiBaoTri()) << " vnd/nam" << endl;
    XeOto oto4("51H-09876", "Mercedes", 2022, 45, "Coach"); // >= 40 chỗ
    cout << "So cho ngoi: 45, Phi bao tri: " << oto4.formatNumber(oto4.TinhPhiBaoTri()) << " vnd/nam" << endl;
    XeOto oto5; // Mặc định: -1 chỗ
    cout << "So cho ngoi: -1, Phi bao tri: " << oto5.formatNumber(oto5.TinhPhiBaoTri()) << " vnd/nam" << endl;

    // Test XeMay
    cout << "\n=== Test PhiBaoTri XeMay ===" << endl;
    XeMay may1("59P1-12345", "Honda", 2019, 50); // < 70cc
    cout << "Dung tich: 50cc, Phi bao tri: " << may1.formatNumber(may1.TinhPhiBaoTri()) << " vnd/nam" << endl;
    XeMay may2("59P1-67890", "Yamaha", 2020, 90); // 70-99cc
    cout << "Dung tich: 90cc, Phi bao tri: " << may2.formatNumber(may2.TinhPhiBaoTri()) << " vnd/nam" << endl;
    XeMay may3("59P1-54321", "Suzuki", 2021, 150); // 100-174cc
    cout << "Dung tich: 150cc, Phi bao tri: " << may3.formatNumber(may3.TinhPhiBaoTri()) << " vnd/nam" << endl;
    XeMay may4("59P1-09876", "Kawasaki", 2022, 200); // >= 175cc
    cout << "Dung tich: 200cc, Phi bao tri: " << may4.formatNumber(may4.TinhPhiBaoTri()) << " vnd/nam" << endl;
    XeMay may5; // Mặc định: -1cc
    cout << "Dung tich: -1cc, Phi bao tri: " << may5.formatNumber(may5.TinhPhiBaoTri()) << " vnd/nam" << endl;

    // Test XeTai
    cout << "\n=== Test PhiBaoTri XeTai ===" << endl;
    XeTai tai1("51C-12345", "Hyundai", 2020, 3.5); // < 4 tấn
    cout << "Tai trong: 3.5 tan, Phi bao tri: " << tai1.formatNumber(tai1.TinhPhiBaoTri()) << " vnd/nam" << endl;
    XeTai tai2("51C-67890", "Isuzu", 2021, 7.0); // 4-8.4 tấn
    cout << "Tai trong: 7.0 tan, Phi bao tri: " << tai2.formatNumber(tai2.TinhPhiBaoTri()) << " vnd/nam" << endl;
    XeTai tai3("51C-54321", "Hino", 2019, 12.0); // 8.5-12.9 tấn
    cout << "Tai trong: 12.0 tan, Phi bao tri: " << tai3.formatNumber(tai3.TinhPhiBaoTri()) << " vnd/nam" << endl;
    XeTai tai4("51C-09876", "Volvo", 2022, 18.0); // 13-18.9 tấn
    cout << "Tai trong: 18.0 tan, Phi bao tri: " << tai4.formatNumber(tai4.TinhPhiBaoTri()) << " vnd/nam" << endl;
    XeTai tai5("51C-11111", "Scania", 2023, 30.0); // >= 27 tấn
    cout << "Tai trong: 30.0 tan, Phi bao tri: " << tai5.formatNumber(tai5.TinhPhiBaoTri()) << " vnd/nam" << endl;
    XeTai tai6; // Mặc định: -1 tấn
    cout << "Tai trong: -1 tan, Phi bao tri: " << tai6.formatNumber(tai6.TinhPhiBaoTri()) << " vnd/nam" << endl;
}

int main() {
    TestPhiBaoTri();
    return 0;
}