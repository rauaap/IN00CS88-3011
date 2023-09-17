#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include "chef.h"

class ItalianChef: public Chef
{
public:
    ItalianChef(std::string, int, int);
    std::string getName();
    void makePasta(int, int);
private:
    int flourAmount;
    int waterAmount;
};

#endif // ITALIANCHEF_H
