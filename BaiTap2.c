#include <stdio.h>

// Hàm chuyển mảng 8 phần tử (0,1) thành số nguyên
int chuyenThanhSoNguyen(int A[8]) {
    int x = 0;
    for (int i = 0; i < 8; i++) {
        x = (x << 1) | A[i];  // Dịch trái `x` sang trái 1 bit và thêm `A[i]`
    }
    return x;
}

// Hàm nhập 8 bit từ người dùng
void nhapBit(int A[8]) {
    int i = 0;
    while (i < 8) {  
        // Kiểm tra nhập 1 chữ số (0 hoặc 1)
        if (scanf("%1d", &A[i]) != 1 || (A[i] != 0 && A[i] != 1)) {
            printf("Lỗi: Chỉ được nhập 0 hoặc 1. Hãy nhập lại từ đầu!\n");
            while (getchar() != '\n'); // Xóa bộ nhớ đệm tránh lỗi lặp vô hạn
            i = 0;
        } else {
            i++; // Chỉ tăng nếu nhập đúng
        }
    }
}

// Hàm xuất 8 bit
void xuatBit(int A[8]) {
    for (int i = 0; i < 8; i++) {
        printf("%d", A[i]);
        if (i % 4 == 3 && i != 7) printf(" ");
    }
    printf("\n");
}

int cong2DayBit(int A[8], int B[8], int KQ[9]) {
    int bitNho = 0;
    for(int i = 7 ; i >= 0; i--) {
        if(A[i] + B[i] == 0) {
            KQ[i] = 0; bitNho = 0;
        }
        if(A[i] + B[i] == 1) {
            KQ[i] = 0;
        }
    }
}

int main() {
    int A[8]; int B[8];

    // Nhập dữ liệu
    printf("\nNhập 8 bit dãy số 1 (chỉ gồm 0 hoặc 1): ");
    nhapBit(A);
    printf("\nNhập 8 bit dãy số 2 (chỉ gồm 0 hoặc 1): ");
    nhapBit(B);

    // Chuyển mảng thành số nguyên
    int x = chuyenThanhSoNguyen(A);

    // Xuất kết quả
    printf("Số nguyên được tạo từ mảng là: %d\n", x);

    return 0;
}
