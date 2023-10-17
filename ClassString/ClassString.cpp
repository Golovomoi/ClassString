#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "headers/AwsomeString.h"

int main()
{
    std::cout << "Введите число строк: " << std::endl;
    int n;
    std::cin >> n;
    std::cout << "введите " << n << " строк разделяя их клавишей enter" << std::endl;
    
    std::vector<AwsomeString> ansVector;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (auto i = 0; i < n; i++) {
        AwsomeString tmp;
        
        std::cin >> tmp;
        ansVector.emplace_back(std::move(tmp));
    }

    std::sort(ansVector.begin(), ansVector.end(), [](AwsomeString& first, AwsomeString& second) -> bool
        {
            return !(first < second);
        }
    );
    std::cout << "строки отсортированные в порядке, обратном лексикографическому: " << std::endl;

    for (auto i : ansVector)
    {
        std::cout << i << std::endl;
    }

}
