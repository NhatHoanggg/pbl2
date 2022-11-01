#ifndef KHACH_H
#define KHACH_H
#include "film.h"
#include <string>
using namespace std;
class guest {
private:
	int num,h,c;
	string vt[100];
	string ma,name,phone,time;

public: 
	guest();
	~guest();
	void bill(string, int);
	void getInfo(film f,room & x);
	bool checkFull();
	bool checkEmpty();
	void update(string ,int );
	friend class room;
	friend class film;
};
#endif // !KHACH_H
