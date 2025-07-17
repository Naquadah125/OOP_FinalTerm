#include <iostream>
#include "PhuongTien.cpp"
using namespace std;

class XeMay : public PhuongTien {
private:
    int congSuat;
public:
    XeMay() {}
    XeMay(string bienSo, string hangSanXuat, int namSanXuat, int congSuat)
        : PhuongTien(bienSo, hangSanXuat, namSanXuat), congSuat(congSuat) {}
    
    int getCongSuat() {
        return congSuat;
    }
    void setCongSuat(int congSuat) {
        this->congSuat = congSuat;
    }

    void HienThiThongTin() override {

    }
    double TinhPhiBaoTri() override {
        return 0.0;
    }
    // friend ostream& operator<< (ostream& os, XeMay& xeMay) {
    //     // output cho 4 biến
    //     return os;
    // }
    // friend istream& operator>> (istream& is, XeMay& xeMay) {
    //     // Input cho 4 biến
    //     return is;
    // }

};