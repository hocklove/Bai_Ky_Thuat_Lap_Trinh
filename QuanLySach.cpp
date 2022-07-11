#include <iostream>
#include <string.h>
#include <conio.h>
#define SIZE 100
using namespace std;

struct Sach
{
    int ma_sach;
    char ten_sach[30];
    char ten_tac_gia[30];
    char loai_sach[30];
    int nam_xuat_ban;
    double gia_tien;
    int so_luong;
};


void Menu()
{
    cout << endl << "===============MENU===============" << endl;
    cout << "a. Nhap thong tin cac cuon sach. " << endl;
    cout << "b. Xuat thong tin cac cuon sach. " << endl;
    cout << "c. Them mot cuon sach. " << endl;
    cout << "d. Tinh tong thanh tien tat ca cac cuon sach. " << endl;
    cout << "e. Sap xep cac cuon sach theo ma sach. " << endl;
    cout << "f. Tim sach theo ten. " << endl;
    cout << "g. Xuat thong tin cac cuon sach co nam xuat ban truoc nam 2000. " << endl;
    cout << "h. Dem so luong sach co gia tri lon hon 50000vnd. " << endl;
    cout << "i. Xuat thong tin cac cuon sach theo loai (Do nguoi dung nhap). " << endl;
    cout << "x. Dung chuong trinh. " << endl;
    cout << "===============HET===============" << endl;
}

void xoaXuongDong(char x[])
{
    size_t len = strlen(x);
    if(x[len - 1] == '\n')
    {
        x[len - 1] = '\0';
    }
}

void nhapPhimBatKy()
{
    cout << "Nhap phim bat ky de tiep tuc!!" << endl;
    getch();
}

void nhapLuaChon(char &select)
{
    cout << "-> Vui long chon mot cong viec: ";
    cin >> select;
}

void nhapSoLuongDanhSach(int &n)
{
    do{
        cout << "Nhap so luong cuon sach: ";
        cin >> n;
    } while (n < 0);
}

void nhapMotCuonSach(Sach &sach)
{
    cout << "- Nhap ma sach: ";
    cin >> sach.ma_sach;
    cout << "- Nhap ten sach: ";
    fflush(stdin); fgets(sach.ten_sach, sizeof(sach.ten_sach), stdin); xoaXuongDong(sach.ten_sach);
    cout << "- Nhap ten tac gia: ";
    fflush(stdin); fgets(sach.ten_tac_gia, sizeof(sach.ten_tac_gia), stdin); xoaXuongDong(sach.ten_tac_gia);
    cout << "- Nhap loai sach: ";
    fflush(stdin); fgets(sach.loai_sach, sizeof(sach.loai_sach), stdin); xoaXuongDong(sach.loai_sach);
    cout << "- Nhap nam xuat ban: ";
    cin >> sach.nam_xuat_ban;
    cout << "- Nhap gia tien: ";
    cin >> sach.gia_tien;
    cout << "- Nhap so luong sach: ";
    cin >> sach.so_luong;
}

void xuatMotCuonSach(Sach sach)
{
    cout << "- Ma sach: " << sach.ma_sach << endl;
    cout << "- Ten sach: ";
    puts(strupr(sach.ten_sach));
    cout << "- Tac gia: ";
    puts(strupr(sach.ten_tac_gia));
    cout << "- The loai: ";
    puts(strupr(sach.loai_sach));
    cout << "- Nam xuat ban: " << sach.nam_xuat_ban << endl;
    cout << "- Gia tien: " << sach.gia_tien << "vnd" << endl;
    cout << "- So luong: " << sach.so_luong << endl;
}

void nhapDanhSach(Sach ds[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "STT: " << i + 1 << endl;
        nhapMotCuonSach(ds[i]);
    }
}

void xuatDanhSach(Sach ds[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "STT: " << i + 1 << endl;
        xuatMotCuonSach(ds[i]);
    }
    delete[] ds;
}

void themMotCuonSach(Sach ds[], int &n)
{
    n += 1;
    nhapMotCuonSach(ds[n - 1]);
    delete[] ds;
}

