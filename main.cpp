#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <vector>

int lineValues(char first, char last)
{
    //char lineChar[2] = {first, last};
    //std::string strLine = lineChar;
    std::array<char,2> lineNums{first, last};  // import the characters into an integer array
    int lineValue = ((lineNums[0]-48)*10 + (lineNums[1]-48));

    return lineValue;
}

int main()
{
    char first_n;
    char last_n;
    std::ifstream inputTxt("scratch.txt");  // declaring input file
    std::string line;
    std::regex find_int("[0-9]+");
    std::smatch submatch_line;  // sub-match
    int added_lines = 0;

    while (std::getline(inputTxt, line))
    {
        // std::cout << line << std::endl;
        int i = 0;
        std::vector<char> num_line{};

        while (i < line.length())
        {
            if (line[i] >= '0' && line[i] <= '9')
            {
                num_line.push_back(line[i]);
                // std::cout << line[i] << std::endl;
            }
            i++;
        }

        first_n = num_line[0];
        std::cout << "first num: " << num_line[0] << std::endl;
        int line_sum;
        last_n = num_line.back();
        std::cout << "last num: " << num_line.back() << std::endl;
        line_sum = lineValues(first_n, last_n);
        /*
        if (num_line.size() > 1)
        {
            last_n = num_line.back();
            std::cout << "last num: " << num_line.back() << std::endl;
            line_sum = lineValues(first_n, last_n);
        } else
        {
            line_sum = first_n - 48;
        }
         */
        std::cout << "concatenated chars as one int: " << line_sum << std::endl;

        added_lines += line_sum;
    }
    std::cout << added_lines << std::endl;

    return 0;
}
