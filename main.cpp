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

int main()
{
    vector<int> allInputs = readDataFromFile();
    Queue<int>* queue = QueueUtils::from_std_vector(allInputs);

    int boardQuantity = queue->Dequeue();

    FIFO* fifo = new FIFO(boardQuantity);
    LRU* lru = new LRU(boardQuantity);
    Optimal* optimal = new Optimal(boardQuantity);

    fifo->ProcessInputs(queue->Copy());
    lru->ProcessInputs(queue->Copy());
    optimal->ProcessInputs(queue->Copy());

    cout << "FIFO " << fifo->GetMissPageQuant() << endl;
    cout << "LRU " << lru->GetMissPageQuant() << endl;
    cout << "OTM " << optimal->GetMissPageQuant() << endl;

    return 0;
}