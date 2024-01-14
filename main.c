#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "linkedlist.h"
#include "library.h"
#include "music.h"
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

#define KEY 244753034//idk why it's this number
#define BUFFER_SIZE 3000

// void err(int i, char*message){
//   if(i < 0){
// 	  printf("Error: %s - %s\n",message, strerror(errno));
//   	exit(0);
//   }
// }

int err(){
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(0);
}


void ccreate(){

    //files
    int le_file;
    le_file = open("story.txt", O_RDWR | O_TRUNC | O_CREAT, 0666); //check these permisisons
    printf("opened le file \n");
    //this initializes all the shared memory
    int *data; int shmid;
    shmid = shmget (KEY, sizeof(int), IPC_CREAT | 0640) ;
    printf ("shmid: %d\n", shmid) ;
    data = shmat (shmid, 0, 0); //attach
    printf("data: %p\n", data);
    printf ("*data: %d\n", *data) ;
    //*data = * data + 10; //work with the segment as a normal pointe
    printf("*data: %d\n", *data) ;
    shmdt (data); //detach
}

int main(int argc, char* argv[]){
    srand( time(NULL) );

    printf("LINKED LIST TESTS\n====================================\n");
    struct song_node** library = make_library();


    //umm testing lol!
    add_song(library, "idk", "rain", "rain.mp3");
    add_song(library, "yasuha", "flyday", "flyday.mp3");
  //  add_song(library, "itzy", "cake", "filepath here");

    //MOVE THIS STUFF TO CLIENT LATER
    while(1){
        printf("enter a command: \n");
        char buff[256];
        char * command = fgets(buff, 100, stdin);
        char strcommand[100];
        sscanf(command, "%s", strcommand);


        if(strcmp( strcommand, "view" )==0){
             printf("you clicked view\n");
           print_library(library);
        }
        else if(strcmp( strcommand, "add") == 0){
            char buff1[256];
            char buff2[256];
            char buff3[256];
            printf("enter the artist name: ");
            char * userartist = fgets(buff1, 100, stdin);
            printf("enter the song name: ");
            char * usersong = fgets(buff2, 100, stdin);
            char song[100];
            char artist[100];


            sscanf(usersong, "%s", song);

            sscanf(userartist, "%s", artist);
            add_song(library, artist, song, song);
            print_library(library);
        }
        else if(strcmp( strcommand, "shuffle") == 0){
            printf("how many songs do you want to shuffle: ");
            char buff[256];
            char * data = fgets(buff, 100, stdin);

            int shuffleint;
            sscanf(data, "%d", &shuffleint);
            //change 5 to the length of the library
           shuffle(library, shuffleint);
        }
        else if(strcmp( strcommand, "search") == 0){
            char buff1[256];
            char buff2[256];
            printf("enter the artist name: ");
            char * userartist = fgets(buff1, 100, stdin);
            printf("enter the song name: ");
            char * usersong = fgets(buff2, 100, stdin);
            char song[100];
            char artist[100];


            sscanf(usersong, "%s", song);

            sscanf(userartist, "%s", artist);
            //okay htis is the search wehn u know the whole name,
            //for the search by first letter we'll have to use more linked list stuff
            // struct song_node* song = search_song(library, "black sabbath", "orchid");
            // printf("found {%s, %s}\n", song->artist, song->name);
            //update_data();
            struct song_node* searching = search_song(library, artist, song);
           // printf("hii");
            if (searching == NULL) {
                printf("Song not found\n");
            }
            else{
                printf("found {%s, %s}\n", searching->artist, searching->name);
            }
        }
        else if(strcmp(strcommand, "remove" ) == 0){
            char buff1[256];
            char buff2[256];
            printf("enter the artist name: ");
            char * userartist = fgets(buff1, 100, stdin);
            printf("enter the song name: ");
            char * usersong = fgets(buff2, 100, stdin);
            err();
            char song[100];
            char artist[100];
            sscanf(usersong, "%s", song);
            sscanf(userartist, "%s", artist);
            strtok(song, "\n");
            strtok(artist, "\n");
            // printf("%s", song);
            remove_song_lib(library, song, artist);
            // err();
            print_library(library);


            // remove_song_lib(library, "aphex twin", "ageispolis");
            //change those artist and song to fgets
            // remove_song_lib(library, "aphex twin", "ageispolis");
        }
        else if(strcmp( strcommand, "menu") == 0){
            print_menu();
        }

        else if(strcmp( strcommand, "play") == 0){
          char buff[256];
          printf("if you want to play the entire playlist, enter y. else, enter n: ");
          fgets(buff, 256, stdin);
          char x = strtok(buff, "\n");
          if(strcmp(x, "y") == 0){
            play_library(library);
          }
          else{
            char buff1[256];
            printf("enter the song name: ");
            char * usersong = fgets(buff1, 100, stdin);
            char buff2[256];
            // printf("loop? enter y or n: ");
            // char * loop = fgets(buff2, 100, stdin);
            // char buff3[256];
            // int times;
            // if(strcmp(buff2, "y") == 0){
            //   printf("how many times? (say -1 for infinite): ");
            //   fgets(buff3, 100, stdin);
            //   sscanf(buff3, "%d", times);
            // }
            play(usersong);
          }
        }

        else{
            printf("that's not a command\n");
        }
    }


//args down here
    // if(argc >1 ){
    //     // if(strcmp(argv[1], "create" ) == 0){
    //     //    struct song_node** library = make_library();
    //     // }
    //     //um do we need a create one.
    //    if(strcmp(argv[1], "view" ) == 0){
    //         printf("you clicked view\n");
    //        print_library(library);
    //     }
    //     else if(strcmp(argv[1], "add" ) == 0){
    //         char buff1[256];
    //         char buff2[256];
    //         printf("enter the artist name: ");
    //         char * userartist = fgets(buff1, 100, stdin);
    //         printf("enter the song name: ");
    //         char * usersong = fgets(buff2, 100, stdin);
    //         char song[100];
    //         char artist[100];


    //         sscanf(usersong, "%s", song);

    //         sscanf(userartist, "%s", artist);
    //         add_song(library, artist, song);
    //         print_library(library);
    //        //we're gonna have to change these things to the fgets thing
    //     }
    //     else if(strcmp(argv[1], "shuffle" ) == 0){
    //         printf("how many songs do you want to shuffle: ");
    //         char buff[256];
    //         char * data = fgets(buff, 100, stdin);

    //         int shuffleint;
    //         sscanf(data, "%d", &shuffleint);
    //         //change 5 to the length of the library
    //        shuffle(library, shuffleint);
    //     }
    //     else if(strcmp(argv[1], "remove" ) == 0){
    //         char buff1[256];
    //         char buff2[256];
    //         printf("enter the artist name: ");
    //         char * userartist = fgets(buff1, 100, stdin);
    //         printf("enter the song name: ");
    //         char * usersong = fgets(buff2, 100, stdin);
    //         err();
    //         char song[100];
    //         char artist[100];
    //         sscanf(usersong, "%s", song);
    //         sscanf(userartist, "%s", artist);
    //         strtok(song, "\n");
    //         strtok(artist, "\n");
    //         // printf("%s", song);
    //         remove_song_lib(library, song, artist);
    //         // err();
    //         print_library(library);


    //         // remove_song_lib(library, "aphex twin", "ageispolis");
    //         //change those artist and song to fgets
    //         // remove_song_lib(library, "aphex twin", "ageispolis");
    //     }
    //     else if(strcmp(argv[1], "search" ) == 0){
    //         char buff1[256];
    //         char buff2[256];
    //         printf("enter the artist name: ");
    //         char * userartist = fgets(buff1, 100, stdin);
    //         printf("enter the song name: ");
    //         char * usersong = fgets(buff2, 100, stdin);
    //         char song[100];
    //         char artist[100];


    //         sscanf(usersong, "%s", song);

    //         sscanf(userartist, "%s", artist);
    //         //okay htis is the search wehn u know the whole name,
    //         //for the search by first letter we'll have to use more linked list stuff
    //         // struct song_node* song = search_song(library, "black sabbath", "orchid");
    //         // printf("found {%s, %s}\n", song->artist, song->name);
    //         //update_data();
    //         struct song_node* searching = search_song(library, artist, song);
    //        // printf("hii");
    //         if (searching == NULL) {
    //     printf("Song not found\n");
    // }
    // else {
    //      printf("found {%s, %s}\n", searching->artist, searching->name);
    // }

    //     }
    //     else if(strcmp(argv[1], "menu" ) == 0){
    //         print_menu();
    //     }
    //     else{
    //         printf("not a valid flag");
    //     }
   // }
}
