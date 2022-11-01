#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "khach.h"

using namespace std;

room x;
film f;
int n;

void banve() {
    f.dsphim();
    fstream g;
    guest k;
    k.getInfo(f,x);
    system("pause");
}

void khachhang() {
    int stop = 1;
    while (stop != 0) {
    nhap:  // nhap lua chon cua khach hang  . .. .
        int k = 0;
        system("cls");
        cout << "\t\t\tDICH VU KHACH HANG: " << endl << endl;
        cout << "\t\t\tNhap lua chon cua ban: " << endl;
        cout << "\t\t\t\t1:Xem danh sach phim hien dang chieu." << endl;
        cout << "\t\t\t\t2:Xem lich chieu trong ngay." << endl;
        cout << "\t\t\t\t3:Mua ve xem phim." << endl;
        cout << "\t\t\t\t4:Huy ve xem phim." << endl;
        cout << "\t\t\t\t0:Thoat." << endl;
        cout << "\t\t\t\t -> Lua chon cua ban la : ";

        cin >> k; stop = k;
        if (k < 0 || k > 4) {
            cout << "\t\t--Lua chon khong phu hop. Vui long nhap lai!" << endl;
            system("pause");
            goto nhap;
        }
        switch (k) {
        case 1:
            f.dsphim();
            system("pause");
            break;
        case 2:
            f.dstrongngay();
            system("pause");
            break;
        case 3:
            banve();
            break;
        }
    }
} 

void nhanvien() {
    
}


int main()
{
    x.setData();

    char stop = 'N';

    ofstream xoa("khach.txt");
    xoa.close();

    do
    {
        
        nhap:
        system("cls");
        //cout << f.getData() << endl;
        n = f.getData();
        cout << "\t\t\tNHAP LUA CHON CUA BAN: " << endl;
        cout << "\t\t\t\t 1:Khach hang" << endl;
        cout << "\t\t\t\t 2:Nhan vien" << endl;
        cout << "\t\t\t\t -> Lua chon cua ban la : "; 
        int chon; 

        cin >> chon;
        
        if (chon < 1 || chon > 2) {
            cout << "\t\t--Lua chon khong phu hop. Vui long nhap lai!" << endl;
            system("pause");
            goto nhap;
        }

        switch (chon) {
        case 1:
            khachhang();
            break;
        case 2:
            nhanvien();
            break;
        }
        
    cout << "\t\tBAN CO MUON TIEP TUC CHUONG TRINH BAN VE XEM PHIM HAY KHONG? [Y/N]    ";
    cin >> stop;
    stop = toupper(stop); // stop conditions;
    } while (stop == 'Y');

    cout << endl;
    cout << "\t\t______________________________________CHUONG TRINH BAN VE XEM PHIM KET THUC______________________________________________" << endl;

    
    return 0;
}



/*


*/



