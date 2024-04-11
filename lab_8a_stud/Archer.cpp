#include "Archer.h"
Archer::Archer(const std::string& name, int max_health_points, int arrows_fired_at_once) : Character(name, max_health_points){
    this->arrows_fired_at_once = arrows_fired_at_once;
}

void Archer::Attack(Character& character){
    character.TakeDamage(arrows_fired_at_once * 2);
}
void Archer::TakeDamage(int damage){
    Character::TakeDamage(2 * damage);
}
void Archer::write(std::ostream& out) const{
    Character::write(out);
    out << "- class: Archer";
}