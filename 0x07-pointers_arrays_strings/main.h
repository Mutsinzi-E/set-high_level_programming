#ifndef MAIN_H
#define MAIN_H

/* 0x05 or 0x07 - function prototypes */

/* 2-strlen.c */
int _strlen(char *s);

/* 3-strspn.c */
unsigned int _strspn(char *s, char *accept);

/* 4-strpbrk.c */
char *_strpbrk(char *s, char *accept);

/* 5-strstr.c */
char *_strstr(char *haystack, char *needle);

/* 6-print_chessboard.c */
void print_chessboard(char (*a)[8]);

/* 7-print_diagsums.c */
void print_diagsums(int *a, int size);

/* Include _putchar if needed */
int _putchar(char c);

#endif /* MAIN_H */
