#pragma once

#include "Spell.h"

class FireballSpell : public Spell {
	private:
			static int damage;
	virtual void Cast(Character& caster, Character& target);
	virtual void Serialize(std::ostream& os) const;
	//zdefiniuj prywatne sta�e pole statyczne DAMAGE o warto�ci 6

};
