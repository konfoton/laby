#include "DrainLifeSpell.h"
int DrainLifeSpell::damage = 3;
int DrainLifeSpell::healing = 3;
void DrainLifeSpell::Cast(Character& caster, Character& target){
        target.TakeDamage(damage);
        caster.GetHealed(healing);
}
void DrainLifeSpell::Serialize(std::ostream& os) const{
    os << "DrainLifeSpell";
}