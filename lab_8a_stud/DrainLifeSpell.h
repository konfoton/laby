#pragma once
#include "Spell.h"
class DrainLifeSpell : public Spell {
    private:
            static int damage;
            static int healing;
    virtual void Cast(Character& caster, Character& target);
    virtual void Serialize(std::ostream& os) const;
    //zdefiniuj prywatne sta�e pole statyczne DAMAGE o warto�ci 3
	//zdefiniuj prywatne sta�e pole statyczne HEALING o warto�ci 3
	

};
