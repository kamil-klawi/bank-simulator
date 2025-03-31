//
// Created by kamil on 3/29/25.
//

#include "../include/User.h"

DateTime User::getBirthday() const {
    return Year(this->birthday.year) / Month(this->birthday.month) / Day(this->birthday.day);
}

std::string User::getIdNumber() const {
    return idNumber;
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

void User::setIdNumber(const std::string& idNumber) {
    this->idNumber = idNumber;
}

void User::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

void User::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void User::setEmail(const std::string& email) {
    this->email = email;
}

void User::setBirthday(int day, int month, int year) {
    this->birthday = {day, month, year};
}
