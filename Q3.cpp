#include <iostream>
#include <map>

int main() {
    int n;
    std::map<int, int> numbersCount; // Map to store count of each number
    int maxCount = 0, minCount = INT_MAX;
    int mostRepeatedNumber, leastRepeatedNumber;

    std::cout << "Enter numbers between 1 to 9 (Enter 0 to stop):" << std::endl;

    while (true) {
        std::cin >> n;
        
        if (n < 1 || n > 9) {
            if (n == 0) {
                break;
            } else {
                std::cout << "Please enter a number between 1 to 9." << std::endl;
                continue;
            }
        }

        numbersCount[n]++;
    }

    for (auto const& pair : numbersCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostRepeatedNumber = pair.first;
        }

        if (pair.second < minCount) {
            minCount = pair.second;
            leastRepeatedNumber = pair.first;
        }
    }

    std::cout << "Number of occurrences for each number:" << std::endl;
    for (auto const& pair : numbersCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << "Most repeated number: " << mostRepeatedNumber << " (repeated " << maxCount << " times)" << std::endl;
    std::cout << "Least repeated number: " << leastRepeatedNumber << " (repeated " << minCount << " times)" << std::endl;

    return 0;
}