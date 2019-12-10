#include "NXB.h"

void NXB::Xemsach()
{
	this->list.Xuat();
}

void NXB::GetBookFromSource(ListSach src)
{
	for (int i = 0; i < src.ls_sach.size(); i++)
	{
		if (this->ten == src.ls_sach[i].get_NhaXuatBan())
		{
			this->list.ls_sach.push_back(src.ls_sach[i]);
		}
	}
}

void NXB::set_ten(string name)
{
	this->ten = name;
}

void NXB::set_pass(string pass)
{
	this->pass = pass;
}

void NXB::Khoasach(ListSach& ls)
{
	cout << "Cac sach dang quan li" << endl;
	list.Xuat();
	cout << "Nhap ten sach can khoa" << endl;
	string ten;
	int flap = 0;
	cin.ignore();
	getline(cin, ten);
	for (int j = 0; j < this->list.ls_sach.size(); j++)
	{
		if (list.ls_sach[j].get_tensach() == ten && list.ls_sach[j].anSach == 0)
		{
			list.ls_sach[j].anSach = 1;
			flap = 1;
		}
	}
	for (int k = 0; k < ls.ls_sach.size(); k++)
	{
		if (ls.ls_sach[k].get_tensach() == ten && ls.ls_sach[k].anSach == 0)
		{
			ls.ls_sach[k].anSach = 1;
		}
	}
	if (flap == 1)
	{
		cout << "Da an sach thanh cong" << endl;
		system("pause");
	}
	else
	{
		cout << "Sach khong ton tai hoac da bi khoa" << endl;
		system("pause");
	}
}

void NXB::Mokhoasach(ListSach& ls)
{
	cout << "Cac sach dang quan li" << endl;
	list.Xuat();
	cout << "Nhap ten sach can mo khoa" << endl;
	string ten;
	int flap = 0;
	cin.ignore();
	getline(cin, ten);
	for (int i = 0; i < list.ls_sach.size(); i++)
	{
		if (list.ls_sach[i].get_tensach() == ten && list.ls_sach[i].anSach == 1)
		{
			list.ls_sach[i].anSach = 0;
			flap = 1;
		}
	}
	for (int k = 0; k < ls.ls_sach.size(); k++)
	{
		if (ls.ls_sach[k].get_tensach() == ten && ls.ls_sach[k].anSach == 1)
		{
			ls.ls_sach[k].anSach = 0;
		}
	}
	if (flap == 1)
	{
		cout << "Mo khoa sach thanh cong" << endl;
		system("pause");
	}
	else
	{
		cout << "Sach khong ton tai hoac khong bi khoa truoc do" << endl;
		system("pause");
	}
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

void NXB::Xoa(ListSach &src)
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

void NXB::Sua(ListSach &src)
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

NXB::NXB()
{
	this->ten = "NXB";
	this->pass = "12345";
}

NXB::~NXB()
{
	this->list.ls_sach.clear();
}
