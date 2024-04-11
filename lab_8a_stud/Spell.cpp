#include "Spell.h"

std::ostream& operator<<(std::ostream& os, const Spell& spell) {
    spell.Serialize(os);
    return os;
}
