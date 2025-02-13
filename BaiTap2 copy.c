#include <stdio.h>
#include <string.h>

// Hàm chuyển mảng 8 phần tử (0,1) thành số nguyên
int chuyenThanhSoNguyen(int A[8]) {
    int x = 0;
    for (int i = 0; i < 8; i++) {  // Duyệt từ A[1] đến A[8]
        x = (x << 1) | A[i];
    }
    
    // Nếu số âm (bit dấu A[1] == 1), chuyển về giá trị bù hai
    if (A[0] == 1) {
        x -= (1 << 8);  // Trừ 256 để chuyển thành số âm
    }
    return x;
}

// Hàm nhập 8 bit
void nhapBit(int A[8]) {
    // int i = 0;
    // while (i < 8) {  
    //     // Kiểm tra nhập 1 chữ số (0 hoặc 1)
    //     if (scanf("%1d", &A[i]) != 1 || (A[i] != 0 && A[i] != 1)) {
    //         printf("Lỗi: Chỉ được nhập 0 hoặc 1. Hãy nhập lại từ đầu!\n");
    //         while (getchar() != '\n'); // Xóa bộ nhớ đệm tránh lỗi lặp vô hạn
    //         i = 0;
    //     } else {
    //         i++; // Chỉ tăng nếu nhập đúng
    //     }
    // }
    char chuoiBanDau[10]; // Chuỗi nhập tạm ban đầu
    printf("gồm số 0 hoặc 1 (tối đa 8 số): ");
    scanf("%8s", chuoiBanDau);
    int lenChuoiBanDau = strlen(chuoiBanDau);
    if(lenChuoiBanDau > 8) {
        printf("Lỗi: Bạn đã nhập quá 8 ký tự!\n");
    }
    int kiemTra = 1;
    for(int i = 0; i < lenChuoiBanDau; i++) {
        if(chuoiBanDau[i] != '0' && chuoiBanDau[i] != '1') {
            kiemTra = 0;  // Nếu có ký tự sai, đặt lại cờ
            printf("Lỗi: Chỉ được nhập 0 hoặc 1. Hãy nhập lại!\n");
            while (getchar() != '\n');  // Xóa bộ nhớ đệm
            break;
        }
    }
    if(kiemTra) {
        int so0ConThieu = 8 - lenChuoiBanDau;

        for(int i = 0; i < so0ConThieu; i ++) {
            A[i] = 0;
        }

        for(int i = 0; i < lenChuoiBanDau; i++) {
            A[i + so0ConThieu] = chuoiBanDau[i] - '0';
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

// Hàm cộng 2 dãy 8 bit
void cong2DayBit(int A[8], int B[8], int KQ[9]) {
    int bitNho = 0;
    for (int i = 7; i >= 0; i--) {
        int tong = A[i] + B[i] + bitNho;
        KQ[i + 1] = tong % 2;  // Lưu bit kết quả vào KQ[1] đến KQ[8]
        bitNho = tong / 2;      // Cập nhật bit nhớ
    }
    KQ[0] = bitNho;  // Lưu bit nhớ vào KQ[0] (bit cao nhất)
    
    // Kiểm tra tràn số có dấu (signed)
    if ((A[0] == B[0]) && (A[0] != KQ[1])) {
        printf("\nCảnh báo: Tràn số phép cộng!\n");
    }
    printf("Kết quả cộng: (%d) + (%d)", chuyenThanhSoNguyen(A),chuyenThanhSoNguyen(B));
    printf(" = %d ", chuyenThanhSoNguyen(KQ + 1));
    printf(", dãy nhị phân: ");
    xuatBit(KQ +1);
}

// Hàm chuyển B thành -B (đảo bit + 1)
void chuyenThanhBu2(int B[8], int KQ[8]) {
    int bitNho = 1;
    // Bước 1: Đảo bit (XOR với 1)
    for (int i = 0; i < 8; i++) {
        KQ[i] = B[i] ^ 1;
    }

    // Bước 2: Cộng 1 vào kết quả đã đảo bit
    for (int i = 7; i >= 0; i--) {
        int tong = KQ[i] + bitNho;
        KQ[i] = tong % 2;  // Lấy phần dư
        bitNho = tong / 2;  // Cập nhật bit nhớ
    }
}

// Hàm trừ 2 dãy 8 bit
void tru2DayBit(int A[8], int B[8], int truB[8], int KQ[9]) {
    chuyenThanhBu2(B,truB);
    int bitNho = 0;
    for(int i = 7; i >=0; i--) {
        int tong = A[i] + truB[i] + bitNho;
        KQ[i+1] = tong %2;
        bitNho = tong / 2;
    }
    KQ[0] = bitNho;

    // Kiểm tra tràn số có dấu (signed)
    if ((A[0] == 0 && B[0] == 1 && KQ[1] == 1) || 
        (A[0] == 1 && B[0] == 0 && KQ[1] == 0)) {
        printf("\nCảnh báo: Tràn số phép trừ!\n");
    }
    printf("Kết quả trừ: (%d) - (%d)", chuyenThanhSoNguyen(A),chuyenThanhSoNguyen(B));
    printf(" = %d ", chuyenThanhSoNguyen(KQ + 1));
    printf(", dãy nhị phân: ");
    xuatBit(KQ +1);
}

// Hàm nhân 2 dãy 8 bit
void nhan2DayBit(int A[8], int B[8], int KQ[17]) {
    int k = 0;
}

int main() {
    int A[8], B[8], truB[8], KQ_cong[9], KQ_tru[9];

    // Nhập dữ liệu
    printf("\nNhập dãy bit 1, ");
    nhapBit(A);
    printf("\nNhập dãy bit 2, ");
    nhapBit(B);
    printf("\n");
    
    // Thực hiện phép cộng
    cong2DayBit(A, B, KQ_cong);
    printf("\n");

    // Thực hiện phép trừ
    tru2DayBit(A, B, truB, KQ_tru);
    printf("\n");

    return 0;
}

