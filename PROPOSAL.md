# Final Project Proposal

## Group Members:

Eva Skarabot, Jo Walkup, Katharine Moncrieffe
# Intentions:

A statement of the problem you are solving and/or a high level description of the project.
Music player/playlist manager with file search functionality

# Intended usage:

A description as to how the project will be used (describe the user interface).
The user interface will be on the command line. Playlists will be in different colors from the songs, and the user will type in commands to control their playlist and the song currently playing.

Furthermore, we will have it act like a shared playlist, so multiple clients can access it.

User commands include:
- add/rmv: Add and remove songs
- play/pause/skip: Play songs (using a music player)
- shuffle: Shuffle
- view: See the entire playlist
- search ___: Search for songs within the playlist by
-   song title
-   artist
-   first letters of either title or artist (if the user inputs the first few letters and presses enter, program will print out a list of songs or artists starting with those letters)
- menu: for a list of user commands


# Technical Details:

A description of your technical design. This should include:

How you will be using the topics covered in class in the project.

How you are breaking down the project and who is responsible for which parts.

Topics used include: allocating memory, working with and finding information about files, managing processes and signals, fork and exec to incorporate a music player, semaphores to make sure only one person is editing the playlist at one time, sockets/pipes so that multiple people can use the playlist

Eva:
- Semaphores and the network part
- user interface

Jo:
- playing actual music files
- finding info about files
- managing signals

Katharine: 
 - being able to manage music files
 - searching for files 

What data structures you will be using and how.
Algorithms/Data Structures used: Linked lists, nodes, sorting and searching
What algorithms and /or data structures you will be using, and how.

# Intended pacing:

A timeline with expected completion dates of parts of the project.

Jan 4-5: Bring back the old project and make it so the user can input things, also input the user interface
Jan 6-8: Make the semaphore and network thing so that it can be used as a shared playlist across
Jan 9-12: 
Jan 13-15: Lots of debugging
Jan 15: we will practice our presentation

