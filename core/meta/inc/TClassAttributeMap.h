// @(#)root/meta:$Id$
// Author: Bianca-Cristina Cristescu   03/07/13

/*************************************************************************
 * Copyright (C) 1995-2013, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT_TClassAttributeMap
#define ROOT_TClassAttributeMap


//////////////////////////////////////////////////////////////////////////
//                                                                      //
// TClassAttributeMap                                                    //
//                                                                      //
// Dictionary of attributes of a TClass.                                //
//                                                                      //
//////////////////////////////////////////////////////////////////////////


#ifndef ROOT_TObject
#include "TObject.h"
#endif
#ifndef ROOT_THashTable
#include "THashTable.h"
#endif


class TClassAttributeMap : public TObject {

private:

   THashTable     fStringProperty; //all properties of String type
   THashTable     fIntProperty; //all properties of Int type

public:

   TClassAttributeMap();
   virtual ~TClassAttributeMap();

   void        AddProperty(const char* key, Int_t value);
   void        AddProperty(const char* key, const char* value);
   Bool_t      HasKey(const char* key) const;
   const char *GetPropertyAsString(const char* key) const;
   Int_t       GetPropertyAsInt(const char* key) const;
   Int_t       GetPropertySize() const;
   Int_t       RemovePropertyInt(const char* key);
   TString     RemovePropertyString(const char* key);
   Bool_t      RemoveProperty(const char* key);
   void        Clear(Option_t* option = "");

   ClassDef(TClassAttributeMap,1) // Container for name/value pairs of TClass attributes
};

#endif // ROOT_TClassAttributeMap


