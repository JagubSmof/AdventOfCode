#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> File_Lines_Vector()
{
    std::string line{};
    std::ifstream file("input.txt");
    std::vector<std::string> file_lines{};

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            file_lines.push_back(line);
        }

        file.close();
    }

    return file_lines;
}

std::string Extract_Nums_From_Line(std::string line)
{
    std::string nums {};
    for (int i = 0; i < line.length(); ++i)
    {
        if (int(line[i]) >= 48 && int(line[i]) <= 57)
        {
            nums.push_back(line[i]);
        }
    }

    return nums;
}

std::string Get_First_And_Last_Num(std::string line)
{
    std::string f_and_l {};

    f_and_l.push_back(line[0]);
    f_and_l.push_back(line[line.length() - 1]);

    return f_and_l;
}

int main()
{
    std::vector<std::string> file_lines{File_Lines_Vector()};
    int total{0};
    for (std::string line: file_lines)
    {
        // read only the numbers into a string
        std::string nums_from_line = Extract_Nums_From_Line(line);
        // get first and last numbers from above string
        std::string first_and_last = Get_First_And_Last_Num(nums_from_line);
        // add these numbers to the total
        total += std::stoi(first_and_last);
    }

    std::cout << total << std::endl;

    return 0;
}