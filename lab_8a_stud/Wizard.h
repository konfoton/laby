#pragma once

#include <ostream>
#include "Character.h"
#include "FireballSpell.h"
#include "DrainLifeSpell.h"
#include "Spell.h"
class Spell;

class Wizard : public Character {

protected:
    Spell** spells;
    int spell_slots;
    int prepared_spells;

public:
    Wizard() = delete;
    Wizard(const Wizard& wizard) = delete;
    Wizard& operator=(const Wizard& wizard) = delete;

    Wizard(const std::string& name, int max_health_points, int spell_slots);

    void Attack(Character& character);
    void Rest(int hours);
    virtual void write(std::ostream& out) const;
    //void TakeDamage(int damage);
    //void GetHealed(int heal);
   
};
