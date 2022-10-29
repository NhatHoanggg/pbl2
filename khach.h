#ifndef KHACH_H
#define KHACH_H
#include "room.h"
#include <string>
using namespace std;
class guest {
private:
	int num,h,c;
	string p[100];
	string name,phone,time;

public: 
	guest();
	~guest();
	void getInfo1(int t, room &x);
	void getInfo2(int t, room &x);
	void getInfo3(int t, room &x);
	void getInfo4(int t, room &x);
	void getInfo5(int t, room &x);
	void getInfo6(int t, room &x);
	void bill();
	//void select();
	void update();
	friend class room;
};
#endif // !KHACH_H
