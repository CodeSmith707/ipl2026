 #include <stdio.h>
 
 #define FILENAME "ascii_record.txt"
 typedef struct {
    char name[64];
    int  id;
    char grade;
 } record;

 void user_input(record[], int);
 void write_file(record[], int);
 void read_file(record[], int);
 void print_file(record[], int);

 void main () {
    int n;
    printf("\nNumber of records to add: ");
    scanf("%d", &n);
    record student[n], student_read[n];
    user_input(student, n);
    write_file(student, n);
    read_file(student_read, n);
    print_file(student_read, n);

    printf("\n");
 }

 void user_input(record s[], int n) {
    for (int i = 0; i<n; i++) {
        printf("student %d: name, id, grade: ", i);
        scanf("%s %d %c", s[i].name, &s[i].id, &s[i].grade);
    }
 }

 void write_file(record s[], int n) {
    FILE *fp = fopen(FILENAME, "w");
    for (int i = 0; i<n; i++) {
        fprintf(fp, "%s\t%d\t%c\n", s[i].name, s[i].id, s[i].grade);
    }
    fclose(fp);
 }

 void read_file(record s[], int n) {
    FILE *fp = fopen(FILENAME, "r");
    for (int i = 0; i<n; i++) {
        fscanf(fp, "%s\t%d\t%c\n", s[i].name, &s[i].id, &s[i].grade);
    }
    fclose(fp);
 }

 void print_file(record s[], int n) {
    for(int i = 0; i<n; i++) {
        printf("\nName: %s\tID: %d\tGrade: %c", s[i].name, s[i].id, s[i].grade);
    }
 }