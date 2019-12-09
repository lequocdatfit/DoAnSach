#include "TacGia.h"

void TacGia::Xemsach()
{
	this->list.Xuat();
}

void TacGia::GetBookFromSource(ListSach src)
{
	for (int i = 0; i < src.ls_sach.size(); i++)
	{
		if (src.ls_sach[i].get_TenTacGia() == this->ten)
		{
			this->list.ls_sach.push_back(src.ls_sach[i]);
		}
	}
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

void TacGia::them()
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

void TacGia::xoa(ListSach &src)
{
	cout << "Nhap ten sach: " << endl;
	string ten;
	cin.ignore();
	getline(cin, ten);
	for (int i = 0; i < this->list.ls_sach.size(); i++)
	{
		if (ten == list.ls_sach[i].get_tensach())
		{
			this->list.ls_sach.erase(list.ls_sach.begin() + i);
		}
	}

	for (int j = 0; j < src.ls_sach.size(); j++)
	{
		if (ten == src.ls_sach[j].get_tensach() && this->get_ten() == src.ls_sach[j].get_TenTacGia())
		{
			src.ls_sach.erase(src.ls_sach.begin() + j);
			break;
		}
	}
}

void TacGia::sua(ListSach &src)
{
	cout << "Nhap ten sach can sua: " << endl;
	string ten;
	float gia;
	getline(cin, ten);
	for (int i = 0; i < this->list.ls_sach.size(); i++)
	{
		if (ten == list.ls_sach[i].get_tensach())
		{
			cout << "Nhap gia can sua" << endl;
			cin >> gia;
			list.ls_sach[i].set_giatien(gia);
		}
	}

	for (int i = 0; i < src.ls_sach.size(); i++)
	{
		if (ten == src.ls_sach[i].get_tensach() && this->get_ten() == src.ls_sach[i].get_TenTacGia())
		{
			src.ls_sach[i].set_giatien(gia);
			break;
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
