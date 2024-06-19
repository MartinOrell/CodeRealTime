#ifndef Shield_h
#define Shield_h

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

#endif /* Shield_h */