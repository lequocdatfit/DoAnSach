#include "ListSach.h"
#include "string.h"

void ListSach::Nhap(Sach x)
{
	this->ls_sach.push_back(x);		
}

void ListSach::Nhap_n_sach()
{
	int soluong;
	cout << "Nhap so luong sach" << endl;
	cin >> soluong;
	for (int i = 0; i < soluong; i++)
	{
		Sach x;
		string ten;
		string ma;
		int anTacgia;
		int anNXB;
		int gia;
		cin.ignore();
		cout << "Nhap ten sach: " << endl;
		getline(cin, ten);
		x.set_tensach(ten);
		cout << "Nhap ma sach: " << endl;
		getline(cin, ma);
		x.set_masach(ma);
		cout << "Nhap gia tien: " << endl;
		cin >> gia;
		x.set_giatien(gia);
		cin.ignore();
		cout << "Nhap ten tac gia: " << endl;
		getline(cin, ten);
		x.set_TenTacGia(ten);
		cout << "Nhap nha xuat ban: " << endl;
		getline(cin, ten);
		x.set_NhaXuatBan(ten);
		this->ls_sach.push_back(x);
	}
}

void ListSach::Xoa1sach(int pos)
{
	ls_sach.erase(ls_sach.begin() + pos);
}

void ListSach::Timkiemvacapnhat(string ten)
{
	int dem = 0;
	int x[100];
	int luachon;
	for (int i = 0; i < this->ls_sach.size(); i++)
	{
		if (ls_sach[i].get_tensach() == ten)
		{
			x[dem++] = i;
		}
	}
	if (dem == 1)
	{
		cout << "Ban muon xoa hay cap nhat gia tri (thoat: so #, xoa: 1, cap nhat gia: 2)" << endl;
		cin >> luachon;
		cin.ignore();
		if (luachon == 1)
		{
			this->ls_sach[x[0]].~Sach();
			this->Xoa1sach(x[0]);
			cout << "Xoa thanh cong" << endl;
		}
		else
		{
			if (luachon == 2)
			{
				cout << "cap nhat gia tien: " << endl;
				int gia;
				cin >> gia;
				cin.ignore();
				this->ls_sach[x[0]].set_giatien(gia);
				cout << "cap nhat gia thanh cong." << endl;
			}
		}
	}
	else
	{
		if (dem > 1)
		{
			string ma;
			cout << "co " << dem << " quyen sach cung ten" << endl;
			cout << "Nhap ma sach can tim: " << endl;
			getline(cin, ma);
			for (int i = 0; i < dem; i++)
			{
				if (ls_sach[x[i]].get_masach() == ma)
				{
					cout << "Ban muon xoa hay cap nhat gia tri (xoa: 1, cap nhat gia: 2)" << endl;
					cin >> luachon;
					cin.ignore();
					if (luachon == 1)
					{
						this->ls_sach[x[i]].~Sach();
						this->Xoa1sach(x[i]);
						cout << "Da xoa" << endl;
					}
					else
					{
						if (luachon == 2)
						{
							cout << "cap nhat gia tien: " << endl;
							int gia;
							cin >> gia;
							cin.ignore();
							this->ls_sach[x[i]].set_giatien(gia);
							cout << "Cap nhat thanh cong" << endl;
						}
					}
				}
			}
		}
		else
		{
			cout << "Khong tim thay sach nao co ten da nhap." << endl;
		}
	}
}

void ListSach::Docfilesach()
{
	ifstream filein;
	string ten;
	string ma;
	int gia;
	string tacgia;
	string NXB;
	int antacgia;
	int annxb;
	string temp;
	filein.open("Listsach.txt", ios::in);
	while (filein.eof() == false)
	{
		Sach x;
		getline(filein, ten, '\t');
		getline(filein, ma, '\t');
		filein >> gia;
		getline(filein, temp,'\t');
		getline(filein, tacgia,'\t');
		getline(filein, NXB,'\t');
		filein >> antacgia;
		filein >> annxb;
		getline(filein, temp);
		x.set_tensach(ten);
		x.set_masach(ma);
		x.set_giatien(gia);
		x.set_TenTacGia(tacgia);
		x.set_NhaXuatBan(NXB);
		this->ls_sach.push_back(x);
	}
	filein.close();
}

void ListSach::Xuat()
{
	for (int i = 0; i < this->ls_sach.size(); i++)
	{
		cout << "Ten sach: " << this->ls_sach[i].get_tensach() <<endl;
		cout << "Ma sach: " << this->ls_sach[i].get_masach() << endl;
		cout << "Gia tien: " << this->ls_sach[i].get_giatien() << endl;
	}
}


ListSach::ListSach()
{

}


ListSach::~ListSach()
{

}
