#include "Evade.h"
#include "Character.h"

Evade::Evade(Character* target, unsigned short nbr_of_rounds, bool is_applicable_at_every_turn, bool is_temporary, unsigned int effect_level):
	Effect(target, nbr_of_rounds, is_applicable_at_every_turn, is_temporary, effect_level)
{}

Evade::~Evade()
{
	if (_is_temporary)	//si l'effet �tait temporaire, on l'annule
	{
		if (_is_applicable_at_every_turn)	//si il s'appliquait � chaque tour, on enl�ve tous les effets accumul�s
			_target->subtractEvade(_effect_level * _initial_nbr_of_rounds);
		else								//sinon, on enl�ve l'effet
			_target->subtractEvade(_effect_level);
	}
}

void Evade::apply()
{
	if ((!_is_applicable_at_every_turn && !_is_first_turn_passed) || _is_applicable_at_every_turn) //si l'effet n'est applicable qu'au 1er tour et qu'on est au 1er tour OU que l'effet s'applique � chaque tour
	{
		if (!_is_first_turn_passed) //si on est au 1er tour
			_is_first_turn_passed = true;

		_target->addEvade(_effect_level);
	}
}
