//
// Created by kamil on 4/2/25.
//

#include <string>
#include <random>

std::string generateIdNumber(int letterCount = 5, int digitsCount = 3) {
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string digits = "0123456789";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> letterDist(0, static_cast<short>(characters.size()) - 1);
    std::uniform_int_distribution<> digitDist(0, static_cast<short>(digits.size()) - 1);
    std::string idNumber;

    for (int i = 0; i < letterCount; i++) {
        const int index = letterDist(gen);
        idNumber += characters[index];
    }

    for (int i = 0; i < digitsCount; i++) {
        const int index = digitDist(gen);
        idNumber += digits[index];
    }

    return idNumber;
}
