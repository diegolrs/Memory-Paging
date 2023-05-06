#include "FIFO.hpp"

FIFO::FIFO(int boardQuant) : MemoryPaging(boardQuant){}

void FIFO::HoldPage(Page* page, Queue<int>* pageInputs)
{
    if(PageIsOnBoard(page))
    {
        return;
    }
    
    this->missPageQuant++;

    Board* b = boards->Dequeue();
    b->HoldPage(page);
    boards->Enqueue(b);
}