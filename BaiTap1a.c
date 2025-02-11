#include <stdio.h>

// Hàm in số nguyên 4 byte dưới dạng nhị phân
void docSoNhiPhan(int x) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
        if (i % 8 == 0) printf(" ");  // Cách mỗi 8 bit để dễ đọc
    }
    printf("\n");
}

int main() {
    int num;

    printf("Hãy nhập một số nguyên bất kỳ (-2,147,483,648 đến 2,147,483,647): ");
    scanf("%d", &num);

    printf("Dạng nhị phân của %d là: \n", num);
    docSoNhiPhan(num);

    return 0;
}

