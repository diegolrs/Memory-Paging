#pragma once
#include <vector>
#include "../Slots/Board.hpp"
#include "../Slots/Page.hpp"
#include "../Queue/QueueUtils.hpp"

class MemoryPaging
{
    public:
        MemoryPaging(int boardQuant);
        void ProcessInputs(Queue<int>* pageInputs);
        
        int IndexOfBoardWithPage(Page* page);
        bool PageIsOnBoard(Page* page);
        int GetMissPageQuant(); 
    protected:
        Queue<Board*>* boards;
        int missPageQuant;
        
        virtual void HoldPage(Page* page, Queue<int>* pageInputs) = 0;
};