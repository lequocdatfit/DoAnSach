#pragma once
#include"ListSach.h"
#include "TacGia.h"
#include "User.h"
#include "NXB.h"

class file
{
public:
	void Docfile(ListSach &l, vector<TacGia>&ls_tg, vector<NXB>&NXB, vector<User>&ls_users);
	void GhiFileTacGia(vector<TacGia>ls_tg);
	void GhiFileNXB(vector<NXB>ls_NXB);
	void GhiFileUser(vector<User>ls_User);
	void WriteUSERages(vector<User>ls_users);
	void ReadUSERover18(vector<User>&ls_users);
	void ReadUSERlesster18(vector<User> &ls_users);
};

