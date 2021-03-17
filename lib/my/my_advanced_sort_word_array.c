/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** No file there, just an epitech header example
*/

#include<unistd.h>
#include"my.h"
#include<stdio.h>
#include <stdlib.h>

char *my_strdup(char const *src);

char *the_realloc(char *list, char *input)
{
    int size = my_strlen(list);
    int len = my_strlen(input);
    char *newlist = malloc(sizeof(char) * (size + len + 1));
    int i = 0;
    for (; i < size; i++)
        newlist[i] = list[i];
    for (int j  = 0; j < len; i++, j++)
        newlist[i] = input[j];
    newlist[i] = '\0';
    return newlist;
}

char **my_realloc(char **list, int len, char *str)
{
    char **newlist = malloc(sizeof(char *) * (len + 2));
    for (int i = 0; i < len; i++) {
        newlist[i] = my_strdup(list[i]);
    }
    if (list != NULL)
        free(list);
    newlist[len] = str;
    newlist[len + 1] = NULL;
    return newlist;
}

void swappinggg(char **a, char **b)
{
    char *c = *a;
    *a = *b;
    *b = c;
}

void under_asciiii(int j, char *argv[],
    int (*cmp)(char *, char *, char *), char *prepath)
{
    int bool = cmp(argv[j], argv[j + 1], prepath);
    if (bool > 0)
        swappinggg(&argv[j], &argv[j + 1]);
    return;
}

int my_advanced_sort_word_array(char **argv,
    int (*cmp)(char *, char *, char *), char *prepath)
{
    int argc = 0;
    for (; argv[argc] != 0; argc++);
    for (int i = 0; i < argc - 1; i++) {
        for (int j = 0; j < argc - i - 1; j++)
            under_asciiii(j, argv, cmp, prepath);
    }
    return 1;
}