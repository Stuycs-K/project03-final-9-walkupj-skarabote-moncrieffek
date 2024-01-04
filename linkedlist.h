#ifndef LINKEDLIST_H
#define LINKEDLIST_H
struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node *memory(char* artist, char* name);
struct song_node * insert_front(struct song_node * list, char* artist, char* name);
struct song_node* insert_in_order(struct song_node* front, char* artist, char* name);
void print_list(struct song_node* front);
struct song_node* find_song(struct song_node* front, char* artist, char* name);
struct song_node* find_first_song(struct song_node* front, char* artist);
struct song_node* remove_song(struct song_node* front, char* artist, char* name);
struct song_node* random_song(struct song_node* front);
struct song_node* free_list(struct song_node* front);
#endif
