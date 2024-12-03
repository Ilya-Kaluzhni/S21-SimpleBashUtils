#ifndef LIB_CAT
#define LIB_CAT

#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

#define TRUE 1
#define FALSE 0

#define OPTIONS "bevEnstT"

#define B 0
#define E 1
#define V 2
#define N 3
#define S 4
#define T 5

typedef unsigned char BYTE;
typedef unsigned char BOOL;

BOOL validate_file_name(const char *file_name);
BOOL process_file(const char *file_name, const BYTE *flags);
BOOL apply_flag(BYTE *flags, const char flag);
BOOL parse_args(int arg_count, char **arg_values, BYTE *flags);
void process_line(const BYTE *flags, char *line, int length, int *line_number);
int is_flag_set(const int bit, const BYTE *flags);
int map_flag_to_bit(const char flag);
char make_visible(char character);

#endif
