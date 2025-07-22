#include <iostream>
#include <limits>
#include "PhuongTien.cpp"
using namespace std;

class XeMay : public PhuongTien {
private:
    int dungTich;
public:
    XeMay() : dungTich(-1) {}
    XeMay(string bienSo, string hangSanXuat, int namSanXuat, int dungTich)
        : PhuongTien(bienSo, hangSanXuat, namSanXuat), dungTich(dungTich) {}
    
    int getDungTich() const {
        return dungTich;
    }
    void setDungTich(int dungTich) {
        this->dungTich = dungTich;
    }

    void HienThiThongTin() const override {
        PhuongTien::HienThiThongTin();
        cout << "Dung tich: " << dungTich << endl;
        cout << "Phi bao tri: " << formatNumber(TinhPhiBaoTri()) << " vnd/nam" << endl;
    }
    double TinhPhiBaoTri() const  override {
        // https://vnexpress.net/xe-may-se-dong-phi-bao-tri-toi-da-180-000-dong-moi-nam-2227621.html
        // dùng value(1 năm) là dung tích xylanh với môtô
        if (dungTich < 0){
            return 0;
        }
        if (dungTich < 70){
            return 90000;
        }
        if (dungTich < 100){
            return 110000;
        }
        if (dungTich < 175){
            return 135000;
        }
        if (dungTich >= 175){
            return 170000;
        }
        return -1;
    }
    friend ostream& operator<<(ostream& os, const XeMay& xeMay) {
        xeMay.PhuongTien::HienThiThongTin();
        os << "Dung tich: " << xeMay.dungTich << "cc" << endl;
        os << "Phi bao tri: " << xeMay.formatNumber(xeMay.TinhPhiBaoTri()) << " vnd/nam" << endl;
        return os;
    }
    friend istream& operator>>(istream& is, XeMay& xeMay) {
        string bienSo, hangSanXuat; 
        int namSanXuat, dungTich;

        cout << "Nhap bien so xe: "; is.ignore(); getline(is, bienSo);
        xeMay.setBienSo(bienSo);
        cout << "Nhap hang san xuat: "; getline(is, hangSanXuat);
        xeMay.setHangSanXuat(hangSanXuat);
        cout << "Nhap nam san xuat: ";
        while (true) { //ng dùng nhập sai, sẽ nhập lại
            is >> namSanXuat;
            if (is.fail() || namSanXuat < 0) {
                cout << "Loi, xin vui long nhap lai nam san xuat: ";
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
            } 
            else {
                xeMay.setNamSanXuat(namSanXuat);
                break;
            }
        }
        cout << "Nhap dung tich: ";
        while (true) {  //ng dùng nhập sai, sẽ nhập lại
            is >> dungTich;
            if (is.fail() || dungTich < 0) {
                cout << "Loi, xin vui long nhap lai dung tich: ";
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
            } 
            else {
                xeMay.setDungTich(dungTich);
                break;
            }
        }

        return is;
    }

};