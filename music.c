#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int play(char * file, char* loop, int times){
	pid_t p = fork();
	if(p < 0){
		perror("fork fail");//output to stderr instead of stdout
		exit(1);
	}
	else if(p == 0){ // child 1
		char *line = "mpg123 ";
		strcat(line, file);
		if(strcmp(loop, "y") == 0){
			char* loop = "-- loop"
			strcat(line, "loop")
		}
		char *args[100];
		parse_args(line, args);
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
