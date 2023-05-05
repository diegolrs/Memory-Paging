#pragma once
#include "Page.hpp"

class Board
{
    public:
        Board();
        Board(Page* page);
        void HoldPage(Page* page);
        bool IsHoldingPage(Page* page);
        int GetPageNumber();
    private:
        Page* page;
};