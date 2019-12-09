#pragma once
#include <string>
#include <iostream>
using namespace std;

class Sach
{
private:
	string ten_sach;
	string ma_sach;
	string TenTacGia;
	string NhaXuatBan;
	int gia;
public:
	void set_tensach(string);
	void set_masach(string);
	void set_giatien(int);
	void set_TenTacGia(string ten);
	void set_NhaXuatBan(string ten);
	string get_TenTacGia();
	string get_NhaXuatBan();
	string get_tensach();
	string get_masach();
	int get_giatien();
	Sach();
	~Sach();
};

