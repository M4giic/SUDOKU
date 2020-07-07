#ifndef ALL_H
#define ALL_H

    typedef struct {
    int *data[3][3];
    int solved;

    }SMALLsqr;

    typedef struct {
    SMALLsqr *content;

    int posX;
    int posY;

    }BIGsqr;

    typedef struct {
        BIGsqr GRID[3][3];
    
    }SUDOKU;

#endif

