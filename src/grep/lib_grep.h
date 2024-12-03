#ifndef LIB_GREP
#define LIB_GREP

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPTIONS "e:ivclnhsf:o"

#define I 0
#define V 1
#define C 2
#define L 3
#define N 4
#define H 5
#define S 6
#define O 7

#define SIZE 1024

typedef unsigned char BYTE;
typedef char BOOL;

void append_pattern(char *, const char *);
BOOL set_pattern_from_file(const char *, char *);
BOOL get_options_from_arguments(int, char **, BYTE *, char *);
int get_bit(const char);
BOOL set_option(BYTE *, const char);
BOOL check_option(const BYTE *, const int);

void define_error(const int);
BOOL match_file(const BYTE *, const char *, const char *, int);
BOOL match_line(const BYTE *, regex_t *, char *, int *, int, const char *, int);

void print_regmatch(const regmatch_t *, const char *, int *);
void output_match(regex_t *, const char *, const BYTE *, int, int,
                  const char *);

#endif