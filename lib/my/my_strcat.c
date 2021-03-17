/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

#include<stdlib.h>

int my_strlen( char const *str);

char *my_strcat(char *dst, char const *src)
{
    int i;
    int j;
    char *result = malloc(sizeof(char) * (my_strlen(dst) + my_strlen(src) + 1));
    for ( i = 0; dst[i] != '\0'; i++)
        result[i] = dst[i];
    for ( j = 0; src[j] != '\0'; i++, j++)
        result[i] = src[j];
    result[i] = '\0';
    return result;
}