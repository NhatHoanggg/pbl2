#include "room.h"
#include <iostream>
#include <iomanip>
using namespace std;

room::room() {
}
room::~room(){
}
void room::setData() {
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				this-> r[i][j][k] = 0;
}
void room::show(int t) {
// A -> K : 65 ;; 
	t = t - 1 ;
	cout << "\t\t\t\t\t RAP SO " << t % 4 + 1 << endl << endl;
	cout << setw(30) << "1"; 
	for (int i = 1; i < 10; i++)
		cout << setw(5) << i + 1; 
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << setw(25) << char(65 + i); 
		for (int j = 0; j < 10; j++)
			cout  << setw(5) << this->r[t][i][j];
		cout << endl;
	}
	cout << endl;
	//cout << "\t\t Gia ve : 50.000 VND" << endl;
	cout << "\t\t\t\t\t 0: Chua co nguoi dat; " << endl;
	cout << "\t\t\t\t\t 1: Da co nguoi dat; " << endl;
	cout << "\t\t\t\t\t Gia ve: 50.000VND / ve; " << endl << endl;
}

int room::count(string s, string ph) { // tgbd , phong

	int t = int(ph[0] - '0');
	int k ;
	if (s == "9h")
		k = 0;
	if (s == "11h")
		k = 4;
	if (s == "15h")
		k = 8;
	if (s == "18h")
		k = 12;
	if (s == "21h")
		k = 16;

	t = t + k - 1;
	int dem = 0;
	for (int i=0 ;i<10; i++)
		for (int j = 0; j < 10; j++) {
			if (r[t][i][j] == 0)
				dem++;
		}
	return dem;
}

void room::update(int n, int h, int c) {
	this->r[n-1][h][c] = 1;
}

