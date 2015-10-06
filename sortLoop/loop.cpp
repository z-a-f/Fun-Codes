#include <algorithm>
#include <ctime>
#include <iostream>

void sorted() {
    // Generate data
    const unsigned arraySize = 32768;
    int data[arraySize];

    for (unsigned c = 0; c < arraySize; ++c)
        data[c] = std::rand() % 256;
	
    clock_t sortStart = clock();
    // std::sort(data, data + arraySize);
    std::cout << "Sorting time: " << static_cast<double>(clock() - sortStart) / CLOCKS_PER_SEC << std::endl;
		
		
    // Test
    clock_t start = clock();
    long long sum = 0;
    std::sort(data, data + arraySize);
    for (unsigned i = 0; i < 100000; ++i)
    {
        // Primary loop
        for (unsigned c = 0; c < arraySize; ++c)
        {
            if (data[c] >= 128)
                sum += data[c];
        }
    }

    double elapsedTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
	
    std::cout << "Sorted time = ";
    std::cout << elapsedTime << std::endl;
    std::cout << "sum = " << sum << std::endl;
}

void unsorted() {
    // Generate data
    const unsigned arraySize = 32768;
    int data[arraySize];

    for (unsigned c = 0; c < arraySize; ++c)
        data[c] = std::rand() % 256;

    // std::sort(data, data + arraySize);

    // Test
    clock_t start = clock();
    long long sum = 0;

    for (unsigned i = 0; i < 100000; ++i)
    {
        // Primary loop
        for (unsigned c = 0; c < arraySize; ++c)
        {
            if (data[c] >= 128)
                sum += data[c];
        }
    }

    double elapsedTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
	
    std::cout << "Unsorted time = ";
    std::cout << elapsedTime << std::endl;
    std::cout << "sum = " << sum << std::endl;
}



int main() {
    // unsorted();
    sorted();
}
