/********************************************************************
 * util.h - Utility header file
 *
 * $Id$
 ********************************************************************/
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <cocotypes.h>


/* Function prototypes for supported OS-9 commands are here */
int os9attr(int, char **);
int os9cmp(int, char **);
int os9copy(int, char **);
int os9dcheck(int, char **);
int os9del(int, char **);
int os9deldir(int, char **);
int os9dir(int, char **);
int os9dsave(int, char **);
int os9dump(int, char **);
int os9format(int, char **);
int os9free(int, char **);
int os9fstat(int, char **);
int os9gen(int, char **);
int os9id(int, char **);
int os9ident(int, char **);
int os9list(int, char **);
int os9makdir(int, char **);
int os9modbust(int, char **);
int os9padrom(int, char **);
int os9rename(int, char **);

int StrToInt(char *s);
void show_help(char **helpMessage);

/* Function prototypes for supported Disk BASIC commands are here */
int decbattr(int, char **);
int decbcopy(int, char **);
int decbdir(int, char **);
int decbdskini(int, char **);
int decbfree(int, char **);
int decbfstat(int, char **);
int decbkill(int, char **);
int decblist(int, char **);
int decbrename(int, char **);