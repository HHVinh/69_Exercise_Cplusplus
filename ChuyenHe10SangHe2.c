#include <stdio.h>

// Hàm chuyển số sang nhị phân với số bit cố định
void decimalToBinaryWithBits(int n, int bits) {
    int binary[32];
    for (int i = bits - 1; i >= 0; i--) {
        binary[i] = n & 1; // Lấy bit cuối cùng của n
        n >>= 1;          // Dịch phải n 1 bit
    }

    // In kết quả
    printf("Số nhị phân (%d-bit): ", bits);
    for (int i = 0; i < bits; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int bits = 4; // Số bit để biểu diễn nhị phân (8 bit, 16 bit, tùy chọn)

    printf("Nhập số nguyên n (có thể âm): ");
    while (scanf("%d", &n) != 1) {
        printf("Dữ liệu nhập không hợp lệ. Hãy nhập một số nguyên.\n");
        while (getchar() != '\n'); // Xóa bộ đệm
    }

    // Chuyển đổi sang nhị phân
    decimalToBinaryWithBits(n, bits);

    return 0;
}
