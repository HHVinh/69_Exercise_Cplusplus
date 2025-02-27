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
    printf("Kết quả không như ban đầu vì phần thập phân bị mất khi ép sang int.\n");

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
    printf("Trước khi ép kiểu: 3.14159 * f = %f\n", 3.14159 * f);
    printf("Ép kiểu: ");
    i = (int) (3.14159 * f);
    printf("i = (int) (3.14159 * f) = %d\n", i);
    printf("Khi ép kiểu float -> int, phần thập phân bị cắt bỏ chứ không làm tròn.\n");

    printf("\n---------------------------------------------------------------------------------------------\n");
    
    printf("\nCâu 5 f = f + (float) i\n");
    printf("Trước khi ép kiểu: f = %f, i = %d", f, i);
    printf(", f * i = %f\n", f * i);
    printf("Ép kiểu: ");
    f = f + (float) i;
    printf("f = f + (float) i = %f\n", f);
    printf("Bài học: Khi cộng int với float, int sẽ được chuyển thành float trước khi tính toán.\n");

    printf("\n---------------------------------------------------------------------------------------------\n");

    printf("\nCâu 6 if (i == (int)((float) i))\n");
    printf("i = %d\n", i);
    printf("Ép sang float: %f\n", (float)i);
    printf("Ép ngược lại int: %d\n", (int)((float)i));
    printf("Kết quả: %s\n", (i == (int)((float)i)) ? "true" : "false");

    printf("\n---------------------------------------------------------------------------------------------\n");

    printf("\nCâu 7 if (i == (int)((double) i))\n");
    printf("Ép sang double: %lf\n", (double)i);
    printf("Ép ngược lại int: %d\n", (int)((double)i));
    printf("Kết quả: %s\n", (i == (int)((double)i)) ? "true" : "false");

    printf("\n---------------------------------------------------------------------------------------------\n");

    printf("\nCâu 8 if (f == (float)((int) f))\n");
    printf("f = %f\n", f);
    printf("Ép sang int: %d\n", (int)f);
    printf("Ép ngược lại float: %f\n", (float)((int)f));
    printf("Kết quả: %s\n", (f == (float)((int)f)) ? "true" : "false");

    printf("\n---------------------------------------------------------------------------------------------\n");

    printf("\nCâu 9 if (f == (double)((int) f))\n");
    printf("f = %f\n", f);
    printf("Ép sang int: %d\n", (int)f);
    printf("Ép sang double: %lf\n", (double)((int)f));
    printf("Kết quả: %s\n", (f == (double)((int)f)) ? "true" : "false");

    return 0;
}
