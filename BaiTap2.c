#include <stdio.h>
#include <string.h>

// Hàm chuyển mảng 8 phần tử (0,1) thành số nguyên
int chuyenThanhSoNguyen8Bit(int A[8]) {
    int x = 0;
    for (int i = 0; i < 8; i++) {  // Duyệt từ A[0] đến A[7]
        x = (x << 1) | A[i];
    }
    
    // Nếu số âm (bit dấu A[0] == 1), chuyển về giá trị bù hai
    if (A[0] == 1) {
        x -= (1 << 8);  // Trừ 256 để chuyển thành số âm
    }
    return x;
}
// Hàm chuyển mảng 8 phần tử (0,1) thành số nguyên
int chuyenThanhSoNguyen16Bit(int A[16]) {
    int x = 0;
    for (int i = 0; i < 16; i++) {
        x = (x << 1) | A[i];
    }
    
    //Nếu số âm (bit dấu A[0] == 1), chuyển về giá trị bù hai
    if (A[0] == 1) {
        x -= (1 << 16);  // Trừ 256 để chuyển thành số âm
    }
    return x;
}
// Hàm nhập 8 bit
void nhapBit(int A[8]) {
    char chuoiBanDau[20]; // Chuỗi nhập tạm ban đầu
    int kiemTra = 0;  // Cờ kiểm tra dữ liệu nhập

    while (kiemTra == 0) {
        printf("gồm số 0 hoặc 1 (tối đa 8 số): ");
        scanf("%s", chuoiBanDau);
        
        int lenChuoiBanDau = strlen(chuoiBanDau);
        
        // Kiểm tra nếu nhập quá 8 ký tự
        if (lenChuoiBanDau > 8) {
            printf("\nLỗi: Bạn đã nhập quá 8 ký tự!\nNhập lại ");
            continue;  // Yêu cầu nhập lại
        }
        
        // Kiểm tra nếu có ký tự khác ngoài '0' hoặc '1'
        kiemTra = 1;  // Giả định đầu vào đúng
        for (int i = 0; i < lenChuoiBanDau; i++) {
            if (chuoiBanDau[i] != '0' && chuoiBanDau[i] != '1') {
                kiemTra = 0;  // Nếu có ký tự sai, đặt lại cờ
                printf("\nLỗi: Chỉ được nhập 0 hoặc 1!\nNhập lại ");
                while (getchar() != '\n');  // Xóa bộ nhớ đệm
                break;  // Thoát khỏi vòng lặp kiểm tra và yêu cầu nhập lại
            }
        }
    }

    // Khi nhập hợp lệ, chuyển chuỗi thành mảng 8 bit
    int lenChuoiBanDau = strlen(chuoiBanDau);
    int so0ConThieu = 8 - lenChuoiBanDau;

    for (int i = 0; i < so0ConThieu; i++) {
        A[i] = 0;  // Điền 0 vào đầu dãy nếu nhập thiếu
    }

    for (int i = 0; i < lenChuoiBanDau; i++) {
        A[i + so0ConThieu] = chuoiBanDau[i] - '0';  // Chuyển ký tự thành số 0 hoặc 1
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
    printf("Kết quả cộng: (%d) + (%d)", chuyenThanhSoNguyen8Bit(A),chuyenThanhSoNguyen8Bit(B));
    printf(" = %d ", chuyenThanhSoNguyen8Bit(KQ + 1));
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
    printf("Kết quả trừ: (%d) - (%d)", chuyenThanhSoNguyen8Bit(A),chuyenThanhSoNguyen8Bit(B));
    printf(" = %d ", chuyenThanhSoNguyen8Bit(KQ + 1));
    printf(", dãy nhị phân: ");
    xuatBit(KQ +1);
}
// Hàm dịch phải cho phép nhân
void dichPhai(int C[1], int D[8], int Q[8]) {
    for (int i = 7; i > 0; i--) {
        Q[i] = Q[i - 1];
    }
    Q[0] = D[7];

    for (int i = 7; i > 0; i--) {
        D[i] = D[i - 1];
    }
    D[0] = C[0];

    C[0] = 0;
}
// Hàm dịch trái cho phép chia
void dichTrai(int D[8], int Q[8]) {
    int bitDauD = D[0];  // Lưu bit dấu ban đầu của D

    for (int i = 0; i < 7; i++) {
        D[i] = D[i + 1];
    }
    D[7] = Q[0];

    for (int i = 0; i < 7; i++) {
        Q[i] = Q[i + 1];
    }
    Q[7] = 0;

    D[0] = bitDauD;  // Giữ nguyên bit dấu của D
}
// Hàm nhân 2 dãy 8 bit
void nhan2DayBit(int M[8], int Q[8],int KQ[17]) {
    int C = 0;       
    int D[8] = {0}; 
    int k = 8;
    int dauA = M[0]; int dauB = Q[0];
    int MCopy[8]; int QCopy[8];
    memcpy(MCopy, M, 8 * sizeof(int));
    memcpy(QCopy, Q, 8 * sizeof(int));
    int truM[8], truQ[8];
    
    if(MCopy[0] == 1) {
        chuyenThanhBu2(MCopy,truM);
        for(int i = 0; i < 8; i++) {
            MCopy[i] = truM[i];
        }
    }
    if(QCopy[0] == 1) {
        chuyenThanhBu2(QCopy,truQ);
        for(int i = 0; i < 8; i++) {
            QCopy[i] = truQ[i];
        }
    }

    // Khởi tạo KQ = 0
    memset(KQ, 0, 17 * sizeof(int));

    while (k > 0) {

        if (QCopy[7] == 1) {  
            // Cộng D + MCopy
            int bitNho = 0;
            for (int i = 7; i >= 0; i--) {
                int tong = D[i] + MCopy[i] + bitNho;
                D[i] = tong % 2;  
                bitNho = tong / 2;
            }
            C = bitNho;  // Cập nhật bit nhớ vào C
        }

        // Dịch phải C, D, Q
        for (int i = 7; i > 0; i--) {
            QCopy[i] = QCopy[i - 1];
        }
        QCopy[0] = D[7];

        for (int i = 7; i > 0; i--) {
            D[i] = D[i - 1];
        }
        D[0] = C;

        C = 0;  // Reset bit C sau khi dịch
        k--;
    }

    // Ghép kết quả vào KQ (C D Q)
    KQ[0] = C;
    for (int i = 0; i < 8; i++) {
        KQ[i + 1] = D[i];
        KQ[i + 9] = QCopy[i];
    }
    if( dauA != dauB) {
        for(int i = 0; i < 17; i++) {
            KQ[i] = KQ[i] ^ 1;
        }
        int bitNho = 1;
        for(int i = 16; i >= 0; i--) {
            int tong = KQ[i] + bitNho;
            KQ[i] = tong % 2;
            bitNho = tong / 2;
        }
    }
    // In kết quả
    printf("Kết quả nhân: (%d) * (%d)", chuyenThanhSoNguyen8Bit(M),chuyenThanhSoNguyen8Bit(Q));
    printf(" = %d ", chuyenThanhSoNguyen16Bit(KQ + 1));
    printf(", dãy nhị phân: ");
    for (int i = 1; i < 17; i++) {
        printf("%d", KQ[i]);
        if(i % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}
// Hàm chia 2 dãy 8 bit
void chia2DayBit(int Q[8], int M[8], int KQ[8]) {
    int k = 8;
    int E[8] = {0};    
    int KQCong[9];    
    int dauM = M[0];    
    int dauQ = Q[0];    
    int MCopy[8], QCopy[8]; 
    int truM[8];
    
    // Sao chép M và Q
    memcpy(MCopy, M, 8 * sizeof(int));
    memcpy(QCopy, Q, 8 * sizeof(int));

    // Tính bù 2 của M để thực hiện phép trừ
    chuyenThanhBu2(MCopy, truM);

    while (k > 0) {
        // Dịch trái E và Q
        dichTrai(E, QCopy);

        // Cộng E + (-M)
        int bitNho = 0;
        for (int i = 7; i >= 0; i--) {
            int tong = E[i] + truM[i] + bitNho;
            KQCong[i + 1] = tong % 2;
            bitNho = tong / 2;
        }
        KQCong[0] = bitNho;

        // Kiểm tra dấu của E - M
        if (KQCong[0] == 0) { // Nếu E - M >= 0
            QCopy[7] = 1;
            memcpy(E, &KQCong[1], 8 * sizeof(int));
        } else { // Nếu E - M < 0
            QCopy[7] = 0;
            // Khôi phục E bằng cách cộng lại M
            bitNho = 0;
            for (int i = 7; i >= 0; i--) {
                int tong = E[i] + MCopy[i] + bitNho;
                E[i] = tong % 2;
                bitNho = tong / 2;
            }
        }
        k--;
    }

    // Nếu số bị chia và số chia khác dấu, đổi dấu thương
    if (dauM != dauQ) {
        chuyenThanhBu2(QCopy, QCopy);
    }

    // Nếu Q và E khác dấu, đổi dấu E
    if ((dauQ == 1 && E[0] == 0) || (dauQ == 0 && E[0] == 1)) {
        chuyenThanhBu2(E, E);
    }

    // Đảm bảo thương đủ 8 bit (nếu có ít hơn 8 bit có nghĩa, thêm 0 vào đầu)
    memcpy(KQ, QCopy, 8 * sizeof(int));

    // In kết quả
    printf("Kết quả chia: (%d) : (%d)", chuyenThanhSoNguyen8Bit(Q), chuyenThanhSoNguyen8Bit(M));
    printf(" = %d ", chuyenThanhSoNguyen8Bit(KQ));
    printf(", dãy nhị phân: ");
    for (int i = 0; i < 8; i++) {
        printf("%d", KQ[i]);
        if (i % 4 == 3) {
            printf(" ");
        }
    }
    printf(" dư %d ", chuyenThanhSoNguyen8Bit(E));
    printf(", dãy nhị phân: ");
    for (int i = 0; i < 8; i++) {
        printf("%d", E[i]);
        if (i % 4 == 3) {
            printf(" ");
        }
    }
    printf("\n");
}
// Hàm chính
int main() {
    int A[8], B[8], truB[8], KQ_cong[9], KQ_tru[9], KQ_nhan[17], KQ_chia[8];

    // Nhập dữ liệu
    printf("\nNhập dãy bit 1, ");
    nhapBit(A);
    printf("\nNhập dãy bit 2, ");
    nhapBit(B);
    printf("\n");
    
   // Phép cộng
   cong2DayBit(A, B, KQ_cong);
   printf("\n");

   // Phép trừ
   tru2DayBit(A, B, truB, KQ_tru);
   printf("\n");

   // Phép nhân
   nhan2DayBit(A, B, KQ_nhan);
   printf("\n");

   // Phép chia
   chia2DayBit(A, B, KQ_chia);
   printf("\n");

   return 0;
}

