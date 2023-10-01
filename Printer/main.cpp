#include <iostream>
#include <string>
#include "Printer.h"
using namespace std;

int main() 
{

    srand(time(NULL));
    QueuePriority ex1(10);
    for (int i = 0; i < 8; i++) 
    {
        string worker = " Worker " + to_string(i);
        ex1.Add(rand() % 100, rand() % 15, worker);
    }
    ex1.Show();
    ex1.Extract();
    ex1.Show();
}