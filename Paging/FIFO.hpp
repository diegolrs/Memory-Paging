#pragma once
#include <vector>
#include "../Slots/Board.hpp"
#include "../Slots/Page.hpp"
#include "../Queue/QueueUtils.hpp"

// First In, First Out
class FIFO
{
    public:
        FIFO(int boardQuant);
        void ProcessInputs(Queue<int>* pageInputs);
        int GetMissPageQuant();
    private:
        Queue<Board*>* boards;
        int missPageQuant;
        
        void HoldPage(Page* page, Queue<int>* pageInputs);
        bool PageIsOnBoard(Page* page);
};