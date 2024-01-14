#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedlist.h"

// 1. insert nodes at the front (this is just for testing) EVA
// 2. insert nodes in order (this is the primary way to insert for later) 
// 3. alphabetical by Artist then by Song
//  you should have a helper function to compare song nodes effectively.
//  print the entire list
// 4. find and return a pointer to a node based on artist and song name  EVA
// 5. find and return a pointer to the first song of an artist based on artist name
// 6. Return a pointer to random element in the list.
// 7. remove a single specified node from the list  EVA
//  specified by both artist and song name.
// 8. free the entire list

//make new nodes
struct song_node *memory(char* artist, char* name, char* mp3){
    struct song_node *p;
    p = calloc(1, sizeof(struct song_node) ); 
    strcpy(p->name, name);
    strcpy(p->artist, artist);
    strcpy(p->mp3, mp3);
    return p;
}


//1.
struct song_node * insert_front(struct song_node * list, char* artist, char* name, char* mp3){
    //different lists for each letter
    struct song_node *new_song;
    new_song = memory(artist, name, mp3);
    new_song->next = list;
    return new_song;
}

//2. 
//for ascii alphabetization MAKE EVERYTHING THE SAME CASE and don't put in accents as first letter
int song_cmp(struct song_node* song1, struct song_node* song2) {
    if (strcmp(song1->artist, song2->artist) != 0) {
        return strcmp(song1->artist, song2->artist);
    }
    else {
        return strcmp(song1->name, song2->name);
    }
}

struct song_node* insert_in_order(struct song_node* front, char* artist, char* name, char* mp3) {
    struct song_node* new_song = memory(artist, name, mp3);
    if (front == NULL || song_cmp(new_song, front) < 0) {
        new_song->next = front;
        return new_song;
    }
    struct song_node* current = front;
    while (current->next != NULL) {
        if (song_cmp(new_song, current->next) > 0) {
            current = current->next;
        }
        else {
            struct song_node* new_next = current->next;
            current->next = new_song;
            new_song->next = new_next;
            return front;
        }
    }
    current->next = new_song;
    new_song->next = NULL;
    return front;
}

//3.
void print_list(struct song_node* front) {
    printf("[ ");
    while (front != NULL) {
        printf("{%s, %s} | ", front->artist, front->name);
        front = front->next;
    }
    printf("]\n");
}

//4. 
//find and return a pointer to a node based on artist and song name
struct song_node* find_song(struct song_node* front, char* artist, char* name) {
    while (front != NULL) {
        if (strcmp(front->artist, artist) == 0) {
            if (strcmp(front->name, name) == 0) {
                return front;
               // printf("node found! {%s, %s}\n", name, artist);
                //printf("node found!\n");
            }
        }
        front = front->next;
    }
    //printf("node not found\n");
    return NULL;
}

//5.
struct song_node* find_first_song(struct song_node* front, char* artist) {
    while (front != NULL) {
        if (strcmp(front->artist, artist) == 0) {
            return front;
        }
        front = front->next;
    }
    return NULL;
}

//6. Return a pointer to random element in the list.
int list_length(struct song_node* front){
    int counter = 1;
    while (front->next){
        counter++;
        front = front->next;
    }
    return counter;
}
struct song_node* random_song(struct song_node* front){
    int len = list_length(front);
    int index = abs(rand())%len;
    for(int i=0; i<index; i++){
        front = front->next;
    }
    return front;
}


//7.
struct song_node* remove_song(struct song_node* front, char* artist, char* name){
    struct song_node *slower = front;
    struct song_node *faster = slower->next;

    struct song_node *current = front;
    struct song_node *temp = front;

    //THIS SHOWS THAT THE SONG EXISTS
    if(find_song(front, artist, name)){
        //if you are removing the first song
        if (strcmp(current->artist, artist) == 0) {
        if (strcmp(current->name, name) == 0) {
            current = current->next;
            free(temp);
            return current;
        }
        }

        


        //THIS IS FOR THE MIDDLE ONES
        while(faster->next){
            if (strcmp(faster->artist, artist) == 0) {
            if (strcmp(faster->name, name) == 0) {
                slower->next = slower->next->next;
                 free(faster);
                 return front;
            }
            }
            slower = slower->next;
            faster = faster->next;
         
        }
       //if you are removing the last song
        if (strcmp(faster->artist, artist) == 0) {
            if (strcmp(faster->name, name) == 0) {
                slower->next = NULL;
                 free(faster);
                 return front;
            }
            }
        //("hello");

        
    }
    //not found
    return front;
}

//8.
struct song_node* free_list(struct song_node* front) {
  while (front != NULL) {
    struct song_node* next = front->next;
    free(front);
    front = next;
  }
  return front;
}
