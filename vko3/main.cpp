#include <iostream>
#include <memory>
#include "italianchef.h"

using namespace std;

int main()
{
    auto mario = std::make_unique<ItalianChef>("Mario", 10, 20);
    mario->makePasta(100, 200);
}
