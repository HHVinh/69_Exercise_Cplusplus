#include <iostream>
using namespace std;

int main()
{
    string hoTen, gioiTinh;
    int namSinh, tuoi;
    cout<<"Nhập họ và tên: ";
    getline(cin,hoTen);
    cout<<"Nhập năm sinh: ";
    cin>>namSinh;
    cout<<"Nhập giới tính: ";
    cin>>gioiTinh;
    tuoi = 2024 - namSinh;
    cout<<"Họ và tên: " <<hoTen <<"\n" <<"Năm sinh: "<<namSinh <<"\n" <<"Giới tính: "<<gioiTinh <<"\n" <<"Tuổi: "<<tuoi;
    return 0;
}