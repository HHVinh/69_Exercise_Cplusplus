#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

bool kiemTraDauVao(const char he2[]) {
    int len = strlen(he2);
    if (len > 8) {
        printf("Dữ liệu nhập không hợp lệ. Vui lòng nhập số nhị phân tối đa 8 ký tự.\n");
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (he2[i] != '0' && he2[i] != '1') {
            printf("Dữ liệu nhập không hợp lệ. Chỉ được nhập các ký tự 0 hoặc 1.\n");
            return false;
        }
    }
    return true;
}

unsigned int he2SangHe10(const char he2[]) {
    unsigned int he10 = 0;
    int len = strlen(he2);

    for (int i = 0; i < len; i++) {
        int num = he2[i] - '0';
        he10 += num * pow(2, len - i - 1);
    }
    return he10;
}

int main() {
    char he2[20];

    printf("Nhập số hệ 2 (tối đa 8 ký tự, chỉ bao gồm 0 và 1): ");
    fgets(he2, sizeof(he2), stdin);
    he2[strcspn(he2, "\n")] = '\0';

    if (!kiemTraDauVao(he2)) {
        return 0;
    }

    unsigned int he10 = he2SangHe10(he2);
    printf("Số thập phân là: %u\n", he10);

    return 0;
}
