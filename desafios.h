#ifndef __CHALLENGES_H__
#define __CHALLENGES_H__
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define CALLENGE_COUNT 12
#define MAX_SIZE 128
#define PIE 3.14159265358979323846
#define HANDLE_ERROR(msg)   \
    do                      \
    {                       \
        perror(msg);        \
        exit(EXIT_FAILURE); \
    } while (0)

typedef struct
{
    FILE *fp;
    int (*challenges[CALLENGE_COUNT])(void);
    int level;
    char *buffer;
    size_t size;
} t_game;

void init(FILE *fp);
// Ejecuta el nivel que se envia por parametro.
int challenge(int challenge_id);
// Finaliza el juego y se liberan los recursos.
void end();

#endif