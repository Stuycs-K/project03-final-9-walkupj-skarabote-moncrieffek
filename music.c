#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "music.h"

// int play(char * file, char* loop, char *times){
int play(char * file){
	printf("forking and playing your song\n");
	pid_t p = fork();
	if(p < 0){
		printf("wuh oh\n");
		perror("fork fail");//output to stderr instead of stdout
		exit(1);
	}
	else if(p == 0){ // child 1
		//printf("in child 1\n");
		char line[512] = "mpg123 ";
		char path[512] = "./";
		file = strtok(file, "\n");
		strcat(file, ".mp3");
		strcat(path, file);
		strcat(line, path);
		//printf("line = %s\n", line);
		// if(strcmp(loop, "y") == 0){
		// 	char* loop = "-- loop";
		// 	strcat(loop, times);
		// 	strcat(line, loop);
		// }
		char * res;
		res = strtok(line, "\n");
		//printf("res = %s\n", res);
		char *args[100];
		parse_args(res, args);
		int a = execvp(args[0], args);
		exit(0);
	}
	return p;
}

void parse_args(char * line, char ** arg_ary){
  char * sep;
  int index = 0;
  while((sep = strsep(&line, " "))){
    arg_ary[index] = sep;
    index++;
  }
  arg_ary[index] = NULL;
}

int main(){
	char usersong[256];
    printf("enter the song name: ");
    fgets(usersong, 256, stdin);
	printf("usersong = %s\n", usersong);
    // printf("loop? enter y or n: ");
    // char loop[256];
	// fgets(loop, 256, stdin);
	// printf("loop = %s\n", loop);
    // char times[256];
    // if(strcmp(loop, "y") == 0){
    // 	printf("how many times?");
    // 	fgets(times, 256, stdin);
	// 	printf("times = %s\n", times);
    // }
    // play(usersong, loop, times);
	play(usersong);
}
