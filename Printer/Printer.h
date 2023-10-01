#pragma once
#include <iostream>
using namespace std;

struct PrintJob {
    string worker;
    time_t time;
};

class QueuePriority
{
    int* wait;
    int* prior;
    PrintJob* print_l;
    int m_length;
    int length;
public:
    QueuePriority(int m);
    ~QueuePriority();
    void Add(int c, int p, const string& worker);
    int Extract();
    void Clear();
    bool IsEmpty();
    bool IsFull();
    int GetCount();
    void Show();
};
