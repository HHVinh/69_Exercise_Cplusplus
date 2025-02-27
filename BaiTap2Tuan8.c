#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Hàm chuyển chuỗi nhị phân thành float
void forceFloat(float *p, char *s) {
    uint32_t intValue = 0;  // Số nguyên 32-bit để lưu giá trị nhị phân

    // Chuyển đổi chuỗi nhị phân sang số nguyên 32-bit
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '1') {
            intValue |= (1U << (31 - i));  // Gán bit vào vị trí tương ứng
        }
    }

    // Ghi giá trị vào vùng nhớ của float bằng ép kiểu con trỏ
    *((uint32_t*)p) = intValue;
}

int main() {
    char binary[33];  // Chuỗi nhị phân tối đa 32 bit + ký tự kết thúc '\0'
    float result;

    // Nhập chuỗi nhị phân
    printf("Nhập dãy nhị phân (32-bit): ");
    scanf("%32s", binary);  // Chỉ nhập tối đa 32 ký tự

    // Chuyển đổi và gán vào biến float
    forceFloat(&result, binary);

    // In ra kết quả
    printf("Số chấm động (single) tương ứng: %g\n", result);

    return 0;
}
