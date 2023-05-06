#pragma once
#include <vector>
#include "../Slots/Board.hpp"
#include "../Slots/Page.hpp"
#include "../Queue/QueueUtils.hpp"

// Least Recently Used
class LRU
{
    public:
        LRU(int boardQuant);
        void HoldPage(Page* page, Queue<int>* pageInputs);
        int GetMissPageQuant();
        void ProcessInputs(Queue<int>* pageInputs);
    private:
        Queue<Board*>* boards;
        int missPageQuant;
        
        bool PageIsOnBoard(Page* page);
        int IndexOfBoardWithPage(Page* page);
        void SendBoardToEndOfQueue(int boardIndex);
};