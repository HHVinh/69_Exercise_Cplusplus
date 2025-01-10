#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<math.h>

bool kiemTraDauVao(const char he16[]) {
    int len = strlen(he16);

    if (len > 2) {
        printf("Chỉ được nhập tối đa 2 kí tự. Vui lòng nhập lại.\n");
        return false;
    }

    else if (len == 1) {
        if (!((he16[0] >= '0' && he16[0] <= '9') || (he16[0] >= 'a' && he16[0] <= 'f') || (he16[0] >= 'A' && he16[0] <= 'F'))) {
            printf("Dữ liệu nhập không hợp lệ. Vui lòng nhập lại.\n");
            return false;
        }
    }

    else {
        for (int i = 0; he16[i] != '\0'; i++) {
            if (!((he16[i] >= '0' && he16[i] <= '9') || (he16[i] >= 'a' && he16[i] <= 'f') || (he16[i] >= 'A' && he16[i] <= 'F'))) {
                printf("Các ký tự phải là 0->9 hoặc A->F. Vui lòng nhập lại.\n");
                return false;
            }
        }

        if (he16[0] >= '1' && he16[0] <= '9' && !(he16[1] >= 'a' && he16[1] <= 'f' || he16[1] >= 'A' && he16[1] <= 'F')) {
            printf("Các số >9 có giá trị từ A->F trong hệ 16. Vui lòng nhập lại.\n");
            return false;
        }
    }

    return true;
}

unsigned int he16SangHe10(const char he16[]) {
    unsigned int he10 = 0;
    int len = strlen(he16);

    for (int i = 0; i < len; i++) {
        char c = he16[i];
        int num;
        if (c >= '0' && c <= '9') {
            num = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            num = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            num = c - 'a' + 10;
        }
        he10 += num * pow(16, len - i - 1);
    }
    return he10;
}

int main() {
    char he16[10];

    printf("Nhập số hệ 16 (tối đa 2 ký tự là 0->9 hoặc A->F): ");
    fgets(he16, sizeof(he16), stdin);
    he16[strcspn(he16, "\n")] = '\0';

    if (!kiemTraDauVao(he16)) {
        return 0;
    }

    unsigned int he10 = he16SangHe10(he16);
    printf("Số thập phân là: %u\n", he10);

    return 0;
}
