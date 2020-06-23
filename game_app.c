#include <stdlib.h>
#include <stdio.h>

//structure visualation
/*

     BIGsqr   |   BIGsqr   |  BIGsqr  
   [smallsqr] | [smallsqr] | [smallsqr]
  --------------------------------------
     BIGsqr   |   BIGsqr   |   BIGsqr  
   [smallsqr] | [smallsqr] | [smallsqr]
  --------------------------------------
     BIGsqr   |   BIGsqr   |   BIGsqr  
   [smallsqr] | [smallsqr] | [smallsqr]

*/

//program fucntionality
/*

  1. Create a correct reference SUDOKU_ORIGIN
  2. Copy values and create SUDOKU_SOLUTION
  3. Remove a number of values from SUDOKU_SOLUTION 
  4. Start solving loop
    1) while loop with "bool solved" as variable
    2) show current SUDOKU_SOLUTION 
    3) ask for BIGsqr position
    4) ask for SMALLsqr data index
    5) ask for value to be placed
    6) check if new SUDOKU_SOLUTION value is same as SUDOKU_ORIGIN
        a) if ok add it to SUDOKU_SOLUTION
        b) if not, say "you dumb bitch"
    7) if not solved go back to point 2
*/

//TO DO and improvment
/*
    DONE:
        1) Printing all sudoku
        2) addiing random values

    TO DO LIST: 
        1) create a file with some finished sudoku and assign them randomly
        2) adding blank sudoku to add own values
        3) make a function that allows user to select position 
        4) check for solved

    POTENTIAL IMPROVEMNT
        1) create SUDOKU_ORIGIN generation algorythm
*/

//  REMEMBER TO KEEP GIT HUB REPO UPDATED


typedef struct SMALLsqr
{
int data[3][3];
int solved;

}SMALLsqr;

typedef struct BIGsqr
{
SMALLsqr content;

int posX;
int posY;

}BIGsqr;

typedef struct SUDOKU
{
    BIGsqr GRID[3][3];
   
}SUDOKU;

void print_sudoku(SUDOKU* SUDOKU_temp)
{

    //this function will always print entire sudoku onto screen


    for (int index_sqrY=0; index_sqrY < 3; index_sqrY++)
    {
        for (int index_row = 0; index_row < 3; index_row++)
        {
            for (int index_sqrX=0; index_sqrX < 3; index_sqrX++)
            {
                for (int index_column=0; index_column < 3; index_column++)
                {
                    printf(" %d",SUDOKU_temp->GRID[index_sqrY][index_sqrX].content.data[index_row][index_column]);
                }
                printf("|");
                
            }
            printf("\n");
        }
        for (size_t i = 1; i < 12; i++)
        printf("--");
        printf("\n");
    }

    printf(" \n -------------------- \n This is Your sudoku \n\n");
    
}
void assignvalue_sudoku(SUDOKU* SUDOKU_temp)
{

    for (int index_sqrY=0; index_sqrY < 3; index_sqrY++)
    {
        for (int index_row = 0; index_row < 3; index_row++)
        {
            for (int index_sqrX=0; index_sqrX < 3; index_sqrX++)
            {
                for (int index_column=0; index_column < 3; index_column++)
                {
                    //this can generate values to be asigned to slots

                    SUDOKU_temp->GRID[index_sqrY][index_sqrX].content.data[index_row][index_column]=1+index_column+index_sqrX+index_row+index_sqrY;
                    //printf("current values: \n\n index_column = %d \n index_row = %d \n index_sqrX = %d \n index_sqrY = %d \n",index_column,index_row,index_sqrX,index_sqrY);
                    //printf("suma = %d \n\n",1+index_column+index_sqrX+index_row+index_sqrY);
                }
                
            }
            
        }

    }

    printf(" \n ---------------- \n Values assigned\n\n\n");
   

}


int main (int argc, char* argv[])
{
    //creating SUDOKU ORIGIN

    SUDOKU SUDOKU_ORIGIN, SUDOKU_SOLUTION;

    assignvalue_sudoku(&SUDOKU_ORIGIN);
    print_sudoku(&SUDOKU_ORIGIN);

    //pos_allocation(&SUDOKU_ORIGIN);
    //pos_allocation(&SUDOKU_SOLUTION);

    return 0;
}