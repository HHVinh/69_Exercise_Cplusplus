#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    cout <<"Hãy nhập bán kính hình tròn: \n";
    float r;
    cin >> r;

    float chuVi = M_PI * 2 * r;
    float dienTich = M_PI * r * r;

    cout <<" Chu vi của hình tròn bán kính "<<r<<" là: "<<chuVi<<endl;
    cout <<" Diện tích của hình tròn bán kính "<<r<<" là: "<<dienTich<<endl;

    return 0;

}