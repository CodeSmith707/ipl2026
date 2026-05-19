#include <stdio.h>

void dec_to_bin(int);
int num_1s_bin();
void dsp_bin_num();

char bin_num[32];

void main() {
    int dec;
    printf("enter decimal number: ");
    scanf("%d", &dec);
    
    dec_to_bin(dec);
    dsp_bin_num();

    int num_1s_in_bin = num_1s_bin();
    printf("\nnumber of 1s in binary number: %d", num_1s_in_bin);
    printf("\n");
}
void dec_to_bin(int dec) {

    for (int i = 31; i >= 0; i--) {
        if ((dec >> i) & 1) {
            bin_num[i] = 1;
        }
        else {
            bin_num[i] = 0;
        }
    }
}
int num_1s_bin() {
    int n;
    for (int i = 0; i<32;i++) {
        if (bin_num[i] == 1) {
            n++;
        }
    }
    return n;
}
void dsp_bin_num() {
    printf("\nbinary number: ");
    for (int i = 31; i>=0; i--) {
        printf("%d", bin_num[i]);
    }
}