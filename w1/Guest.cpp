#include "Guest.h"

Sach* Guest::Timsach(ListSach &l)
{
	int timthay = 0;
	cin.ignore();
	do
	{
		cout << "Nhap ten sach" << endl;
		string ten;
		getline(cin, ten);
		int dem = 0;
		int x[100];
		for (int i = 0; i < l.ls_sach.size(); i++)
		{
			if (l.ls_sach[i].get_tensach() == ten && l.ls_sach[i].anSach == 0)
			{
				x[dem++] = i;
			}
		}
		if (dem == 1)
		{
			cout << "Da tim thay 1 sach" << endl;
			cout << "Ten sach: " << l.ls_sach[x[0]].get_tensach() << endl;
			cout << "Ma sach: " << l.ls_sach[x[0]].get_masach() << endl;
			cout << "Gia tien: " << l.ls_sach[x[0]].get_giatien() << endl;
			return &l.ls_sach[x[0]];
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
					if (l.ls_sach[x[i]].get_masach() == ma)
					{
						cout << "Ten sach: " << l.ls_sach[x[i]].get_tensach() << endl;
						cout << "Ma sach: " << l.ls_sach[x[i]].get_masach() << endl;
						cout << "Gia tien: " << l.ls_sach[x[i]].get_giatien() << endl;
						return &l.ls_sach[x[i]];
					}
				}
			}
			else
			{
				cout << "Khong tim thay sach nay" << endl;
				system("pause");
			}
		}
	} while (timthay == 0);
}

Guest::Guest()
{

}


Guest::~Guest()
{
}
