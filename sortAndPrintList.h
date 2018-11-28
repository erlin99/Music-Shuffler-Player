#ifndef SORTANDPRINTLIST_H_
#define SORTANDPRINTLIST_H_

//Function definition. It sorts the array received alphabetically.
//Algorithm used: Quick Sort Algorithm
void sort(char listToSort[][80] , int *length);

//function definition. It prints out the sorted list of Artists + Songs
void printSortedList(int *numArt, int numSongsPerArtist[],char artistNames[][80],char sortedArtistsNames[][80],char artist1[][80],char artist2[][80],char artist3[][80],char artist4[][80]);

#endif
