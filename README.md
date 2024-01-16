[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/SQs7pKlr)
# Stuyify

### JoKE
Jo Walkup, Katharine Moncrieffe, Eva Skarabot

### Project Description:
music playlist manager and player

### Instructions:
if ffmpeg isn't installed, install it

then use make compile and make run



type "menu" first to get a list of commands you can use
users can type commands (add, remove, play, etc) to control the playlists and play music
they can also type commands such as 
- shuffle which will generate a random order of however many songs they want
- search which will help you determine what song you are looking for (if you ever want to end the loop however, you will need to type break for both questions)

### Bugs:
- when you play the whole playlist, the child process sleeps for the length of the longest song (manually inputted), so sometimes there's a gap between when the last song finished and the next song begins
- you can add songs that don't have mp3 files (only two mp3 files are rain.mp3 and flyday.mp3), but if you want to play the entire playlist, enter clear first (to only play songs with mp3 files)
- also only songs with one-word titles can be played
