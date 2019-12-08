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
	void Xemsach(ListSach src, bool An);
	void set_ten(string name);
	void set_pass(string pass);
	string get_ten();
	string get_pass();
	void Nhapthongtin();
	void Them();
	void Xoa();
	void Sua();
	NXB();
	~NXB();
};

