//
// Created by kamil on 3/29/25.
//

#include "../include/User.h"

DateTime User::displayBirthday(int day, int month, int year) {
    return Year(year) / Month(month) / Day(day);
}

std::string User::getFirstName() const {
    return firstName;
}

std::string User::getLastName() const {
    return lastName;
}

std::string User::getEmail() const {
    return email;
}
