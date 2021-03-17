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
#include"lib/my/my.h"
#include<string.h>

void displayerr(char *toprint, int bool)
{
    for (int i = 0; toprint[i] != '\0'; i++)
        write(2, &toprint[i], 1);
    write(2, ": ", 2);
    char *err = strerror(errno);
    for (int i = 0; err[i] != '\0'; i++)
        write(2, &err[i], 1);
    write(2, "\n", 1);
    if (bool)
        exit(0);
}

char **fill_tmp(char **tmp, char *buff)
{
    int index = 0;
    for (int j = 0; j < 5; j++) {
        int i = index;
        for (; buff[i] != ' ' && buff[i] != '\0' && buff[i] != '\n'; i++);
        tmp[j] = malloc(sizeof(char) * 1000);
        tmp[j] = my_strncpy(tmp[j], &buff[index], i - index);
        tmp[j][i + 1] = '\0';
        if (buff[i] == '\0')
            return tmp;
        index = i + 1;
    }
    tmp[4] = NULL;
    return tmp;
}

char *prepare_newenv(char *name, char *value)
{
    char *new = malloc(sizeof(char) * my_strlen(name) + my_strlen(value) + 2);
    new = my_strcpy(new, name);
    new[my_strlen(name)] = '=';
    new = my_strcat(new, value);
    new[my_strlen(name) + 1 + my_strlen(value)] = '\0';
    return new;
}

char **separate(char *line, char **paths)
{
    int num = 0;
    for (int i = 5; i < my_strlen(line); i++, num++) {
        char *onepath = malloc(sizeof(char) * 150);
        int j = 0;
        for ( j = i; line[j] != '\0' && line[j] != ':'; j++);
        onepath = my_strncpy(onepath, &line[i], j - i);
        onepath[j - i] = '\0';
        paths[num] = my_strdup(onepath);
        i = j;
    }
    paths[num] = NULL;
    return paths;
}

int checkpath(char **env, char **tmp, pid_t f)
{
    char **path = get_path_into_env(env);
    int ex = -1;
    tmp = tempo(tmp);
    for (int i = 0; path[i] != NULL && ex == -1 && path[0] != NULL; i++) {
        path[i] = my_strcat(path[i], "/");
        char *time = tmp[0];
        tmp[0] = my_strcat(path[i], tmp[0]);
        if (f == 0)
            ex = execve(tmp[0], tmp, env);
        else
            wait(&ex);
        tmp[0] = time;
    }
    free(path);
    return ex;
}