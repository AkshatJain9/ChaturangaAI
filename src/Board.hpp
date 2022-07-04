#pragma once
#include <stdint.h>

class Board { 
    public:
        Board();
        ~Board();
        
        uint8_t** getBoard();
        void setBoard(uint8_t** board);
        void switchPlayer();
        bool getPlayer();




    private:
        int currBoard [8][8];
        uint8_t** board; // 2D array of uint8_t representing the board
        bool turn; // True for White, False for Black
};
