/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _BSSHADERPROPERTY_H_
#define _BSSHADERPROPERTY_H_

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "NiObject.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiExtraData;
class NiTimeController;
class BSShaderProperty;
typedef Ref<BSShaderProperty> BSShaderPropertyRef;

/*! Bethesda-specific Property node */
class BSShaderProperty : public NiObject {
public:
	/*! Constructor */
	NIFLIB_API BSShaderProperty();

	/*! Destructor */
	NIFLIB_API virtual ~BSShaderProperty();

	/*!
	 * A constant value which uniquly identifies objects of this type.
	 */
	NIFLIB_API static const Type TYPE;

	/*!
	 * A factory function used during file reading to create an instance of this type of object.
	 * \return A pointer to a newly allocated instance of this type of object.
	 */
	NIFLIB_API static NiObject * Create();

	/*!
	 * Summarizes the information contained in this object in English.
	 * \param[in] verbose Determines whether or not detailed information about large areas of data will be printed out.
	 * \return A string containing a summary of the information within the object in English.  This is the function that Niflyze calls to generate its analysis, so the output is the same.
	 */
	NIFLIB_API virtual string asString( bool verbose = false ) const;

	/*!
	 * Used to determine the type of a particular instance of this object.
	 * \return The type constant for the actual type of the object.
	 */
	NIFLIB_API virtual const Type & GetType() const;

	//--BEGIN MISC CUSTOM CODE--//


   // Unknown
   // \return The current value.
   unsigned short GetFlags() const;

   // Unknown
   // \param[in] value The new value.
   void SetFlags( unsigned short value );

   // Unknown (Set to 0x21 for NoLighting, 0x11 for Water)
   // \return The current value.
   BSShaderType GetShaderType() const;

   // Unknown (Set to 0x21 for NoLighting, 0x11 for Water)
   // \param[in] value The new value.
   void SetShaderType( const BSShaderType & value );

   // Shader Property Flags
   // \return The current value.
   BSShaderFlags GetShaderFlags() const;

   // Shader Property Flags
   // \param[in] value The new value.
   void SetShaderFlags( const BSShaderFlags & value );

   // Unknown
   // \return The current value.
   float GetEnvmapScale() const;

   // Unknown
   // \param[in] value The new value.
   void SetEnvmapScale( float value );

	//--END CUSTOM CODE--//
protected:
	/*! Unknown */
	unsigned int unknownFlag;
	/*! Object Name */
	IndexString name;
	/*! Extra data object index. (The first in a chain) */
	Ref<NiExtraData > extraData;
	/*! The number of Extra Data objects referenced through the list. */
	mutable unsigned int numExtraDataList;
	/*! List of extra data indices. */
	vector<Ref<NiExtraData > > extraDataList;
	/*! Controller object index. (The first in a chain) */
	Ref<NiTimeController > controller;
	/*! Unknown */
	unsigned short flags;
	/*! Unknown (Set to 0x21 for NoLighting, 0x11 for Water) */
	BSShaderType shaderType;
	/*! Shader Property Flags */
	BSShaderFlags shaderFlags;
	/*! Unknown */
	unsigned short unknownShort1;
	/*! Unknown */
	int unknownInt2;
	/*! Unknown */
	float envmapScale;
public:
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObject *> GetPtrs() const;
};

//--BEGIN FILE FOOT CUSTOM CODE--//

//--END CUSTOM CODE--//

} //End Niflib namespace
#endif
