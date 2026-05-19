#include <stdio.h>

union decision {
    unsigned char flag;
    struct {
        unsigned int my_choice:1;
        unsigned int mother_choice:1;
        unsigned int father_choice:1;
        unsigned int socially_accep:1;
        unsigned int fin_viable:1;
        unsigned int aptitude:1;
        unsigned int i_enjoy_it:1;
        unsigned int decision:1;
    }field;
};

union decision input();
void make_decision(union decision *);
void print_decision(union decision *);

int main() {
    union decision d;
    d = input();
    make_decision(&d);
    print_decision(&d);
    return 0;
}

union decision input() {
    union decision d;
    d.flag = 0;
    int temp;
    printf("1 for YES and 0 for NO\n\n");
    printf("Is this your choice? ");
    scanf("%u", &temp);
    d.field.my_choice = temp;
    printf("Does your mother support it? ");
    scanf("%u", &temp);
    d.field.mother_choice = temp;
    printf("Does your father support it? ");
    scanf("%u", &temp);
    d.field.father_choice = temp;
    printf("Is it socially acceptable? ");
    scanf("%u", &temp);
    d.field.socially_accep = temp;
    printf("Is it financially viable? ");
    scanf("%u", &temp);
    d.field.fin_viable = temp;
    printf("Do you have aptitude for it? ");
    scanf("%u", &temp);
    d.field.aptitude = temp;
    printf("Do you like it? ");
    scanf("%u", &temp);
    d.field.i_enjoy_it = temp;
    return d;
}

void make_decision(union decision *d) {
    if (d->field.my_choice && d->field.fin_viable && d->field.aptitude && d->field.i_enjoy_it) {
        d->field.decision = 1;
    }
    else {
        d->field.decision = 0;
    }
}

void print_decision(union decision *d) {
        printf("\n========== DECISION REPORT ==========\n\n");

    printf("Your choice              : %s\n",
           d->field.my_choice ? "YES" : "NO");

    printf("Mother supports          : %s\n",
           d->field.mother_choice ? "YES" : "NO");

    printf("Father supports          : %s\n",
           d->field.father_choice ? "YES" : "NO");

    printf("Socially acceptable      : %s\n",
           d->field.socially_accep ? "YES" : "NO");

    printf("Financially viable       : %s\n",
           d->field.fin_viable ? "YES" : "NO");

    printf("You have aptitude        : %s\n",
           d->field.aptitude ? "YES" : "NO");

    printf("You like it              : %s\n",
           d->field.i_enjoy_it ? "YES" : "NO");

    printf("\nFINAL DECISION           : %s\n",
           d->field.decision ? "GO AHEAD" : "DO NOT PROCEED");
}