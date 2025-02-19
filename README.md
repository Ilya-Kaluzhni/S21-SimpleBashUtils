# S21-SimpleBashUtils

В этом проекте мне предстояло познакомиться с базовыми утилитами Bash по работе с текстами на языке программирования С и научиться их разрабатывать. Эти утилиты (cat и grep) достаточно часто используются при работе в терминале Linux. В рамках этого проекта я также узнал, как организованы утилиты Bash, и научился писать программы следуя структурному подходу. 


### История cat

> cat был частью ранних версий Unix, например, Версии 1, и заменил pr, утилиту PDP-7 и Multics для копирования одного файла на экран.

### Использование cat

cat — одна из наиболее часто используемых команд в Unix-подобных операционных системах. Команда имеет три взаимосвязанные функции в отношении текстовых файлов: отображение, объединение их копий и создание новых.

`cat [OPTION] [FILE]...`

### Опции cat

| № | Опции | Описание |
| ------ | ------ | ------ |
| 1 | -b (GNU: --number-nonblank) | нумерует только непустые строки |
| 2 | -e предполагает и -v (GNU only: -E то же самое, но без применения -v) | также отображает символы конца строки как $  |
| 3 | -n (GNU: --number) | нумерует все выходные строки |
| 4 | -s (GNU: --squeeze-blank) | сжимает несколько смежных пустых строк |
| 5 | -t предполагает и -v (GNU: -T то же самое, но без применения -v) | также отображает табы как ^I |

### История grep 

> Томпсон написал первую версию на PDP-11 языке ассемблера, чтобы помочь Ли Э. МакМахону проанализировать текст «Записок Федералиста» и определить авторство отдельных статей. Текстовый редактор ed (также созданный Томпсоном) имел поддержку регулярных выражений, но его нельзя было использовать для такого большого объема текста, поэтому Томпсон извлек этот код в отдельный инструмент. Он выбрал это название, потому что в ed команда g / re / p печатала все строки, соответствующие заданному шаблону. 
grep впервые был включен в Версию 4 Unix. Заявив, что он «обычно упоминается как прототип программного средства», Макилрой приписал grep «безвозвратное внедрение» философии инструментов Томпсона в Unix.

### Использование grep 

`grep [options] template [file_name]`

### Опции grep 

| № | Опции | Описание |
| ------ | ------ | ------ |
| 1 | -e | Шаблон. |
| 2 | -i | Игнорирует различия регистра.  |
| 3 | -v | Инвертирует смысл поиска соответствий. |
| 4 | -c | Выводит только количество совпадающих строк. |
| 5 | -l | Выводит только совпадающие файлы.  |
| 6 | -n | Предваряет каждую строку вывода номером строки из файла ввода. |
| 7 | -h | Выводит совпадающие строки, не предваряя их именами файлов. |
| 8 | -s | Подавляет сообщения об ошибках о несуществующих или нечитаемых файлах. |
| 9 | -f file | Получает регулярные выражения из файла. |
| 10 | -o | Печатает только совпадающие (непустые) части совпавшей строки. |
