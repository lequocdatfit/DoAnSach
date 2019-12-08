
#include <iostream>
#include "Sach.h"
#include "ListSach.h"
#include "HoaDon.h"
#include "Guest.h"
#include "User.h"
#include "TacGia.h"
#include "NXB.h"
#include "ADMIN.h"
#include <vector>
#include "file.h"
using namespace std;

int main()
{
	ListSach ls;
	vector<NXB>ls_NXB;
	vector<TacGia>ls_TacGia;
	vector<User> ls_User;
	vector<User> ls_Userover18;
	vector<User> ls_Userlesster18;
	file f;
	f.Docfile(ls,ls_TacGia,ls_NXB,ls_User);
	f.WriteUSERages(ls_User);
	//f.ReadUSERover18(ls_Userover18);
	//f.ReadUSERlesster18(ls_Userlesster18);
	//ls.Nhap_n_sach();
	ls.Xuat();
	/*string ten;
	cin.ignore();
	cout << "Nhap ten sach can tim kiem" << endl;
	getline(cin, ten);
	ls.Timkiemvacapnhat(ten);
	ls.Xuat();*/


	/*vector<HoaDon>ls_hoadon;
	HoaDon a;
	int tongtien = 0;
	int luachon = 1;
	do
	{
		system("cls");
		a.Tinhhoadon(ls);
		if (a.Get_book().get_tensach() != "\0")
		{
			ls_hoadon.push_back(a);
		}
		cout << "Ban muon mua them khong (1: them, 0:Khong)" << endl;
		cin >> luachon;
	} while (luachon != 0);
	for (int i = 0; i < ls_hoadon.size(); i++)
	{
		tongtien += ls_hoadon[i].Get_book().get_giatien() * ls_hoadon[i].Get_soluong();
		cout << ls_hoadon[i].Get_book().get_tensach() << "\t" << ls_hoadon[i].Get_book().get_giatien() << "*" << ls_hoadon[i].Get_soluong() << " =" << ls_hoadon[i].Get_book().get_giatien() * ls_hoadon[i].Get_soluong() << endl;
	}
	cout << "==================================" << endl;
	cout << "Tong tien la:" << tongtien << endl;*/



	//int luachon = 0;
	/*string user, pass;
	Guest* a;
	a = new User();
	cout << "Nhap user" << endl;
	getline(cin, user);
	getline(cin, pass);
	if (user == a->getName() && user == a->getPass())
	{
		cout << "Dang nhap thanh cong" << endl;
	}*/
	
	int luachon = 1;
	int mua = 1;
	vector<HoaDon>ls_hoadon;
	Guest g;
	User x;
	ADMIN ad;
	TacGia tg;
	NXB nxb;
	string ten;
	string pass;
	string pass2;

	int flap = 0;
	do
	{
		system("cls");
		cout << "Dang nhap USER" << endl;
		cout << "Nhap id" << endl;
		getline(cin, ten);
		cout << "Nhap pass" << endl;
		getline(cin, pass);
		for (int i = 0; i < ls_User.size(); i++)
		{
			if (ten == ls_User[i].getName() && pass == ls_User[i].getpass())
			{
				flap = 1;
				cout << "Dang nhap thanh cong" << endl;
				x = ls_User[i];
			}
		}
		if (flap == 0)
		{
			cout << "Dang nhap sai" << endl;
			system("pause");
		}
	} while (flap!=1);

	while (luachon!=0)
	{
		system("cls");
		cout << "1. Mua sach va cap nhat" << endl;
		cout << "2. Phan quyen admin" << endl;
		cout << "3. Tac gia" << endl;
		cout << "4. NXB" << endl;
		cout << "5. Guest" << endl;
		cout << "6. Gui tin nhan" << endl;
		cout << "7. Xem tin nhan" << endl;
		cout << "8. Promotion" << endl;
		cout << "0. Thoat" << endl;
		cout << "Nhap lua chon" << endl;
		cin >> luachon;
		switch (luachon)
		{
		case 1:
			x.Muasach(ls_hoadon, ls);
			while (mua != 0)
			{
				system("cls");
				if (x.get_Age() > 18)
				{
					x.Capnhatdonhang(ls_hoadon, ls, ad.giamgiaover18);
				}
				else
				{
					x.Capnhatdonhang(ls_hoadon, ls, ad.giamgiaolesster18);
				}
				cout << "Ban co muon cap nhat don hang(1:co, 0:khong)" << endl;
				cin >> mua;
			}
			break;
		case 2:
			ad.Phanquyen();
			system("pause");
			break;
		case 3:
			cout << "1. xem sach" << endl;
			cout << "2. them sach" << endl;
			cout << "Nhap lua chon" << endl;
			cin >> luachon;
			if (luachon == 1)
			{
				tg.Xemsach(ls, ad.phan_quyen);
				system("pause");
			}
			if (luachon == 2)
			{
				tg.them(ls);
			}
			break;
		case 4:
			cout << "1. xem sach" << endl;
			cout << "Nhap lua chon" << endl;
			cin >> luachon;
			if (luachon == 1)
			{
				nxb.Xemsach(ls, ad.phan_quyen);
				system("pause");
			}
			break;
		case 5:
			g.Timsach(ls);
			cout << "Ban muon mua sach(1:co, 0:khong) ?" << endl;
			cin >> luachon;
			if (luachon == 1)
			{
				while (luachon != 0)
				{
					system("cls");
					cout << "1. Dang nhap" << endl;
					cout << "2. Dang ki" << endl;
					cout << "0. Thoat" << endl;
					cout << "Nhap lua chon" << endl;
					cin >> luachon;
					if (luachon == 1)
					{
						cin.ignore();
						cout << "Dang nhap" << endl;
						cout << "Nhap ten user";
						getline(cin, ten);
						cout << "Nhap pass" << endl;
						getline(cin, pass);
						if (ten == x.getName() && pass == x.getpass())
						{
							x.Muasach(ls_hoadon, ls);
							while (mua != 0)
							{
								system("cls");
								x.Capnhatdonhang(ls_hoadon, ls, ad.giamgiaolesster18);
								cout << "Ban co muon cap nhat don hang(1:co, 0:khong)" << endl;
								cin >> mua;
							}
						}
					}
					if (luachon == 2)
					{
						cin.ignore();
						User y;
						cout << "Nhap ten tai khoan" << endl;
						getline(cin, ten);
						cout << "Nhap pass " << endl;
						cout << "Nhap lai pass" << endl;
						cout << "Tao tai khoan thanh cong" << endl;
					}
				}
			}
			break;
		case 6:
			x.Guitinnhan(ls_User);
			break;
		case 7:
			x.Xemtinnhan();
			break;
		case 8:
			cout << "Nhap ten dang nhap admin" << endl;
			cin.ignore();
			getline(cin, ten);
			cout << "Nhap pass admin" << endl;
			getline(cin, pass);
			if (ten == ad.get_ten() && pass == ad.get_pass())
			{
				cout << "Dang nhap thanh cong";
				ad.Promotion();
			}
			else
			{
				cout << "Dang nhap sai" << endl;
			}
			break;
		case 0:
			break;
		default:
			break;
		}
		cout << "Ban co muon tiep tuc(1:co, 0:khong)" << endl;
		cin >> luachon;
	}

	system("pause");
	return 0;
}

