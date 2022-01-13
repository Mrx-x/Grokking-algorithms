#include <iostream>
#include <stdint.h>
#include <vector>
#include <stdlib.h>


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
    std::vector<int> arr(100);
    for(std::vector<int>::iterator i = arr.begin(); i < arr.end(); ++i)
    {
        *i = j;
        ++j;
    }
    int pos = binary_search(arr, atol(argv[1]));

    if(pos != -1) std::cout << "Element position = [" << pos << "]\n"; 

    return 0;
}