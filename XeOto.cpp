#include <iostream>
#include "PhuongTien.cpp"
using namespace std;

class XeOto : public PhuongTien {
private:
    int soChoNgoi;
    string kieuDang;
public:
    XeOto() {}
    XeOto(string bienSo, string hangSanXuat, int namSanXuat, int choNgoi, string kieuDang)
        : PhuongTien(bienSo, hangSanXuat, namSanXuat), soChoNgoi(choNgoi), kieuDang(kieuDang) {}

    int getSoChoNgoi() {
        return soChoNgoi;
    }
    string getKieuDang() {
        return kieuDang;
    }
    void setSoChoNgoi(int choNgoi) {
        this->soChoNgoi = choNgoi;
    }
    void setKieuDang(string kieuDang) {
        this->kieuDang = kieuDang;
    }

    void HienThiThongTin() override {

    }
    double TinhPhiBaoTri() override {

    }
    friend ostream& operator<< (ostream& os, XeOto& xeOto){
        // output cho 5 biến
        return os;
    }
    friend istream& operator>> (istream& is, XeOto& xeOto) {
        // Input cho 5 biến
        return is;
    }

};
