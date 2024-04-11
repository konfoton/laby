#include "Wizard.h"
void Wizard::Rest(int hours){
    Character::GetHealed(hours);
    if(prepared_spells < spell_slots){
    if(hours % 2 == 0){
        FireballSpell* temp = new FireballSpell;
        spells[prepared_spells] = temp;
    } else {
        DrainLifeSpell* temp = new DrainLifeSpell;
        spells[prepared_spells] = temp;
    }
    prepared_spells += 1;
    }
}
Wizard::Wizard(const std::string& name, int max_health_points, int spell_slots) : Character(name, max_health_points){
    spells = new Spell*[spell_slots];
    this->spell_slots = spell_slots;
    this->prepared_spells = 0;
    for(int i = 0; i < spell_slots; i++){
        spells[i] = nullptr;
    }
}
void Wizard::Attack(Character& character){
    if(prepared_spells > 0){
        spells[prepared_spells-1]->Cast(*this, character);
        delete spells[prepared_spells-1];
        spells[prepared_spells-1] = nullptr;
        prepared_spells -= 1;
    } else {
        Character::Attack(character);
    }
}
void Wizard::write(std::ostream& out) const{
    Character::write(out);
    out << "-class Wizard Prepared spells: ";
    for(int i = 0; i < prepared_spells; i++){
        out << *spells[i] << " ";
    }
}