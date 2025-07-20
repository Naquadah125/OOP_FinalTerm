#include <iostream>
#include <limits>
#include "PhuongTien.cpp"
using namespace std;

class XeTai : public PhuongTien {
private:
    double taiTrong; // tấn
public:
    XeTai() : taiTrong(-1) {}
    XeTai(string bienSo, string hangSanXuat, int namSanXuat, double taiTrong)
        : PhuongTien(bienSo, hangSanXuat, namSanXuat), taiTrong(taiTrong) {}
    
    double getTaiTrong() const {
        return taiTrong;
    }
    void setTaiTrong(double taiTrong) {
        this->taiTrong = taiTrong;
    }

    void HienThiThongTin() override {
        PhuongTien::HienThiThongTin();
        cout << "Tai trong: " << taiTrong << endl;
        cout << "Phi bao tri: " << formatNumber(TinhPhiBaoTri()) << " vnd/nam" << endl;
    }
    double TinhPhiBaoTri() override {
        // https://thuvienphapluat.vn/ma-so-thue/bai-viet/hien-hanh-muc-thu-phi-duong-bo-doi-voi-xe-tai-la-bao-nhieu-xe-nao-khong-phai-chiu-phi-duong-bo-theo-549935-193612.html
        // lấy value 1 năm
        if (taiTrong < 0){
            return 0;
        }
        if (taiTrong < 4){
            return 180000 * 12;
        }
        if (taiTrong < 8.5){
            return 270000 * 12;
        }
        if (taiTrong < 13){
            return 390000 * 12;
        }
        if (taiTrong < 19){
            return 590000 * 12;
        }
        if (taiTrong < 27){
            return 720000 * 12;
        }
        if (taiTrong >= 27){
            return 1040000 * 12;
        }
        return -1;
    }
    friend ostream& operator<<(ostream& os, XeTai& xeTai) {
        xeTai.PhuongTien::HienThiThongTin();
        os << "Tai trong: " << xeTai.taiTrong << " tan"<< endl;
        os << "Phi bao tri: " << xeTai.formatNumber(xeTai.TinhPhiBaoTri()) << " vnd/nam" << endl;
        return os;
    }
    friend istream& operator>>(istream& is, XeTai& xeTai) {
        string bienSo, hangSanXuat; 
        int namSanXuat, taiTrong;

        cout << "Nhap bien so xe: "; is >> bienSo;
        xeTai.setBienSo(bienSo);
        cout << "Nhap hang san xuat: "; is >> hangSanXuat;
        xeTai.setHangSanXuat(hangSanXuat);
        cout << "Nhap nam san xuat: ";
        while (true) {
            is >> namSanXuat;
            if (is.fail() || namSanXuat < 0) {
                cout << "Loi, xin vui long nhap lai nam san xuat: ";
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                xeTai.setNamSanXuat(namSanXuat);
                break;
            }
        }
        cout << "Nhap tai trong: ";
        while (true) {
            is >> taiTrong;
            if (is.fail() || taiTrong < 0) {
                cout << "Loi, xin vui long nhap lai tai trong: ";
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                xeTai.setTaiTrong(taiTrong);
                break;
            }
        }

        return is;
    }

};