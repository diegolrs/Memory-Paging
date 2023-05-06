#pragma once
#include <assert.h>
#include <vector>

#include "../Queue/Queue.hpp"
#include "../Queue/QueueUtils.hpp"
#include "../Paging/FIFO.hpp"
#include "../Paging/LRU.hpp"
#include "../Paging/Optimal.hpp"

namespace Test
{
    const int QUANT_OF_INPUTS = 4;
    const int QUANT_OF_OUTPUTS = 3;

    std::vector<int> GetInput1();
    std::vector<int> GetInput2();
    std::vector<int> GetInput3();
    std::vector<int> GetInput4();
    void ValidatePaging(FIFO* fifo, Optimal* opt, LRU* lru, int order);
    void RunTests();
}
