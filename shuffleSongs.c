#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "shuffleSongs.h"

//function definition. It shuffles the songsToBeShuffled and prints out the shuffled playlist
void shuffleSongs(char songsToBeShuffled[][80], int *totalSongs)
{
  srand(time(NULL)); //initialisation of random number generator

  int i, j; //stating variables to control the for loops
  char swap[80]; //array for swaping

  //for loop to implement the shuffling algorithm - fisher yates
  for (i = 1; i < *totalSongs*2; i++)
  {
    j = rand()%(i+1); //select a random integer between 0 and i

    //as long as j not = to i, swap string in row j with the one in row i
    if (j != i)
    {
      strcpy(swap, songsToBeShuffled[j]);
      strcpy(songsToBeShuffled[j], songsToBeShuffled[i]);
      strcpy(songsToBeShuffled[i], swap);
    }
  }

  //if the total songs <= 5, ignore the rule that same songs can only appear again after 5 different songs
  if (*totalSongs <= 5)
  {
    //for loop to print out the songs shuffled (less or equal than 5 songs)
    for (i = 0; i < *totalSongs*2; i++)
    {
      printf("%s\n", songsToBeShuffled[i]);
    }
  }
  //if total songs > 5, make sure a song can only appear again after at least 5 different songs
  else
  {
    goback: //point to return to
    i = 0; //initialize i to 0
    //while loop to compare each song with the following 5 songs to check if they are the same
    while (i < (*totalSongs*2))
    {
      for (j = i+1; j < i+6; j++)
      {
        //if there are same songs in within the limit of 5 swap song i with song i+6
        if (strcmp(songsToBeShuffled[i], songsToBeShuffled[j]) == 0 && i != (*totalSongs*2)-6)
        {
          strcpy(swap, songsToBeShuffled[j]);
          strcpy(songsToBeShuffled[j], songsToBeShuffled[i+6]);
          strcpy(songsToBeShuffled[i+6], swap);
        }
        //if there are same songs and i+6 is over the size of the array, swap with the 1st element of the array
        if (strcmp(songsToBeShuffled[i], songsToBeShuffled[j]) == 0 && i<(*totalSongs*2) && i>(*totalSongs*2)-6)
        {
          strcpy(swap, songsToBeShuffled[j]);
          strcpy(songsToBeShuffled[j], songsToBeShuffled[0]);
          strcpy(songsToBeShuffled[0], swap);
        }
      }
      i++;
    }
    //check for a second time if there are equal songs in within the 5 songs limit
    //second check is because the songs that might have been swapped with the first element of the array
    while (i < (*totalSongs*2))
    {
      for (j = i+1; j < i+6; j++)
      {
        //if there equal songs in within the limit, go back and repeat the process
        if (strcmp(songsToBeShuffled[i], songsToBeShuffled[j]) == 0)
        {
          goto goback; //return to goback statement
        }
      }
      i++;
    }

    //for loop to print out the shuffled array
    for (int i = 0; i < *totalSongs*2; i++)
    {
      printf("%s\n", songsToBeShuffled[i]);
    }
  }
}
