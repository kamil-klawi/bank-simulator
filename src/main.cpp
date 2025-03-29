#include <iostream>

#include "../include/User.h"

int main() {
    std::string firstName = "John";
    std::string lastName = "Doe";
    std::string email = "john.doe@example.com";
    int day = 1;
    int month = 1;
    int year = 1999;
    User user(firstName, lastName, email, day, month, year);
    std::cout << User::displayBirthday(day, month, year);

    return 0;
}
