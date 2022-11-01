#ifndef FILM_H
#define FILM_H

#include "room.h"
#include <string>

using namespace std;

class film {
	int num;
	string ma[10],ten[10],tgian[10],theloai[10];
public:
	film();
	~film();
	void dsphim();
	void dstrongngay();
	int getData();
	void update();
	string find(string m);
};
#endif 
