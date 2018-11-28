#include <string.h>
#include <stdio.h>
#include "sortAndPrintList.h"

//Function definition. It sorts the array received alphabetically.
//Algorithm used: Quick Sort Algorithm
void sort(char listToSort[][80] , int *length)
{
  //variable declarations
  int i =0;
  int j=0;
  int minIndex = 0;
  int minIndexChanged = 0;
  char swap[80];

  //for loop implementing quick sort
  for (i = 0; i < (*length-1); i++)
  {
    minIndex = i; //start with minIndex at the same position as i
    //for loop to implement quick sort
    for (j = i+1; j < *length; j++)
    {
      //find the minimum element in the list
      if (strcmp(listToSort[j], listToSort[minIndex]) < 0)
      {
        minIndex = j;
        minIndexChanged = 1;
      }
    }
    //swap elements
    if (minIndexChanged == 1)
    {
      memset(swap, '$', 80 - 2);
      swap[80 - 1] = '\0';
      strcpy(swap, listToSort[i]);
      strcpy(listToSort[i], listToSort[minIndex]);
      strcpy(listToSort[minIndex], swap);
      minIndexChanged = 0;
    }
  }
}
//function definition. It prints out the sorted list of Artists + Songs
void printSortedList(int *numArt, int numSongsPerArtist[],char artistNames[][80],char sortedArtistsNames[][80],char artist1[][80],char artist2[][80],char artist3[][80],char artist4[][80])
{
  int j;
  //for loop that runs through all the artists entered by user
  for (int i = 0; i < *numArt; i++)
  {
    //print the the artists in alphabetically order
    printf("%s\n", sortedArtistsNames[i]);

    /*The following 4 if statements compare the sortedArtistsNames array with the
    artistNames array to determine the correct array of songs for each sorted artist.
    This is needed in order to not get the songs of an artist mixed with the wrong artist*/
    //if sorted artist corresponds to artist1 entered by user, print out sorted songs of artist1
    if (strcmp(sortedArtistsNames[i], artistNames[0]) == 0)
    {
      for (j = 0; j < numSongsPerArtist[0]; j++)
      {
        printf("  - %s\n", artist1[j]);
      }
    }
    //if sorted artist corresponds to artist2 entered by user, print out sorted songs of artist2
    if (strcmp(sortedArtistsNames[i], artistNames[1]) == 0)
    {
      for (j = 0; j < numSongsPerArtist[1]; j++)
      {
        printf("  - %s\n", artist2[j]);
      }
    }
    //if sorted artist corresponds to artist3 entered by user, print out sorted songs of artist3
    if (strcmp(sortedArtistsNames[i], artistNames[2]) == 0)
    {
      for (j = 0; j < numSongsPerArtist[2]; j++)
      {
        printf("  - %s\n", artist3[j]);
      }
    }
    //if sorted artist corresponds to artist4 entered by user, print out sorted songs of artist4
    if (strcmp(sortedArtistsNames[i], artistNames[3]) == 0)
    {
      for (j = 0; j < numSongsPerArtist[3]; j++)
      {
        printf("  - %s\n", artist4[j]);
      }
    }
    printf("\n");
  }
}
