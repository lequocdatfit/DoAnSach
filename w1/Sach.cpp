#include "Sach.h"


void Sach::set_tensach(string s)
{
	this->ten_sach = s;
}

void Sach::set_masach(string s)
{
	this->ma_sach = s;
}

void Sach::set_giatien(int tien)
{
	this->gia = tien;
}

void Sach::set_TenTacGia(string ten)
{
	this->TenTacGia = ten;
}

void Sach::set_NhaXuatBan(string ten)
{
	this->NhaXuatBan = ten;
}

string Sach::get_TenTacGia()
{
	return this->TenTacGia;
}

string Sach::get_NhaXuatBan()
{
	return NhaXuatBan;
}

string Sach::get_tensach()
{
	return this->ten_sach;
}

string Sach::get_masach()
{
	return this->ma_sach;
}

int Sach::get_giatien()
{
	return this->gia;
}

Sach::Sach()
{
	this->gia = 1000;
	this->ten_sach = "\0";
	this->ma_sach = "\0";
	this->anSach = 0;
}


Sach::~Sach()
{
	this->ten_sach = "\0";
	this->gia = 0;
	this->ma_sach = "\0";
	this->anSach = 0;
}
