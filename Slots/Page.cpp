#include "Page.hpp"

Page::Page(int number)
{
    this->number = number;
}

bool Page::HasSameNumber(Page* other)
{
    return this->number == other->number;
}

int Page::GetNumber()
{
    return number;
}