#include <stdio.h>

// Hàm xuất ra biểu diễn nhị phân của float 32-bit theo IEEE 754
void dumpFloat(float *p) {
    // Ép kiểu float thành unsigned int 32-bit để thao tác bit
    unsigned int bits = *(unsigned int*)p;

    // Tách các phần của số dấu chấm động
    unsigned int sign = (bits >> 31) & 1;         // Lấy bit dấu (bit 31)
    unsigned int exponent = (bits >> 23) & 0xFF;  // Lấy phần mũ (8 bit tiếp theo)
    unsigned int mantissa = bits & 0x7FFFFF;      // Lấy phần trị (23 bit cuối)

    // In kết quả
    printf("%u ", sign);  // In bit dấu

    // In phần mũ (8 bit)
    for (int i = 7; i >= 0; i--) {
        printf("%u", (exponent >> i) & 1);
    }
    printf(" ");

    // In phần trị (23 bit)
    for (int i = 22; i >= 0; i--) {
        printf("%u", (mantissa >> i) & 1);
    }

    printf("\n");
}

int main() {
    float x;
    printf("Nhập vào số chấm động (32-bit): ");
    scanf("%f", &x);  // Nhập số float từ bàn phím
    printf("Biểu diễn nhị phân tương ứng: ");
    dumpFloat(&x);  // Xuất ra nhị phân
    return 0;
}
