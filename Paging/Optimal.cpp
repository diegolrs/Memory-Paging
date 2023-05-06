#include "Optimal.hpp"

Optimal::Optimal(int boardQuant) : MemoryPaging(boardQuant){}

void Optimal::HoldPage(Page* page, Queue<int>* pageInputs)
{
    if(PageIsOnBoard(page))
    {
        return;
    }
    
    this->missPageQuant++;
    boards = OptimalUtils::SortBoards(boards, pageInputs);

    Board* b = boards->Dequeue();
    b->HoldPage(page);
    boards->Enqueue(b);
}