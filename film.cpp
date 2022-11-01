#include "film.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

film::film() {
}
film::~film() {
}

int film::getData() {
	fstream g; 
	g.open("film.txt");
	int i = -1;
	while (!g.eof()) {
		i++;
		getline(g, ma[i], '|'); // ma  - ten - tgian - theloai
		getline(g, ten[i], '|');
		getline(g, tgian[i], '|');
		getline(g, theloai[i]);
	}
	num = i;
	return i;
	g.close();
}

void film::dsphim() {
	//cout << num << endl;  num == 5 
	system("cls");
	cout << "\t\t\t\tDANH SACH PHIM DANG CHIEU" << endl;
	cout << "\t\t\t+====+================================+==========+==================================+" << endl;
	cout << "\t\t\t| Ma |        Ten Phim                |Thoi Luong|       The Loai                   |" << endl;
	cout << "\t\t\t+====+================================+==========+==================================+" << endl;
	for (int i = 0; i < num; i++) {
		cout << "\t\t\t|" << setw(4) << right << ma[i] << "|";
		cout << setw(32) << left << ten[i] << "|";
		cout << setw(10) << tgian[i] << "|";
		cout << setw(34) << left << theloai[i] << "|" << endl;
	}
	cout << "\t\t\t+====+================================+==========+==================================+" << endl;

}


string film::find(string m) {
	for (int i = 0; i < num; i++) {
		if (m == ma[i])
			return ten[i];
	}
}


void film::dstrongngay() {
	system("cls");
	fstream g;
	g.open("lich.txt");
	string id, time, room,name,tenphim;

	cout << "\t\t\t\tLICH CHIEU TRONG NGAY HOM NAY" << endl;
	cout << "\t\t\t+=============+=======================================+==========+" << endl;
	cout << "\t\t\t| Gio bat dau |       Ten Phim                        | Ma Phong |" << endl;
	cout << "\t\t\t+=============+=======================================+==========+" << endl;
	while (!g.eof()) {
		getline(g, time, '|');
		getline(g, id, '|');
		getline(g, room);
		tenphim = find(id);
		if (!g.eof()) {
			cout << "\t\t\t|" << setw(8) << right << time << setw(6) << "|";
			cout << setw(39) << left << tenphim << "|";
			cout << setw(7) << right << room << setw(4) << "|" << endl;
		}

	} ;
	
	cout << "\t\t\t+=============+=======================================+==========+" << endl;
	g.close();
}