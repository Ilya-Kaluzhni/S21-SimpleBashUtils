#include "lib_grep.h"

#define BUFFER_SIZE 1024

BOOL get_options_from_arguments(int argc, char *argv[], BYTE *options,
                                char *patterns) {
  int opt;
  BOOL was_error = 1;
  while ((opt = getopt(argc, argv, OPTIONS)) != -1 && was_error) {
    switch (opt) {
      case 'e':
        append_pattern(patterns, optarg);
        break;
      case 'f':
        if (!set_pattern_from_file(optarg, patterns)) was_error = -1;
        break;
      case 'i':
        if (!set_option(options, 'i')) was_error = 0;
        break;
      case 'c':
        if (!set_option(options, 'c')) was_error = 0;
        break;
      case 'l':
        if (!set_option(options, 'l')) was_error = 0;
        break;
      case 'v':
        if (!set_option(options, 'v')) was_error = 0;
        break;
      case 'n':
        if (!set_option(options, 'n')) was_error = 0;
        break;
      case 'h':
        if (!set_option(options, 'h')) was_error = 0;
        break;
      case 's':
        if (!set_option(options, 's')) was_error = 0;
        break;
      case 'o':
        if (!set_option(options, 'o')) was_error = 0;
        break;
      case '?':
      default:
        was_error = 0;
        break;
    }
  }
  return was_error;
}

void append_pattern(char *patterns, const char *new_pattern) {
  size_t current_len = strlen(patterns);
  size_t new_pattern_len = strlen(new_pattern);
  if (current_len + new_pattern_len + 2 < SIZE) {
    if (current_len > 0) {
      strcat(patterns, "|");
    }
    strcat(patterns, new_pattern);
  } else {
    printf("No memory\n");
  }
}

BOOL set_pattern_from_file(const char *optarg, char *patterns) {
  BOOL result = 1;
  FILE *file = fopen(optarg, "r");
  if (file != NULL) {
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
      size_t len = strlen(buffer);
      if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
      }
      append_pattern(patterns, buffer);
    }
    fclose(file);
  } else {
    result = 0;
  }

  return result;
}

BOOL set_option(BYTE *options, const char option) {
  BOOL result = 1;
  int bit = get_bit(option);
  if (bit == -1)
    result = 0;
  else
    *options = *options | (1 << bit);

  return result;
}

BOOL check_option(const BYTE *options, const int bit) {
  return ((*options & (1 << bit)));
}

int get_bit(const char option) {
  int result = -1;
  switch (option) {
    case 'i':
      result = 0;
      break;
    case 'v':
      result = 1;
      break;
    case 'c':
      result = 2;
      break;
    case 'l':
      result = 3;
      break;
    case 'n':
      result = 4;
      break;
    case 'h':
      result = 5;
      break;
    case 's':
      result = 6;
      break;
    case 'o':
      result = 7;
      break;
  }
  return result;
}

void print_regmatch(const regmatch_t *rm, const char *buffer, int *offset) {
  for (int i = rm->rm_so; i < rm->rm_eo; i++) {
    printf("%c", buffer[*offset + i]);
  }
  printf("\n");
  *offset += rm->rm_eo;
}

void output_match(regex_t *regular, const char *buffer, const BYTE *options,
                  int curr_line, int count_files, const char *name_file) {
  regmatch_t reg_match;
  int offset = 0;
  int result = 1;
  int first = 1;
  while ((result = regexec(regular, buffer + offset, 1, &reg_match, 0)) == 0) {
    if (!check_option(options, H) && count_files > 1 && first)
      printf("%s:", name_file);
    if (check_option(options, N) && first) printf("%d:", curr_line);
    first = 0;
    print_regmatch(&reg_match, buffer, &offset);
  }
}

BOOL match_line(const BYTE *options, regex_t *regular, char *buffer,
                int *match_count, int curr_line, const char *name_file,
                int count_files) {
  BOOL error = 1;
  int match_count_line = 0;
  int result = regexec(regular, buffer, 0, NULL, 0);
  if ((!result && !check_option(options, V)) ||
      (result && check_option(options, V))) {
    match_count_line++;
    if (!check_option(options, L) && !check_option(options, C)) {
      if (check_option(options, O) && !check_option(options, V))
        output_match(regular, buffer, options, curr_line, count_files,
                     name_file);
      else {
        if (!check_option(options, H) && count_files > 1)
          printf("%s:", name_file);
        if (check_option(options, N)) printf("%d:", curr_line);
        printf("%s\n", buffer);
      }
    }
  } else if (result != 0 && check_option(options, V)) {
    if (check_option(options, N)) printf("%d:", curr_line);
    if (check_option(options, O)) printf("%s:", name_file);
    printf("%s\n", buffer);
  }

  *match_count += match_count_line;

  return error;
}

BOOL match_file(const BYTE *options, const char *pattern, const char *name_file,
                int count_files) {
  BOOL error = 1;
  FILE *file = fopen(name_file, "r");
  if (file != NULL) {
    char buffer[BUFFER_SIZE];
    int match_count_file = 0;
    regex_t regular;
    int cflags = REG_EXTENDED;

    if (check_option(options, I)) {
      cflags |= REG_ICASE;
    }

    if (regcomp(&regular, pattern, cflags) != 0) {
      error = -1;
    }

    int curr_line = 1;
    while (fgets(buffer, BUFFER_SIZE, file) != NULL && error) {
      size_t len = strlen(buffer);
      if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
      }
      error = match_line(options, &regular, buffer, &match_count_file,
                         curr_line, name_file, count_files);
      curr_line++;
    }

    if (check_option(options, C)) {
      if (!check_option(options, H) && count_files > 1) {
        printf("%s:", name_file);
      }
      if (check_option(options, L) && match_count_file) {
        match_count_file = 1;
      }
      printf("%d\n", match_count_file);
    }

    if (match_count_file && check_option(options, L)) {
      printf("%s\n", name_file);
    }

    regfree(&regular);
  } else {
    error = 0;
  }

  if (file != NULL) {
    fclose(file);
  }

  return error;
}

void define_error(const int error) {
  switch (error) {
    case 0:
      printf("Can't open file\n");
      break;
    case -1:
      printf("Can't compile a regular expression\n");
      break;
    case -2:
      printf("Can't match a line from file\n");
      break;
  }
}
