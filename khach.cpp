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

void guest::getInfo(film f,room &x) {
	cout << "\t\t\tNhap ma phim ban muon xem : -> " ; 
	cin >> ma;
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

	cout << "\t\t\t\tHo Ten Khach Hang: ";
	cin.ignore();
	getline(cin, name);
	cout << "\t\t\t\tSo dien thoai: ";
	getline(cin, phone);
	cout << "\t\t\t\tNhap suat xem: ";
	getline(cin, time);
	cout << "\t\t\t\tNhap so ve muon mua ";
	cin >> num;

	
	//x.show(n); 9h1

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
	

	for (int i = 0; i < num; i++) {
		cout << "\t\t\t\t - Nhap vi tri cho ngoi thu " << i + 1 << ": ";

		if (i == 0) cin.ignore();
		else fflush(stdin);

		getline(cin, vt[i]);
		
		vt[i][0] = toupper(vt[i][0]);
		
		h = int(vt[i][0] ) - 65;
		c = int(vt[i][1] ) - 49;

		if (vt[i].length() == 3)
			c = 9;
		x.update(n, h, c);

	}
	cout << "\n\t\t\t____________________________________________________" << endl << endl;
	system("pause");

	bill(phim, n);
	update(phim, n);
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
	g.open("khach.txt");
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

bool guest:: checkFull() {
	return false;
}
bool guest:: checkEmpty() {
	return false;
}

