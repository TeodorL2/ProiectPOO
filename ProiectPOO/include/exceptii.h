#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <iostream>
#include <exception>

class problema_imcarcare_fereastra : public std::runtime_error
{
public:
    problema_imcarcare_fereastra(const std::string& mesaj="");
};

class forma_necunoscuta : public std::runtime_error
{
public:
    forma_necunoscuta(const std::string& mesaj="");
};


#endif // EXCEPTII_H
