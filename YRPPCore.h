//strcpy is "unsafe"? wtf?
// DC: yeah, no length limit so char foo[3]; strcpy(foo, "roflcakes") works and smashes stack
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef YRPPCore_H
#define YRPPCore_H

//Syringe interaction header - also includes <windows.h>
#include <Syringe.h>

//Assembly macros
#include <ASMMacros.h>

#include <wchar.h>

//Macro for class members with getters and setters! Thanks DCoder!
#define PROPERTY(type,name)\
	protected:\
		type name;\
	public:\
		type get_ ## name() \
			{ return name; }\
		void set_ ## name(type value)\
			{ name = value; }

//readonly version
#define PROPERTY_READO(type,name)\
	protected:\
		type name;\
	public:\
		const type _ ## name() \
			{ return name; }

//struct or class instances
#define PROPERTY_STRUCT(type,name)\
	protected:\
		type name;\
	public:\
		type* get_ ## name() \
			{ return &name; }\
		void set_ ## name(type value)\
			{ name = value; }

//readonly //huh? -pd // not really necessary, just nitpicking since I don't like exposing raw data to the world 
// (I was using it on shield types, but I can discard it if it's unnecessary)
#define PROPERTY_READO_STRUCT(type,name)\
	protected:\
		type name;\
	public:\
		type* _ ## name() \
			{ return &name; } \
		type q_ ## name()\
			{ return name; }

//Arrays
#define PROPERTY_ARRAY(type,name,length)\
	protected:\
		type name[length];\
	public:\
		type get_ ## name(int n)\
			{ return name[n]; }\
		void set_ ## name(int n, type value)\
			{ name[n] = value; }

//Arrays of struct or class instances
#define PROPERTY_STRUCT_ARRAY(type,name,length)\
	protected:\
		type name[length];\
	public:\
		type* get_ ## name(int n)\
			{ return &name[n]; }\
		void set_ ## name(int n, type value)\
			{ name[n] = value; }

//Strings
#define PROPERTY_STRING(name,length)\
	protected:\
		char name[length];\
	public:\
		char* get_ ## name()\
			{ return name; }\
		void  set_ ## name(const char* value)\
			{ strncpy(name, value, length); }

#define PROPERTY_UNICODE(name,length)\
	protected:\
		wchar_t name[length];\
	public:\
		wchar_t* get_ ## name()\
			{ return name; }\
		void  set_ ## name(const wchar_t* value)\
			{ wcsncpy(name, value, length); }

//Not gettable/settable members
#define PROTECTED_PROPERTY(type,name)\
	protected:\
		type name;

// following westwood's style
#define VALIDTAG(str) \
	(strcmpi("<none>", str) && strcmpi("none", str))

#endif
