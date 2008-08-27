#ifndef DCODER_H
#define DCODER_H

// macros DCoder uses and pd dislikes :)

// for exportfuncs, repeating stuff is annoying :P
#define GET(clsname, var, reg) clsname var = (clsname )R->get_ ## reg ();

#define RET_UNLESS(expr) if(!(expr)) { return 0; }
#define RETZ_UNLESS(expr) if(!(expr)) { return ; }

// please don't mix the two hashmaps in one class

// hashmap of pointers
#define EXT_P_DEFINE(clsname) \
	static stdext::hash_map<clsname*, clsname ## Data*> Ext_p; \
	static void __stdcall Create(clsname*);                    \
	static void __stdcall Delete(clsname*);                    \
	static void __stdcall Load(clsname*, IStream*);            \
	static void __stdcall Save(clsname*, IStream*);            \
	static void __stdcall LoadFromINI(clsname*, CCINIClass*);

#define EXT_P_DECLARE(clsname) \
	typedef stdext::hash_map<clsname*, clsname ## Ext::clsname ## Data*> hashext_p; \
	typedef clsname ## Ext::clsname ## Data ExtData;    \
	hashext_p clsname ## Ext :: Ext_p;

// hashmap of structures
#define EXT_V_DEFINE(clsname) \
	static stdext::hash_map<clsname*, clsname ## Data > Ext_v;\
	static void __stdcall Create(clsname*);                   \
	static void __stdcall Delete(clsname*);                   \
	static void __stdcall Load(clsname*, IStream*);           \
	static void __stdcall Save(clsname*, IStream*);           \
	static void __stdcall LoadFromINI(clsname*, CCINIClass*);

#define EXT_V_DECLARE(clsname) \
	typedef stdext::hash_map<clsname*, clsname ## Ext::clsname ## Data > hashext_v; \
	typedef clsname ## Ext::clsname ## Data ExtData;    \
	hashext_v clsname ## Ext :: Ext_v;

#define BIND_CALLBACKS(clsname) \
		clsname ## Callback::Create		=	clsname ## Ext::Create;          \
		clsname ## Callback::Delete		=	clsname ## Ext::Delete;          \
		clsname ## Callback::Load			=	clsname ## Ext::Load;            \
		clsname ## Callback::Save			=	clsname ## Ext::Save;            \
		clsname ## Callback::LoadFromINI	=	clsname ## Ext::LoadFromINI;

// I'm lazy, so sue me
#define CONTAINS(var, ptr) \
	(var.find(ptr) != var.end())

#define ALLOC(clsname, ptr) \
	clsname *ptr = new clsname();

#define DEALLOC(var, ptr) \
	delete var[ptr]; \
	var.erase(var.find(ptr));

#define ARRAY_ITERATE(clsname, pINI) \
	if(clsname ## Callback::LoadFromINI) {                                   \
		for(int i = 0; i < clsname::Array->get_Count(); ++i) {                 \
			clsname ## Callback::LoadFromINI(clsname::Array->GetItem(i), pINI);  \
		} \
	}

#endif
