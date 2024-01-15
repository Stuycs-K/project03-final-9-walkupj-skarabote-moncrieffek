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
    *data = * data + 10; //work with the segment as a normal pointe
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

int parse_args( char * line, char ** arg_ary ){
    int i = 0;
    while(line != NULL){
        
        arg_ary[i] = strsep(&line, ",");
        i++;
    }
    return i;
}
int main(int argc, char* argv[]){
    srand( time(NULL) );

    printf("welcome to stuyify!\n====================================\n");
    struct song_node** library = make_library();



     int r_file;
    r_file = open("songs.txt", O_RDONLY, 0);

    char buff[BUFFER_SIZE+1];
    buff[BUFFER_SIZE]=0;

    char d[] = ","; //the delimerator
        int bytes;
    while((bytes = read(r_file, buff, BUFFER_SIZE))){
        char * entries[64];
        char * line = buff;
        int num;
        num = parse_args( line, entries );
        printf("NUMBER OF SONGS: %d", num/2);
        int i=0;
        int g=0;
       
      while (g < num){
      //      err();
      //err();
       printf("ENTRY%d: %s",i, entries[i]);
       
        // printf("ENTRY: %s", entries[0]);
        // printf("ENTRY: %s", entries[1]);
        // printf("ENTRY: %s", entries[2]);
        // printf("ENTRY: %s", entries[3]);
        // printf("ENTRY: %s", entries[4]);
       // printf("ENTRY: %s", entries[5]);
        //if()
        g++;
      i++;
     
    }
    int count = 0;
     int h = 0;
     while (count < num/2){
       // err();
    add_song(library, entries[h+1], entries[h]);
     h = h+2;
     count++;
     }
    printf("hi");
//     //int bytesread;
    }
    

//     while(buff != NULL){
//         char test[100] = "wow,i,am,trying,ig";
//         char * curr = test;
//         char * entry;
//         entry = strsep(&curr, ",");
//    // if(bytes == -1)err();//all non 0 are true
//    // char *entry = strsep(&bytes, d);
//    // printf("Bytes read: %u",bytes);
//     printf("%s\n",entry);
//     }







    // //umm testing lol!
    // add_song(library, "arctic monkeys", "i wanna be yours");
    // add_song(library, "zeph", "world");
    // add_song(library, "itzy", "cake");

    

    //shared memory
    ccreate();//i think it's because a new shared memory is being created every time



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
         //  printf("here goes...\n");
         //  ddisplay();
        }
        else if(strcmp( strcommand, "add") == 0){
            //attach the shared memory
    int *data; int shmid;
   shmid = shmget (KEY, sizeof(int), 0 | 0640) ;
   data = shmat (shmid, 0, 0); //attach
           // ccreate();
            // char buff1[256];
            // char buff2[256];
            // printf("enter the artist name: ");
            // char * userartist = fgets(buff1, 100, stdin);
            // printf("enter the song name: ");
            // char * usersong = fgets(buff2, 100, stdin);
            // char song[100];
            // char artist[100];
            
            
            // sscanf(usersong, "%s", song);
            
            // sscanf(userartist, "%s", artist);
            // add_song(library, artist, song); 
            print_library(library);




//um
    int semd = semget(KEY, 1, 0);

    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_flg = SEM_UNDO;
    sb.sem_op = -1; //setting the operation to down

printf("did some stuff\n");

 

//err();

    semop(semd, &sb, 1); //perform the operation
     printf("got the semaphore!\n");
   
     
    

    printf("data: %p\n", data);
    printf ("*data: %d\n", *data) ;
   // *data = * data + 10; //work with the segment as a normal pointe
    printf("*data: %d\n", *data);

    struct stat stat_buffer;
    int readdata;
    readdata = open("songs.txt", O_RDWR | O_APPEND); //| 0_APPEND

    int r_file;
    r_file = open("songs.txt", O_RDONLY, 0);
    int bam = *data;
    
   // lseek( r_file, -1 * bam-1 , SEEK_END );
    char buff[BUFFER_SIZE+1];
    buff[BUFFER_SIZE]=0;


        int bytes;
    while((bytes = read(r_file, buff, BUFFER_SIZE))){

    printf("%s\n",buff);

    }

 


    char modify_line[300];//LMFAOO CHECK ALL THE 30s
    //printf("write one line of the story: ");
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

    //fgets(modify_line,300,stdin);
    //printf("the line u wrote: %s\n", modify_line);
    //printf("size of the line: %d", strlen(modify_line));
   // arr = realloc(arr, sizeof(struct pop_entry) * stat_buffer ->st_size + 23); //15+8+8 = 23
//     char buff[256];


    int ssize = strlen(song);
    int asize = strlen(artist);
    int size = strlen(song) + strlen(artist);

    write(readdata,&song,ssize);
    write(readdata,",", 1);
    write(readdata,&artist,asize);
    write(readdata,",", 1);
    *data = size; //work with the segment as a normal pointe
  // printf("*data: %d\n", *data) ;
    



    sb.sem_op = 1; //set the operation to up
    semop(semd, &sb, 1); //perform the operation
shmdt (data); //detach

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
           // rremove();


//THIS IS THE ACTUAL WRITING STUFF
    int filee;
    filee = open("songs.txt", O_RDWR | O_APPEND); //| 0_APPEND
   // write_library(library, readdata);
for(int i=0; i<26; i++){
    int letter = i+71;
    

//printf("letter: %s", letter);
// for(int i=0; i<26; i++){
//         struct song_node* letter_list = lib[letter];
//         if(lib[i]){
//             printf("%c: ", i+97);
//             print_letter(lib, i+97);
//         }
//         letter++;
//     }
// err();
 struct song_node* front = library[i];
// err();
    while (front != NULL) { //front is a song_node that's inputed lol (library[letter])
        char * wowa = front->artist;
        char * wows = front->name;

    
    int ssize = strlen(wows);
    int asize = strlen(wowa);
    int size = strlen(wows) + strlen(wowa);

            char ssong[100];
            char aartist[100];

    sscanf(wows, "%s", ssong);
    sscanf(wowa, "%s", aartist);

    write(filee,&ssong,ssize);
    write(filee,",", 1);
    write(filee,&aartist,asize);
    write(filee,",", 1);

    front = front->next;
    }
   // letter ++;






}

            exit(0);
            //take everything out of the structs and put it in the shared memory file
        }
        else if(strcmp( strcommand, "clear") == 0){
           rremove();
           //clear_library(library);
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
