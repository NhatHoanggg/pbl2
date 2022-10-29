#include "khach.h"
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>


using namespace std;

guest::guest() {

}

guest::~guest() {

}


// PHIM 1; 
void guest::getInfo1(int t,room &x) {
    system("cls");
    cout << "\t\t" << "Minions: The Rise of Gru" << endl;
    cout << "\t\t+=============================================================+" << endl;
    cout << "\t\t|               ** LICH CHIEU TRONG NGAY **                   |" << endl;
    cout << "\t\t+======================+======================+===============+" << endl;
    cout << "\t\t|    Gio Bat Dau       |    So Ghe Trong      |    Ma Phong   |" << endl;
    cout << "\t\t+======================+======================+===============+" << endl;
    cout << setw(30) <<  "9h" << setw(22) << x.count(1) << setw(20) << "R1" << endl;
    cout << setw(30) << "18h" << setw(22) << x.count(16) << setw(20) << "R4" << endl;
    cout << setw(30) << "21h" << setw(22) << x.count(19) << setw(20) << "R3" << endl;
	cout << "\t\tHo Ten Khach Hang: "; 
	cin.ignore();
	getline(cin, name);
    cout << "\t\tSo dien thoai: ";
	getline(cin, phone);
    cout << "\t\tNhap suat xem: "; 
    getline(cin, time);
	cout << "\t\tNhap so ve muon mua ";
    cin >> num;   
    int n{};
    if (time == "9h") {
        n = 1;
        x.show(1);
    }

    if (time == "18h") {
        n = 16;
        x.show(16);
    }
    if (time == "21h") {
        n = 19;
        x.show(19);
    }
    //x.show(n);
    for (int i = 0; i < num; i++) {
        cout << "\t\t\tNhap vi tri cho ngoi thu " << i + 1 << ": ";

        if (i == 0) cin.ignore();
        else fflush(stdin);
        getline(cin, p[i]);

        p[i][0] = toupper(p[i][0]);
        h = int(p[i][0]) - 65;
        c = int(p[i][1]) - 49;

        if (p[i].length() == 3)
            c = 9;
        x.update(n, h, c);

    }
    
    cout << "\t\t\t -> So tien phai tra : " << 50000 * num << "VND" << endl; 
}

//PHIM2;
void guest::getInfo2(int t, room &x) {

    cout << "\t\t" << "Bong Dung Trung So  " << endl;
    cout << "\t\t+=============================================================+" << endl;
    cout << "\t\t|               ** LICH CHIEU TRONG NGAY **                   |" << endl;
    cout << "\t\t+======================+======================+===============+" << endl;
    cout << "\t\t|    Gio Bat Dau       |    So Ghe Trong      |    Ma Phong   |" << endl;
    cout << "\t\t+======================+======================+===============+" << endl;
    cout << setw(30) << "9h" << setw(22) << x.count(2) << setw(20) << "R2" << endl;
    cout << setw(30) << "11h" << setw(22) << x.count(5) << setw(20) << "R1" << endl;
    cout << setw(30) << "21h" << setw(22) << x.count(20) << setw(20) << "R4" << endl;
    cout << "\t\tHo Ten Khach Hang: ";
    cin.ignore();
    getline(cin, name);
    cout << "\t\tSo dien thoai: ";
    getline(cin, phone);
    cout << "\t\tNhap suat xem: ";
    getline(cin, time);
    cout << "\t\tNhap so ve muon mua ";
    cin >> num;
    int n;
    if (time == "9h") {
        n = 1;
        x.show(2);
    }
    if (time == "11h") {
        n = 2;
        x.show(5);
    }
    if (time == "21h") {
        n = 3;
        x.show(20);
    }

    //x.show(n);
    for (int i = 0; i < num; i++) {
        cout << "\t\t\tNhap vi tri cho ngoi thu " << i + 1 << ": ";

        if (i == 0) cin.ignore();
        else fflush(stdin);
        getline(cin, p[i]);

        p[i][0] = toupper(p[i][0]);
        h = int(p[i][0]) - 65;
        c = int(p[i][1]) - 49;
        cout << h << " " << c << endl;
        if (p[i].length() == 3)
            c = 9;
        x.update(n, h, c);
    }
}


