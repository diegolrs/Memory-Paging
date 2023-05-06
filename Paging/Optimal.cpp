#include "Optimal.hpp"

Optimal::Optimal(int boardQuant)
{
    missPageQuant = 0;
    boards = new Queue<Board*>();

    for(int i = 0; i < boardQuant; i++)
    {
        Board* b = new Board();
        boards->Enqueue(b);
    }
}

void Optimal::ProcessInputs(Queue<int>* pageInputs)
{
    int inputSize = pageInputs->Length();
    
    for(int i = 0; i < inputSize; i++)
    {
        int page = pageInputs->Dequeue();
        HoldPage(new Page(page), pageInputs);
    }
}

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

int Optimal::GetMissPageQuant()
{
    return missPageQuant;
}

bool Optimal::PageIsOnBoard(Page* page)
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

int Optimal::IndexOfBoardWithPage(Page* page)
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