#pragma once
#include <vector>
#include "../Slots/Board.hpp"
#include "../Slots/Page.hpp"
#include "../Queue/QueueUtils.hpp"

class FIFO
{
    public:
        FIFO(int boardQuant);
        void HoldPage(Page* page);
        int GetMissPageQuant();
    private:
        Queue<Board*>* boards;
        int missPageQuant;
        
        bool PageIsOnBoard(Page* page);
};