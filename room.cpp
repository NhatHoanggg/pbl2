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
	cout << "\t\t\t RAP SO " << t % 4 + 1 << endl << endl;
	cout << setw(10) << "1"; 
	for (int i = 1; i < 10; i++)
		cout << setw(5) << i + 1; 
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << setw(5) << char(65 + i); 
		for (int j = 0; j < 10; j++)
			cout  << setw(5) << this->r[t][i][j];
		cout << endl;
	}
	cout << endl;
	cout << "\t\t Gia ve : 50.000 VND" << endl;
	cout << "\t\t 0: Chua co nguoi dat; " << endl;
	cout << "\t\t 1: Da co nguoi dat; " << endl << endl;
}

int room::count(int t) {
	t = t - 1;
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

