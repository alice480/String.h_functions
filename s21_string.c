#include "s21_string.h"

int s21_strlen(const char *str) {
    int length = 0;
    if (str) {
        for (; *(str + length); length++) {;}
    } else {
        length = -1;
    }
    return length;
}

int s21_strcmp(const char *str1, const char *str2) {
    int diff = 0;
    if (str1 && str2) {
        for (int i = 0; *(str1 + i); i++) {
            if (str1[i] && str2[i]) {
                if (str1[i] != str2[i] && diff == 0)
                    diff = str1[i] - str2[i];
            } else if (diff == 0) {
                if (str1[i])
                    diff = 1;
                else
                    diff = -1;
            }
        }
    } else {
        if (str1)
            diff = 1;
        else if (str2)
            diff = -1;
    }
    return diff;
}

char* s21_strcpy(char *copy_str, const char *orig_str) {
    char *address = copy_str;
    if (copy_str && orig_str) {
        for (int i = 0; *(orig_str + i); i++) {
            copy_str[i] = orig_str[i];
        }
    }
    return address;
}
