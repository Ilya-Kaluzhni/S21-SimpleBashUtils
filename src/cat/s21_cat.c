#include <stdio.h>
#include <stdlib.h>

#include "lib_cat.h"

int main(int arg_count, char *arg_values[]) {
  int code = 0;
  if (arg_count > 1) {
    BYTE *flags = calloc(1, sizeof(BYTE));
    if (flags == NULL) {
      printf("Memory allocation error\n");
      code = 1;
    } else {
      if (parse_args(arg_count, arg_values, flags)) {
        while (optind < arg_count) {
          if (!process_file(arg_values[optind], flags)) {
            printf("Invalid file name: %s\n", arg_values[optind]);
          }
          optind++;
        }
      } else {
        printf("Incorrect flags for parsing\n");
        code = 1;
      }
      free(flags);
    }
  } else {
    printf("Not arguments, use: ./s21_cat [-arg] [file]\n");
    code = 1;
  }

  return code;
}
