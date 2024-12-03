#include "lib_grep.h"

int main(int argc, char *argv[]) {
  BYTE options = 0;
  char patterns[SIZE] = {0};
  int error = 1;
  if ((error = get_options_from_arguments(argc, argv, &options, patterns)) >
      0) {
    if (patterns[0] == '\0') {
      append_pattern(patterns, argv[optind]);
      optind++;
    }
    int count_files = argc - optind;
    if (!count_files) error = -2;
    while (optind < argc && error) {
      error = match_file(&options, patterns, argv[optind], count_files);
      if (!check_option(&options, S)) {
        define_error(error);
      } else
        error = 1;
      optind++;
    }
  } else if (!check_option(&options, S)) {
    if (error == -1)
      printf("Pattern file name error\n");
    else if (error == -2)
      printf("Enter at least one file\n");
  }
}