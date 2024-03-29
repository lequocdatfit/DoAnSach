#include "file.h"

void file::Docfile(ListSach& l, vector<TacGia>& ls_tg, vector<NXB>& ls_NXB, vector<User>&ls_users, vector<ADMIN>&ls_admin)
{
	ifstream filein;
	string ten;
	string ma;
	int gia;
	string tacgia;
	string tNXB;
	int age;
	int ansach;
	string temp;
	filein.open("Listsach.txt", ios::in);
	while (filein.eof() == false)
	{
		Sach x;
		getline(filein, ten, '\t');
		getline(filein, ma, '\t');
		filein >> gia;
		getline(filein, temp, '\t');
		getline(filein, tacgia, '\t');
		getline(filein, tNXB,'\t');
		filein >> ansach;
		getline(filein, temp, '\n');
		x.set_tensach(ten);
		x.set_masach(ma);
		x.set_giatien(gia);
		x.set_TenTacGia(tacgia);
		x.set_NhaXuatBan(tNXB);
		x.anSach = ansach;
		l.ls_sach.push_back(x);
	}
	filein.close();
	
	filein.open("TacGia.txt", ios::in);
	string name;
	string pass;
	while (filein.eof()==false)
	{
		getline(filein, name, '\t');
		getline(filein, pass);
		TacGia tg;
		tg.set_ten(name);
		tg.set_pass(pass);
		ls_tg.push_back(tg);
	}

	filein.close();

	filein.open("NXB.txt", ios::in);
	while (filein.eof()==false)
	{
		getline(filein, name, '\t');
		getline(filein, pass);
		NXB nxb;
		nxb.set_ten(name);
		nxb.set_pass(pass);
		ls_NXB.push_back(nxb);
	}
	filein.close();

	filein.open("USER.txt", ios::in);
	while (filein.eof() == false)
	{
		getline(filein, name, '\t');
		getline(filein, pass, '\t');
		filein >> age;
		getline(filein, temp);
		User us;
		us.set_name(name);
		us.set_pass(pass);
		us.set_age(age);
		ls_users.push_back(us);
	}
	filein.close();

	filein.open("ADMIN.txt", ios::in);
	while (filein.eof()==false)
	{
		getline(filein, ten, '\t');
		getline(filein, pass);
		ADMIN ad;
		ad.set_Name(ten);
		ad.set_Pass(pass);
		ls_admin.push_back(ad);
	}
	filein.close();
}

void file::GhiFileTacGia(vector<TacGia> ls_tg)
{
	fstream fileout;
	fileout.open("TacGia.txt", ios::out);
	for (int i = 0; i < ls_tg.size(); i++)
	{
		fileout << ls_tg[i].get_ten() << "\t" << ls_tg[i].get_pass() << endl;
	}
	fileout.close();
}

void file::GhiFileNXB(vector<NXB> ls_NXB)
{
	fstream fileout;
	fileout.open("NXB.txt", ios::out);
	for (int i = 0; i < ls_NXB.size(); i++)
	{
		fileout << ls_NXB[i].get_ten() << "\t" << ls_NXB[i].get_pass() << endl;
	}
	fileout.close();
}

void file::GhiFileUser(vector<User> ls_User)
{
	fstream fileout;
	fileout.open("USER.txt", ios::out);
	for (int i = 0; i < ls_User.size(); i++)
	{
		fileout << ls_User[i].getName() << "\t" << ls_User[i].getpass() << "\t" <<ls_User[i].get_Age() << endl;
	}
	fileout.close();
}

void file::GhithemUser(User x)
{
	fstream fileout;
	fileout.open("USER.txt", ios::app);
	fileout << "\n" << x.getName() << "\t" << x.getpass() << "\t" << x.get_Age();
	fileout.close();
}

void file::GhiFileSach(ListSach l)
{
	fstream fileout;
	fileout.open("Listsach.txt", ios::out);
	for (int i = 0; i < l.ls_sach.size(); i++)
	{
		fileout << "\n" << l.ls_sach[i].get_tensach() << "\t" << l.ls_sach[i].get_masach() << "\t" << l.ls_sach[i].get_giatien() << "\t" << l.ls_sach[i].get_TenTacGia() << "\t" << l.ls_sach[i].get_NhaXuatBan()<<"\t"<<l.ls_sach[i].anSach;
	}
	fileout.close();
}

void file::GhiFileHoadon(User us)
{
	fstream fileout;
	fileout.open("Hoadon.txt", ios::app);
	for (int i = 0; i < us.ls_hoadon.size(); i++)
	{
		HoaDon temp = us.ls_hoadon[i];
		fileout << "\n" << us.getName() << "\t" << temp.Get_book().get_tensach() << "\t" << temp.Get_soluong() << "\t" << temp.Get_tien();
	}
	fileout.close();
}

void file::WriteUSERages(vector<User> ls_users)
{
	vector<User>ls_userover18;
	vector<User>ls_userlesster18;
	for (int i = 0; i < ls_users.size(); i++)
	{
		if (ls_users[i].get_Age() > 18)
		{
			User temp;
			temp = ls_users[i];
			ls_userover18.push_back(temp);
		}
		else
		{
			User temp;
			temp = ls_users[i];
			ls_userlesster18.push_back(temp);
		}
	}

	fstream fileout;
	fileout.open("USER[AGESover18].txt", ios::out);
	for (int j = 0; j < ls_userover18.size(); j++)
	{
		fileout << ls_userover18[j].getName() << endl;
	}
	fileout.close();

	fileout.open("USER[AGElesster18].txt", ios::out);
	for (int k = 0; k < ls_userlesster18.size(); k++)
	{
		fileout << ls_userlesster18[k].getName() << endl;
	}
	fileout.close();
}

void file::ReadUSERover18(vector<User> &ls_users)
{
	fstream filein;
	string ten;
	filein.open("USER[AGESover18].txt", ios::in);
	while (filein.eof()==false)
	{
		User temp;
		getline(filein, ten);
		temp.set_name(ten);
		ls_users.push_back(temp);
	}
	filein.close();
}

void file::ReadUSERlesster18(vector<User>& ls_users)
{
	fstream filein;
	string ten;
	filein.open("USER[AGElesster18].txt", ios::in);
	while (filein.eof() == false)
	{
		User temp;
		getline(filein, ten);
		temp.set_name(ten);
		ls_users.push_back(temp);
	}
	filein.close();
}