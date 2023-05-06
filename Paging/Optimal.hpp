#pragma once
#include <vector>
#include "../Slots/Board.hpp"
#include "../Slots/Page.hpp"
#include "../Queue/QueueUtils.hpp"
#include "MemoryPaging.hpp"
#include "OptimalUtils.hpp"

// Optimal Algorithm
class Optimal : public MemoryPaging
{
    public:
        Optimal(int boardQuant);
    private:
        void HoldPage(Page* page, Queue<int>* pageInputs) override;
};