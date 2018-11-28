#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "insertArtistsAndSongs.h" //contains function for reading in artists and songs
#include "shuffleSongs.h" //contains function for shuffling songs and printing shuffled songs
#include "sortAndPrintList.h" //contains function for sorting arrays alphabetically and printing out sorted list

// #include "functions.h"
#define MaxArtists 4 //defining maximum number of artists to 4
#define MaxSongs 3 //defining maximum number of songs 3

int main(void)//main function
{
  char artistNames[MaxArtists][80];//array containing artists artists names
  char sortedArtistsNames[MaxArtists][80];//array containing artists in alphabetically order
  char songsArtist1[MaxSongs][80];//array for Artist 1 songs
  char songsArtist2[MaxSongs][80];//array for Artist 2 songs
  char songsArtist3[MaxSongs][80];//array for Artist 3 songs
  char songsArtist4[MaxSongs][80];//array for Artist 4 songs

  int numOfArtists;//total number of artists entered by user
  int numSongsPerArtist[MaxArtists];//total number of songs per artist entered by the user
  int totalSongs = 0; //total number of songs between all artists

  printf("\nWelcome to the iPod Music Player.\n");
  printf("To indicate you don't want to enter more artists/songs press 'Enter'.\n");

  //calling function that reads songs + artits and keeps count of numOfArtists & numSongsPerArtist
  numOfArtists = insertArtistsAndSongs(artistNames, songsArtist1, songsArtist2, songsArtist3, songsArtist4, numSongsPerArtist);

  //copy entire artistNames array into sortedArtistsNames to be sorted in the following function
  memcpy(sortedArtistsNames, artistNames, sizeof(artistNames));

  //calling function that sorts the artists alphabetically
  sort(sortedArtistsNames, &numOfArtists);

  //calling function to sort from each artist alphabetically
  sort(songsArtist1, &numSongsPerArtist[0]);//sort songs of artist 1
  sort(songsArtist2, &numSongsPerArtist[1]);//sort songs of artist 2
  sort(songsArtist3, &numSongsPerArtist[2]);//sort songs of artist 3
  sort(songsArtist4, &numSongsPerArtist[3]);//sort songs of artist 4

  //print out the sorted list of Artists + Songs
  printf("\nSorted list of Songs: \n");
  //calling function to print out the sorted list of Artists + Songs
  printSortedList(&numOfArtists, numSongsPerArtist, artistNames, sortedArtistsNames, songsArtist1, songsArtist2, songsArtist3, songsArtist4);

  //for loop to calculate the total number of songs entered by user
  for (int i = 0; i < MaxArtists; i++)
  {
    totalSongs += numSongsPerArtist[i];
  }

  char songsToBeShuffled[totalSongs*2][80]; //array to contain all the songs times 2

  int i = 0; //declaring identifier to use in the while loop
  //while loop to insert all songs times 2 into songsToBeShuffled array
  //The songs will be entered to this new array in the form of: "artistName - songName"
  while (i < totalSongs*2)
  {
    int j;
    //introducing songs of artist 1 in the form specified
    for (j = 0; j < numSongsPerArtist[0]; j++)
    {
      strcpy(songsToBeShuffled[i], artistNames[0]);
      strcat(songsToBeShuffled[i], " - ");
      strcat(songsToBeShuffled[i], songsArtist1[j]);
      i++;
    }
    //introducing songs of artist 2 in the form specified
    for (j = 0; j < numSongsPerArtist[1]; j++)
    {
      strcpy(songsToBeShuffled[i], artistNames[1]);
      strcat(songsToBeShuffled[i], " - ");
      strcat(songsToBeShuffled[i], songsArtist2[j]);
      i++;
    }
    //introducing songs of artist 3 in the form specified
    for (j = 0; j < numSongsPerArtist[2]; j++)
    {
      strcpy(songsToBeShuffled[i], artistNames[2]);
      strcat(songsToBeShuffled[i], " - ");
      strcat(songsToBeShuffled[i], songsArtist3[j]);
      i++;
    }
    //introducing songs of artist 4 in the form specified
    for (j = 0; j < numSongsPerArtist[3]; j++)
    {
      strcpy(songsToBeShuffled[i], artistNames[3]);
      strcat(songsToBeShuffled[i], " - ");
      strcat(songsToBeShuffled[i], songsArtist4[j]);
      i++;
    }
  }

  //print out the shuffled playlist. Whith each song appearing twice and separate it by at least 5 songs
  printf("Shuffled Playlist:\n");
  //calling function that shuffles the songsToBeShuffled and displays them on the screen
  shuffleSongs(songsToBeShuffled, &totalSongs);
  printf("\n");

  return 0;
}
