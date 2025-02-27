#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

// Hàm hiển thị nhị phân của số float
void dumpFloat(float *p) {
    uint32_t *intPtr = (uint32_t*)p;  // Ép kiểu float thành số nguyên 32-bit
    uint32_t value = *intPtr;

    // In phần dấu
    printf("%d ", (value >> 31) & 1);

    // In phần mũ (8 bit)
    for (int i = 30; i >= 23; i--) {
        printf("%d", (value >> i) & 1);
    }
    printf(" ");

    // In phần trị (23 bit)
    for (int i = 22; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
    }
    printf("\n");
}

// Hàm tạo số float từ chuỗi nhị phân
void forceFloat(float *p, char *s) {
    uint32_t intValue = 0;
    int len = strlen(s);

    // Chuyển chuỗi nhị phân sang số nguyên 32-bit
    for (int i = 0; i < len; i++) {
        if (s[i] == '1') {
            intValue |= (1U << (31 - i));
        }
    }
    // Ghi vào vùng nhớ float
    *((uint32_t*)p) = intValue;
}

int main() {
    float num;

    // Biểu diễn nhị phân của 1.3E+20
    num = 1.3E+20;
    printf("Biểu diễn nhị phân của 1.3E+20: ");
    dumpFloat(&num);

    // Số float nhỏ nhất lớn hơn 0
    num = 1.17549435E-38F;  // Giá trị gần nhất của float > 0
    printf("\nSố float nhỏ nhất lớn hơn 0: %e\n", num);
    printf("Biểu diễn nhị phân: ");
    dumpFloat(&num);

    // Khảo sát các số đặc biệt

    // INF (vô cực dương)
    num = INFINITY;
    printf("\n+∞ (INF): ");
    dumpFloat(&num);

    // -INF (vô cực âm)
    num = -INFINITY;
    printf("-∞ (INF): ");
    dumpFloat(&num);

    // NaN (Not a Number)
    num = NAN;
    printf("NaN: ");
    dumpFloat(&num);

    // Các phép toán đặc biệt
    float x = 10.0;

    printf("\nKhảo sát các phép toán đặc biệt:\n");
    printf("10 - (+∞) = %f", x - INFINITY); printf(" (Một số thực trừ cho dương vô cùng sẽ ra âm vô cùng)\n");
    printf("(+∞) - (+∞) = %f", INFINITY - INFINITY); printf(" (Dương vô cùng trừ dương vô cùng sẽ ra không xác định)\n");
    printf("10 / 0 = %f", x / 0.0); printf(" (Chia một số thực dương cho 0.0 sẽ ra dương vô cùng)\n");
    printf("0 / 0 = %f", 0.0 / 0.0); printf(" (0.0 chia 0.0 sẽ ra không xác định)\n");
    printf("(+∞) / (+∞) = %f", INFINITY / INFINITY); printf(" (Dương vô cùng chia dương vô cùng sẽ ra không xác định)\n");
    printf("sqrt(-10) = %f", sqrt(-10)); printf(" (Căn bậc 2 của một số âm sẽ ra không xác định)\n");

    return 0;
}
