#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

const char *prompt = "#cisfun$ ";
char *command = NULL;
size_t len = 0;
ssize_t read;
char **args;
char *token;
char *path;
char *path2;
int status;

#endif /* MAIN_H */
