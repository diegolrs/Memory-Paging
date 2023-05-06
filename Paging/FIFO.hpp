#pragma once
#include <vector>
#include "../Slots/Board.hpp"
#include "../Slots/Page.hpp"
#include "../Queue/QueueUtils.hpp"
#include "MemoryPaging.hpp"

// First In, First Out
class FIFO : public MemoryPaging
{
    public:
        FIFO(int boardQuant);
    private:
        void HoldPage(Page* page, Queue<int>* pageInputs) override;
};