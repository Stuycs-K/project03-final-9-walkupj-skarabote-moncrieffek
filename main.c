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
    le_file = open("songs.txt", O_RDWR | O_TRUNC | O_CREAT, 0666); //check these permisisons
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


void ddisplay(){
   //dont create but access the semaphore
    int *data; int shmid;
    shmid = shmget (KEY, sizeof(int), 0 | 0640) ;
    data = shmat (shmid, 0, 0); //attach
  //open the story to read it (bam and data not technically needed rn)
        int r_file;
    r_file = open("songs.txt", O_RDONLY, 0);
    int bam = *data;
    
   
    char buff[BUFFER_SIZE+1];
    buff[BUFFER_SIZE]=0;

//err();
    int bytes;
    while((bytes = read(r_file, buff, BUFFER_SIZE))){
    if(bytes == -1)err();//all non 0 are true

   // printf("Bytes read: %u",bytes);
    printf("%s\n",buff);
    //int bytesread;
    }
    //we attached it so we need to detach it
    shmdt (data); //detach
}

void rremove(){
//like in display, we are accessing the shareed memory by the same key
int shmid;
    shmid = shmget(KEY, sizeof(int), IPC_CREAT | 0640);




//here we are just printing out the file
  int r_file;
    r_file = open("songs.txt", O_RDONLY, 0);
    char buff[BUFFER_SIZE+1];
    buff[BUFFER_SIZE]=0;

//err();
    int bytes;
    while((bytes = read(r_file, buff, BUFFER_SIZE))){
    //if(bytes == -1)err();//all non 0 are true
    printf("helo\n");
   // printf("Bytes read: %u",bytes);
    printf("%s\n",buff);
    //int bytesread;
    }
   // ddisplay();

    //we remove it
    shmctl(shmid, IPC_RMID, 0); //remove the segment
}


int main(int argc, char* argv[]){
    srand( time(NULL) );

    printf("LINKED LIST TESTS\n====================================\n");
    struct song_node** library = make_library();


    //umm testing lol!
    add_song(library, "arctic monkeys", "i wanna be yours");
    add_song(library, "zeph", "world");
    add_song(library, "itzy", "cake");

    //shared memory
    ccreate();

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
           printf("here goes...\n");
           ddisplay();
        }
        else if(strcmp( strcommand, "add") == 0){
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
            add_song(library, artist, song); 
            print_library(library);




//um
    int semd = semget(KEY, 1, 0);
    // struct sembuf {
    //     short sem_op;
    //     short sem_num;
    //     short sem_flag;
    // };

    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_flg = SEM_UNDO;
    sb.sem_op = -1; //setting the operation to down



 

//err();

    semop(semd, &sb, 1); //perform the operation
     printf("got the semaphore!\n");
   
     int *data; int shmid;
   shmid = shmget (KEY, sizeof(int), 0 | 0640) ;
   data = shmat (shmid, 0, 0); //attach
    


    struct stat stat_buffer;
    int readdata;
    readdata = open("story.txt", O_RDWR | O_APPEND); //| 0_APPEND

     int r_file;
    r_file = open("story.txt", O_RDONLY, 0);
    int bam = *data;
    
    lseek( r_file, -1 * bam-1 , SEEK_END );
    char buff[BUFFER_SIZE+1];
    buff[BUFFER_SIZE]=0;


        int bytes;
    while((bytes = read(r_file, buff, BUFFER_SIZE))){

    printf("%s\n",buff);

    }

 


    char modify_line[300];//LMFAOO CHECK ALL THE 30s
    printf("write one line of the story: ");

    fgets(modify_line,300,stdin);
    printf("the line u wrote: %s\n", modify_line);
    printf("size of the line: %d", strlen(modify_line));
   // arr = realloc(arr, sizeof(struct pop_entry) * stat_buffer ->st_size + 23); //15+8+8 = 23
//     char buff[256];


    int size = strlen(modify_line);

    write(readdata,&modify_line,size);
    *data = size; //work with the segment as a normal pointe
  // printf("*data: %d\n", *data) ;
    shmdt (data); //detach



    sb.sem_op = 1; //set the operation to up
    semop(semd, &sb, 1); //perform the operation


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

        else if(strcmp( strcommand, "exit") == 0){
            rremove();
            exit(0);
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
