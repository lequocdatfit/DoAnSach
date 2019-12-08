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
	bool Promotionover18;
	bool Promotionlesster18;
	void Phanquyen();
	void Xoa();
	void Them();
	void Promotion();
	string get_ten();
	string get_pass();
	ADMIN();
	~ADMIN();
};