//PHIM3 
void guest::getInfo3(int t, room &x) {

    cout << "\t\t" << "Black Adam   " << endl;
    cout << "\t\t+=============================================================+" << endl;
    cout << "\t\t|               ** LICH CHIEU TRONG NGAY **                   |" << endl;
    cout << "\t\t+======================+======================+===============+" << endl;
    cout << "\t\t|    Gio Bat Dau       |    So Ghe Trong      |    Ma Phong   |" << endl;
    cout << "\t\t+======================+======================+===============+" << endl;
    cout << setw(30) << "9h" << setw(22) << x.count(3) << setw(20) << "R3" << endl;
    cout << setw(30) << "11h" << setw(22) << x.count(6) << setw(20) << "R2" << endl;
    cout << setw(30) << "15h" << setw(22) << x.count(9) << setw(20) << "R1" << endl;
    cout << "\t\tHo Ten Khach Hang: ";
    cin.ignore();
    getline(cin, name);
    cout << "\t\tSo dien thoai: ";
    getline(cin, phone);
    cout << "\t\tNhap suat xem: ";
    getline(cin, time);
    cout << "\t\tNhap so ve muon mua ";
    cin >> num;
    int n;
    if (time == "9h") {
        n = 1;
        x.show(3);
    }
    if (time == "11h") {
        n = 2;
        x.show(6);
    }
    if (time == "15h") {
        n = 3;
        x.show(9);
    }

    //x.show(n);
    for (int i = 0; i < num; i++) {
        cout << "\t\t\tNhap vi tri cho ngoi thu " << i + 1 << ": ";

        if (i == 0) cin.ignore();
        else fflush(stdin);
        getline(cin, p[i]);

        p[i][0] = toupper(p[i][0]);
        h = int(p[i][0]) - 65;
        c = int(p[i][1]) - 49;
        cout << h << " " << c << endl;
        if (p[i].length() == 3)
            c = 9;
        x.update(n, h, c);
    }
}


// PHIM 4
void guest::getInfo4(int t, room &x) {

    cout << "\t\t" << "Quai Vat Song Mekong   " << endl;
    cout << "\t\t+=============================================================+" << endl;
    cout << "\t\t|               ** LICH CHIEU TRONG NGAY **                   |" << endl;
    cout << "\t\t+======================+======================+===============+" << endl;
    cout << "\t\t|    Gio Bat Dau       |    So Ghe Trong      |    Ma Phong   |" << endl;
    cout << "\t\t+======================+======================+===============+" << endl;
    cout << setw(30) << "9h" << setw(22) << x.count(4) << setw(20) << "R4" << endl;
    cout << setw(30) << "11h" << setw(22) << x.count(7) << setw(20) << "R3" << endl;
    cout << setw(30) << "15h" << setw(22) << x.count(10) << setw(20) << "R2" << endl;
    cout << setw(30) << "18h" << setw(22) << x.count(13) << setw(20) << "R1" << endl;
    cout << "\t\tHo Ten Khach Hang: ";
    cin.ignore();
    getline(cin, name);
    cout << "\t\tSo dien thoai: ";
    getline(cin, phone);
    cout << "\t\tNhap suat xem: ";
    getline(cin, time);
    cout << "\t\tNhap so ve muon mua ";
    cin >> num;
    int n;
    if (time == "9h") {
        n = 1;
        x.show(4);
    }
    if (time == "11h") {
        n = 2;
        x.show(7);
    }
    if (time == "15h") {
        n = 3;
        x.show(10);
    }
    if (time == "18h") {
        n = 4;
        x.show(13);
    }

    //x.show(n);
    for (int i = 0; i < num; i++) {
        cout << "\t\t\tNhap vi tri cho ngoi thu " << i + 1 << ": ";

        if (i == 0) cin.ignore();
        else fflush(stdin);
        getline(cin, p[i]);

        p[i][0] = toupper(p[i][0]);
        h = int(p[i][0]) - 65;
        c = int(p[i][1]) - 49;
        cout << h << " " << c << endl;
        if (p[i].length() == 3)
            c = 9;
        x.update(n, h, c);
    }
}

