#include "bass24-osx/bass.h"
#include<unistd.h>
#include <stdio.h>

// make a basic thing to get a filename (song name?) from user
// send that over to Bass
// 1st step: play one thing
// 2nd step: loop
// also update readme to say u need to download bass

void startMusic () {
HMUSIC hm;
	BASS_Init (-1, 44100, 0, 0, NULL);
	hm=BASS_MusicLoad(FALSE,"music.mp3",0,0,BASS_SAMPLE_LOOP,0);
	BASS_ChannelPlay(hm,FALSE);
}

void endMusic() {
	BASS_Stop();
	BASS_Free();
}

int main(){
  printf("well i sure hope this works!\n");
  startMusic();
  sleep(100);
  endMusic();
}
