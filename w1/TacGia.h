#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Sach.h"
#include "ListSach.h"
using namespace std;
class TacGia
{
private:
	string ten;
	string pass;
	ListSach list;
public:
	void Xemsach(ListSach src, bool An);
	string get_ten();
	string get_pass();
	void set_ten(string ten);
	void set_pass(string pass);
	void Nhapthongtin();
	void them(ListSach l);
	void xoa();
	void sua();
	TacGia();
	~TacGia();
};