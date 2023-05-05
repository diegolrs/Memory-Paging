#include "Optimal.hpp"


Optimal::Optimal(int boardQuant, Queue<int>* pageInputs)
{
    missPageQuant = 0;
    this->pageInputs = pageInputs->Copy();
    boards = new Queue<Board*>();

    for(int i = 0; i < boardQuant; i++)
    {
        Board* b = new Board();
        boards->Enqueue(b);
    }
}

void Optimal::HoldPage(Page* page)
{
    pageInputs->Dequeue();

    if(PageIsOnBoard(page))
    {
        return;
    }
    
    this->missPageQuant++;
    boards = OptimalUtils::sortBoards(boards, pageInputs);
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