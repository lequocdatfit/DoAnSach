#pragma once
#include "Sach.h"
#include <vector>
#include <fstream>
class ListSach
{
public:
	vector<Sach>ls_sach;
	void Docfilesach();
	void Xuat();
	void XuatCoPhanQuyen();
	void Nhap(Sach);
	void Nhap_n_sach();
	void Timkiemvacapnhat(string ten);
	void Xoa1sach(int pos);
	void Capnhat();
	ListSach();
	~ListSach();
};

