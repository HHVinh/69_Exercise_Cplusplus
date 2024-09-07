#include <iostream>
using namespace std;

int main()
{
    cout <<"Hãy nhập giá trị của chiều dài hình chữ nhật: ";
    float a, b;
    cin >> a;
    cout <<"Hãy nhập giá trị của chiều rộng hình chữ nhật: ";
    cin >> b;

    float chuVi = (a+b)*2;
    float dienTich = (a*b);

    cout <<"Chu vi hình chữ nhật là: "<<chuVi<<endl;
    cout <<"Diện tích hình chữ nhật là :"<<dienTich<<endl;

    return 0;
    

}