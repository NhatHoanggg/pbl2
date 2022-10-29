#pragma once
#ifndef ROOM_H
#define ROOM_H
#include <string>
using namespace std;
class room{
private:
	string id;
	int r[20][10][10];
public:
	room();
	~room();
	void setData();
	void update(int ,int ,int);
	void show(int);
	//bool check(int , int, int);
	int count(int);
};

#endif // !ROOM_H
