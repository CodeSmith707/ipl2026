#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT  "input_file.txt"
#define OUTPUT "output_file.txt"

typedef struct Node Node;
struct Node {
    Node  *next;
    char data[100];
};


void main () {
    FILE *in, *ou;
    Node *head = NULL, *current = NULL, *newNode;
    char line[100];

    in = fopen(INPUT, "r");
    if (in == NULL) {
        printf("failed to read\n");
        return;
    }

    while(fgets(line, sizeof(line), in)) {
        newNode = (Node *)malloc(sizeof(Node));

        strcpy(newNode->data, line);
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            current = head;
        }
        else {
            current->next = newNode;
            current = newNode;
        }
    }
    fclose(in);

    ou = fopen(OUTPUT, "w");
    current = head;
    while (current != NULL) {
        fputs(current->data, ou);
        current = current->next;
    }
    fclose(ou);

    current = head;
    while (current != NULL) {
        Node *deleteNode = current;
        current = current->next;
        free(deleteNode);
    }

    printf("Lines copied sucessfully!\n");
    return;
}
