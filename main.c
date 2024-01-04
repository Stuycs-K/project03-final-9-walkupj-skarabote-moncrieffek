#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>
#include "linkedlist.h"
#include "library.h"


int main(int argc, char* argv[]){
    srand( time(NULL) );

    printf("LINKED LIST TESTS\n====================================\n");

    struct song_node* front = memory("artistB", "t");
    front = insert_in_order(front, "artistA", "h");
    front = insert_in_order(front, "artistA", "f");
    front = insert_in_order(front, "artistA", "d");
    front = insert_in_order(front, "artistA", "g");

    printf("Testing print_list:\n");
    print_list(front);
    printf("====================================\n");
    printf("Testing find_song on {artistA, h}:\n");
    
    if(find_song(front, "artistA", "h")) {
        printf("node found! {%s, %s}\n", find_song(front, "artistA", "h")->artist, find_song(front, "artistA", "h")->name);
    }
    else {
        printf("node not found\n");
    }

    printf("====================================\n");
    printf("Testing random\n");
    struct song_node* random_test = random_song(front);
    printf("{%s, %s}\n", random_test->artist, random_test->name);
    
    printf("====================================\n");
    printf("Testing find_first_song on artistA\n");
    printf("{%s, %s}\n", find_first_song(front, "artistA")->artist, find_first_song(front, "artistA")->name);
    printf("Testing find_first_song on artistB\n");
    printf("{%s, %s}\n", find_first_song(front, "artistB")->artist, find_first_song(front, "artistB")->name);

    printf("====================================\n");
    
    printf("Testing remove with {artistA, d}\n");
    front = remove_song(front, "artistA", "d");
    print_list(front);

    printf("Testing remove with {artistA, g}\n");
    front = remove_song(front, "artistA", "g");
    print_list(front);
    
    printf("Testing remove with {artistB, t}\n");
    front = remove_song(front, "artistB", "t");
    print_list(front);
    
    printf("Testing remove with {artistG, k}\n");
    front = remove_song(front, "artistG", "k");
    print_list(front);

    printf("====================================\n"); 
    printf("Freeing list\n");
    front = free_list(front);
    print_list(front);



    printf("\n");
    printf("MUSIC LIBRARY TESTS\n====================================\n");

    struct song_node** library = make_library();
    
    printf("Testing print_letter on empty library\n");
    print_letter(library, 'a');

    printf("====================================\n");
    printf("Testing print_library on empty library\n");
    print_library(library);
    
    printf("====================================\n");
    printf("Testing add_song\n");

    add_song(library, "aphex twin", "xtal"); 
    add_song(library, "aphex twin", "ageispolis");
    add_song(library, "arctic monkeys", "i wanna be yours");
    add_song(library, "black sabbath", "sabbath bloody sabbath");
    add_song(library, "black sabbath", "orchid");
    add_song(library, "bob dylan", "visions of johanna");
    add_song(library, "zeph", "cylmwihm");
    add_song(library, "zeph", "world");
    add_song(library, "2pac", "california love");
    add_song(library, "6ix9ine", "fefe");

    printf("====================================\n");
    printf("Testing print_letter with stuff added now\n");
    print_letter(library, 'a');
    printf("====================================\n");
    printf("Testing print_library with stuff added now\n");
    print_library(library);

    printf("====================================\n");
    printf("Testing search_song on {black sabbath: orchid}\n");
    struct song_node* song = search_song(library, "black sabbath", "orchid");
    printf("found {%s, %s}\n", song->artist, song->name);

    printf("Testing search_song on {taylor swift: style}\n");
    song = search_song(library, "taylor swift", "style");
    if (song == NULL) {
        printf("Song not found, meaning search_song worked correctly\n");
    }
    else {
        printf("search_song didn't work correctly\n");
    }

    printf("====================================\n");
    printf("Testing search_artist on aphex twin\n");
    song = search_artist(library, "aphex twin");
    printf("found {%s, %s}\n", song->artist, song->name);

    printf("Testing search_artist on abba\n");
    song = search_artist(library, "abba");
    if (song == NULL) {
        printf("Artist not found, meaning search_artist worked correctly\n");
    }
    else {
        printf("search_artist didn't work correctly\n");
    }

    printf("====================================\n");
    printf("Testing print_artist on aphex twin\n");
    print_artist(library, "aphex twin");
    
    printf("Testing print_artist on taylor swift\n");
    print_artist(library, "taylor swift");
    
    printf("====================================\n");
    printf("Testing shuffle with n=5\n");
    shuffle(library, 5);

    printf("====================================\n");
    printf("Testing remove_song_lib on {aphex twin, ageispolis}\n");
    remove_song_lib(library, "aphex twin", "ageispolis");
    print_library(library);

    printf("Testing remove_song_lib on {black sabbath, sabbath bloody sabbath}\n");
    remove_song_lib(library, "black sabbath", "sabbath bloody sabbath");
    print_library(library);

    printf("Testing remove_song_lib on {6ix9ine, fefe}\n");
    remove_song_lib(library, "6ix9ine", "fefe");
    print_library(library);

    printf("====================================\n");
    printf("Testing clear_library\n");
    clear_library(library);
    print_library(library);

    printf("====================================\n");
    printf("Adding songs to empty library\n");
    add_song(library, "ac/dc", "thunderstruck");
    add_song(library, "led zeppelin", "kashmir");
    print_library(library);

    printf("====================================\n");
    printf("Testing print_artist on black sabbath\n");
    print_artist(library, "black sabbath");
    
    clear_library(library);
}
