#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>
#include "linkedlist.h"
#include "library.h"
#include <errno.h>

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

int main(int argc, char* argv[]){
    srand( time(NULL) );

    printf("LINKED LIST TESTS\n====================================\n");
    struct song_node** library = make_library();


    //umm testing lol!
    add_song(library, "arctic monkeys", "i wanna be yours");
    add_song(library, "zeph", "world");
    add_song(library, "itzy", "cake");
    
    // struct song_node* front = memory("artistB", "t");
    // front = insert_in_order(front, "artistA", "h");
    // front = insert_in_order(front, "artistA", "f");
    // front = insert_in_order(front, "artistA", "d");
    // front = insert_in_order(front, "artistA", "g");


    //change these to include our commands
    if(argc >1 ){
        // if(strcmp(argv[1], "create" ) == 0){
        //    struct song_node** library = make_library();
        // }
        //um do we need a create one.
       if(strcmp(argv[1], "view" ) == 0){
            printf("you clicked view\n");
           print_library(library); 
        }
        else if(strcmp(argv[1], "add" ) == 0){
            char buff1[256];
            char buff2[256];
            printf("enter the artist name: ");
            char * userartist = fgets(buff1, 100, stdin);
            printf("enter the song name: ");
            char * usersong = fgets(buff2, 100, stdin);
            char song[100];
            char artist[100];
            printf("enter the mp3 link: ");
            char* usermp3 = fgets(buff2, 100, stdin);
            sscanf(usersong, "%s", song);
            sscanf(userartist, "%s", artist);
            sscanf(usermp3, "%s", usermp3);
            add_song(library, artist, song); 
            print_library(library);
           //we're gonna have to change these things to the fgets thing
        }
        else if(strcmp(argv[1], "shuffle" ) == 0){
            printf("how many songs do you want to shuffle: ");
            char buff[256];
            char * data = fgets(buff, 100, stdin);
    
            int shuffleint; 
            sscanf(data, "%d", &shuffleint);
            //change 5 to the length of the library
           shuffle(library, shuffleint);
        }
        else if(strcmp(argv[1], "remove" ) == 0){
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
        else if(strcmp(argv[1], "search" ) == 0){
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
    else {
         printf("found {%s, %s}\n", searching->artist, searching->name);
    }
   
        }
        else if(strcmp(argv[1], "menu" ) == 0){
            print_menu();
            //SOMEONE GOTTA MAKE THIS FUNCTION: just like a list of all the functions a user can do lol
        }
        else{
            printf("not a valid flag");
        }
    }
//testing:
    // printf("Testing print_list:\n");
    // print_list(front);
    // printf("====================================\n");
    // printf("Testing find_song on {artistA, h}:\n");
    
    // if(find_song(front, "artistA", "h")) {
    //     printf("node found! {%s, %s}\n", find_song(front, "artistA", "h")->artist, find_song(front, "artistA", "h")->name);
    // }
    // else {
    //     printf("node not found\n");
    // }

    // printf("====================================\n");
    // printf("Testing random\n");
    // struct song_node* random_test = random_song(front);
    // printf("{%s, %s}\n", random_test->artist, random_test->name);
    
    // printf("====================================\n");
    // printf("Testing find_first_song on artistA\n");
    // printf("{%s, %s}\n", find_first_song(front, "artistA")->artist, find_first_song(front, "artistA")->name);
    // printf("Testing find_first_song on artistB\n");
    // printf("{%s, %s}\n", find_first_song(front, "artistB")->artist, find_first_song(front, "artistB")->name);

    // printf("====================================\n");
    
    // printf("Testing remove with {artistA, d}\n");
    // front = remove_song(front, "artistA", "d");
    // print_list(front);

    // printf("Testing remove with {artistA, g}\n");
    // front = remove_song(front, "artistA", "g");
    // print_list(front);
    
    // printf("Testing remove with {artistB, t}\n");
    // front = remove_song(front, "artistB", "t");
    // print_list(front);
    
    // printf("Testing remove with {artistG, k}\n");
    // front = remove_song(front, "artistG", "k");
    // print_list(front);

    // printf("====================================\n"); 
    // printf("Freeing list\n");
    // front = free_list(front);
    // print_list(front);


//USE THIS
    // printf("\n");
    // printf("MUSIC LIBRARY TESTS\n====================================\n");

    // struct song_node** library = make_library();
    
    // printf("Testing print_letter on empty library\n");
    // print_letter(library, 'a');

    // printf("====================================\n");
    // printf("Testing print_library on empty library\n");
    // print_library(library);
    
    // printf("====================================\n");
    // printf("Testing add_song\n");

    // add_song(library, "aphex twin", "xtal"); 
    // add_song(library, "aphex twin", "ageispolis");
    // add_song(library, "arctic monkeys", "i wanna be yours");
    // add_song(library, "black sabbath", "sabbath bloody sabbath");
    // add_song(library, "black sabbath", "orchid");
    // add_song(library, "bob dylan", "visions of johanna");
    // add_song(library, "zeph", "cylmwihm");
    // add_song(library, "zeph", "world");
    // add_song(library, "2pac", "california love");
    // add_song(library, "6ix9ine", "fefe");

    // printf("====================================\n");
    // printf("Testing print_letter with stuff added now\n");
    // print_letter(library, 'a');
    // printf("====================================\n");
    // printf("Testing print_library with stuff added now\n");
    // print_library(library);

    // printf("====================================\n");
    // printf("Testing search_song on {black sabbath: orchid}\n");
    // struct song_node* song = search_song(library, "black sabbath", "orchid");
    // printf("found {%s, %s}\n", song->artist, song->name);

    // printf("Testing search_song on {taylor swift: style}\n");
    // song = search_song(library, "taylor swift", "style");
    // if (song == NULL) {
    //     printf("Song not found, meaning search_song worked correctly\n");
    // }
    // else {
    //     printf("search_song didn't work correctly\n");
    // }

    // printf("====================================\n");
    // printf("Testing search_artist on aphex twin\n");
    // song = search_artist(library, "aphex twin");
    // printf("found {%s, %s}\n", song->artist, song->name);

    // printf("Testing search_artist on abba\n");
    // song = search_artist(library, "abba");
    // if (song == NULL) {
    //     printf("Artist not found, meaning search_artist worked correctly\n");
    // }
    // else {
    //     printf("search_artist didn't work correctly\n");
    // }

    // printf("====================================\n");
    // printf("Testing print_artist on aphex twin\n");
    // print_artist(library, "aphex twin");
    
    // printf("Testing print_artist on taylor swift\n");
    // print_artist(library, "taylor swift");
    
    // printf("====================================\n");
    // printf("Testing shuffle with n=5\n");
    // shuffle(library, 5);

    // printf("====================================\n");
    // printf("Testing remove_song_lib on {aphex twin, ageispolis}\n");
    // remove_song_lib(library, "aphex twin", "ageispolis");
    // print_library(library);

    // printf("Testing remove_song_lib on {black sabbath, sabbath bloody sabbath}\n");
    // remove_song_lib(library, "black sabbath", "sabbath bloody sabbath");
    // print_library(library);

    // printf("Testing remove_song_lib on {6ix9ine, fefe}\n");
    // remove_song_lib(library, "6ix9ine", "fefe");
    // print_library(library);

    // printf("====================================\n");
    // printf("Testing clear_library\n");
    // clear_library(library);
    // print_library(library);

    // printf("====================================\n");
    // printf("Adding songs to empty library\n");
    // add_song(library, "ac/dc", "thunderstruck");
    // add_song(library, "led zeppelin", "kashmir");
    // print_library(library);

    // printf("====================================\n");
    // printf("Testing print_artist on black sabbath\n");
    // print_artist(library, "black sabbath");
    
    // clear_library(library);
}
