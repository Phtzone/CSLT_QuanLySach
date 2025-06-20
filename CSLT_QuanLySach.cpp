#include <iostream>
#include <string>

using namespace std;

struct Sach {
    int soThuTu;
    string maSach;
    string tenMatHang;
    int soLuongTonKho;
    double donGia;
    double thanhTien;
    double donGiaBan;
};

Sach danhSachSach[100];
int soLuongSach = 0;

bool kiemTraMaSach(const string& maSach) {
    for (int i = 0; i < soLuongSach; i++) {
        if (danhSachSach[i].maSach == maSach) {
            return true;
        }
    }
    return false;
}

void NhapSach() {
    int n;
    cout << "Nhap so luong sach: ";
    cin >> n;
    cin.ignore(); // Loai bo ky tu xuong dong trong bo dem

    for (int i = 0; i < n; i++) {
        Sach s;
        s.soThuTu = soLuongSach + 1;
        cout << "\nNhap thong tin sach thu " << s.soThuTu << ":\n";

        do {
            cout << "Ma sach: ";
            getline(cin, s.maSach);
            if (kiemTraMaSach(s.maSach)) {
                cout << "Ma sach da ton tai, vui long nhap lai!\n";
            }
        } while (kiemTraMaSach(s.maSach));

        cout << "Ten mat hang: ";
        getline(cin, s.tenMatHang);
        cout << "So luong ton kho: ";
        cin >> s.soLuongTonKho;
        cout << "Don gia: ";
        cin >> s.donGia;
        cin.ignore(); // Loai bo ky tu xuong dong

        s.thanhTien = s.soLuongTonKho * s.donGia;
        cout << "Don gia ban: ";
        cin >> s.donGiaBan;
        cin.ignore(); // Loai bo ky tu xuong dong

        danhSachSach[soLuongSach++] = s;
    }
}

void ThemSach() {
    int viTri;
    cout << "\nNhap vi tri muon them sach (tu 1 den " << soLuongSach + 1 << "): ";
    cin >> viTri;
    cin.ignore();

    if (viTri < 1 || viTri > soLuongSach + 1) {
        cout << "Vi tri khong hop le!\n";
        return;
    }

    Sach s;
    cout << "\nNhap thong tin sach moi:\n";

    do {
        cout << "Ma sach: ";
        getline(cin, s.maSach);
        if (kiemTraMaSach(s.maSach)) {
            cout << "Ma sach da ton tai. Cong don so luong va cap nhat thong tin.\n";
            for (int i = 0; i < soLuongSach; i++) {
                if (danhSachSach[i].maSach == s.maSach) {
                    int soLuongMoi;
                    double donGiaMoi;

                    cout << "So luong nhap moi: ";
                    cin >> soLuongMoi;
                    cout << "Don gia nhap moi: ";
                    cin >> donGiaMoi;
                    cin.ignore();

                    danhSachSach[i].soLuongTonKho += soLuongMoi;
                    danhSachSach[i].donGia = (danhSachSach[i].donGia * danhSachSach[i].soLuongTonKho + donGiaMoi * soLuongMoi) / (danhSachSach[i].soLuongTonKho + soLuongMoi);
                    danhSachSach[i].thanhTien = danhSachSach[i].soLuongTonKho * danhSachSach[i].donGia;

                    cout << "Da cap nhat thanh cong!\n";
                    return;
                }
            }
        }
    } while (false);

    cout << "Ten mat hang: ";
    getline(cin, s.tenMatHang);
    cout << "So luong ton kho: ";
    cin >> s.soLuongTonKho;
    cout << "Don gia: ";
    cin >> s.donGia;
    cin.ignore();

    s.thanhTien = s.soLuongTonKho * s.donGia;
    cout << "Don gia ban: ";
    cin >> s.donGiaBan;
    cin.ignore();

    for (int i = soLuongSach; i >= viTri; i--) {
        danhSachSach[i] = danhSachSach[i - 1];
    }
    s.soThuTu = viTri;
    danhSachSach[viTri - 1] = s;
    soLuongSach++;

    for (int i = viTri; i < soLuongSach; i++) {
        danhSachSach[i].soThuTu = i + 1;
    }

    cout << "\nThem sach thanh cong!" << endl;
}

void XoaSach() {
    string maSach;
    cin.ignore();
    cout << "\nNhap ma sach can xoa: ";
    getline(cin, maSach);

    bool found = false;
    for (int i = 0; i < soLuongSach; i++) {
        if (danhSachSach[i].maSach == maSach) {
            for (int j = i; j < soLuongSach - 1; j++) {
                danhSachSach[j] = danhSachSach[j + 1];
            }
            soLuongSach--;
            found = true;
            break;
        }
    }

    if (found) {
        cout << "\nXoa sach thanh cong!" << endl;
    }
    else {
        cout << "\nKhong tim thay sach!" << endl;
    }
}

void SapXepDanhSach() {
    for (int i = 0; i < soLuongSach - 1; i++) {
        for (int j = i + 1; j < soLuongSach; j++) {
            if (danhSachSach[i].donGia > danhSachSach[j].donGia) {
                Sach temp = danhSachSach[i];
                danhSachSach[i] = danhSachSach[j];
                danhSachSach[j] = temp;
            }
        }
    }
    cout << "\nSap xep danh sach theo don gia thanh cong!" << endl;
}

void TinhGiaTriTonKho() {
    int tongSoLuong = 0;
    double tongGiaTri = 0;

    for (int i = 0; i < soLuongSach; i++) {
        tongSoLuong += danhSachSach[i].soLuongTonKho;
        tongGiaTri += danhSachSach[i].thanhTien;
    }

    cout << "\nTon kho sach: " << endl;
    cout << "- So luong: " << tongSoLuong << endl;
    cout << "- So tien: " << tongGiaTri << endl;
}

void InDanhSach() {
    cout << "\n===== DANH SACH HANG HOA =====" << endl;
    for (int i = 0; i < soLuongSach; i++) {
        cout << "So thu tu:        " << danhSachSach[i].soThuTu << endl;
        cout << "- Ma sach:          " << danhSachSach[i].maSach;
        cout << "                 "<<"Ten Sach:  " << danhSachSach[i].tenMatHang << endl;
        cout << "- So luong ton kho: " << danhSachSach[i].soLuongTonKho;
        cout << "                 "<<"Don gia:   " << danhSachSach[i].donGia << endl;
        cout << "- Thanh tien:       " << danhSachSach[i].thanhTien << endl;
        cout << "- Don gia ban:      " << danhSachSach[i].donGiaBan << endl;
        cout << "-----------------------------" << endl;
    }
}


int main() {
    int luaChon;
    while (true) {
        cout << "\n===== QUAN LY SACH =====" << endl;
        cout << "1. Nhap danh sach sach" << endl;
        cout << "2. Them sach moi" << endl;
        cout << "3. Xoa sach" << endl;
        cout << "4. Sap xep danh sach theo don gia" << endl;
        cout << "5. Tinh gia tri ton kho" << endl;
        cout << "6. In danh sach" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1:
            NhapSach();
            break;
        case 2:
            ThemSach();
            break;
        case 3:
            XoaSach();
            break;
        case 4:
            SapXepDanhSach();
            break;
        case 5:
            TinhGiaTriTonKho();
            break;
        case 6:
            InDanhSach();
            break;
        case 0:
            cout << "Thoat chuong trinh!" << endl;
            return 0;
        default:
            cout << "Lua chon khong hop le!" << endl;
        }
    }
    return 0;
}
