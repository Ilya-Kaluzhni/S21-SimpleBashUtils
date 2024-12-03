FLAGS = -Wall -Werror -Wextra -std=c11 -g

lib_cat:
	gcc $(FLAGS) -c lib_cat.c -o lib_cat.o

s21_cat: lib_cat
	gcc $(FLAGS) s21_cat.c lib_cat.o -o s21_cat

clean:
	rm -rf *.o
	rm -rf s21_cat

rebuild: clean s21_cat

test:
	bash tests_cat.sh

format:
	clang-format -style=file:../../materials/linters/.clang-format -i s21_cat.c
	clang-format -style=file:../../materials/linters/.clang-format -i lib_cat.c
	clang-format -style=file:../../materials/linters/.clang-format -i lib_cat.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem s21_grep.c lib_grep.c lib_grep.h
