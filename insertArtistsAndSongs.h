#ifndef INSERTARTISTSANDSONGS_H_
#define INSERTARTISTSANDSONGS_H_

//function definition. Reads in a maximum of three songs entered by the user
int insertSongs(char songs[][80], char artistNames[]);

//function definition. Reads in artists entered by the user and calls insertSongs function to read songs for each artist
int insertArtistsAndSongs(char artistNames[][80], char songsArtist1[][80], char songsArtist2[][80], char songsArtist3[][80], char songsArtist4[][80], int numSongsPerArtist[4]);

#endif
