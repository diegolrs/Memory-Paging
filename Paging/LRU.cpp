#include "LRU.hpp"

LRU::LRU(int boardQuant) : MemoryPaging(boardQuant){}

void LRU::HoldPage(Page* page, Queue<int>* pageInputs)
{
    if(PageIsOnBoard(page))
    {
        int index = IndexOfBoardWithPage(page);
        SendBoardToEndOfQueue(index);
        return;
    }
    
    this->missPageQuant++;

    Board* b = boards->Dequeue();
    b->HoldPage(page);
    boards->Enqueue(b);
}

void LRU::SendBoardToEndOfQueue(int boardIndex)
{
    std::vector<Board*> vec = QueueUtils::to_std_vector(boards);
    Board* b = vec[boardIndex];
    vec.erase(vec.begin()+boardIndex);
    boards = QueueUtils::from_std_vector(vec);
    boards->Enqueue(b);
}