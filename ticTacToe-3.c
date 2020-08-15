/*------------------------------------------------------------------------
| Destiny Jenkins                                                         |

| This program runs a two player game of Tic Tac Toe on a 3x3 game board. |
--------------------------------------------------------------------------*/
#include <stdio.h>
#define ROUNDS 4
#include <stdbool.h>

void printBoard(char rowA[5], char rowB[5], char rowC[5]);/* Function that prints game board*/
bool isOpen(char *p, char *r, char *t, int rowX, int columnX);/*Function that checks if space is occupied*/


int main()
{
    printf("***Tic Tac Toe***\n");
    printf("\n");
   
    printf("Player 1 is X.\n");
    printf("Player 2 is O.\n");
    printf("\n");
   
   int rowX;/* Row that player 1 inputs*/
   int columnX = 0;/*Column that player 1 inputs*/
   int rowO; /* Row that player 2 inputs*/
   int columnO = 0;/*Column that player 2 inputs*/
   char rowA[] = {' ', ' ', ' '}; /*Row 1 of board*/ 
   char rowB[]= {' ', ' ', ' '};/*Row 2 of board*/
   char rowC[]= {' ', ' ', ' '};/*Row 3 of board*/
   char *p;/* Pointer for Row A*/
   char *q;/* Pointer for Row space in Row A after user inserts column*/
   char *r;/* Pointer for Row B*/
   char *s;/* Pointer for Row space in Row B after user inserts column*/
   char *t;/* Pointer for Row space in Row C*/
   char *u;/* Pointer for Row space in Row C after user inserts column*/
   int count = 0;/*Counts the number of rounds*/
   char answer;/*y or n answer that user inputs to restart the game*/
    
    /*Points to space in Row A that user chooses*/
    p=rowA;
    *p=rowA[0];
    q=rowA+columnX;
    
    /*Points to space in Row B that user chooses*/
    r=rowB;
    *r=rowB[0];
    s=rowB+columnX;
    
    /*Points to space in Row C that user chooses*/
    t=rowC;
    u=rowC+columnX;
    
    printBoard(p, r, t); /*prints board*/  
    
   
    
   for(int i=0; i<ROUNDS; i++) /*loops game until someone wins or there is a tie*/
    {
         printf("\n");
        
   
         /*Player 1's turn*/
         printf("Current Move: Player 1\n");
         
         printf("\n");/*Blank line*/
         
         printf("Enter Row: ");
         scanf("%u" , &rowX);
         
         
         printf("\n");/*Blank line*/
         
         
         while(rowX>2)/*Ensures that a value from 0-2 is chosen*/
         {   printf("Please enter a value from 0 to 2: ");
             scanf("%u", &rowX);
         }

             printf("\n");
             printf("Enter Column: ");
             scanf("%u" , &columnX);
             
         
             while(columnX>2)/*Ensures that a value from 0-2 is chosen*/
             {  
               printf("Please enter a value from 0 to 2: ");
               scanf("%u", &columnX);
             }  
             
             
             printf("\n");/*Blank line*/
             
             
             
               
             while(!isOpen(p, r, t, rowX, columnX)) /*Makes sure that space is not already occupied*/
             {
               printf("Space occupied. Please try again. \n");
               
               printf("\n");
             
               printf("Current Move: Player 1\n");
         
               printf("\n");
         
               printf("Enter Row: ");
               scanf("%u" , &rowX);
         
               printf("\n");
               
         
               while(rowX>2)
               {  printf("Please enter a value from 0 to 2: ");
                  scanf("%u", &rowX);
               }


               printf("\n");
               printf("Enter Column: ");
               scanf("%u" , &columnX);
               
             
               while(columnX>2)
               {  
                  printf("Please enter a value from 0 to 2: ");
                  scanf("%u", &columnX);
               }
               
               
           }
       
          /*Determines which space to fill with an X*/
          switch(rowX)
          {
            case 0: 
            q=p+columnX;
            *q = 'X';
            break;
            
            case 1: 
            s=r+columnX;
            *s = 'X';
            break;
            
            case 2:
            u=t+columnX;
            *u = 'X';   
          } 
              
              
     
          printBoard(p, r, t);/*Prints board*/ 
             
   
          printf("\n");/*Blank line*/
   
   
          if(rowA[0] == 'X' && rowA[1] == 'X' && rowA[2] == 'X')/*Checks to see if there are 3 Xs horizontally
                                                                  in row A*/
   
          {                                                       
            printf("Player 1 has won!!! \n");
            break;   
          } 
         
         
          else if(rowB[0] == 'X' && rowB[1] == 'X' && rowB[2] == 'X')/*Checks to see if there are 3 Xs horizontally
                                                                       in row B*/
          {
            printf("Player 1 has won!!! \n"); 
            break; 
          } 
          
         
          else if(rowC[0] == 'X' && rowC[1] == 'X' && rowC[2] == 'X')/*Checks to see if there are 3 Xs horizontally
                                                                       in row C*/
          {
            printf("Player 1 has won!!! \n");
            break;
          }  
         
         
          else if(rowA[0] == 'X' && rowB[0] == 'X' && rowC[0] == 'X')/*Checks to see if there are 3 Xs vertically
                                                                       in column 0*/
          {
            printf("Player 1 has won!!! \n");
            break;
          }  
    
   
         
          else if(rowA[1] == 'X' && rowB[1] == 'X' && rowC[1] == 'X')/*Checks to see if there are 3 Xs vertically
                                                                       in column 1 */
          {
            printf("Player 1 has won!!! \n");
            break;
          }
         
         
          else if(rowA[2] == 'X' && rowB[2] == 'X' && rowC[2] == 'X')/*Checks to see if there are 3 Xs vertically
                                                                       in column 2*/
          {
            printf("Player 1 has won!!! \n");
            break;
          } 
     
         
          else if(rowA[0] == 'X' && rowB[1] == 'X' && rowC[2] == 'X')/*Checks to see if there are 3 Xs diagonally
                                                                       from the first space in row A to the last
                                                                       space in row C*/
         {
            printf("Player 1 has won!!! \n");
            break;
         } 
         
         
         else if(rowA[2] == 'X' && rowB[1] == 'X' && rowC[0] == 'X')/*Checks to see if there are 3 Xs diagonally
                                                                      from the last space in row A to the first
                                                                      space in row C*/
        {
         printf("Player 1 has won!!! \n"); 
         break; 
        }
   
 
         
        /*Player 2's turn*/
        printf("Current Move: Player 2\n");
             
         
        printf("\n");/*Blank line*/
             
         
        printf("Enter Row: ");
        scanf("%u" , &rowO);
             
         
        printf("\n");/*Blank line*/
             
         
        while(rowO>2)/*Enseures that a value from 0-2 is chosen*/
        {  
         printf("Please enter a value from 0 to 2: ");
         scanf("%u", &rowO);
        }


        printf("\n");/*Blank line*/
  
        
        printf("Enter Column: ");
        scanf("%u" , &columnO);
   
 
        while(columnO>2)/*Enseures that a value from 0-2 is chosen*/
        { 
         printf("Please enter a value from 0 to 2: ");
         scanf("%u", &columnO);
        } 
          
        printf("\n");/*Blank line*/
             
             
        while(!isOpen(p, r, t, rowO, columnO))/*Makes sure that space is not already occupied*/
        {               
         printf("Space occupied. Please try again. \n");
             
         printf("\n");
             
         printf("Current Move: Player 2\n");
         
         printf("\n");
         
         printf("Enter Row: ");
         scanf("%u" , &rowO);
         
         printf("\n");
               
         
         while(rowO>2)              
         {     
          printf("Please enter a value from 0 to 2: ");
          scanf("%u", &rowO);
         }

         printf("\n");
             
         printf("Enter Column: ");
         scanf("%u" , &columnO);
             
         
         while(columnO>2)             
         {  
          printf("Please enter a value from 0 to 2: ");
          scanf("%u", &columnO);
         } 
        }
                       
     
       /*Determines which space to fill with an X*/
       switch(rowO)
       {
         case 0: 
         q=p+columnO;
         *q = 'O';
         break;
            
         case 1: 
         s=r+columnO;
         *s = 'O';
         break;
            
         case 2:
         u=t+columnO;
         *u = 'O';
         break;
       } 
      
               
       printBoard(p, r, t);/*Prints board*/
        
       printf("\n");/*Blank line*/ 
   
      
       /*Did player 2 win?*/
       if(rowA[0] == 'O' && rowA[1] == 'O' && rowA[2] == 'O')/*Checks to see if there are 3 Os horizontally
                                                               in row A*/
       {
         printf("Player 2 has won!!!");
         break;
       }
       
         
       else if(rowB[0] == 'O' && rowB[1] == 'O' && rowB[2] == 'O')/*Checks to see if there are 3 Os horizontally
                                                                    in row B*/
       {
         printf("Player 2 has won!!!");
         break;
       } 
         
         
       else if(rowC[0] == 'O' && rowC[1] == 'O' && rowC[2] == 'O')/*Checks to see if there are 3 Os horizontally
                                                                    in row C*/
       {     
         printf("Player 2 has won!!!");
         break;
       }  
         
         
       else if(rowA[0] == 'O' && rowB[0] == 'O' && rowC[0] == 'O')/*Checks to see if there are 3 Os vertically
                                                                    in column 0*/
       {
          printf("Player 2 has won!!!");
          break;
       } 
   
         
        else if(rowA[1] == 'O' && rowB[1] == 'O' && rowC[1] == 'O')/*Checks to see if there are 3 Xs vertically
                                                                     in column 1 */
        {
           printf("Player 2 has won!!!");
           break;
        }
         
    
    
         else if(rowA[2] == 'O' && rowB[2] == 'O' && rowC[2] == 'O')/*Checks to see if there are 3 Os vertically
                                                                      in column 2*/
         {
            printf("Player 2 has won!!! \n");
            break;
         }
    
       
         
          else if(rowA[0] == 'O' && rowB[1] == 'O' && rowC[2] == 'O')/*Checks to see if there are 3 Os diagonally
                                                                       from the first space in row A to the last
                                                                       space in row C*/
          {
            printf("Player 2 has won!!!");
            break;
          }
    
    
          else if(rowA[2] == 'O' && rowB[1] == 'O' && rowC[0] == 'O')/*Checks to see if there are 3 Os diagonally
                                                                       from the last space in row A to the first
                                                                       space in row C*/
          {
            printf("Player 2 has won!!!");
            break;
          }
   
          count++;/*Counts amount of rounds played*/
   }
           
      
    /*Determines if there is a tie*/
    if(count>=ROUNDS)
    {
       printf("It's a tie!!! \n");
    }
    
    
    printf("\n");/*Blank line*/
         

    
    printf("Would you like play again? (y or n):");
       scanf("%s", &answer);
      
       if(answer == 'y')
       {
         return main();
       }
       
       else
       {
         printf("Thanks for playing!");
       }
    
          

    return 0;
}

void printBoard(char rowA[5], char rowB[5], char rowC[5])
            
{  printf(" %c | %c | %c \n", rowA[0], rowA[1], rowA[2] ); /*Row 1 of board*/
   printf("---+---+---\n");
 
            
   printf(" %c | %c | %c \n", rowB[0], rowB[1], rowB[2] ); /*Row 2 of board*/
   printf("---+---+---\n");

            
   printf(" %c | %c | %c \n", rowC[0], rowC[1], rowC[2] ); /*Row 3 of board*/
               
    return;
 }
 
 
bool isOpen(char *p, char *r, char *t, int rowX, int columnX)/*Makes sure that space is not already occupied*/
{
  if((rowX==0 && *(p+columnX) != ' ') ||(rowX==1 && *(r+columnX) != ' ') ||(rowX==2 && *(t+columnX) != ' '))
  {
    return false;
  } 
  
  else 
  {
    return true;
  }
} 