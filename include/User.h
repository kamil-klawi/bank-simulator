//
// Created by kamil on 3/29/25.
//

#ifndef USER_H
#define USER_H

#include <chrono>
#include <string>

using DateTime = std::chrono::year_month_day;
using Year = std::chrono::year;
using Month = std::chrono::month;
using Day = std::chrono::day;

class User {
public:
    User(
        std::string& idNumber,
        std::string& firstName,
        std::string& lastName,
        std::string& email,
        int day,
        int month,
        int year
        ) : idNumber(idNumber), firstName(firstName), lastName(lastName), email(email), birthday(day, month, year) {}
    DateTime getBirthday() const;
    std::string getIdNumber() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmail() const;
    void setIdNumber(const std::string& idNumber);
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setEmail(const std::string& email);
    void setBirthday(int day, int month, int year);
private:
    std::string idNumber;
    std::string firstName;
    std::string lastName;
    std::string email;
    struct Date {
        int year;
        int month;
        int day;
        Date(int d, int m, int y) : day(d), month(m), year(y) {}
    };
    Date birthday;
};

#endif //USER_H
