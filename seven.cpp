#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    try {
        std::ifstream inputFile("input.txt");
        if (!inputFile.is_open()) {
            throw std::runtime_error("Cannot open input file.");
        }

        std::vector<int> numbers;
        int num;
        while (inputFile >> num) {
            numbers.push_back(num);
        }

        inputFile.close();

        std::set<int> digitSet;

        for (int number : numbers) {
            while (number > 0) {
                digitSet.insert(number % 10);
                number /= 10;
            }
        }

        for (int number : numbers) {
            if (number >= 10 && number < 100) {
                while (number > 0) {
                    digitSet.erase(number % 10);
                    number /= 10;
                }
            }
        }

        for (int digit : digitSet) {
            std::cout << digit << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    int a;
    std::cin >> a;
    return 0;
}
