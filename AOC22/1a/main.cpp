#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::ifstream file ("input.txt");
    std::string line {};

    int total = 0;
    int max = 0;

    while (std::getline(file, line))
    {
        if (line.size() == 0)
        {
            max = std::max(max, total);
            total = 0;
        } else {
            total += std::stoi(line);
        }
    }

    max = std::max(max, total);

    std::cout << max << "\n";

    return max;
}