#include "User.h"

void User::Nhapthongtin()
{
	string Name;
	string Age;
	string pass;
	cout << "Nhap Name" << endl;
	getline(cin, Name);
	cout << "Nhap Age" << endl;
	getline(cin, Age);
	cout << "Nhap pass" << endl;
	getline(cin, pass);
	this->Name = Name;
	this->pass = pass;
}

void User::Muasach(ListSach &l)
{
	HoaDon x;
	Sach* a = NULL;
	int luachon, soluong;
	a = Timsach(l);
	if (a != NULL)
	{
		cout << "Ban co muon mua hay khong(1:co, 0:khong)" << endl;
		cin >> luachon;
		if (luachon == 1)
		{
			cout << "Nhap so luong" << endl;
			cin >> soluong;
			x.Set_book(*a);
			x.Set_soluong(soluong);
			x.Set_Tien(soluong * (*a).get_giatien());
			ls_hoadon.push_back(x);
			cout << "Da them vao hoa don" << endl;
			system("pause");
		}
		else
		{
			cout << "Khong mua" << endl;
			system("pause");
			return;
		}
	}
}

void User::Capnhatdonhang(ListSach &l, int giamgia)
{
	int luachon = 0;
	int vitri;
	do
	{
		float tongtien = 0;
		system("cls");
		cout << "----------------------------------" << endl;
		cout << "\t**DON HANG**" << endl;
		cout << "\tKhach hang: " << this->getName() << endl;
		cout << "----------------------------------" << endl;
		for (int i = 0; i < ls_hoadon.size(); i++)
		{
			tongtien += ls_hoadon[i].Get_book().get_giatien() * ls_hoadon[i].Get_soluong();
			cout << ls_hoadon[i].Get_book().get_tensach() << "\t" << ls_hoadon[i].Get_book().get_giatien() << "*" << ls_hoadon[i].Get_soluong() << " =" << ls_hoadon[i].Get_book().get_giatien() * ls_hoadon[i].Get_soluong() << endl;
		}
		cout << "Giam gia: " << giamgia << "%" << endl;
		cout << "==================================" << endl;
		cout << "Tong tien la: " << tongtien - tongtien * giamgia / 100 * 1.0 << endl;
		cout << "ban co muon them hay xoa khong? (1:them, 2:xoa, 0: xac nhan mua )" << endl;
		cin >> luachon;
		if (luachon == 1)
		{
			this->Muasach(l);
		}
		if (luachon == 2)
		{
			cout << "Nhap vi tri sach can xoa" << endl;
			cin >> vitri;
			ls_hoadon.erase(ls_hoadon.begin() + vitri - 1);
			tongtien = 0;
			for (int i = 0; i < ls_hoadon.size(); i++)
			{
				tongtien += ls_hoadon[i].Get_book().get_giatien() * ls_hoadon[i].Get_soluong();
				cout << ls_hoadon[i].Get_book().get_tensach() << "\t" << ls_hoadon[i].Get_book().get_giatien() << "*" << ls_hoadon[i].Get_soluong() << " =" << ls_hoadon[i].Get_book().get_giatien() * ls_hoadon[i].Get_soluong() << endl;
			}
			cout << "Giam gia: " << giamgia << "%" << endl;
			cout << "==================================" << endl;
			cout << "Tong tien la:" << tongtien - tongtien * giamgia / 100 * 1.0 << endl;
		}
		if (luachon == 0)
		{
			cout << "Cam on quy khach da mua hang" << endl;
			system("pause");
		}
	} while (luachon!=0);
}

string User::getName()
{
	return this->Name;
}

string User::getpass()
{
	return this->pass;
}

int User::get_Age()
{
	return this->Age;
}

void User::set_name(string name)
{
	this->Name = name;
}

void User::set_pass(string pass)
{
	this->pass = pass;
}

void User::set_age(int age)
{
	this->Age = age;
}

void User::Guitinnhan(vector<User>ls_users)
{
	string id;
	cout << "Nhap ten nguoi nhan" << endl;
	cin.ignore();
	getline(cin, id);
	string tin;
	bool kiemtra = false;
	cout << "Nhap tin nhan can gui" << endl;
	getline(cin, tin);
	for (int i = 0; i < ls_users.size(); i++)
	{
		if (ls_users[i].getName() == id)
		{
			kiemtra = true;
			ls_users[i].message = tin;
			ofstream fileout;
			fileout.open("Message[" + id + "]" + ".txt", ios::app);
			fileout<< this->getName() << "\t" << tin << endl;
			fileout.close();
		}
	}
	if (kiemtra == true)
	{
		cout << "Gui tin thanh cong" << endl;
	}
	else
	{
		cout << "Nguoi dung khong ton tai" << endl;
	}
}

void User::Xemtinnhan()
{
	fstream filein;
	filein.open("Message[" + this->getName() + "]" + ".txt", ios::in);
	while (filein.eof()==false)
	{
		string temp;
		getline(filein, temp);
		cout << temp << endl;
	}
	filein.close();
}


User::User()
{
	this->Name = "ABC";
	this->pass = "1234";
	this->Age = 1;
}


User::~User()
{
}
