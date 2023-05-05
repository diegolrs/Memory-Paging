#pragma once
#include <vector>
#include "../Slots/Board.hpp"
#include "../Slots/Page.hpp"
#include "../Queue/QueueUtils.hpp"

// Optimal Algorithm
class Optimal
{
    public:
        Optimal(int boardQuant);
        void HoldPage(Page* page);
        int GetMissPageQuant();
    private:
        Queue<Board*>* boards;
        int missPageQuant;
        
        bool PageIsOnBoard(Page* page);
        int IndexOfBoardWithPage(Page* page);
        void SendBoardToEndOfQueue(int boardIndex);
};