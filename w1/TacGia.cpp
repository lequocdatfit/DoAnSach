#include "TacGia.h"

void TacGia::Xemsach(ListSach src, bool An)
{
	if (An == true)
	{
		for (int i = 0; i < src.ls_sach.size(); i++)
		{
			if (src.ls_sach[i].anTacgia == true)
			{
				src.ls_sach.erase(src.ls_sach.begin() + i);
			}
		}
	}
	src.Xuat();
}


string TacGia::get_ten()
{
	return this->ten;
}

string TacGia::get_pass()
{
	return this->pass;
}

void TacGia::set_ten(string ten)
{
	this->ten = ten;

}

void TacGia::set_pass(string pass)
{
	this->pass = pass;
}

void TacGia::Nhapthongtin()
{
	string ten;
	cout << "Nhap ten: " << endl;
	getline(cin, ten);
	this->ten = ten;
	cout << "Nhap pass: " << endl;
	getline(cin, ten);
	this->pass = ten;
}

void TacGia::them(ListSach l)
{
	Sach a;
	string ten;
	int gia;
	cin.ignore();
	cout << "Nhap ten sach" << endl;
	getline(cin, ten);
	a.set_tensach(ten);
	cout << "Nhap ma sach" << endl;
	getline(cin, ten);
	a.set_masach(ten);
	a.set_TenTacGia(this->ten);
	cout << "Nhap NXB" << endl;
	getline(cin, ten);
	a.set_NhaXuatBan(ten);
	cout << "Nhap gia" << endl;
	cin >> gia;
	a.set_giatien(gia);
	this->list.ls_sach.push_back(a);
}

void TacGia::xoa()
{
	cout << "Nhap ten sach: " << endl;
	string ten;
	getline(cin, ten);
	for (int i = 0; i < this->list.ls_sach.size(); i++)
	{
		if (ten == list.ls_sach[i].get_tensach())
		{
			this->list.ls_sach.erase(list.ls_sach.begin() + i);
		}
	}
}

void TacGia::sua()
{
	cout << "Nhap ten sach can sua: " << endl;
	string ten, temp;
	getline(cin, ten);
	for (int i = 0; i < this->list.ls_sach.size(); i++)
	{
		if (ten == list.ls_sach[i].get_tensach())
		{
			cout << "Nhap ten sach can sua" << endl;
			getline(cin, temp);
			list.ls_sach[i].set_tensach(temp);
		}
	}
}

TacGia::TacGia()
{
	this->ten = "tacgia";
	this->pass = "12345";
}


TacGia::~TacGia()
{
	this->list.ls_sach.clear();
}
