#include <iostream>
#include "PhuongTien.cpp"
using namespace std;

class XeTai : public PhuongTien {
private:
    double taiTrong;
public:
    XeTai() {}
    XeTai(string bienSo, string hangSanXuat, int namSanXuat, double taiTrong)
        : PhuongTien(bienSo, hangSanXuat, namSanXuat), taiTrong(taiTrong) {}
    
    double getTaiTrong() {
        return taiTrong;
    }
    void setTaiTrong(double taiTrong) {
        this->taiTrong = taiTrong;
    }

    void HienThiThongTin() override {

    }
    double TinhPhiBaoTri() override {
        return 0.0;
    }
    // friend ostream& operator<< (ostream& os, XeTai& xeTai) {
    //     // output cho 4 biến
    //     return os;
    // }
    // friend istream& operator>> (istream& is, XeTai& xeTai) {
    //     // Input cho 4 biến
    //     return is;
    // }

};