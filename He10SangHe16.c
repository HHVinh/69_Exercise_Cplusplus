#include <stdio.h>

void he10SangHe16(unsigned int num) {
    unsigned int count = 2;
    char he16[count];

    int viTri = count - 1;
    while (num > 0 && viTri >= 0) {
        int phanDu = num % 16;

        if (phanDu < 10) {
            he16[viTri] = '0' + phanDu;
        }
        else {
            he16[viTri] = 'A' + (phanDu - 10);
        }

        num = num / 16;
        viTri--;
    }

    printf("Dãy thập lục phân là: ");
    for (int i = 0; i < count; i++) {
        if (he16[i] != 0) {
            printf("%c", he16[i]);
        } else {
            printf("0");
        }
    }
    printf("\n");
}

int main() {
    unsigned int num;
    
    printf("Hãy nhập một số nguyên bất kì từ 0 đến 255: ");
    scanf("%u", &num);

    if (num > 255) {
        printf("Bạn đã nhập dữ liệu sai. Vui lòng nhập lại.\n");
        return 1;
    }

    he10SangHe16(num);
    return 0;
}

