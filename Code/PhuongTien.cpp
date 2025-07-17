#pragma once
#include <iostream>
using namespace std;

class PhuongTien {
private:
    string bienSo;
    string hangSanXuat;
    int namSanXuat;
public:
    PhuongTien() {}
    PhuongTien(string bienSo, string hangSanXuat, int namSanXuat) 
        : bienSo(bienSo), hangSanXuat(hangSanXuat), namSanXuat(namSanXuat) {}
    virtual ~PhuongTien() {}

    string getBienSo()  {
        return bienSo;
    }
    string getHangSanXuat()  {
        return hangSanXuat;
    }
    int getNamSanXuat()  {
        return namSanXuat;
    }
    void setBienSo(string bienSo) {
        this->bienSo = bienSo;
    }
    void setHangSanXuat(string hangSanXuat) {
        this->hangSanXuat = hangSanXuat;
    }
    void setNamSanXuat(int namSanXuat) {
        this->namSanXuat = namSanXuat;
    }

    virtual void HienThiThongTin() {
        cout << "Bien so: " << bienSo << endl;
        cout << "Hang san xuat: " << hangSanXuat << endl;
        cout << "Nam san xuat: " << namSanXuat << endl;
    }
    virtual double TinhPhiBaoTri() = 0;

};