#pragma once

#include <GameOptionsClass.h>

class InputManagerClass {
public:
	static InputManagerClass * &Instance;

	byte DoSomething()
		{ JMP_THIS(0x54F720); }

	bool IsKeyPressed(int key) const
		{ JMP_THIS(0x54F5C0); }

	bool IsForceFireKeyPressed() const {
		return this->IsKeyPressed(GameOptionsClass::Instance->KeyForceFire1)
			|| this->IsKeyPressed(GameOptionsClass::Instance->KeyForceFire2);
	}

	bool IsForceMoveKeyPressed() const {
		return this->IsKeyPressed(GameOptionsClass::Instance->KeyForceMove1)
			|| this->IsKeyPressed(GameOptionsClass::Instance->KeyForceMove2);
	}

	bool IsForceSelectKeyPressed() const {
		return this->IsKeyPressed(GameOptionsClass::Instance->KeyForceSelect1)
			|| this->IsKeyPressed(GameOptionsClass::Instance->KeyForceSelect2);
	}

protected:
  int field_0;
  int field_4;
  int field_8;
  int field_C;
  int field_10;
  byte Keycodes_b[256];
  WORD Keycodes_w[256];
  int field_314;
  int field_318;
};