//PHIM5
void guest::getInfo5(int t, room &x) {

    cout << "\t\t" << "Co Gai Tu Qua Khu     " << endl;
    cout << "\t\t+=============================================================+" << endl;
    cout << "\t\t|               ** LICH CHIEU TRONG NGAY **                   |" << endl;
    cout << "\t\t+======================+======================+===============+" << endl;
    cout << "\t\t|    Gio Bat Dau       |    So Ghe Trong      |    Ma Phong   |" << endl;
    cout << "\t\t+======================+======================+===============+" << endl;
    cout << setw(30) << "11h" << setw(22) << x.count(8) << setw(20) << "R4" << endl;
    cout << setw(30) << "15h" << setw(22) << x.count(11) << setw(20) << "R3" << endl;
    cout << setw(30) << "18h" << setw(22) << x.count(14) << setw(20) << "R2" << endl;
    cout << setw(30) << "21h" << setw(22) << x.count(17) << setw(20) << "R1" << endl;
    cout << "\t\tHo Ten Khach Hang: ";
    cin.ignore();
    getline(cin, name);
    cout << "\t\tSo dien thoai: ";
    getline(cin, phone);
    cout << "\t\tNhap suat xem: ";
    getline(cin, time);
    cout << "\t\tNhap so ve muon mua ";
    cin >> num;
    int n;
    if (time == "11h") {
        n = 1;
        x.show(8);
    }
    if (time == "15h") {
        n = 2;
        x.show(11);
    }
    if (time == "18h") {
        n = 3;
        x.show(14);
    }
    if (time == "21h") {
        n = 4;
        x.show(17);
    }
    //x.show(n);
    for (int i = 0; i < num; i++) {
        cout << "\t\t\tNhap vi tri cho ngoi thu " << i + 1 << ": ";

        if (i == 0) cin.ignore();
        else fflush(stdin);
        getline(cin, p[i]);

        p[i][0] = toupper(p[i][0]);
        h = int(p[i][0]) - 65;
        c = int(p[i][1]) - 49;
        cout << h << " " << c << endl;
        if (p[i].length() == 3)
            c = 9;
        x.update(n, h, c);
    }
}


//PHIM6
void guest::getInfo6(int t, room &x) {

    cout << "\t\t" << "Mon Phai Vo Meo     " << endl;
    cout << "\t\t+=============================================================+" << endl;
    cout << "\t\t|               ** LICH CHIEU TRONG NGAY **                   |" << endl;
    cout << "\t\t+======================+======================+===============+" << endl;
    cout << "\t\t|    Gio Bat Dau       |    So Ghe Trong      |    Ma Phong   |" << endl;
    cout << "\t\t+======================+======================+===============+" << endl;
    cout << setw(30) << "15h" << setw(22) << x.count(12) << setw(20) << "R4" << endl;
    cout << setw(30) << "18h" << setw(22) << x.count(15) << setw(20) << "R3" << endl;
    cout << setw(30) << "21h" << setw(22) << x.count(18) << setw(20) << "R2" << endl;
    cout << "\t\tHo Ten Khach Hang: ";
    cin.ignore();
    getline(cin, name);
    cout << "\t\tSo dien thoai: ";
    getline(cin, phone);
    cout << "\t\tNhap suat xem: ";
    getline(cin, time);
    cout << "\t\tNhap so ve muon mua ";
    cin >> num;
    int n;
    if (time == "15h") {
        n = 1;
        x.show(12);
    }
    if (time == "18h") {
        n = 2;
        x.show(15);
    }
    if (time == "21h") {
        n = 3;
        x.show(18);
    }

    //x.show(n);
    for (int i = 0; i < num; i++) {
        cout << "\t\t\tNhap vi tri cho ngoi thu " << i + 1 << ": ";

        if (i == 0) cin.ignore();
        else fflush(stdin);
        getline(cin, p[i]);

        p[i][0] = toupper(p[i][0]);
        h = int(p[i][0]) - 65;
        c = int(p[i][1]) - 49;
        cout << h << " " << c << endl;
        if (p[i].length() == 3)
            c = 9;
        x.update(n, h, c);
    }
    
}


void guest::bill() {
    
}