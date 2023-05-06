#include "LRU.hpp"

LRU::LRU(int boardQuant)
{
    missPageQuant = 0;
    boards = new Queue<Board*>();

    for(int i = 0; i < boardQuant; i++)
    {
        Board* b = new Board();
        boards->Enqueue(b);
    }
}

void LRU::ProcessInputs(Queue<int>* pageInputs)
{
    int inputSize = pageInputs->Length();
    
    for(int i = 0; i < inputSize; i++)
    {
        int page = pageInputs->Dequeue();
        HoldPage(new Page(page), pageInputs);
    }  
}

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

int LRU::GetMissPageQuant()
{
    return missPageQuant;
}

bool LRU::PageIsOnBoard(Page* page)
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

int LRU::IndexOfBoardWithPage(Page* page)
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

void LRU::SendBoardToEndOfQueue(int boardIndex)
{
    std::vector<Board*> vec = QueueUtils::to_std_vector(boards);
    Board* b = vec[boardIndex];
    vec.erase(vec.begin()+boardIndex);
    boards = QueueUtils::from_std_vector(vec);
    boards->Enqueue(b);
}