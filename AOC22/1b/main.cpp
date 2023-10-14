#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::ifstream file ("../1a/input.txt");
    std::string line {};

    int total = 0;
    int max = 0;
    std::vector<int> lines {};

    while (std::getline(file, line))
    {
        if (line.size() == 0)
        {
            max = std::max(max, total);
            lines.push_back(total);
            total = 0;
        } else {
            total += std::stoi(line);
        }
    }

    max = std::max(max, total);

    std::sort(lines.begin(), lines.end());
    std::reverse(lines.begin(), lines.end());

    total = lines[0];
    total += lines[1];
    total += lines[2];

    std::cout << total << "\n";

    return total;
}