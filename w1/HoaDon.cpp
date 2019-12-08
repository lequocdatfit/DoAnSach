#include "HoaDon.h"

void HoaDon::Tinhhoadon(ListSach ls)
{
	string ten;
	string id;
	int co = 0;
	int dem = 0;
	int x[100];
	int soluong = 0;
	cout << "Nhap ten sach:" << endl;
	cin.ignore();
	getline(cin, ten);
	for (int i = 0; i < ls.ls_sach.size(); i++)
	{
		if (ls.ls_sach[i].get_tensach() == ten)
		{
			x[dem++] = i;
		}
	}
	if (dem == 1)
	{
		cout << "Da tim thay 1 loai sach" << endl;
		cout << "Nhap so luong: " << endl;
		cin >> soluong;
		this->Set_book(ls.ls_sach[x[0]]);
		this->Set_soluong(soluong);
		this->Set_Tien(soluong * ls.ls_sach[x[0]].get_giatien());
		cout << "Da them vao hoa don" << endl;
	}
	else
	{
		if (dem > 1)
		{
			co = 0;
			cout << "Tim thay nhieu sach co ten nay" << endl;
			cout << "Nhap ID: " << endl;
			getline(cin, id);
			for (int j = 0; j < dem; j++)
			{
				if (ls.ls_sach[x[j]].get_masach() == id)
				{
					cout << "Da tim thay sach co ID da nhap" << endl;
					cout << "Nhap so luong: " << endl;
					cin >> soluong;
					this->Set_book(ls.ls_sach[x[j]]);
					this->Set_soluong(soluong);
					this->Set_Tien(soluong * ls.ls_sach[x[j]].get_giatien());
					cout << "Da them vao hoa don" << endl;
				}
			}
			if (co == 1)
			{
				cout << "Khong tim thay sach" << endl;
			}
		}
		else
		{
			cout << "Khong tim thay sach" << endl;
		}
	}
	
}

void HoaDon::Set_book(Sach x)
{
	this->book = x;
}

void HoaDon::Set_Tien(int money)
{
	this->tien = money;
}

void HoaDon::Set_soluong(int cuon)
{
	this->soluong = cuon;
}

int HoaDon::Get_tien()
{
	return this->tien;
}

Sach HoaDon::Get_book()
{
	return this->book;
}

int HoaDon::Get_soluong()
{
	return this->soluong;
}

HoaDon::HoaDon()
{
	this->book.set_tensach("\0");
}


HoaDon::~HoaDon()
{
}
