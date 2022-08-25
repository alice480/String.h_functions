CC = gcc
CFLAGS = -Wall -Wextra -Werror
DIR = ../build/

all: strlen_tests strcmp_tests

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c

s21_string_test1.o: s21_string_test.c
	$(CC) $(CFLAGS) -DStrlen_tests -c s21_string_test.c

s21_string_test2.o: s21_string_test.c
	$(CC) $(CFLAGS) -DStrcmp_tests -c s21_string_test.c

s21_string_test3.o: s21_string_test.c
	$(CC) $(CFLAGS) -DStrcpy_tests -c s21_string_test.c

strlen_tests: s21_string.o s21_string_test1.o
	$(CC) -o $(DIR)Quest_1 s21_string.o s21_string_test.o

strcmp_tests: s21_string.o s21_string_test2.o
	$(CC) -o $(DIR)Quest_2 s21_string.o s21_string_test.o

strcpy_tests: s21_string.o s21_string_test3.o
	$(CC) -o $(DIR)Quest_3 s21_string.o s21_string_test.o

clean:
	rm -rf *.o
	rm -rf ../build/Quest_* 

rebuild: 
	clean all
