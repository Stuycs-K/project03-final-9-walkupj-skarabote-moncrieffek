#include "linkedlist.h"
#include "library.h"
#ifndef MUSIC_H
#define MUSIC_H
void parse_args(char * line, char ** arg_ary);
// int play(char * file, char*loop, char *times);
int play(char * file);
void play_library(struct song_node**);
#endif