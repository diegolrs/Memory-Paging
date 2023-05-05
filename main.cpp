#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include "FileReader/FileReader.hpp"
#include "Queue/Queue.hpp"
#include "Queue/QueueUtils.hpp"
#include "Paging/FIFO.hpp"

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

int main()
{
    vector<int> allInputs = readDataFromFile();
    Queue<int>* queue = QueueUtils::from_std_vector(allInputs);

    int boardQuantity = queue->Dequeue();
    int inputSize = queue->Length();

    FIFO* fifo = processFifo(boardQuantity, queue);

    cout << "FIFO " << fifo->GetMissPageQuant();

    return 0;
}