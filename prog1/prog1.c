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
    int is_deleted;
    int id;
    char name[64];
} record;

void take_user_data(record[], int);
void write_bin_file(record[], int);
void display(int);
// int dsp_rcrd_num();
// void dsp_nth_rcrd(int);
void delete_rcrd(int, int);

int main () {
    int n;
    int choice;
    int id_delete;
    printf("\nNumber of records to write: ");
    scanf("%d", &n);
    record studnt[n];
    take_user_data(studnt, n);
    write_bin_file(studnt, n);

    display(n);
    printf("\nDo you want to delete a record? (YES = 1 AND NO = 0)");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter ID of record to delete: ");
        scanf("%d", &id_delete);

        delete_rcrd(n, id_delete);
    }
    display(n);
    // int x = dsp_rcrd_num();
    // dsp_nth_rcrd(n);

    printf("\n");
    return 0;
}

void take_user_data(record s[], int n) {
    for (int i = 0; i<n; i++) {
        printf("\nstudent id %d: ", i);
        scanf("%d", &s[i].id);
        printf("\nstudent name %d: ", i);
        scanf("%s", s[i].name);
        s[i].is_deleted = 0;
    }
}

void write_bin_file(record s[], int n) {
    FILE *fp = fopen(FILENAME, "wb");

    if (fp == NULL)
        return;
    
    fwrite(s, sizeof(record), n, fp);
    fclose(fp);
}

void display(int n) {
    record student[n];
    FILE *fp = fopen(FILENAME, "rb");
    fread(student, sizeof(record), n, fp);
    fclose(fp);
    for (int i = 0; i<n; i++) {
        if (student[i].is_deleted == 0) {
            printf("\nID: %d\tName: %s", student[i].id, student[i].name);
        }
    }
}
// int dsp_rcrd_num() {
//     FILE *fp = fopen(FILENAME, "rb");
//     fseek(fp, 0, SEEK_END);
//     int size = ftell(fp);
//     int num_rcrds = size / sizeof(record);
//     int rcrcd_index;
//     for (int i = 0; i<num_rcrds; i++) {
//         printf("record %d -> %d\n", i, i);
//     }
//     scanf("%d", &rcrcd_index);
//     if (rcrcd_index>= 0 && rcrcd_index<= num_rcrds) {
//         return rcrcd_index;
//     }
//     else {
//         printf("invalid entry");
//         return -1;
//     }
//     fclose(fp);
// }

// void dsp_nth_rcrd(int pos) {
//     record s;
//     FILE *fp = fopen(FILENAME, "rb");
//     fseek(fp, (pos - 1)*sizeof(record), SEEK_SET);
//     fread(&s, sizeof(record), 1, fp);
//     printf("%d  %s", s.id, s.name);
// }

void delete_rcrd(int n, int to_delete_id) {
    FILE *fp = fopen(FILENAME, "rb");
    record student[n];
    fread(student, sizeof(record), n, fp);
    for (int i =0; i<n; i++) {
        if (student[i].id == to_delete_id) {
            student[i].is_deleted = 1;
        }
    }
    fclose(fp);

    FILE *fp_ = fopen(FILENAME, "wb");
    fwrite(student, sizeof(record), n, fp_);
    fclose(fp_);
}
