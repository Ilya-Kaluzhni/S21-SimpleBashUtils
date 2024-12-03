# !/bin/bash

echo "-e is"
./s21_grep -e is tests/test_1.txt > output1.txt
grep -e is tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-f tests/patterns.txt"
./s21_grep -f tests/patterns.txt tests/test_1.txt > output1.txt
grep -f tests/patterns.txt tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-i IS"
./s21_grep -i IS tests/test_1.txt > output1.txt
grep -i IS tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-v is"
./s21_grep -v is tests/test_1.txt > output1.txt
grep -v is tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-v Is"
./s21_grep -v Is tests/test_1.txt > output1.txt
grep -v Is tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-vi iS"
./s21_grep -vi iS tests/test_1.txt > output1.txt
grep -vi iS tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-iv iS"
./s21_grep -iv iS tests/test_1.txt > output1.txt
grep -iv iS tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-c is"
./s21_grep -c is tests/test_1.txt > output1.txt
grep -c is tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-c iS"
./s21_grep -c iS tests/test_1.txt > output1.txt
grep -c iS tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-cv iS"
./s21_grep -cv iS tests/test_1.txt > output1.txt
grep -cv iS tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-cv is"
./s21_grep -cv is tests/test_1.txt > output1.txt
grep -cv is tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-l is file_1.txt file_2.txt"
./s21_grep -l is tests/test_1.txt tests/test_2.txt > output1.txt
grep -l is tests/test_1.txt tests/test_2.txt > output2.txt
diff -s output1.txt output2.txt

echo "-lv is file_1.txt file_2.txt"
./s21_grep -lv is tests/test_1.txt tests/test_2.txt > output1.txt
grep -lv is tests/test_1.txt tests/test_2.txt > output2.txt
diff -s output1.txt output2.txt

echo "-lv iS file_1.txt file_2.txt"
./s21_grep -lv iS tests/test_1.txt tests/test_2.txt > output1.txt
grep -lv iS tests/test_1.txt tests/test_2.txt > output2.txt
diff -s output1.txt output2.txt

echo "-n is"
./s21_grep -n is tests/test_1.txt > output1.txt
grep -n is tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-in IS"
./s21_grep -in IS tests/test_1.txt > output1.txt
grep -in IS tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-nv is"
./s21_grep -nv is tests/test_1.txt > output1.txt
grep -nv is tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-h is"
./s21_grep -h is tests/test_1.txt > output1.txt
grep -h is tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-cnh is"
./s21_grep -cnh is tests/test_1.txt > output1.txt
grep -cnh is tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-s is (unknown_file.txt)"
./s21_grep -s is tests/unknown_file.txt > output1.txt
grep -s is tests/unknown_file.txt > output2.txt
diff -s output1.txt output2.txt

echo "-f tests/patterns.txt -s (unknown_file.txt)"
./s21_grep -f tests/patterns.txt -s tests/unknown_file.txt > output1.txt
grep -f tests/patterns.txt -s tests/unknown_file.txt > output2.txt
diff -s output1.txt output2.txt

echo "-f tests/patterns.txt -s "
./s21_grep -f tests/patterns.txt -s tests/test_1.txt > output1.txt
grep -f tests/patterns.txt -s tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-o is"
./s21_grep -o is tests/test_1.txt > output1.txt
grep -o is tests/test_1.txt > output2.txt
diff -s output1.txt output2.txt

echo "-o is file_1.txt file_2.txt"
./s21_grep -o is tests/test_1.txt tests/test_2.txt > output1.txt
grep -o is tests/test_1.txt tests/test_2.txt > output2.txt
diff -s output1.txt output2.txt

echo "-ov is file_1.txt file_2.txt"
./s21_grep -ov is tests/test_1.txt tests/test_2.txt > output1.txt
grep -ov is tests/test_1.txt tests/test_2.txt > output2.txt
diff -s output1.txt output2.txt

echo "-no is file_1.txt file_2.txt"
./s21_grep -no is tests/test_1.txt tests/test_2.txt > output1.txt
grep -no is tests/test_1.txt tests/test_2.txt > output2.txt
diff -s output1.txt output2.txt

echo "-oihlnc -e is -e iS -f tests/patterns.txt file_1.txt file_2.txt"
./s21_grep -oihlnc -e is -e iS -f tests/patterns.txt tests/test_1.txt tests/test_2.txt > output1.txt
grep -oihlnc -e is -e iS -f tests/patterns.txt tests/test_1.txt tests/test_2.txt > output2.txt
diff -s output1.txt output2.txt


rm -rf output1.txt
rm -rf output2.txt