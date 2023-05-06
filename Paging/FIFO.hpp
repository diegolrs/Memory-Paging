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
        void HoldPage(Page* page, Queue<int>* pageInputs);
        int GetMissPageQuant();
        void ProcessInputs(Queue<int>* pageInputs);
    private:
        Queue<Board*>* boards;
        int missPageQuant;
        
        bool PageIsOnBoard(Page* page);
};