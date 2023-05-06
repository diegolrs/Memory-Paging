#pragma once
#include <vector>
#include "../Slots/Board.hpp"
#include "../Slots/Page.hpp"
#include "../Queue/QueueUtils.hpp"
#include "MemoryPaging.hpp"

// Least Recently Used
class LRU : public MemoryPaging
{
    public:
        LRU(int boardQuant);
    private:
        void HoldPage(Page* page, Queue<int>* pageInputs) override;
        void SendBoardToEndOfQueue(int boardIndex);
};