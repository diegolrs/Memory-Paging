#include "Optimal.hpp"
#include <iostream>


Optimal::Optimal(int boardQuant)
{
    missPageQuant = 0;
    //this->pageInputs = pageInputs->Copy();
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
        std::cout << page->GetNumber() << " " << " TEM PAG. " << std::endl;
        return;
    }
    
    std::cout << page->GetNumber() << " " << " NAO TEM PAG. " << std::endl;
    this->missPageQuant++;
    boards = OptimalUtils::SortBoards(boards, pageInputs);

    Board* b = boards->Dequeue();
    b->HoldPage(page);
    boards->Enqueue(b);

    std::cout << std::endl << "\n DEPOIS \n";
    int size = boards->Length();
    for(int i = 0; i < size; i++)
    {
        Board* b = boards->Dequeue();
        std::cout << b->GetPageNumber() << ", ";
        boards->Enqueue(b);
    }
    std::cout << "\n-----\n";
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