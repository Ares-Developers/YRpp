#pragma once

#include <Helpers/CompileTime.h>

class Powerups {
	public:
	// all these actually point to arrays with 0x13 items, see ePowerup for their numbering
	/**
	 * e.g. Powerups::Weights[pow_Unit] is the weight of the free unit crate
	 */

	// the name of the effect, for INI reading purposes
	static constexpr reference<const char*, 0x7E523Cu, 19u> const Effects{};

	// the weight of the effect
	static constexpr reference<int, 0x81DA8Cu, 19u> const Weights{};

	// the effect-specific argument
	static constexpr reference<double, 0x89EC28u, 19u> const Arguments{};

	// can this crate appear on water?
	static constexpr reference<bool, 0x89ECC0u, 19u> const Naval{};

	// index into AnimTypeClass::Array
	static constexpr reference<int, 0x81DAD8u, 19u> const Anims{};
};
