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

void guest::getName() {
	cout << "\t\t\t\tHo Ten Khach Hang: ";
	cin.ignore();
	getline(cin, name);
}

void guest::getSDT() {

nhap:
	cout << "\t\t\t\tNhap so dien thoai : ";
	getline(cin, phone);
	if (phone[0] != '0' || phone.length() != 10) {
		cout << "\t\t\t\tSo dien thoai khong hop le. Vui long nhap lai. " << endl;
		goto nhap;
	}
	for (int i = 1; i < phone.length(); i++)
		if (int(phone[i]) < 48 || int(phone[i]) > 57) {
			cout << "\t\t\t\tSo dien thoai khong hop le khong hop le. Vui long nhap lai" << endl;
			goto nhap;
		}
}

void guest::getTime() {
nhap:
	cout << "\t\t\t\tNhap suat xem: ";
	getline(cin, time);
	if (time != "9h" && time != "11h" && time != "15h" && time != "18h" && time != "21h") {
		cout << "\t\t\t\tSuat " << time << " khong ton tai! . Vui long nhap lai. " << endl;
		goto nhap;
	}

}

void guest::getNum() {
nhap:
	cout << "\t\t\t\tNhap so ve muon mua: ";
	cin >> num;
	if (num < 1) {
		cout << "\t\t\t\tNhap khong hop le. Vui long nhap lai.." << endl;
		goto nhap;
	}
}


void guest::muave(film f,room &x) {
	input:
	cout << "\t\t\tNhap ma phim ban muon xem : -> " ; 
	cin >> ma;
	if (!f.checkMa(ma)) {
		cout << "\t\t\t .. Ma phim khong hop le. Vui long nhap lai !" << endl;
		goto input;
	}
	fstream g;
	string tgbd, id, r, tenphim , s[5], phim; // tgian bat dau - ma - room - ...

	int d = -1 ;

	g.open("lich.txt");

	cout << "\t\t\t\tLICH CHIEU TRONG NGAY HOM NAY" << endl;
	cout << "\t\t\t+=============+=======================================+==========+==============+" << endl;
	cout << "\t\t\t| Gio bat dau |       Ten Phim                        | Ma Phong | So Ghe Trong |" << endl;
	cout << "\t\t\t+=============+=======================================+==========+==============+" << endl;

	while (!g.eof()) {
		//d++;
		getline(g, tgbd, '|');      // thoi gian bat dau
		getline(g, id, '|');        // ma phim 
		getline(g, r);              // ma phong
		tenphim = f.find(id);       

		if (!g.eof() && (ma == id)) {
			d++;
			cout << "\t\t\t|" << setw(8) << right << tgbd << setw(6) << "|";  // gio bat dau
			cout << setw(39) << left << tenphim << "|";   // ten phim
			cout << setw(7) << right << r << setw(4) << "|" ;  // ma phong 
			// so ghe trong
			cout << setw(9) << x.count(tgbd,r) << setw(6) << "|" << endl;
			s[d] = tgbd + r;
			phim = tenphim;
		}

	};
	cout << "\t\t\t+=============+=======================================+==========+==============+" << endl << endl;

	//cout << "\t\t\t\tHo Ten Khach Hang: ";
	//cin.ignore();
	//getline(cin, name);
	getName();

	//cout << "\t\t\t\tSo dien thoai: ";
	//getline(cin, phone);
	getSDT();

	//cout << "\t\t\t\tNhap suat xem: ";
	//getline(cin, time);
	getTime();


	//cout << "\t\t\t\tNhap so ve muon mua ";
	//cin >> num;
	getNum();

	int k, n ;

	for (int i = 0; i <= d; i++) {
		if (s[i].find("9h") == 0 && time == "9h") {
			k = 0;
			n = int(s[i][s[i].length() - 1] - '0');
		}
		if (s[i].find("11h") == 0 && time == "11h") {
			k = 4;
			n = int(s[i][s[i].length() - 1] - '0');
		}
		if (s[i].find("15h") == 0 && time == "15h") {
			k = 8;
			n = int(s[i][s[i].length() - 1] - '0');
		}
		if (s[i].find("18h") == 0 && time == "18h") {
			k = 12;
			n = int(s[i][s[i].length() - 1] - '0');
		}
		if (s[i].find("21h") == 0 && time == "21h") {
			k = 16;
			n = int(s[i][s[i].length() - 1] - '0');
		}
	}

	n = n + k;
	
	x.show(n);
	
	int h, c;
	for (int i = 0; i < num; i++) {

		if (i == 0) cin.ignore();
		else fflush(stdin);
		nhap:
		cout << "\t\t\t\t - Nhap vi tri cho ngoi thu " << i + 1 << ": ";


		getline(cin, vt[i]);
		
		vt[i][0] = toupper(vt[i][0]);
		
		h = int(vt[i][0] ) - 65;
		c = int(vt[i][1] ) - 49;

		if (vt[i].length() == 3)
			c = 9;
		if (!x.checkEmpty(n, h, c)) {
			cout << "\t\t\t\t...Cho ngoi khong hop le. Vui long nhap lai ! " << endl;
			goto nhap;
		}
		x.update(n, h, c);

	}
	cout << "\n\t\t\t____________________________________________________" << endl << endl;

	system("pause");

	update(phim, n);  // cap nhat khach hang vao file khach.txt

	bill(phim, n);  // xuat hoa don 
	
	g.close();
	
}

