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

#define PROPERTY_PTR(type,name)\
	protected:\
		type name;\
	public:\
		type get_ ## name() \
			{ return name; }\
		void set_ ## name(type value)\
			{ name = value; } \
		type* lea_ ## name() \
			{ return &name; }

//readonly version
#define PROPERTY_READONLY(type,name)\
	protected:\
		type name;\
	public:\
		const type get_ ## name() \
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

//readonly
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

//Operation: The Cleansing
#define R0 {return 0;}
#define RX {}

// following westwood's style
#define VALIDTAG(str) \
	(strcmpi("<none>", str) && strcmpi("none", str))

#endif
