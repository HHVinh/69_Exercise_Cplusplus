#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

void he16SangHe2(const char *he16) {

    int count = 0;
    char he16To2[16][5] = {
        "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
    };

    for (int i = 0; he16[i] != '\0'; i++) {
        char c = he16[i];
        int value;


        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;
        } else {
            printf("Ký tự không hợp lệ: %c\n", c);
            return;
        }

        printf("%s", he16To2[value]);
        count++;

        if (count == 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    char he16[10];

    printf("Nhập số hệ 16 (tối đa 2 ký tự là 0->9 hoặc A->F): ");
    fgets(he16, sizeof(he16), stdin);
    he16[strcspn(he16, "\n")] = '\0';

    if (!kiemTraDauVao(he16)) {
        return 0;
    }
    
    printf("Số nhị phân là: ");
    he16SangHe2(he16);

    return 0;
}
