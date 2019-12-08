#include "NXB.h"

void NXB::Xemsach(ListSach src, bool An)
{
	if (An == true)
	{
		for (int i = 0; i < src.ls_sach.size(); i++)
		{
			if (src.ls_sach[i].anNXB == true)
			{
				src.ls_sach.erase(src.ls_sach.begin() + i);
			}
		}
	}
	src.Xuat();
}

void NXB::set_ten(string name)
{
	this->ten = name;
}

void NXB::set_pass(string pass)
{
	this->pass = pass;
}

string NXB::get_ten()
{
	return this->ten;
}

string NXB::get_pass()
{
	return this->pass;
}

void NXB::Nhapthongtin()
{
	string ten;
	cout << "Tao ten: " << endl;
	getline(cin, ten);
	this->ten = ten;
	cout << "Tao pass: " << endl;
	getline(cin, ten);
	this->ten = ten;
}

void NXB::Them()
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
	cout << "Nhap ten tac gia" << endl;
	getline(cin, ten);
	a.set_TenTacGia(ten);
	a.set_NhaXuatBan(this->ten);
	cout << "Nhap gia" << endl;
	cin >> gia;
	a.set_giatien(gia);
	this->list.ls_sach.push_back(a);
}

void NXB::Xoa()
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

void NXB::Sua()
{
	cout << "Nhap ten sach can sua: " << endl;
	string ten, temp;
	for (int i = 0; i < list.ls_sach.size(); i++)
	{
		if (ten == list.ls_sach[i].get_tensach())
		{
			cout << "Nhap ten can sua" << endl;
			getline(cin, temp);
			this->list.ls_sach[i].set_tensach(temp);
		}
	}
}

NXB::NXB()
{
	this->ten = "NXB";
	this->pass = "12345";
}


NXB::~NXB()
{
	this->list.ls_sach.clear();
}
