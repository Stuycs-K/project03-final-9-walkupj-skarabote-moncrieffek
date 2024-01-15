#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>
#include "linkedlist.h"
#include "library.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <unistd.h>
#include <string.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/ipc.h> 
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/socket.h> 
#include <netdb.h>


#ifndef NETWORKING_H
#define KEY 244753034
#define NETWORKING_H
#define PORT "19231"
#define BUFFER_SIZE 1024
#endif

void clientLogic(int server_socket){
//         struct song_node** library = make_library(); //might not need
//         printf("enter a command: \n");
//         char buff[256];
//         char * command = fgets(buff, 100, stdin);
//         char strcommand[100];
//         sscanf(command, "%s", strcommand);


//         if(strcmp( strcommand, "view" )==0){
//              printf("you clicked view\n");
//            print_library(library); 
//            printf("here goes...\n");
//          //  ddisplay();
//         }
//         else if(strcmp( strcommand, "add") == 0){
//             //attach the shared memory
//     int *data; int shmid;
//    shmid = shmget (KEY, sizeof(int), 0 | 0640) ;
//    data = shmat (shmid, 0, 0); //attach
//             print_library(library);




// //um
//     int semd = semget(KEY, 1, 0);

//     struct sembuf sb;
//     sb.sem_num = 0;
//     sb.sem_flg = SEM_UNDO;
//     sb.sem_op = -1; //setting the operation to down

// printf("did some stuff\n");

 

// //err();

//     semop(semd, &sb, 1); //perform the operation
//      printf("got the semaphore!\n");
   
     
    

//     printf("data: %p\n", data);
//     printf ("*data: %d\n", *data) ;
//     *data = * data + 10; //work with the segment as a normal pointe
//     printf("*data: %d\n", *data);

//     struct stat stat_buffer;
//     int readdata;
//     readdata = open("songs.txt", O_RDWR | O_APPEND); //| 0_APPEND

//     int r_file;
//     r_file = open("songs.txt", O_RDONLY, 0);
//     int bam = *data;
    
//     lseek( r_file, -1 * bam-1 , SEEK_END );
//     char buff[BUFFER_SIZE+1];
//     buff[BUFFER_SIZE]=0;


//         int bytes;
//     while((bytes = read(r_file, buff, BUFFER_SIZE))){

//     printf("%s\n",buff);

//     }

 


//     char modify_line[300];//LMFAOO CHECK ALL THE 30s
//     //printf("write one line of the story: ");
//     char buff1[256];
//             char buff2[256];
//             printf("enter the artist name: ");
//             char * userartist = fgets(buff1, 100, stdin);
//             printf("enter the song name: ");
//             char * usersong = fgets(buff2, 100, stdin);
//             char song[100];
//             char artist[100];
            
            
//             sscanf(usersong, "%s", song);
            
//             sscanf(userartist, "%s", artist);
//             add_song(library, artist, song); 

//     //fgets(modify_line,300,stdin);
//     //printf("the line u wrote: %s\n", modify_line);
//     //printf("size of the line: %d", strlen(modify_line));
//    // arr = realloc(arr, sizeof(struct pop_entry) * stat_buffer ->st_size + 23); //15+8+8 = 23
// //     char buff[256];


//     int ssize = strlen(song);
//     int asize = strlen(artist);
//     int size = strlen(song) + strlen(artist);

//     write(readdata,&song,ssize);
//     write(readdata,",", 1);
//     write(readdata,&artist,asize);
//     write(readdata,"\n", 1);
//     *data = size; //work with the segment as a normal pointe
//   // printf("*data: %d\n", *data) ;
    



//     sb.sem_op = 1; //set the operation to up
//     semop(semd, &sb, 1); //perform the operation
// shmdt (data); //detach

//         }
//         else if(strcmp( strcommand, "shuffle") == 0){
//             printf("how many songs do you want to shuffle: ");
//             char buff[256];
//             char * data = fgets(buff, 100, stdin);
    
//             int shuffleint; 
//             sscanf(data, "%d", &shuffleint);
//             //change 5 to the length of the library
//            shuffle(library, shuffleint);
//         }
//         else if(strcmp( strcommand, "search") == 0){
//             char buff1[256];
//             char buff2[256];
//             printf("enter the artist name: ");
//             char * userartist = fgets(buff1, 100, stdin);
//             printf("enter the song name: ");
//             char * usersong = fgets(buff2, 100, stdin);
//             char song[100];
//             char artist[100];
            

//             sscanf(usersong, "%s", song);
            
//             sscanf(userartist, "%s", artist);
//             //okay htis is the search wehn u know the whole name, 
//             //for the search by first letter we'll have to use more linked list stuff
//             // struct song_node* song = search_song(library, "black sabbath", "orchid");
//             // printf("found {%s, %s}\n", song->artist, song->name);
//             //update_data();
//             struct song_node* searching = search_song(library, artist, song);
//            // printf("hii");
//             if (searching == NULL) {
//                 printf("Song not found\n");
//             }
//             else{
//                 printf("found {%s, %s}\n", searching->artist, searching->name);
//             }
//         }
//         else if(strcmp(strcommand, "remove" ) == 0){
//             char buff1[256];
//             char buff2[256];
//             printf("enter the artist name: ");
//             char * userartist = fgets(buff1, 100, stdin);
//             printf("enter the song name: ");
//             char * usersong = fgets(buff2, 100, stdin);
//             err();
//             char song[100];
//             char artist[100];
//             sscanf(usersong, "%s", song);
//             sscanf(userartist, "%s", artist);
//             strtok(song, "\n");
//             strtok(artist, "\n");
//             // printf("%s", song);
//             remove_song_lib(library, song, artist);
//             // err(); 
//             print_library(library);

            
//             // remove_song_lib(library, "aphex twin", "ageispolis");
//             //change those artist and song to fgets
//             // remove_song_lib(library, "aphex twin", "ageispolis");
//         }
//         else if(strcmp( strcommand, "menu") == 0){
//             print_menu();
//         }

//         else if(strcmp( strcommand, "exit") == 0){
//            // rremove();
//             exit(0);
//         }
//         else if(strcmp( strcommand, "clear") == 0){
//            rremove();
//         }
        
//         else{
//             printf("that's not a command\n");
//         }

        
    }
// //   Listens for a string (use the buffer size),
// // Reply with the rot13 of the string.
// char userinput[256];
// printf("enter in a string: \n");
// scanf("%s", &userinput);
// int len, bytes_sent;
// char buff[256+1];
// len = strlen(userinput);
// bytes_sent = send(server_socket, userinput, len, 0);
// recv(server_socket, buff, 256, 0);
// printf("RECIEVED: %s\n", buff);


int main(int argc, char *argv[] ) {
  char* IP = "127.0.0.1";
  if(argc>1){
    IP=argv[1];
  }
  while(1){
  int server_socket = client_tcp_handshake(IP);
  printf("client connected.\n");
  
  clientLogic(server_socket);
  }
}