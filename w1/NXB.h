#pragma once
#include <iostream>
#include <string>
#include "ListSach.h"
#include <vector>
using namespace std;
class NXB
{
	string ten;
	string pass;
	ListSach list;
public:
	void Xemsach();
	void GetBookFromSource(ListSach src);
	void set_ten(string name);
	void set_pass(string pass);
	void Khoasach(ListSach &ls);
	void Mokhoasach(ListSach& ls);
	string get_ten();
	string get_pass();
	void Nhapthongtin();
	void Them();
	void Xoa(ListSach &src);
	void Sua(ListSach &src);
	NXB();
	~NXB();
};

