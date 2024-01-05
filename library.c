#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "linkedlist.h"

// EVA initialize a new library: Allocate enough memory for 27 linked lists, make sure each entry is an empty list.
// AAREEB Add song nodes
// EVA Search for a song given song and artist name (return a pointer).
// AAREEB Search for an artist (return a pointer).
// EVA Print out all the entries under a certain letter.
// AAREEB Print out all the songs of a certain artist
// EVA Print out the entire library.
// AAREEB Shuffle - print out a series of n randomly chosen songs. (can have duplicates)
// EVA Delete a song from the library ()
//  specified by both artist and song name.
// AAREEB Clear out all the linked lists in the library.

//1.
struct song_node ** make_library(){
    struct song_node ** library_array;
    library_array = calloc(27, sizeof(struct song_node*));
    return library_array;
}

//2.
void add_song(struct song_node** lib, char* artist, char* name) {
    int index;
    if (*artist >= 97 && *artist <= 122) {
        index = *artist - 97;
    }
    else {
        index = 26;
    }
    lib[index] = insert_in_order(lib[index], artist, name);
}

//3.
struct song_node * search_song(struct song_node ** lib, char* artist, char* name){
   //
    struct song_node* front;
    if (*artist >= 97 && *artist <= 122) {
        front = lib[*artist - 97];
    }
    else {
        front = lib[26];
    }
    return find_song(front, artist, name);
}

//4.
struct song_node* search_artist(struct song_node** lib, char* artist) {
    struct song_node* front;
    if (*artist >= 97 && *artist <= 122) {
        front = lib[*artist - 97];
    }
    else {
        front = lib[26];
    }
    return find_first_song(front, artist);
}



//5.
void print_letter(struct song_node** lib, char letter){
    //printf("[ ");
    if(letter >= 97 && letter <= 122){
        print_list(lib[letter-97]);
    }
    else{
        print_list(lib[26]);
    }
    //printf("]\n");
}


//6.
void print_artist(struct song_node** lib, char* artist) {
    struct song_node* front = search_artist(lib, artist);
    printf("[ ");
    while (front != NULL && strcmp(front->artist, artist) == 0) {
        printf("{%s, %s} | ", front->artist, front->name);
        front = front->next;
    }
    printf("]\n");
}

//7.
//Print out the entire library.
void print_library(struct song_node** lib){
    int letter = 97;
    for(int i=0; i<26; i++){
        struct song_node* letter_list = lib[letter];
        if(lib[i]){
            printf("%c: ", i+97);
            print_letter(lib, i+97);
        }
        letter++;
    }
    if(lib[26]){
        printf("special characters: ");
        print_letter(lib, 123);
    }
}

//8.
void shuffle(struct song_node** lib, int n) {
    struct song_node* front = NULL;
    for (int i = 0; i < n; i++) {
        int index = abs(rand()) % 27;
        while (lib[index] == NULL) {
            index = abs(rand()) % 27;
        }
        struct song_node* randsong = random_song(lib[index]);
        front = insert_front(front, randsong->artist, randsong->name);
    }
    print_list(front);
    free_list(front);
}

//9.//delete
//use the search for song function
//use delete node function WHICH given the first letter will delete the song


void remove_song_lib(struct song_node** lib, char* artist, char* name){
    int index;
    if (*artist >= 97 && *artist <= 122) {
        index = *artist - 97;
    }
    else {
        index = 26;
    }
    lib[index] = remove_song(lib[index], artist, name);
}


    // struct song_node *current = front;
    // struct song_node *temp = front;

    // //THIS SHOWS THAT THE SONG EXISTS
    // if(find_song(front, artist, name)){
    //     //if you are removing the first song
    //     if (strcmp(current->artist, artist) == 0) {
    //     if (strcmp(current->name, name) == 0) {
    //         current = current->next;
    //         free(temp);
    //         return current;
    //     }
    //     }


//10.
void clear_library(struct song_node** lib) {
    for (int i = 0; i < 27; i++) {
        lib[i] = free_list(lib[i]);
    }
}

void print_node(struct node *s){ 
  if(s != NULL) printf("%s by %s\n", s->song, s->artist);
}

void search_artist(struct node *front, char *artist){
    struct node *current = front;
    while(current){
        if(strcmp(current->artist, artist) == 0){
            print_node(current);
        }
        current = current->next;
    }
    return NULL;

//11. extra !!
void print_menu(){
    printf("here are a list of commands you can use in this music player!\n");
    printf("add/rmv: Add and remove songs\n");
    printf("play/pause/skip: Play songs (using a music player)\n");
    printf("shuffle: Shuffle\n");
    printf("view: See the entire playlist\n");
    printf("search ___: Search for songs within the playlist by the song title and artist, or first letters\n");
    printf("menu: Print a list of user commands\n");
}
}
