#include <stdio.h>

int main() {
    float f = 3.14159;
    int i = 10;

    printf("\nCâu 1 Chuyển đổi float -> int -> float\n");
    float f1 = 3.9;
    int i1 = (int) f1;
    float f2 = (float) i1;
    printf("Ban đầu: float = %f\n", f1);
    printf("Ép sang int: %d\n", i1);
    printf("Ép ngược lại float: %f\n", f2);
    printf("Kết quả không như ban đầu vì phần thập phân bị mất khi ép kiểu sang int.\n");

    printf("\n---------------------------------------------------------------------------------------------\n");

    printf("\nCâu 2 Chuyển đổi int -> float -> int\n");
    int i2 = 123456789;
    float f3 = (float) i2;
    int i3 = (int) f3;
    printf("Ban đầu: int = %d\n", i2);
    printf("Ép sang float: %f\n", f3);
    printf("Ép ngược lại int: %d\n", i3);
    printf("Kết quả không như ban đầu vì float không thể lưu chính xác số int lớn, dẫn đến làm tròn sai.\n");

    printf("\n---------------------------------------------------------------------------------------------\n");

    printf("\nCâu 3 Kiểm tra tính kết hợp của phép cộng\n");
    float x = 1.0e10, y = -1.0e10, z = 1.0;
    printf("Giá trị ban đầu: x = %f, y = %f, z = %f\n", x, y, z);
    float res1 = (x + y) + z;
    float res2 = x + (y + z);
    printf("(x+y)+z = %f\n", res1);
    printf("x+(y+z) = %f\n", res2);
    printf("Kết quả %s giống nhau.\n", (res1 == res2) ? "có" : "không");
    printf("Lý do:\n");
    printf("   - Phép cộng số chấm động không luôn có tính kết hợp do lỗi làm tròn.\n");
    printf("   - Khi cộng số lớn với số nhỏ, số nhỏ có thể bị bỏ qua.\n");


    printf("\n---------------------------------------------------------------------------------------------\n");

    printf("\nCâu 4 i = (int) (3.14159 * f)\n");
    int i4 = i; float f4 = f;
    printf("Trước khi ép kiểu: f = %f, 3.14159 * f = %f\n", f4, 3.14159 * f4);
    printf("Ép kiểu: ");
    i4 = (int) (3.14159 * f4);
    printf("i = (int) (3.14159 * f) = %d\n", i4);
    printf("Khi ép kiểu float -> int, phần thập phân bị cắt bỏ chứ không làm tròn.\n");

    printf("\n---------------------------------------------------------------------------------------------\n");
    
    printf("\nCâu 5 f = f + (float) i\n");
    int i5 = i; float f5 = f;
    printf("Trước khi ép kiểu: f = %f, i = %d", f5, i5);
    printf(", f + i = %f\n", f5 + i5);
    printf("Ép kiểu: ");
    f5 = f5 + (float) i5;
    printf("f = f + (float) i = %f\n", f5);
    printf("Khi cộng int với float, int sẽ được chuyển thành float trước khi tính toán.\n");

    printf("\n---------------------------------------------------------------------------------------------\n");

    printf("\nCâu 6 if (i == (int)((float) i))\n");
    int i6 = i; float f6 = f;
    printf("i = %d\n", i6);
    printf("Ép sang float: %f\n", (float)i6);
    printf("Ép ngược lại int: %d\n", (int)((float)i6));
    printf("Kết quả: %s\n", (i6 == (int)((float)i6)) ? "true" : "false");
    printf("Kết quả như ban đầu vì float có thể lưu chính xác số nguyên trong pham vi ± 2^24.\n");

    printf("\n---------------------------------------------------------------------------------------------\n");

    printf("\nCâu 7 if (i == (int)((double) i))\n");
    int i7 = i; float f7 = f;
    printf("i = %d\n", i7);
    printf("Ép sang double: %lf\n", (double)i7);
    printf("Ép ngược lại int: %d\n", (int)((double)i7));
    printf("Kết quả: %s\n", (i7 == (int)((double)i7)) ? "true" : "false");
    printf("Kết quả như ban đầu vì double có thể lưu chính xác số nguyên trong pham vi ± 2^53.\n");

    printf("\n---------------------------------------------------------------------------------------------\n");

    printf("\nCâu 8 if (f == (float)((int) f))\n");
    int i8 = i; float f8 = f;
    printf("f = %f\n", f8);
    printf("Ép sang int: %d\n", (int)f8);
    printf("Ép ngược lại float: %f\n", (float)((int)f8));
    printf("Kết quả: %s\n", (f8 == (float)((int)f8)) ? "true" : "false");
    printf("Kết quả không như ban đầu vì phần thập phân bị mất khi ép kiểu sang int.\n");

    printf("\n---------------------------------------------------------------------------------------------\n");

    printf("\nCâu 9 if (f == (double)((int) f))\n");
    int i9 = i; float f9 = f;
    printf("f = %f\n", f9);
    printf("Ép sang int: %d\n", (int)f9);
    printf("Ép sang double: %lf\n", (double)((int)f9));
    printf("Kết quả: %s\n", (f9 == (double)((int)f9)) ? "true" : "false");
    printf("Kết quả không như ban đầu vì phần thập phân bị mất khi ép kiểu sang int.\n");

    return 0;
}
