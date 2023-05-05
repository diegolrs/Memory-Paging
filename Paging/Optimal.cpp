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

void Optimal::HoldPage(Page* page)
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

void Optimal::SendBoardToEndOfQueue(int boardIndex)
{
    std::vector<Board*> vec = QueueUtils::to_std_vector(boards);
    Board* b = vec[boardIndex];
    vec.erase(vec.begin()+boardIndex);
    boards = QueueUtils::from_std_vector(vec);
    boards->Enqueue(b);
}