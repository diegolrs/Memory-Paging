#include "Board.hpp"

Board::Board()
{
    this->page = nullptr;
}

Board::Board(Page* page)
{
    this->page = page;
}

void Board::HoldPage(Page* page)
{
    this->page = page;
}

bool Board::IsHoldingPage(Page* page)
{
    return this->page != nullptr && page != nullptr && this->page->HasSameNumber(page);
}

int Board::GetPageNumber()
{
    if(page == nullptr)
        return -1;
    return page->GetNumber();
}