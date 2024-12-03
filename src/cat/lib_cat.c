#include "lib_cat.h"

BOOL parse_args(int arg_count, char *arg_values[], BYTE *flags) {
  struct option long_options[] = {{"number-nonblank", 0, NULL, 'b'},
                                  {"number", 0, NULL, 'n'},
                                  {"squeeze-blank", 0, NULL, 's'},
                                  {0, 0, 0, 0}};

  int current_option;
  BOOL parsing_success = TRUE;

  while ((current_option = getopt_long(arg_count, arg_values, OPTIONS,
                                       long_options, 0)) != -1 &&
         parsing_success) {
    switch (current_option) {
      case 'b':
        if (!apply_flag(flags, 'b')) parsing_success = FALSE;
        break;
      case 'e':
        if (!apply_flag(flags, 'e')) parsing_success = FALSE;
        if (!apply_flag(flags, 'v')) parsing_success = FALSE;
        break;
      case 'v':
        if (!apply_flag(flags, 'v')) parsing_success = FALSE;
        break;
      case 's':
        if (!apply_flag(flags, 's')) parsing_success = FALSE;
        break;
      case 'n':
        if (!apply_flag(flags, 'n')) parsing_success = FALSE;
        break;
      case 't':
        if (!apply_flag(flags, 't')) parsing_success = FALSE;
        if (!apply_flag(flags, 'v')) parsing_success = FALSE;
        break;
      case 'T':
        if (!apply_flag(flags, 't')) parsing_success = FALSE;
        break;
      case '?':
      default:
        parsing_success = FALSE;
        break;
    }
  }
  return parsing_success;
}

BOOL apply_flag(BYTE *flags, const char flag) {
  BOOL success = TRUE;
  int flag_position = map_flag_to_bit(flag);
  if (flag_position == -1)
    success = FALSE;
  else
    *flags = *flags | (1 << flag_position);

  return success;
}

int map_flag_to_bit(const char flag) {
  int bit_position = -1;
  switch (flag) {
    case 'b':
      bit_position = 0;
      break;
    case 'e':
      bit_position = 1;
      break;
    case 'v':
      bit_position = 2;
      break;
    case 'n':
      bit_position = 3;
      break;
    case 's':
      bit_position = 4;
      break;
    case 't':
      bit_position = 5;
      break;
  }
  return bit_position;
}

int is_flag_set(const int bit, const BYTE *flags) {
  return (*flags & (1 << bit));
}

BOOL process_file(const char *file_name, const BYTE *flags) {
  BOOL operation_successful = TRUE;
  FILE *input_file = fopen(file_name, "r");
  if (input_file != NULL) {
    char line[MAX_LINE_LENGTH];

    int blank_lines_count = 0;
    int current_line_number = 1;

    size_t bytes_read = fgets(line, MAX_LINE_LENGTH, input_file) != NULL
                            ? strlen(line)
                            : (size_t)-1;

    while (bytes_read != (size_t)-1) {
      if (line[0] == '\n')
        blank_lines_count++;
      else
        blank_lines_count = 0;
      if (blank_lines_count < 2 || !is_flag_set(S, flags))
        process_line(flags, line, bytes_read, &current_line_number);

      bytes_read = fgets(line, MAX_LINE_LENGTH, input_file) != NULL
                       ? strlen(line)
                       : (size_t)-1;
    }
    fclose(input_file);
  } else {
    operation_successful = FALSE;
  }
  return operation_successful;
}

void process_line(const BYTE *flags, char *line, int length, int *line_number) {
  for (int i = 0; i < length; i++) {
    if (is_flag_set(B, flags) && !i && line[i] != '\n') {
      printf("%6d\t", *line_number);
      (*line_number)++;
    }

    if (is_flag_set(E, flags) && line[i] == '\n') printf("$");

    if (is_flag_set(N, flags) && !i) {
      printf("%6d\t", *line_number);
      (*line_number)++;
    }

    if (is_flag_set(T, flags) && line[i] == '\t') {
      printf("^");
      line[i] = 'I';
    }

    if (is_flag_set(V, flags)) line[i] = make_visible(line[i]);

    printf("%c", line[i]);
  }
}

char make_visible(char character) {
  unsigned char u_char = (unsigned char)character;
  if (character != '\n' && character != '\t') {
    if (u_char > 127) {
      printf("M-");
      u_char = u_char & 0x7F;
    }

    if (iscntrl(u_char)) {
      printf("^");
      u_char = u_char | 0x40;
    } else if (u_char == 0x7F) {
      printf("^");
      u_char = '?';
    }
  }

  return (char)u_char;
}