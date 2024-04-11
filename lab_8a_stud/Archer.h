#pragma once

#include "Character.h"

class Archer : public Character {

protected:
    int arrows_fired_at_once;

public:
    Archer() = delete;
    Archer(const std::string& name, int max_health_points, int arrows_fired_at_once);

    void Attack(Character& character);
    // void Rest(int hours);
    void TakeDamage(int damage);
    //void GetHealed(int heal);
    virtual void write(std::ostream& out) const;
    
};
