#include "Menu.h"
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
	vector<ADMIN>ls_admin;
	vector<User> ls_User;
	vector<User> ls_Userover18;
	vector<User> ls_Userlesster18;
	file f;
	f.Docfile(ls, ls_TacGia, ls_NXB, ls_User, ls_admin);
	f.WriteUSERages(ls_User);
	//f.ReadUSERover18(ls_Userover18);
	//f.ReadUSERlesster18(ls_Userlesster18);
	//ls.Nhap_n_sach();
	//ls.Xuat();
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
	int dangnhap = 1;
	//Dang nhap
	do
	{
		cout << "1.Dang nhap USER" << endl;
		cout << "2.Dang nhap Admin" << endl;
		cout << "3.Dang nhap tac gia" << endl;
		cout << "4.Dang nhap NXB" << endl;
		cout << "0. Thoat" << endl;
		cout << "Nhap lua chon" << endl;
		cin >> dangnhap;

		if (dangnhap == 1)
		{
			do
			{
				system("cls");
				cout << "Dang nhap USER" << endl;
				cout << "Nhap id" << endl;
				cin.ignore();
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
						break;
					}
				}
				if (flap == 0)
				{
					cout << "Dang nhap sai" << endl;
					system("pause");
				}
			} while (flap != 1);

			while (luachon != 0)
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
						tg.them();
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
		}
		if (dangnhap == 2)
		{
			int loginad = 0;
			do
			{
				system("cls");
				cout << "Dang nhap Admin" << endl;
				cout << "Nhap id" << endl;
				cin.ignore();
				getline(cin, ten);
				cout << "Nhap pass" << endl;
				getline(cin, pass);
				for (int i = 0; i < ls_admin.size(); i++)
				{
					if (ls_admin[i].get_ten() == ten && ls_admin[i].get_pass() == pass)
					{
						loginad = 1;
						cout << "Dang nhap thanh cong" << endl;
						ad = ls_admin[i];
						break;
					}
				}
				if (loginad == 0)
				{
					cout << "Dang nhap sai" << endl;
					system("pause");
				}
			} while (loginad != 1);
			int luachonad = 1;
			while (luachonad != 0)
			{
				system("cls");
				cout << "1. Khoa sach " << endl;
				cout << "2. Nhan tin cho user" << endl;
				cout << "0. Thoat" << endl;
				cin >> luachonad;
				switch (luachonad)
				{
				case 1:
					ad.Phanquyen();
					system("pause");
					break;
				case 2:
					ad.Guitinnhan(ls_User);
					system("pause");
					break;
				case 0:
					break;
				default:
					break;
				}
			}
		}

		if (dangnhap == 3)
		{
			int logintg = 0;
			do
			{
				system("cls");
				cout << "Dang nhap tac gia" << endl;
				cout << "Nhap id" << endl;
				cin.ignore();
				getline(cin, ten);
				cout << "Nhap pass" << endl;
				getline(cin, pass);
				for (int i = 0; i < ls_TacGia.size(); i++)
				{
					if (ls_TacGia[i].get_ten() == ten && ls_TacGia[i].get_pass() == pass)
					{
						logintg = 1;
						cout << "Dang nhap thanh cong" << endl;
						tg = ls_TacGia[i];
						break;
					}
				}
				if (logintg == 0)
				{
					cout << "Dang nhap sai" << endl;
					system("pause");
				}
			} while (logintg!=1);
			
			int luachontg = 1;
			system("cls");
			cout << "1. xem sach" << endl;
			cout << "2. them sach" << endl;
			cout << "3. Xoa sach" << endl;
			cout << "4. Sua sach" << endl;
			cout << "Nhap lua chon" << endl;
			cin >> luachontg;
			if (luachontg == 1)
			{
				tg.Xemsach(ls, ad.phan_quyen);
				system("pause");
			}
			if (luachontg == 2)
			{
				tg.them();
			}
			if (luachontg == 3)
			{
				tg.xoa();
			}
			if (luachontg == 4)
			{
				tg.sua();
			}
			break;
		}
		if (dangnhap == 4)
		{
			int loginnxb = 0;
			int luachonnxb;
			do
			{
				system("cls");
				cout << "Dang nhap NXB" << endl;
				cout << "Nhap id" << endl;
				cin.ignore();
				getline(cin, ten);
				cout << "Nhap pass" << endl;
				getline(cin, pass);
				for (int i = 0; i < ls_NXB.size(); i++)
				{
					if (ls_NXB[i].get_ten() == ten && ls_NXB[i].get_pass() == pass)
					{
						loginnxb = 1;
						cout << "Dang nhap thanh cong" << endl;
						nxb = ls_NXB[i];
						break;
					}
				}
				if (loginnxb == 0)
				{
					cout << "Dang nhap sai" << endl;
					system("pause");
				}
			} while (loginnxb!=1);

			system("cls");
			cout << "1. xem sach" << endl;
			cout << "2. them sach" << endl;
			cout << "3. Xoa sach" << endl;
			cout << "4. Sua sach" << endl;
			cout << "Nhap lua chon" << endl;
			cin >> luachonnxb;
			if (luachonnxb == 1)
			{
				nxb.Xemsach(ls, ad.phan_quyen);
				system("pause");
			}
			if (luachonnxb == 2)
			{
				nxb.Them();
			}
			if (luachonnxb == 3)
			{
				nxb.Xoa();
			}
			if (luachonnxb == 4)
			{
				nxb.Sua();
			}
			break;
		}
	} while (dangnhap!=0);
	system("pause");
	return 0;
}
