#include <stdio.h>
#include <stdlib.h>

#define FILENAME "record.bat"
/*
1st we write data into strucutres
2nd write structure data into binary file
3rd write function to find mth record from binary file
4th write function to delete record from binary file
*/

typedef struct {
    int id;
    char name[64];
} record;

void write_data(record[], int);
void write_bin_file(record[], int);
int dsp_rcrd_num();
void dsp_nth_rcrd(int);

int main () {
    int n;
    printf("\nNumber of records to write: ");
    scanf("%d", &n);
    record studnt[n];
    write_data(studnt, n);
    write_bin_file(studnt, n);
    int x = dsp_rcrd_num();
    dsp_nth_rcrd(n);

    printf("\n");
    return 0;
}

void write_data(record s[], int n) {
    for (int i = 0; i<n; i++) {
        printf("\nstudent id %d: ", i);
        scanf("%d", &s[i].id);
        printf("\nstudent name %d: ", i);
        scanf("%s", s[i].name);
    }
}

void write_bin_file(record s[], int n) {
    FILE *fp = fopen(FILENAME, "wb");

    if (fp == NULL)
        return;
    
    fwrite(s, sizeof(record), n, fp);
    fclose(fp);
}

int dsp_rcrd_num() {
    FILE *fp = fopen(FILENAME, "rb");
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    int num_rcrds = size / sizeof(record);
    int rcrcd_index;
    for (int i = 0; i<num_rcrds; i++) {
        printf("record %d -> %d\n", i, i);
    }
    scanf("%d", &rcrcd_index);
    if (rcrcd_index>= 0 && rcrcd_index<= num_rcrds) {
        return rcrcd_index;
    }
    else {
        printf("invalid entry");
        return -1;
    }
    fclose(fp);
}

void dsp_nth_rcrd(int pos) {
    record s;
    FILE *fp = fopen(FILENAME, "rb");
    fseek(fp, (pos - 1)*sizeof(record), SEEK_SET);
    fread(&s, sizeof(record), 1, fp);
    printf("%d  %s", s.id, s.name);
}