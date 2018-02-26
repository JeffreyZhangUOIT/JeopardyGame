#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct player {
    char  name[256];
    int score;
};
 
int main( ) {

   struct player player1;        
   struct player player2;        		
   struct player player3;
   struct player player4;
 
   
   printf("enter player1 name: ");
   player1.name, scanf("%s", player1.name);
   printf("enter play 1 score: ");
   player1.score, scanf("%d", player1.score);	
   



   /* print player1 info */
   printf( "player1 name : %s\n", player1.name);
   printf( "player1 score: %d\n", player1.score);

return 0;
}

//not finished
