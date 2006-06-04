/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPARTICLESDATA_H_
#define _NIPARTICLESDATA_H_

#include "NiAutoNormalParticlesData.h"

#include "gen/obj_defines.h"

class NiParticlesData;
typedef Ref<NiParticlesData> NiParticlesDataRef;

/*!
 * NiParticlesData - Generic rotating particles data block.
 */

class NiParticlesData : public NI_PARTICLES_DATA_PARENT {
public:
	NiParticlesData();
	~NiParticlesData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_PARTICLES_DATA_MEMBERS
};

#endif
