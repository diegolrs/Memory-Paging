#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include "FileReader/FileReader.hpp"
#include "Queue/Queue.hpp"
#include "Queue/QueueUtils.hpp"
#include "Paging/FIFO.hpp"
#include "Paging/LRU.hpp"
#include "Paging/Optimal.hpp"
#include "Tests/Test.hpp"

using namespace std;

const string FILE_ADDRESS = "input.txt";

vector<int> readDataFromFile()
{
    return FileReader::ReadFile(FILE_ADDRESS);
}

void runProgram()
{
    vector<int> allInputs = readDataFromFile();
    Queue<int>* queue = QueueUtils::from_std_vector(allInputs);
    int boardQuantity = queue->Dequeue();

    FIFO* fifo = new FIFO(boardQuantity);
    Optimal* optimal = new Optimal(boardQuantity);
    LRU* lru = new LRU(boardQuantity);

    fifo->ProcessInputs(queue->Copy());
    optimal->ProcessInputs(queue->Copy());
    lru->ProcessInputs(queue->Copy());

    cout << "FIFO " << fifo->GetMissPageQuant() << endl;
    cout << "OTM " << optimal->GetMissPageQuant() << endl;
    cout << "LRU " << lru->GetMissPageQuant() << endl;
}

void runTests()
{
    Test::RunTests();
}

int main()
{
    //runTests();
    runProgram();
    return 0;
}