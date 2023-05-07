#include "Test.hpp"

std::vector<int> Test::GetInput1()
{
    std::vector<int> vec;
    const int size = 13;
    int inputs[size] = {4, 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};

    for(int i = 0; i < size; i++)
        vec.push_back(inputs[i]);
    return vec;
}

std::vector<int> Test::GetInput2()
{
    std::vector<int> vec;
    const int size = 21;
    int inputs[size] = {3, 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};

    for(int i = 0; i < size; i++)
        vec.push_back(inputs[i]);
    return vec;
}

std::vector<int> Test::GetInput3()
{
    std::vector<int> vec;
    const int size = 21;
    int inputs[size] = {5, 1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6};

    for(int i = 0; i < size; i++)
        vec.push_back(inputs[i]);
    return vec;
}

std::vector<int> Test::GetInput4()
{
    std::vector<int> vec;
    const int size = 21;
    int inputs[size] = {4, 1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6};

    for(int i = 0; i < size; i++)
        vec.push_back(inputs[i]);
    return vec;
}

void Test::ValidatePaging(FIFO* fifo, Optimal* opt, LRU* lru, int order)
{
    int outputs[QUANT_OF_INPUTS][QUANT_OF_OUTPUTS] = {{10, 6, 8}, {15, 9, 12}, {10, 7, 8}, {14, 8, 10}};
    assert(fifo->GetMissPageQuant() == outputs[order][0]);
    assert(opt->GetMissPageQuant() == outputs[order][1]);
    assert(lru->GetMissPageQuant() == outputs[order][2]);
}

void Test::RunTests()
{
    std::vector<int> input;

    for(int i = 0; i < QUANT_OF_INPUTS; i++)
    {
        if(i == 0) input = GetInput1();
        else if(i == 1) input = GetInput2();
        else if(i == 2) input = GetInput3();
        else if(i == 3) input = GetInput4();

        Queue<int>* queue = QueueUtils::from_std_vector(input);
        int boardQuantity = queue->Dequeue();

        FIFO* fifo = new FIFO(boardQuantity);
        Optimal* optimal = new Optimal(boardQuantity);
        LRU* lru = new LRU(boardQuantity);

        fifo->ProcessInputs(queue->Copy());
        optimal->ProcessInputs(queue->Copy());
        lru->ProcessInputs(queue->Copy());

        ValidatePaging(fifo, optimal, lru, i);

        std::cout << "Input " << i+1 << " has passed with values: ";
        std::cout << "FIFO = " << fifo->GetMissPageQuant() << ", ";
        std::cout << "OTM = " << optimal->GetMissPageQuant() << ", ";
        std::cout << "LRU = " << fifo->GetMissPageQuant() << std::endl;
    }
}