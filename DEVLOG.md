# Dev Log:

## Katharine Moncrieffe

### 2024-01-03 - added to proposal
worked on brainstorming ideas, writing proposal with jo and eva

### 2024-01-04, 05, weekend - began work
finalized idea + plans in class with eva, started work on my tasks
-> added a basic search function

### 2024-01-08, 09 - worked on music
found new libraries to play music after realizing bass wasn't working
tested new libraries, will finalize and begin to implement soon
-> continued searching for solution to undefined reference error we ran into in class, no progress so far

### 2024-01-10 - edited nodes, found more mp3s for demo
working with mpg123, editing node fields to include an mp3 to allow easier playback of music files
-> found more mp3s for nodes at home

### 2024-01-11 - readme and checking work
edited readme, removed compilation errors and checked that all functions, function headers, structs etc were consistent

### 2024-01-12, weekend - checking work, added loop
edited previous functions, main to make sure everything worked well with each other. added looping

## Jo Walkup

### 2024-01-04 - Added to proposal
Added the technical details section, what parts I would be responsible for, and the intentions section. 10 min

### 2024-01-04 - Added file work from previous lab
Added the code to go through all files and extract their information

### 2024-01-04 - Modified the file stuff
Condensed the code into a single function to be used, ~10 min

### 2024-01-05 - Bass basics
Added music file, downloaded Bass, made plan

### 2024-01-07 - Bass struggling
Wrote some basic Bass code, tried to compile, major errors. Tried to understand the library & how to use. ~2 hrs

### 2024-01-08 - More Bass struggling
Desperately trying to compile, but always getting an "undefined symbols" error. Will ask K tmrw. ~40 minutes
Also merged :D

### 2024-01-10 - No more Bass + mpg123 started
Deleted Bass because it sucked, starting writing functions for play and such using mpg123

### 2024-01-11 - Finished play function
Wrote the play function- user inputs song title (one word + .mp3), and it forks & execs

### 2024-01-12 - Play fine-tuning
Play works in current directory, only needs to input title (no .mp3), also will work on pause (?)

### 2024-01-13 - Looping play
Able to play the entire playlist

## Eva Skarabot

### 2024-01-03 - start proposal
Wrote what parts I would be responsible for, finished the intended usage section, included all the features

### 2024-01-04 - put in old music project
Copied and pasted in our old working music library project; 5 mins

### 2024-01-04 - commands
Updated the if statements for the commands we would use this program, wrote in comments so that we could fill in for the functions later; 20 mins

### 2024-01-05 - menu
Created the menu function and tested it so that make run ARGS=menu works as intended; 10 mins

### 2024-01-07 - add, shuffle
Updated code so that the ARGS=add and shuffle works, also uses user input now; remove is still broken

### 2024-01-07 - search
Updated code so that the ARGS=search works, also uses user input now; remove is still broken

### 2024-01-08 - looping
Made it a looping program that commands could be put in

### 2024-01-09 - shared memory
Included some shared memory and would access it in the "add" command

### 2024-01-09 - exit
added an exit command so the user doesn't have to command c every time

### 2024-01-10 - 2021-01-12 - semaphores
implementing shared memory and semaphores so that the list would save in a file

### 2024-01-11 - 2024-01-12 - networking, but ended up not in final project
Tried implementing sockets and a networking system, was recieving bugs so did not end up follwoing through

### 2024-01-12 - sharing songs part 1
Finished managing to share the memory between "make run"s, but only if you added it in the run before

### 2024-01-14 - finished sharing songs
Finished making the songs you add carry over forever

### 2024-01-15 - signals and merging
Finished merging and fixing merge conflicts, preparing for the presentation, adding in signal that still saves the songs you added even if you SIGQUIT