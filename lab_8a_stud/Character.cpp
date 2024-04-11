#include "Character.h"
Character::Character(const std::string& name, int max_health_points){
    this->name = name;
    this->max_health_points = max_health_points;
    this->current_health_points = max_health_points;
}

void Character::Attack(Character& character){
    if(current_health_points > 0){
    character.TakeDamage(2);
    }
}
void Character::Rest(int hours){
    if(hours + current_health_points <= max_health_points){
        current_health_points += hours;
    } else{
        current_health_points = max_health_points;
    }
}
void Character::TakeDamage(int damage){
    if(current_health_points - damage >= 0){
        current_health_points -= damage;
    } else {
        current_health_points = 0;
    }
}
void Character::GetHealed(int heal){
    if(heal + current_health_points <= max_health_points){
        current_health_points += heal;
    } else{
        current_health_points = max_health_points;
    }
}
void Character::write(std::ostream& out) const{
    out << this->name << "(HP: " << this->current_health_points << "/" << this->max_health_points << ")";
}
std::ostream& operator<<(std::ostream& out, const Character& os){
     os.write(out);
     return out; 
}