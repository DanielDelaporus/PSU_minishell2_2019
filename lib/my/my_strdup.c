/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

#include <stdlib.h>

int my_strlen( char const *str);

char *my_strdup(char const *src)
{
    char *result = malloc(sizeof(char) * my_strlen(src) + 1);
    int i = 0;
    for (; src [i] != '\0'; i++) {
        result[i] = src[i];
    }
    result[i] = '\0';
    return result;
}