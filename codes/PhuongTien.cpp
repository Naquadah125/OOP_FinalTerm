#pragma once
#include <iostream>
#include <string>
using namespace std;

class PhuongTien {
private:
    string bienSo;
    string hangSanXuat;
    int namSanXuat;
public:
    PhuongTien() : bienSo(""), hangSanXuat(""), namSanXuat(1900) {}
    PhuongTien(string bienSo, string hangSanXuat, int namSanXuat) 
        : bienSo(bienSo), hangSanXuat(hangSanXuat), namSanXuat(namSanXuat) {}
    virtual ~PhuongTien() {}

    string getBienSo() const {
        return bienSo;
    }
    string getHangSanXuat() const {
        return hangSanXuat;
    }
    int getNamSanXuat() const {
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

    virtual void HienThiThongTin(){
        cout << "Bien so: " << bienSo << endl;
        cout << "Hang san xuat: " << hangSanXuat << endl;
        cout << "Nam san xuat: " << namSanXuat << endl;
    }
    virtual double TinhPhiBaoTri(){
        return 0.0;
    }
    string formatNumber(int num){
        string s = to_string(num);
        for (int i = s.length() - 3; i > 0; i -= 3) { // Duyệt từ phải qua trái, mỗi 3 ký tự
            s.insert(i, ".");                // Chèn dấu chấm tại vị trí i
        }
        return s;
    }

};