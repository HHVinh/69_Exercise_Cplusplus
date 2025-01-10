#include <stdio.h>
void he10SangHe2(unsigned int num) {
    unsigned int count = 8;
    unsigned int he2[count];

    for (int i = 0; i < count; i++) {
        he2[i] = 0;
    }

    for (int i = count - 1; i >= 0; i--) {
        he2[i] = num % 2;
        num = num / 2;
    }

    printf("Dãy nhị phân là: ");
    for (int i = 0; i < count; i++) {
        printf("%d", he2[i]);
        if ((i + 1) % 4 == 0 && i < count - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    unsigned int num;

    printf("Hãy nhập một số nguyên bất kì từ 0 đến 255): ");
    scanf("%u", &num);

    if (num > 255) {
        printf("Bạn đã nhập dữ liệu sai.\n");
        return 1;
    }
    
    he10SangHe2(num);
    return 0;
}
