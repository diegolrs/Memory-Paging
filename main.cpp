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

using namespace std;

vector<int> readDataFromFile()
{
    return FileReader::ReadFile("input.txt");
}

vector<int> cloneVector(vector<int> vect1)
{
    vector<int> vect2; 
    copy(vect1.begin(), vect1.end(), back_inserter(vect2));
    return vect2;
}

FIFO* processFifo(int boardQuantity, Queue<int>* pageInputs)
{
    FIFO* fifo = new FIFO(boardQuantity);
    int inputSize = pageInputs->Length();
    
    for(int i = 0; i < inputSize; i++)
    {
        int page = pageInputs->Dequeue();
        fifo->HoldPage(new Page(page));
        pageInputs->Enqueue(page);
    }

    return fifo;
}

LRU* processLRU(int boardQuantity, Queue<int>* pageInputs)
{
    LRU* lru = new LRU(boardQuantity);
    int inputSize = pageInputs->Length();
    
    for(int i = 0; i < inputSize; i++)
    {
        int page = pageInputs->Dequeue();
        lru->HoldPage(new Page(page));
        pageInputs->Enqueue(page);
    }

    return lru;
}

Optimal* processOptimal(int boardQuantity, Queue<int>* pageInputs)
{
    Optimal* optimal = new Optimal(boardQuantity);
    optimal->ProcessInputs(pageInputs);

    return optimal;
}

int main()
{
    vector<int> allInputs = readDataFromFile();
    Queue<int>* queue = QueueUtils::from_std_vector(allInputs);

    int boardQuantity = queue->Dequeue();
    int inputSize = queue->Length();

    //FIFO* fifo = processFifo(boardQuantity, queue);
    //LRU* lru = processLRU(boardQuantity, queue);
    Optimal* optimal = processOptimal(boardQuantity, queue);

    //cout << "FIFO " << fifo->GetMissPageQuant() << endl;
    //cout << "LRU " << lru->GetMissPageQuant() << endl;
    cout << "OTM " << optimal->GetMissPageQuant() << endl;

    return 0;
}