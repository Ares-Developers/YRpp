#pragma once

class Powerups {
	public:
	// all these actually point to arrays with 0x13 items, see ePowerup for their numbering
	/**
	 * e.g. Powerups::Weights[pow_Unit] is the weight of the free unit crate
	 */

	// the name of the effect, for INI reading purposes
	static char ** &Effects;

	// the weight of the effect
	static int * &Weights;

	// the effect-specific argument
	static double * &Arguments;

	// can this crate appear on water?
	static bool * &Naval;

	// index into AnimTypeClass::Array
	static int * &Anims;
};
