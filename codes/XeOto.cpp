#include <iostream>
#include <limits>
#include "PhuongTien.cpp"
using namespace std;

class XeOto : public PhuongTien {
private:
    int soChoNgoi;
    string kieuDang;
public:
    XeOto() : soChoNgoi(-1), kieuDang("Invalid") {}
    XeOto(string bienSo, string hangSanXuat, int namSanXuat, int choNgoi, string kieuDang)
        : PhuongTien(bienSo, hangSanXuat, namSanXuat), soChoNgoi(choNgoi), kieuDang(kieuDang) {}

    int getSoChoNgoi() const {
        return soChoNgoi;
    }
    string getKieuDang() const {
        return kieuDang;
    }
    void setSoChoNgoi(int choNgoi) {
        this->soChoNgoi = choNgoi;
    }
    void setKieuDang(string kieuDang) {
        this->kieuDang = kieuDang;
    }

    void HienThiThongTin() const override {
        PhuongTien::HienThiThongTin();
        cout << "So Cho Ngoi: " << soChoNgoi << " nguoi" << endl;
        cout << "Kieu dang: " << kieuDang << endl;
        cout << "Phi bao tri: " << formatNumber(TinhPhiBaoTri()) << " vnd/nam" << endl;
    }
    double TinhPhiBaoTri() const override{
        // https://dailyxetaihyundai.vn/tin-tuc-su-kien/muc-phi-bao-tri-duong-bo-cho-xe-o-to-xe-ban-tai-xe-tai-moi-nhat-2018.html
        // lấy value 1 năm:
        if (soChoNgoi < 0){
            return 0;
        }
        if (soChoNgoi < 10){
            return 2160000;
        }
        if (soChoNgoi < 25){
            return 3240000;
        }
        if (soChoNgoi < 40){
            return 4680000;
        }
        if (soChoNgoi >= 40){
            return 7080000;
        }
        return -1;
    }
    friend ostream& operator<<(ostream& os, const XeOto& xeOto){
        xeOto.PhuongTien::HienThiThongTin();
        os << "So Cho Ngoi: " << xeOto.soChoNgoi << " nguoi" << endl;
        os << "Kieu dang: " << xeOto.kieuDang << endl;
        os << "Phi bao tri: " << xeOto.formatNumber(xeOto.TinhPhiBaoTri()) << " vnd/nam" << endl;
        return os;
    }
    friend istream& operator>>(istream& is, XeOto& xeOto){
        string bienSo, hangSanXuat, kieuDang; 
        int namSanXuat, soChoNgoi;

        cout << "Nhap bien so xe: "; is.ignore(); getline(is, bienSo);
        xeOto.setBienSo(bienSo);
        cout << "Nhap hang san xuat: "; getline(is, hangSanXuat);
        xeOto.setHangSanXuat(hangSanXuat);
        cout << "Nhap nam san xuat: ";  
        while (true) {
            is >> namSanXuat;
            if (is.fail() || namSanXuat < 0) {
                cout << "Loi, xin vui long nhap lai nam san xuat: ";
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
            } 
            else {
                xeOto.setNamSanXuat(namSanXuat);
                break;
            }
        }
        cout << "Nhap so cho ngoi: ";
        while (true) {
            is >> soChoNgoi;
            if (is.fail() || soChoNgoi < 0) {
                cout << "Loi, xin vui long nhap lai so cho ngoi: ";
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
            } 
            else {
                xeOto.setSoChoNgoi(soChoNgoi);
                break;
            }
        }
        cout << "Nhap kieu dang: "; is.ignore(); getline(is, kieuDang); 
        xeOto.setKieuDang(kieuDang);

        return is;
    }

};
