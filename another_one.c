/*
** EPITECH PROJECT, 2019
** PSU_minishell_2019
** File description:
** No file there, just an epitech header example
*/
#define _GNU_SOURCE
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include"lib/my/my.h"

char **tempo(char **tmp)
{
    for (int i = 0; i < 5; i++) {
        if (my_strcmp("", tmp[i]) == 0) {
            tmp[i] = NULL;
            i = 5;
        }
    }
    return tmp;
}

char **shorten(int ex, char **env, char **tmp, pid_t f)
{
    if (ex == -1)
        ex = checkpath(env, tmp, f);
    if (ex == -1)
        displayerr(tmp[0], 1);
    for (int i = 0; i < 5; i++)
        tmp[i] = "";
    return tmp;
}

char **get_path_into_env(char **env)
{
    char **path = malloc(sizeof(char *) * 10);
    for (int i = 0; env[i] != NULL; i++) {
        char *tmpp = malloc(sizeof(char) * 4 + 1);
        if (my_strcmp(my_strncpy(tmpp, env[i], 4), "PATH") == 0)
            path = separate(env[i], path);
        free(tmpp);
    }
    return path;
}