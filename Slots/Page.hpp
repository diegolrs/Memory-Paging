#pragma once

class Page
{
    public:
        Page(int number);
        bool HasSameNumber(Page* other);
        int GetNumber();
    private:
        int number;
};