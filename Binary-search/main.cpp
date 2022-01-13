#include <iostream>
#include <stdint.h>
#include <vector>
#include <stdlib.h>
#include <time.h>


int binary_search(const std::vector<int> &array,const int &item)
{
    int low = 0;
    int high = array.size() - 1;
    int mid;
    int guess;

    while(low <= high)
    {
        mid = (low + high) / 2;
        guess = array[mid];
        if(guess == item) return mid;
        if(guess > item) high = mid - 1;
        else 
            low = mid + 1;
    }
    std::cout << "Element missing\n";
    return -1;
}

int main(int argc, char* argv[])
{
    size_t j = 1;
    std::vector<int> arr(1000000);
    clock_t start, stop;
    double time;

    for(std::vector<int>::iterator i = arr.begin(); i < arr.end(); ++i)
    {
        *i = j;
        ++j;
    }

    start = clock();
    int pos = binary_search(arr, atol(argv[1]));
    stop = clock();

    if(pos != -1) std::cout << "Element position = [" << pos << "]\n"; 

    time = ((double)(stop - start)) / CLOCKS_PER_SEC;
    std::cout << "Lead time  = [" << time << "]\n";

    return 0;
}