#pragma once
#include "Sach.h"
#include "ListSach.h"
class HoaDon
{
private:
	Sach book;
	int tien;
	int soluong;
public:
	void Tinhhoadon(ListSach list);
	void Set_book(Sach x);
	void Set_Tien(int money);
	void Set_soluong(int cuon);
	int Get_tien();
	Sach Get_book();
	int Get_soluong();
	HoaDon();
	~HoaDon();
};

