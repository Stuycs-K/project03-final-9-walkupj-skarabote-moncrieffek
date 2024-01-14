#ifndef LIBRARY_H
#define LIBRARY_H
struct song_node** make_library();
void add_song(struct song_node** lib, char* artist, char* name, char* mp3);
struct song_node* search_song(struct song_node** lib, char* artist, char* name);
struct song_node* search_artist(struct song_node** lib, char* artist);
void print_letter(struct song_node** lib, char letter);
void print_artist(struct song_node** lib, char* artist);
void print_library(struct song_node** lib);
void shuffle(struct song_node** lib, int n);
struct song_node** remove_song_lib(struct song_node** lib, char* artist, char* name);
void clear_library(struct song_node** lib);
void print_menu();
#endif
