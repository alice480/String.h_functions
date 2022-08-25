#include <stdio.h>
#include "s21_string.h"

void s21_strlen_test(const char *str, int result);
void s21_strcmp_test(const char *str1, const char *str2, int result);
void s21_strcpy_test(const char *orig_str, int size);

int main() {
    const char *str1 = "helloWorld";
    const char *str2 = NULL;
    const char *str3 = "";
    const char *str4 = "a";
    #ifdef Strlen_tests
        s21_strlen_test(str1, 10);
        printf("\n");
        s21_strlen_test(str2, -1);
        printf("\n");
        s21_strlen_test(str3, 0);
        printf("\n");
        s21_strlen_test(str4, 1);
    #endif
    #ifdef Strcmp_tests
        s21_strcmp_test(str1, str4, 7);
        printf("\n");
        s21_strcmp_test(str1, str2, 1);
        printf("\n");
        s21_strcmp_test(str1, str1, 0);
        printf("\n");
        s21_strcmp_test(str2, str2, 0);
        printf("\n");
        s21_strcmp_test(str3, str3, 0);
    #endif
    #ifdef Strcpy_tests
        s21_strcpy_test(str1, 10);
        printf("\n");
        s21_strcpy_test(str2, 0);
        printf("\n");
        s21_strcpy_test(str3, 0);
        printf("\n");
        s21_strcpy_test(str4, 1);
    #endif
    return 0;
}

void s21_strlen_test(const char *str, int result) {
    int length = s21_strlen(str);
    for (int i = 0; i < length; i++)
        printf("%c", str[i]);
    printf(" %d ", length);
    if (length == result)
        printf("SUCCESS");
    else
        printf("FAIL");
}

void s21_strcmp_test(const char *str1, const char *str2, int result) {
    int diff = s21_strcmp(str1, str2);
    int length1 = s21_strlen(str1);
    int length2 = s21_strlen(str2);
    for (int i = 0; i < length1; i++)
        printf("%c", str1[i]);
    printf(" ");
    for (int i = 0; i < length2; i++)
        printf("%c", str2[i]);
    printf(" %d ", diff);
    if (diff == result)
        printf("SUCCESS");
    else
        printf("FAIL");
}

void s21_strcpy_test(const char *orig_str, int size) {
    char *my_copy = malloc((size + 1) * sizeof(char));
    s21_strcpy(my_copy, orig_str);
    for (int i = 0; i < size; i++)
        printf("%c", orig_str[i]);
    printf(" ");
    for (int i = 0; i < size; i++)
        printf("%c", my_copy[i]);
    printf(" ");
    int flag = 1;
    if (orig_str && my_copy) {
        for (int i = 0; *(orig_str + i); i++)
            if (orig_str[i] && my_copy[i])
                flag *= (orig_str[i] == my_copy[i]);
    }
    if (flag)
        printf("SUCCESS");
    else
        printf("FAIL");
    free(my_copy);
}