double tienTatCaCuonSach(Sach ds[], int n)
{
    double thanh_tien = 0;
    for(int i = 0; i < n; i++)
    {
        thanh_tien += ds[i].gia_tien;
    }
    return thanh_tien;
}

void sapXepDanhSach(Sach ds[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n - 1; j++)
        {
            int temp = ds[i].ma_sach;
            ds[i].ma_sach = ds[j].ma_sach;
            ds[j].ma_sach = temp;
        }
    }
}

void timSachTheoTen(Sach ds[], int n)
{
    int flag = 0;
    char ten_sach[50];
    cout << "-> Nhap ten sach can tim: ";
    fflush(stdin); fgets(ten_sach, sizeof(ten_sach), stdin); xoaXuongDong(ten_sach);
    for(int i = 0; i < n; i++)
    {
        if(strcmp(strupr(ds[i].ten_sach), strupr(ten_sach)) == 0)
        {
            xuatMotCuonSach(ds[i]);
            flag ++;
        }
    }
    if(flag == 0)
    {
        cout << "Khong tim thay!\n";
    }
}

// thong tin sach truoc nam 2000
void xuatThongTinSach(Sach ds[], int n)
{
    int flag = 0;
    for(int i = 0; i < n; i++)
    {
        if(ds[i].nam_xuat_ban <= 2000)
        {
            xuatMotCuonSach(ds[i]);
            flag ++;
        }
    }
    if(flag == 0)
    {
        cout << "Khong co sach nao phu hop!\n";
    }
}

// so luong sach co gia tren 50000
int demSach(Sach ds[], int n)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(ds[i].gia_tien >= 50000)
        {
            count ++;
        }
    }
    return count;
}

// danh sach cac quyen sach theo loai
void thongTinSach(Sach ds[], int n)
{
    int flag = 0;
    char loai_sach[50];
    cout << "-> Nhap the loai: ";
    fflush(stdin); fgets(loai_sach, sizeof(loai_sach), stdin); xoaXuongDong(loai_sach);
    for(int i = 0; i < n; i++)
    {
        if(strcmp(strupr(ds[i].loai_sach), strupr(loai_sach)) == 0)
        {
            xuatMotCuonSach(ds[i]);
            flag ++;
        }
    }
    if(flag == 0)
    {
        cout << "Khong co sach nao de hien thi!\n";
    }
}

void Handling(char select)
{
    Sach ds[SIZE];
    int n;
    switch(select)
    {
        case 'a':
            nhapSoLuongDanhSach(n);
            nhapDanhSach(ds, n);
            nhapPhimBatKy();
            break;
        case 'b':
            xuatDanhSach(ds, n);
            nhapPhimBatKy();
            break;
        case 'c':
            themMotCuonSach(ds, n);
            cout << "Nhap phim bat ky de hien thi lai danh sach!\n";
            getch();
            xuatDanhSach(ds, n);
            nhapPhimBatKy();
            break;
        case 'd':
            cout << "Tien cua tat ca cac cuon sach la: " << tienTatCaCuonSach(ds, n) << endl;
            nhapPhimBatKy();
            break;
        case 'e':
            sapXepDanhSach(ds, n);
            cout << "Nhap phim bat ky de cap nhat lai danh sach!! \n" << endl;
            getch();
            xuatDanhSach(ds, n);
            nhapPhimBatKy();
            break;
        case 'f':
            timSachTheoTen(ds, n);
            nhapPhimBatKy();
            break;
        case 'g':
            xuatThongTinSach(ds, n);
            nhapPhimBatKy();
            break;
        case 'h':
            cout << "So luong sach co gia tren 50000 la: " << demSach(ds, n) << " quyen" << endl;
            nhapPhimBatKy();
            break;
        case 'i':
            thongTinSach(ds, n);
            nhapPhimBatKy();
            break;
        case 'x':
            cout << "\nCHAO TAM BIET!!\n";
            break;
        default:
            cout << "Lua chon khong hop le. Nhap phim bat ky de chon lai!!\n";
            getch();
    }
}

int main()
{
    char select;
    do{
        Menu();
        nhapLuaChon(select);
        Handling(select);
    } while(select != 'x');
    return 0;
}
