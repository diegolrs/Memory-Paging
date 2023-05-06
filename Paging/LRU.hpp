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
        void ProcessInputs(Queue<int>* pageInputs);
        int GetMissPageQuant();
    private:
        Queue<Board*>* boards;
        int missPageQuant;
        
        void HoldPage(Page* page, Queue<int>* pageInputs);
        bool PageIsOnBoard(Page* page);
        int IndexOfBoardWithPage(Page* page);
        void SendBoardToEndOfQueue(int boardIndex);
};