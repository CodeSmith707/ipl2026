#include <stdio.h>
typedef union {
    unsigned char flag;
    struct bits {
        unsigned int firstBit:1;
        unsigned int secndBit:1;
        unsigned int thirdBit:1;
        unsigned int forthBit:1;
    }field;

} bitfield;
void print_binary_char(unsigned char);

int main () {
    bitfield b1;
    b1.flag = 0;
    b1.field.secndBit = 1;
    b1.field.firstBit = 1;
    b1.field.forthBit = 1;
    b1.field.thirdBit = 1;
    printf("the number %d using bitfields in binary: ", b1.flag);
    print_binary_char(b1.flag);
    return 0;
}

void print_binary_char(unsigned char num) {
    for (char i = 7; i>=0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}