#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>


#define RAND_RANGE(min, max) rand() % (max - min) + min
#define COUNT_OF(arr) (sizeof arr / sizeof arr[0])
#define CHANCE_STUTTER 10
#define CHANCE_INTERJECT 10


char* interjections[] = {
    "uwu", "owo", "OwO", "UwU",
    "nyaa", "rawr", "*nuzzles*", "*pounces*",
    "(・`ω´・)", "teehee", "hehe",
    "*whispers to self", "x3", ";;w;;"
};


bool roll(int chance) {
    return RAND_RANGE(0, 100) < chance;
}


char replace_char(char ch) {
    if (ch == 'r' || ch == 'l') return 'w';
    if (ch == 'R' || ch == 'L') return 'W';
    return ch;
}

void stutter(char ch) {
    printf("%c-%c", ch, ch);
}


void interject(void) {
    printf(" %s ", interjections[RAND_RANGE(0, COUNT_OF(interjections))]);
}


void replace_and_print(char ch) {
    putchar(replace_char(ch));
}


int main(void) {
    int ch;
    bool prev_was_space = true;
    srand(time(NULL));

    while ((ch = getchar()) != EOF) {
        if (prev_was_space && isalpha(ch) && roll(CHANCE_STUTTER)) {
            stutter(ch);
        } else if (isspace(ch) && roll(CHANCE_INTERJECT)) {
            interject();
        } else {
            replace_and_print(ch);
        }

        prev_was_space = isspace(ch);
    }

    return 0;
}
