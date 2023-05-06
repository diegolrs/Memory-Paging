#pragma once
#include <vector>
#include "../Slots/Board.hpp"
#include "../Slots/Page.hpp"
#include "../Queue/QueueUtils.hpp"
#include "OptimalUtils.hpp"

// Optimal Algorithm
class Optimal
{
    public:
        Optimal(int boardQuant);
        void ProcessInputs(Queue<int>* pageInputs);

        void HoldPage(Page* page, Queue<int>* pageInputs);
        int GetMissPageQuant();
    private:
        Queue<Board*>* boards;
        int missPageQuant;
        Queue<int>* pageInputs;
        
        bool PageIsOnBoard(Page* page);
        int IndexOfBoardWithPage(Page* page);
};