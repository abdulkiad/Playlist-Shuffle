/* Project 1
============================================================================
Name : Abduls Playlist---------
Author : Abdulrahman salim
Student NO.: 15362566
Version  : V1
Copyright  : Abdulrahman.c
Description : playlist
============================================================================
*/
#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char arr[1000][700]; // stores playlist data (limited to 100 rows)
int history[1000];
int main(void) {
	int numberOfLine = 0;
	int l;
	FILE *fp = fopen("C:\\Users\\User\\Desktop\\folder\\playlist.txt.txt", "r+" );  /* open for reading */
	// This will take each row in the file and store it in arr.
	if (fp == NULL ){ /* check does playlist file exist etc */
		perror ("Error occured ");
		numberOfLine = -1; /* use this as a file not found code */
	} else
		// fgets returns NULL when it gets to the end of the file
		while ( fgets( arr[numberOfLine], sizeof(arr[numberOfLine]), fp ) != NULL ) {
			numberOfLine++;
		}
		
	fclose (fp);
	printf("\n             ----------Intial Playlist---------      \n");
	
	for(l=0;l<=numberOfLine;l++)
	{
		printf(" %s\n",arr[l]); // printing textfiles
	}
	



	int n=numberOfLine;
	int i,j,k;
	char temp[700];
  //loop to bubble sort
	for(j=0; j<n; j++)
	{
		for(k=0; k<=n-1-j; k++) //buble sorting with strings
		{
			if(strcmp(arr[k],arr[k+1])>0) //sorting algorithim comparing the strings
			{
				strcpy(temp, arr[k]);
				strcpy(arr[k], arr[k+1]); //algorithim to sort
				strcpy(arr[k+1], temp);
			}
		}
	}
	
	
	printf("\n             ----------Sorted Playlist---------      \n");
	for(i=0;i<=n;i++)
	{
	
		printf("%s\n",arr[i]); //printing sorted list

	}	

	srand(clock()); //allow random function
	int w,z,h;

	int c=0;
	printf("\n             ----------Shuffled Playlist---------      \n");

	for (w=0;w<=numberOfLine;w++)
	{
		z=rand()%numberOfLine ; //randomising it
		
		for ( h = 0; h <numberOfLine; h++) // checks if you have played the song before. (function)
		{
			if (z==history[h]) //if yes you are generating another random number.
			{
				
				z=rand()%numberOfLine ; //randomizing again if same song comes up again
				h=0;
				
			} 
			if(history[numberOfLine]!=0)
			{
				return 0;
			}
			
						
		}
		printf("%s\n",arr[z]);
		history[w]=z;
		
	}



		return 0;
}

