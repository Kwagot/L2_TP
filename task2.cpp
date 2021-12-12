#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void task_2(std::ifstream & input) {

    std::string word;
    char letter;

    for (std::string line; std::getline(input,line); ) {

        std::stringstream string_stream(line);
        while (string_stream >> word) {
            if (word.length() > 0) {
                letter = word[0];
                if (letter == 'A' || letter == 'a' ||
                    letter == 'U' || letter == 'u' ||
                    letter == 'E' || letter == 'e' ||
                    letter == 'O' || letter == 'o' ||
                    letter == 'Y' || letter == 'y' ||
                    letter == 'I' || letter == 'i'
                ) {
                    std::cout << word << std::endl;
                }
            }
        }
    }
}
