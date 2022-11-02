#ifndef KHACH_H
#define KHACH_H
#include "film.h"
#include <string>
using namespace std;
class guest {
private:
	int num;
	string vt[100];
	string ma,name,phone,time;

public: 
	guest();
	~guest();
	void bill(string, int);
	void muave(film f,room & x);
	void huyve();
	void update(string ,int );
	friend class room;
	friend class film;

	void getName();
	void getSDT();
	void getTime();
	void getNum();
};
#endif // !KHACH_H
