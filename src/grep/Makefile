FLAGS = -Wall -Werror -Wextra -std=c11 -g

lib_grep:
	gcc $(FLAGS) -c lib_grep.c -o lib_grep.o -std=c11

s21_grep:lib_grep
	gcc $(FLAGS) s21_grep.c lib_grep.o -o s21_grep

clean:
	rm -rf *.o
	rm -rf s21_grep

rebuild: clean s21_grep

test:
	bash test_grep.sh

format:
	clang-format -style=file:../../materials/linters/.clang-format -i s21_grep.c
	clang-format -style=file:../../materials/linters/.clang-format -i lib_grep.c
	clang-format -style=file:../../materials/linters/.clang-format -i lib_grep.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem s21_grep.c lib_grep.c lib_grep.h