void guest::bill(string phim, int n) {
	
	system("cls");
	n = n % 4;
	if (n == 0)
		n = 4;

	cout << "\t\t\t\t+====================================================+" << endl;
	cout << "\t\t\t\t|                   HOA DON MUA VE                   |" << endl;
	cout << "\t\t\t\t+====================================================+" << endl;
	cout << "\t\t\t\t|    Ten Khach hang: " << setw(27) << name << setw(6) << "|" << endl;
	cout << "\t\t\t\t|    So dien thoai : " << setw(27) << phone << setw(6) << "|" << endl;
	cout << "\t\t\t\t|    Ten phim : " << setw(32) << phim << setw(6) << "|" << endl;
	cout << "\t\t\t\t|    Suat xem : " << setw(5) << time << setw(33) << "|" << endl;
	cout << "\t\t\t\t|    Rap so : " << n << setw(39) << "|" << endl;
	cout << "\t\t\t\t|    So ve mua : " << num << setw(36) << "|" << endl;

	for (int i = 0; i < num; i++) {
		cout << "\t\t\t\t| \t- Vi Tri Ngoi Thu " << setw(3) << right << i + 1 << ": " << setw(5) << vt[i] << setw(18) << "|" << endl;
	}

	cout << "\t\t\t\t|    -> Thanh Tien : " << setw(10) << num * 50000 << " VND" << setw(19) << "|" << endl;

	cout << "\t\t\t\t+====================================================+" << endl;
	
}

void guest::update(string phim,int n) {

	fstream g;
	g.open("khach.txt", ios::out | ios::app); // ghi chen vao file khach.txt
	n = n % 4;
	if (n == 0)
		n = 4;

	g << name << "|" << phone << "|" << phim << "|" << n << "|" << num << "|";
	for (int i = 0; i < num-1; i++) {
		g << vt[i] <<"|";
	}
	g << vt[num - 1] << endl; 

	// name|phone|phim|rap|num|vt[i] \n
	g.close();
}


void guest::huyve() {
	system("cls");
	fstream g;
	string hoten, dt, ten, sdt, phim, r, n, v[100];
	g.open("khach.txt");
	cout << "\t\t\t\tHUY VE" << endl;
	cin.ignore();
	cout <<"\t\t\t Nhap ho va ten : "; 
	getline(cin, hoten);
	cout << "\t\t\t Nhap so dien thoai: ";
	getline(cin, dt);
	cout << "\t\t\t __________________________" << endl << endl;

	bool ktra = false;
	while (!g.eof()) {
		getline(g, ten, '|');
		getline(g, sdt, '|');
		if (hoten == ten && dt == sdt) {
			ktra = true; 
			break;
		}
	}
	if (ktra) {

		getline(g, phim, '|');
		getline(g, r, '|');
		getline(g, n, '|');
		int k;
		k = int(n[0] - '0');
		for (int i = 0; i < k-1; i++) {
			getline(g, v[i], '|');
		}
		getline(g, v[k - 1]);

		cout << "\t\t\t\t THONG TIN BAN DAU CUA BAN: " << endl;
		cout << "\t\t\t Ho Ten : " << ten << endl;
		cout << "\t\t\t So dien thoai : " << sdt << endl;
		cout << "\t\t\t Phim da chon : " << phim << endl;
		cout << "\t\t\t Rap so : " << r << endl;
		cout << "\t\t\t So ve da mua: " << n << endl;
		cout << "\t\t\t Vi tri da dat:";

		for (int i = 0; i < k; i++) {
			cout << " | " << v[i];
		}
		cout << " | " << endl;
		cout << "\t\t\t __________________________" << endl << endl;

		int ve,tmp = -1;
		string huy[100];
		//input:
		cout << "\t\t\t Nhap so ve muon huy: "; 
		cin >>  ve;

		//if (ve > num) {
		//	cout << "\t\t\t So ve muon huy khong hop le. Yeu cau nhap lai..!" << endl;
		//	goto input;
		//}

		cin.ignore();
		for (int i = 0; i < ve; i++) {
			cout << "\t\t\t - Nhap vi tri muon huy thu " << i + 1 << ": ";
			getline(cin, huy[i]);
			
			huy[i][0] = toupper(huy[i][0]);
		}
		
		string m[100];
		
		bool kt;

		for (int i = 0; i < k; i++) {
			ktra = true;
			for (int j = 0; j < ve; j++) {
				if (v[i] == huy[j]) {
				kt = false;
				break;
				}
			}
			if (kt) {
				tmp++;
				//cout << v[i] << " ";	
				m[tmp] = v[i];
			}
		}
		cout << "\t\t\t ";
		for (int i = 0; i <= tmp; i++) {
			cout << m[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << "\t\t\t Khach hang khong ton tai." << endl;
	}
	g.close();
}