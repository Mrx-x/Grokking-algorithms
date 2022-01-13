#include <iostream>
#include <vector>
#include <cstdlib>

void SelectSort(std::vector<int> &arr)
{
    int temp;
    for(size_t i = 1; i < arr.size(); ++i)
    {
        for(size_t j = i; j > 0 && arr[j-1] > arr[j]; --j)
        {
            temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
        }
    }
}

int main()
{
    srand(time(NULL));
    clock_t start, stop;
    double time;

    std::vector<int> arr(10);
    for(std::vector<int>::iterator i = arr.begin(); i < arr.end(); ++i)
    {
        *i = 1 + rand() % 100;
        std::cout << *i << "|";
    }

    start = clock();
    SelectSort(arr);
    stop = clock();
    time = ((double)(stop - start)) / CLOCKS_PER_SEC;

    std::cout << "\n\n|SelectSort|\n\n";
    for(std::vector<int>::iterator i = arr.begin(); i < arr.end(); ++i)
    {
        std::cout << *i << "|";
    }

    std::cout << "\n\nLead time = [" << time << "]\n";

    return 0;    
}