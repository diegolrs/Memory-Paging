#pragma once
#include <vector>
#include "../Slots/Board.hpp"
#include "../Slots/Page.hpp"
#include "../Queue/QueueUtils.hpp"

namespace OptimalUtils
{
    struct OptimalData
    {
        Board* board;
        int distanceToNext;
    };

    int GetNextOccurrence(int pageValue, Queue<int>* pageInputs);
    bool sortingFunction(OptimalData d1, OptimalData d2);
    Queue<Board*>* SortBoards(Queue<Board*> *boards, Queue<int>* pageInputs);
};