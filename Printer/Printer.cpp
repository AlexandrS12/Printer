#include "Printer.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void QueuePriority::Show()
{
    cout << "\n-------------------------------------" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << "Worker: " << print_l[i].worker << " - Priority: " << prior[i] << " - Time: ";
        char Buff[30];
        ctime_s(Buff, sizeof(Buff), &print_l[i].time);
        cout << Buff;
    }
    cout << "\n-------------------------------------" << endl;
}

QueuePriority::~QueuePriority()
{
    delete[] wait;
    delete[] prior;
    delete[] print_l;
}

QueuePriority::QueuePriority(int m_length)
{
    m_length = m_length;
    wait = new int[m_length];
    prior = new int[m_length];
    print_l = new PrintJob[m_length];
    length = 0;
}

void QueuePriority::Clear()
{
    length = 0;
}

bool QueuePriority::IsEmpty()
{
    return length == 0;
}

bool QueuePriority::IsFull()
{
    return length == m_length;
}

int QueuePriority::GetCount()
{
    return length;
}

void QueuePriority::Add(int c, int p, const string& worker)
{
    if (!IsFull())
    {
        wait[length] = c;
        prior[length] = p;
        print_l[length].worker = worker;
        print_l[length].time = time(nullptr);
        length++;
    }
}

int QueuePriority::Extract()
{
    if (!IsEmpty())
    {
        int max_pri = prior[0];
        int pos_max_pri = 0;

        for (int i = 1; i < length; i++)
        {
            if (max_pri < prior[i])
            {
                max_pri = prior[i];
                pos_max_pri = i;
            }
        }

        int temp1 = wait[pos_max_pri];
        int temp2 = prior[pos_max_pri];
        for (int i = pos_max_pri; i < length - 1; i++)
        {
            wait[i] = wait[i + 1];
            prior[i] = prior[i + 1];
            print_l[i] = print_l[i + 1];
        }
        length--;
        return temp1;
    }
    else
    {
        return -1;
    }
}
