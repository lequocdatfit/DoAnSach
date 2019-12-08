#include "ADMIN.h"

void ADMIN::Phanquyen()
{
	cout << "Ban co muon phan quyen cho tac gia va nha xuat ban" << endl;
	int luachon;
	cout << "Nhap lua chon (1. co, 0. khong)" << endl;
	cin >> luachon;
	if (luachon == 1)
	{
		phan_quyen = true;
		cout << "Da phan quyen" << endl;
	}
	if (luachon == 0)
	{
		phan_quyen = false;
		cout << "Khong phan quyen" << endl;
	}
}

void ADMIN::Xoa()
{
	int luachon;
	string ten;
	cout << "1. Xoa NXB" << endl;
	cout << "2. Xoa tac gia" << endl;
	cout << "3. Xoa user" << endl;
	cout << "4. Xoa sach" << endl;
	cout << "Nhap lua chon" << endl;
	cin >> luachon;
	cin.ignore();
	if (luachon == 1)
	{
		cout << "Nhap ten NXB" << endl;
		getline(cin, ten);
		for (int i = 0; i < ls_NXB.size(); i++)
		{
			if (ten == ls_NXB[i]->get_ten())
			{
				ls_NXB.erase(ls_NXB.begin() + i);
			}
		}
	}
	if (luachon == 2)
	{
		cout << "Nhap ten tac gia" << endl;
		getline(cin, ten);
		for (int i = 0; i < ls_tacgia.size(); i++)
		{
			if (ten == ls_tacgia[i]->get_ten())
			{
				ls_tacgia.erase(ls_tacgia.begin() + i);
			}
		}
	}
	if (luachon == 3)
	{
		cout << "Nhap ten user" << endl;
		getline(cin, ten);
		for (int i = 0; i < ls_tacgia.size(); i++)
		{
			if (ten == ls_user[i]->getName())
			{
				ls_user.erase(ls_user.begin() + i);
			}
		}
	}
	if (luachon == 4)
	{
		Sach* a;
		a = Guest::Timsach(this->SachQL);
	}
}

void ADMIN::Them()
{
	int luachon;
	cout << "1. Them NXB" << endl;
	cout << "2. Them tac gia" << endl;
	cout << "3. Them user" << endl;
	cout << "4. Them Sach" << endl;
	cout << "Nhap lua chon: " << endl;
	cin >> luachon;
	cin.ignore();
	if (luachon == 1)
	{
		NXB a;
		a.Nhapthongtin();
		this->ls_NXB.push_back(&a);
	}
	if (luachon == 2)
	{
		TacGia t;
		t.Nhapthongtin();
		this->ls_tacgia.push_back(&t);
	}
	if (luachon == 3)
	{
		User u;
		u.Nhapthongtin();
		this->ls_user.push_back(&u);
	}
	if (luachon == 4)
	{
		this->SachQL.Nhap_n_sach();
	}
}

void ADMIN::Promotion()
{
	int luachon;
	int giamgiaover18;
	int giamgialesster18;
	cout << "Tao khuyen mai" << endl;
	cout << "1. Khuyen mai cho do tuoi > 18" << endl;
	cout << "2. Khuyen mai cho do tuoi <= 18" << endl;
	cout << "Nhap lua chon" << endl;
	cin >> luachon;
	if (luachon == 1)
	{
		this->Promotionover18 = true;
		cout << "Nhap giam gia" << endl;
		cin >> giamgiaover18;
		this->giamgiaover18 = giamgiaover18;
	}
	if (luachon == 2)
	{
		this->Promotionlesster18 = true;
		cout << "Nhap giam gia" << endl;
		cin >> giamgiaolesster18;
		this->giamgiaolesster18 = giamgiaolesster18;
	}
	
}

string ADMIN::get_ten()
{
	return this->ten;
}

string ADMIN::get_pass()
{
	return this->pass;
}


ADMIN::ADMIN()
{
	this->ten = "admin";
	this->pass = "123456";
	giamgiaolesster18 = 0;
	giamgiaover18 = 0;
	phan_quyen = false;
	Promotionover18 = false;
	Promotionlesster18 = false;
}


ADMIN::~ADMIN()
{
}
