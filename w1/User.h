#pragma once
#include <string>
#include "HoaDon.h"
#include <iostream>
using namespace std;
#include "Guest.h"

class User :public Guest
{
private:
	string Name;
	int Age;
	string pass;
public:
	string message;
	void Nhapthongtin();
	void Muasach(vector<HoaDon> &ls_hoadon, ListSach &l);
	void Capnhatdonhang(vector<HoaDon>&ls_hoadon, ListSach &l, int giamgia);
	string getName();
	string getpass();
	int get_Age();
	void set_name(string name);
	void set_pass(string pass);
	void set_age(int age);
	void Guitinnhan(vector<User>ls_users);
	void Xemtinnhan();
	User();
	~User();
};

