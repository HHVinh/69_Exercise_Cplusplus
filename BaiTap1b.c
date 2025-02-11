#include <stdio.h>

// Hàm chuyển mảng 32 phần tử (0,1) thành số nguyên
int chuyenThanhSoNguyen(int A[32]) {
    int x = 0;
    for (int i = 0; i < 32; i++) {
        x = (x << 1) | A[i];  // Dịch trái `x` sang trái 1 bit và thêm `A[i]`
    }
    return x;
}

// Hàm nhập 32 bit từ người dùng
void nhapBit(int A[32]) {
    int i = 0;
    while (i < 32) {  
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

// Hàm xuất 32 bit
void xuatBit(int A[32]) {
    for (int i = 0; i < 32; i++) {
        printf("%d", A[i]);
        if (i % 8 == 7 && i != 31) printf(" ");
    }
    printf("\n");
}

int main() {
    int A[32];

    // Nhập dữ liệu
    printf("\nNhập 32 bit (chỉ gồm 0 hoặc 1): ");
    nhapBit(A);

    // Trình bày cho đẹp
    printf("\nDãy bit vừa nhập là: ");
    xuatBit(A);

    // Chuyển mảng thành số nguyên
    int x = chuyenThanhSoNguyen(A);

    // Xuất kết quả
    printf("Số nguyên được tạo từ mảng là: %d\n", x);

    return 0;
}
