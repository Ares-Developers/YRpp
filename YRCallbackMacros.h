#error DEPRECATED

#ifndef CALLBACKMACROS_H
#define CALLBACKMACROS_H

//Implementation of Callbacks of type void, no arguments.
#define CALLBACK_IMPL_XX(clsname,name)\
	EXPORT _ ## clsname ## Callback_ ## name(REGISTERS* R)\
	{\
		if(clsname ## Callback::name)\
			clsname ## Callback::name();\
		return 0;\
	}

//Implementation of Callbacks of type void, this-Pointer as argument.
#define CALLBACK_IMPL_XTHIS(clsname,name,reg)\
	EXPORT _ ## clsname ## Callback_ ## name(REGISTERS* R)\
	{\
		if(clsname ## Callback::name)\
		{\
			clsname * pThis = (clsname *)R->get_ ## reg ();\
			clsname ## Callback::name(pThis);\
		}\
		return 0;\
	}

//Implementation of Callbacks of type void, this-Pointer and Stream-Pointer as arguments.
#define CALLBACK_IMPL_LOADSAVE(clsname,name,stack)\
	EXPORT _ ## clsname ## Callback_ ## name(REGISTERS* R)\
	{\
		if(clsname ## Callback::name)\
		{\
			clsname* pThis = (clsname*)R->get_StackVar32(stack + 0x4); \
			IStream* pStm = (IStream*)R->get_StackVar32(stack + 0x8);\
			clsname ## Callback::name(pThis, pStm);\
		}\
		return 0;\
	}

//Implementation of Callbacks of type void, this-Pointer and CCINI-Pointer as arguments.
#define CALLBACK_IMPL_LOADFROMINI(clsname,name,reg_this,stack)\
	EXPORT _ ## clsname ## Callback_ ## name(REGISTERS* R)\
	{\
		if(clsname ## Callback::name)\
		{\
			clsname * pThis = (clsname *)R->get_ ## reg_this ();\
			CCINIClass* pINI = (CCINIClass*)R->get_StackVar32(stack + 0x4);\
			clsname ## Callback::name(pThis, pINI);\
		}\
		return 0;\
	}

//Implementation of Callbacks of type int, String to parse as argument.
//Return -1 will continue normally. Return any number will jump to return_address.
#define CALLBACK_IMPL_PARSESTRING(clsname,name,reg_str,return_address)\
	EXPORT _ ## clsname ## Callback_ ## name(REGISTERS* R)\
	{\
		if(clsname ## Callback::name)\
		{\
			char* pString=(char*)R->get_ ## reg_str ## ();\
			int nResult=clsname ## Callback::name (pString);\
			if(nResult>=0)\
			{\
				R->set_EAX(nResult);\
				return return_address;\
			}\
		}\
		return 0;\
	}

//Macro for AbstractTypes
#define CALLBACK_HEAD_ABSTRACTTYPE(clsname) \
	static void (_stdcall* Create)(clsname*);\
	static void (_stdcall* Delete)(clsname*);\
	static void (_stdcall* Load)(clsname*,IStream*);\
	static void (_stdcall* Save)(clsname*,IStream*);\
	static void (_stdcall* LoadFromINI)(clsname*,CCINIClass*);

#define CALLBACK_INIT_ABSTRACTTYPE(clsname)\
	void (_stdcall* clsname ## Callback::Create)(clsname*)=NULL;\
	void (_stdcall* clsname ## Callback::Delete)(clsname*)=NULL;\
	void (_stdcall* clsname ## Callback::Load)(clsname*,IStream*)=NULL;\
	void (_stdcall* clsname ## Callback::Save)(clsname*,IStream*)=NULL;\
	void (_stdcall* clsname ## Callback::LoadFromINI)(clsname*,CCINIClass*)=NULL;

#define CALLBACK_IMPL_ABSTRACTTYPE(clsname,ini_reg,ini_stack,load_stack,save_stack)\
	CALLBACK_IMPL_XTHIS(clsname,Create,EAX);\
	CALLBACK_IMPL_XTHIS(clsname,Delete,ECX);\
	CALLBACK_IMPL_LOADSAVE(clsname,Load,load_stack);\
	CALLBACK_IMPL_LOADSAVE(clsname,Save,save_stack);\
	CALLBACK_IMPL_LOADFROMINI(clsname,LoadFromINI,ini_reg,ini_stack);

// for Object
#define CALLBACK_HEAD_OBJECT(clsname) \
	static void (_stdcall* Create)(clsname*);\
	static void (_stdcall* Delete)(clsname*);\
	static void (_stdcall* Load)(clsname*,IStream*);\
	static void (_stdcall* Save)(clsname*,IStream*);

#define CALLBACK_INIT_OBJECT(clsname)\
	void (_stdcall* clsname ## Callback::Create)(clsname*)=NULL;\
	void (_stdcall* clsname ## Callback::Delete)(clsname*)=NULL;\
	void (_stdcall* clsname ## Callback::Load)(clsname*,IStream*)=NULL;\
	void (_stdcall* clsname ## Callback::Save)(clsname*,IStream*)=NULL;

#define CALLBACK_IMPL_OBJECT(clsname,load_stack,save_stack)\
	CALLBACK_IMPL_XTHIS(clsname,Create,EAX);\
	CALLBACK_IMPL_XTHIS(clsname,Delete,ECX);\
	CALLBACK_IMPL_LOADSAVE(clsname,Load,load_stack);\
	CALLBACK_IMPL_LOADSAVE(clsname,Save,save_stack);


#endif
