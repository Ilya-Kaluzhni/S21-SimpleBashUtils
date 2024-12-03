# !/bin/bash

echo "Нет флагов 1 файл"
./s21_cat tests/test_1.txt > output1.txt
cat tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "Нет флагов 2 файла"
./s21_cat tests/test_1.txt tests/test_2.txt > output1.txt
cat tests/test_1.txt tests/test_2.txt > output2.txt
diff -s output1.txt output2.txt

echo "-b"
./s21_cat -b tests/test_1.txt > output1.txt
cat -b tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-e"
./s21_cat -e tests/test_1.txt > output1.txt
cat -e tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-n"
./s21_cat -n tests/test_1.txt > output1.txt
cat -n tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-s"
./s21_cat -s tests/test_1.txt > output1.txt
cat -s tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-t"
./s21_cat -t tests/test_1.txt > output1.txt
cat -t tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "--number"
./s21_cat --number tests/test_1.txt > output1.txt
cat -n tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "--squeeze-blank"
./s21_cat --squeeze-blank tests/test_1.txt > output1.txt
cat -s tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "--number-nonblank"
./s21_cat --number-nonblank tests/test_1.txt > output1.txt
cat -b tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

rm -rf output1.txt
rm -rf output2.txt