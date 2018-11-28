#include <stdio.h>
#include <string.h>

#include "insertArtistsAndSongs.h"
//function definition. Reads in a maximum of three songs entered by the user
int insertSongs(char songs[][80], char artistNames[])
{
  int i;
  //for loop to read in the 3 songs
  for (i = 0; i < 3; i++)
  {
    //prompt message asking user to enter songs
    START: printf("Insert song %d for %s:\n", i+1, artistNames);
    fgets(songs[i], 80, stdin); //reads line from standar input

    //if statement to ensure that at least 1 song is entered
    if (songs[0][0] == '\n')
    {
      //if song 1 not entered display warning message and go back to 'START'
      printf("INSERT AT LEAST ONE SONG!!!\n");
      goto START;//go back to asking for song number 1
    }

    //if the return command is pressed by user for following songs, exit
    if (i != 0 && songs[i][0] == '\n')
     break;

    //remove '\n' and replace with '\0' from end of the string
    songs[i][strlen(songs[i])-1] = '\0';
  }
  return i; //return the number of songs entered
}
//function definition. Reads in artists entered by the user and calls insertSongs function to read songs for each artist
int insertArtistsAndSongs(char artistNames[][80], char songsArtist1[][80], char songsArtist2[][80], char songsArtist3[][80], char songsArtist4[][80], int numSongsPerArtist[4])
{
  int i;
  //for loop to read in artists + songs for each artist calling insertSongs function
  for (i = 0; i < 4; i++)
  {
    //prompt message asking user to enter artist/group name
    START: printf("\nInsert an artist/group name:\n");
    fgets(artistNames[i], 80, stdin);

    //if statement to ensure that at least 1 artist is entered
    if (artistNames[0][0] == '\n')
    {
      //if no artist entered the first time, display warning message and go back to 'START'
      printf("INSERT AT LEAST ONE ARTIST!!!\n");
      goto START;//go back to asking for the first artist
    }

    //if the return command is pressed by user, exit
    if (i != 0 && artistNames[i][0] == '\n')
      break;

    //remove '\n' and replace with '\0' from end of the string
    artistNames[i][strlen(artistNames[i])-1] = '\0';

    //for artist 1 store songs in songsArtist1 array
    if (i == 0){
      //number of songs from artist1 = element 0 in numSongsPerArtist array
      numSongsPerArtist[i] = insertSongs(songsArtist1, artistNames[i]);
    }
    //for artist 2 store songs in songsArtist2 array
    else if (i == 1){
      //number of songs from artist2 = element 1 in numSongsPerArtist array
      numSongsPerArtist[i] = insertSongs(songsArtist2, artistNames[i]);
    }
    //for artist 3 store songs in songsArtist3 array
    else if (i == 2){
      //number of songs from artist3 = element 2 in numSongsPerArtist array
      numSongsPerArtist[i] = insertSongs(songsArtist3, artistNames[i]);
    }
    //for artist 4 store songs in songsArtist4 array
    else if (i == 3){
      //number of songs from artist4 = element 3 in numSongsPerArtist array
      numSongsPerArtist[i] = insertSongs(songsArtist4, artistNames[i]);
    }
  }
  return i; //return number of artists entered
}
