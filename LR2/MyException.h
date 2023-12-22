#pragma once
#include <iostream>
#include <stdexcept>
class MyException : public std::runtime_error {
public:
    MyException(const std::string& message) : std::runtime_error(message) {}
};