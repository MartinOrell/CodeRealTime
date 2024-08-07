#pragma once

#include <iostream>

class Shield{
    public:
        Shield();
        Shield(int defence, int durability);
        friend std::ostream& operator <<(std::ostream& os, Shield const & shield);
    private:
        int _defence;
        int _durability;
};