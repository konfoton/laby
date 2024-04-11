#pragma once

#include <string>
#include <ostream>

class Character {

protected:
    std::string name;
    int max_health_points;
    int current_health_points;

public:
    Character() = delete;
    Character(const std::string& name, int max_health_points);

    void Attack(Character& character);
    void Rest(int hours);
    virtual void TakeDamage(int damage);
    void GetHealed(int heal);
    virtual void write(std::ostream& out) const;
    friend std::ostream& operator<<(std::ostream& out, const Character& os);
};
