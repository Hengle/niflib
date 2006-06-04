/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _AKEYEDDATA_H_
#define _AKEYEDDATA_H_

#include "NiObject.h"

#include "gen/obj_defines.h"

class AKeyedData;
typedef Ref<AKeyedData> AKeyedDataRef;

/*!
 * AKeyedData - Single items of data linked to particular key times.
 */

class AKeyedData : public A_KEYED_DATA_PARENT {
public:
	AKeyedData();
	~AKeyedData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	A_KEYED_DATA_MEMBERS
};

#endif
