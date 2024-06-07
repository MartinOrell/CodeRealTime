#include "Shield.h"

Shield::Shield()
    : Shield::Shield(0,1){}

Shield::Shield(int defence, int durability)
    : _defence(defence), _durability(durability){}

std::ostream& operator<<(std::ostream& os, Shield const & shield){
    os << "(Defence: " << shield._defence << ", Durability: " << shield._durability << ")";
    return os;
}