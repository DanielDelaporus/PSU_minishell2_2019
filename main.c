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

char **my_unsetenv(char *name, char **env)
{
    if (my_strcmp("", name) == 0)
        write(2, "Error: too few arguments.\n", 26);
    int len = my_strlen(name);
    int lenv = 0;
    for (; env[lenv] != NULL ;lenv++ );
    for (int i = 0; env[i] != NULL; i++) {
        char *tmp = malloc(sizeof(char) * len + 1);
        tmp[len] = '\0';
        tmp = my_strncpy(tmp, env[i], len);
        if (my_strcmp(tmp, name) == 0) {
            for (int j = i; j < lenv; j++)
                env[j] = env[j + 1];
            free(tmp);
            return env;
        }
        free(tmp);
    }
    return env;
}

char **my_setenv(char *name, char *value, char **env)
{
    if (my_strcmp("", name) == 0 || my_strcmp("", value) == 0) {
        for (int j = 0; env[j] != NULL;
            my_putstr(env[j]), my_putstr("\n"), j++);
        return env;
    }
    int lenv = 0;
    for (; env[lenv] != NULL; lenv++);
    for (int i = 0; i < lenv; i++) {
        char *tmp = malloc(sizeof(char) * my_strlen(name) + 1);
        tmp = my_strncpy(tmp, env[i], my_strlen(name));
        if ((my_strcmp(tmp, name) == 0)) {
            my_strcpy(&env[i][my_strlen(name) + 1], value);
            free(tmp);
            return env;
        }
        free(tmp);
    }
    env = my_realloc(env, lenv, prepare_newenv(name, value));
    return env;
}

void others(char **tmp, char **env)
{
    if (my_strcmp("unsetenv", tmp[0]) && my_strcmp("cd", tmp[0]) &&
        my_strcmp("setenv", tmp[0]) && my_strcmp("env", tmp[0])
        && my_strcmp("exit", tmp[0])) {
        int ex = 0;
        pid_t f = fork();
        char *tmpbuff = malloc(sizeof(char) * 4096);
        tmpbuff = getcwd(tmpbuff, 4096);
        tmpbuff = my_strcat(tmpbuff, "/");
        char *time = malloc(sizeof(char) * my_strlen(tmp[0]) + 1);
        time = my_strcpy(time, tmp[0]);
        tmp[0] = my_strcat(tmpbuff, tmp[0]);
        if (f == 0)
            ex = execve(tmp[0], tmp, env);
        else
            wait(&ex);
        tmp[0] = time;
        tmp = shorten(ex, env, tmp, f);
        free(time);
        free(tmpbuff);
    }
}

char **undermain(char *buff, char **nenv, char **env)
{
    char **tmp = malloc(sizeof(char *) * 5);
    tmp = fill_tmp(tmp, buff);
    if (my_strcmp("cd", tmp[0]) == 0) {
        int res = chdir(tmp[1]);
        if (res == -1)
            displayerr(tmp[1], 0);
    }
    if (my_strcmp("env", tmp[0]) == 0)
        for (int j = 0; nenv[j] != NULL;
            my_putstr(nenv[j]), my_putstr("\n"), j++);
    if (my_strcmp("setenv", tmp[0]) == 0)
        nenv = my_setenv(tmp[1], tmp[2], nenv);
    if (my_strcmp("unsetenv", tmp[0]) == 0)
        nenv = my_unsetenv(tmp[1], nenv);
    others(tmp, env);
    free(tmp);
    return nenv;
}

int main(int argc, char *argv[], char **env)
{
    char *buff = malloc(sizeof(char) * 4096);
    size_t size = 4096;
    int rd = 1;
    int lenv = 0;
    for (; env[lenv] != NULL ;lenv++ );
    char **nenv = malloc(sizeof(char *) * lenv + 1);
    for (int i = 0; i < lenv; nenv[i] = env[i], i++);
    nenv[lenv] = NULL;
    while (my_strcmp("exit\n", buff) != 0) {
        if (isatty(0))
            write(1, "$> ", 3);
        rd = getline(&buff, &size, stdin);
        if (rd <= 0)
            return 0;
        nenv = undermain(buff, nenv, env);
    }
    my_putstr("exit\n");
    return 0;
}