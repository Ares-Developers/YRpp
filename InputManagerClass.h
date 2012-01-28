#ifndef INPUTMGR_H
#define INPUTMGR_H

class InputManagerClass {
public:
	static InputManagerClass * &Instance;

	byte DoSomething()
		{ JMP_THIS(0x54F720); }

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

#endif
