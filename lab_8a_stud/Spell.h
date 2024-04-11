#pragma once
#include "Character.h"
#include <ostream>

class Character;
class Spell {

public:
    virtual ~Spell() = default;
    virtual void Cast(Character& caster, Character& target) = 0;
    friend std::ostream& operator<<(std::ostream& os, const Spell& spell);
    friend class Character;

protected:
    virtual void Serialize(std::ostream& os) const = 0;
};
