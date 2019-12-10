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
	void Xemsach();
	void GetBookFromSource(ListSach src);
	string get_ten();
	string get_pass();
	void Khoasach();
	void Mokhoasach();
	void set_ten(string ten);
	void set_pass(string pass);
	void Nhapthongtin();
	void them();
	void xoa(ListSach &src);
	void sua(ListSach &src);
	TacGia();
	~TacGia();
};