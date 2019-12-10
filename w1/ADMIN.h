#pragma once
#include "User.h"
#include "TacGia.h"
#include "NXB.h"
#include "Sach.h"

class ADMIN
{
private:
	string ten;
	string pass;
	vector<User*>ls_user;
	vector<TacGia*>ls_tacgia;
	vector<NXB*>ls_NXB;
	ListSach SachQL;
public:
	int giamgiaover18;
	int giamgiaolesster18;
	bool phan_quyen;
	int Ansach;
	bool Promotionover18;
	bool Promotionlesster18;
	void Phanquyen();
	void Xemsach();
	void GetSourceBook(ListSach& src);
	void Xoa();
	void Them();
	void Promotion();
	void set_Name(string ten);
	void set_Pass(string pass);
	void Guitinnhan(vector<User>ls_users);
	string get_ten();
	string get_pass();
	ADMIN();
	~ADMIN();
};

