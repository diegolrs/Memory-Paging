#include "MemoryPaging.hpp"

MemoryPaging::MemoryPaging(int boardQuant)
{
    missPageQuant = 0;
    boards = new Queue<Board*>();

    for(int i = 0; i < boardQuant; i++)
    {
        Board* b = new Board();
        boards->Enqueue(b);
    }
}

void MemoryPaging::ProcessInputs(Queue<int>* pageInputs)
{
    int inputSize = pageInputs->Length();
    
    for(int i = 0; i < inputSize; i++)
    {
        int page = pageInputs->Dequeue();
        HoldPage(new Page(page), pageInputs);
    }
}

int MemoryPaging::GetMissPageQuant()
{
    return missPageQuant;
}

bool MemoryPaging::PageIsOnBoard(Page* page)
{
    std::vector<Board*> vec = QueueUtils::to_std_vector(boards);

    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i]->IsHoldingPage(page))
        {
            return true;
        }
    }

    return false;
}

int MemoryPaging::IndexOfBoardWithPage(Page* page)
{
    std::vector<Board*> vec = QueueUtils::to_std_vector(boards);

    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i]->IsHoldingPage(page))
        {
            return i;
        }
    }

    return -1;
}