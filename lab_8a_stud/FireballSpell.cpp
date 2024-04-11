#include "FireballSpell.h"
int FireballSpell::damage = 6;
void FireballSpell::Cast(Character& caster, Character& target){
        target.TakeDamage(damage);
}
void FireballSpell::Serialize(std::ostream& os) const{
    os << "FireballSpell";
}