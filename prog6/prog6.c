#include <stdio.h>
#include <math.h>

#define COLUMN  40
#define ROW     20

typedef struct {
    int x;
    int y;
    int radius;
} circle;

void init_grid(char[][COLUMN]);
void create_circle(circle*);
void draw_circle(char[][COLUMN], circle*);
void print_circle(char[][COLUMN]);
int  circle_formula(circle *, int, int);

void main() {
    char grid[ROW][COLUMN];
    init_grid(grid);

    circle c;
    create_circle(&c);
    draw_circle(grid, &c);
    print_circle(grid);
    printf("\n");
}

void init_grid(char grid[ROW][COLUMN]) {
    for (int i = 0; i<ROW; i++) {
        for (int j = 0; j<COLUMN; j++) {
            grid[i][j] = ' ';
        }
    }
}

void create_circle(circle *c) {
    printf("\nCenter of circle x,y: ");
    scanf("%d %d", &c->x, &c->y);
    printf("\nRadius of circle: ");
    scanf("%d", &c->radius);
}

int circle_formula(circle *c, int x, int y) {
    int x_term = (x - c->x) * (x - c->x);
    int y_term = (y - c->y) * (y - c->y);

    return x_term + y_term;
}

void draw_circle(char grid[ROW][COLUMN], circle* c) {
    int i, j;

    for (i = 0; i<ROW; i++) {
        for (j = 0; j<COLUMN; j++) {
            if (circle_formula(c, i, j) == (c->radius * c->radius)) {
                grid[i][j] = 'o';
            }
        }
    }
}

void print_circle(char grid[ROW][COLUMN]) {
    for (int i = 0; i<ROW; i++) {
        for (int j = 0; j<COLUMN; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}