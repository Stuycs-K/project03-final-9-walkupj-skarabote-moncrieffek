#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
  //printf("main started\n");
  char *path = malloc(sizeof(path));
  if(argc == 1){
    printf("Please enter a path: \n");
    char input[15];
    //printf("input created\n");
    fgets(input, 15, stdin);
    //printf("fgets ran\n");
    sscanf(input, "%s", path);
    //printf("sscanf ran\n");
  }
  if(argc == 2){
    path = argv[1];
  }
  //printf("path created\n");
  DIR * dir = opendir(path); // should be the second argument after the program name
  //printf("dir created and opened\n");
  printf("directory: %s\n", path);
  int totalSize = 0;
  struct dirent *entry;
  //printf("entry created\n");
  entry = readdir(dir); // THIS IS THE SEGFAULTING LINE you fucker
  //printf("entry read into\n");
  while(entry){
    //printf("inside while loop\n");
    struct stat *info;
    info = malloc(sizeof(struct stat)*1);
    stat(path, info); // or struct stat *info = stat(path, info);  idk yet
    //printf("info created and read into\n");
    int i = entry->d_type;
    char *type;
    if(i == DT_DIR) type = "folder";
    if(i == DT_REG) type = "file";
    printf("name: %s  type: %s\n", entry->d_name, type);
    // printf("name: %s     type: %d\n", entry->d_name, entry->d_type);
    if(i != DT_DIR) totalSize += info->st_size;
    entry = readdir(dir);
    free(info);
  }
  closedir(dir);
  printf("size of %s: %d\n", path, totalSize);
}
