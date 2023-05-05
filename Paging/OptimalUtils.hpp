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

    int Optimal::GetNextOccurrence(int pageValue, Queue<int>* pageInputs)
    {
        std::vector<int> vec = QueueUtils::to_std_vector(pageInputs);

        for(int i = 0; i < vec.size(); i++)
        {
            if(vec[i] == pageValue)
                return i;
        }

        return -1;
    }

    bool sortingFunction(OptimalData d1, OptimalData d2)
    {
        if(d1.distanceToNext == -1)
            return true;

        return d1.distanceToNext >= d2.distanceToNext;
    }
    

    Queue<Board*>* sortBoards(Queue<Board*> *boards, Queue<int>* pageInputs)
    {
        std::vector<OptimalData> vec;
        Queue<OptimalData>* queue;
        
        // Distance
            for(int i = 0; i < boards->Length(); i++)
            {
                OptimalData data;
                Board* _ = boards->Dequeue();
                data.board = _;
                data.distanceToNext = GetNextOccurrence(data.board->GetPageNumber(), pageInputs);
                vec.push_back(data);
                boards->Enqueue(_);
            }

        // Sorting
            queue = QueueUtils::from_std_vector(vec);
            queue = QueueUtils::sort_queue(queue, sortingFunction);
            Queue<Board*>* sortedQueues = new Queue<Board*>();

        // Saving to Queue
            int size = queue->Length();
            for(int i = 0; i < size; i++)
            {
                sortedQueues->Enqueue(queue->Dequeue());
            }

        return sortedQueues;
    }
};