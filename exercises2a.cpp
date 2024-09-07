#include <iostream>
using namespace std;

int main()
{
    double toan, van, dtb;
    cout <<"Nhập điểm toán: ";
    cin >> toan;
    cout <<"Nhập điểm văn: ";
    cin >> van;
    dtb = (toan + van)/2;
    cout <<"Điểm trung bình 2 môn là: " << dtb <<"\n";
    return 0;
}