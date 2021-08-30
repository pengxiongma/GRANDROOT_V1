// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME SimEventDict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "SimEfield.h"
#include "SimSignal.h"
#include "SimShower.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_SimEfield(void *p = 0);
   static void *newArray_SimEfield(Long_t size, void *p);
   static void delete_SimEfield(void *p);
   static void deleteArray_SimEfield(void *p);
   static void destruct_SimEfield(void *p);
   static void streamer_SimEfield(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SimEfield*)
   {
      ::SimEfield *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::SimEfield >(0);
      static ::ROOT::TGenericClassInfo 
         instance("SimEfield", ::SimEfield::Class_Version(), "SimEfield.h", 16,
                  typeid(::SimEfield), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::SimEfield::Dictionary, isa_proxy, 16,
                  sizeof(::SimEfield) );
      instance.SetNew(&new_SimEfield);
      instance.SetNewArray(&newArray_SimEfield);
      instance.SetDelete(&delete_SimEfield);
      instance.SetDeleteArray(&deleteArray_SimEfield);
      instance.SetDestructor(&destruct_SimEfield);
      instance.SetStreamerFunc(&streamer_SimEfield);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SimEfield*)
   {
      return GenerateInitInstanceLocal((::SimEfield*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SimEfield*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_SimSignal(void *p = 0);
   static void *newArray_SimSignal(Long_t size, void *p);
   static void delete_SimSignal(void *p);
   static void deleteArray_SimSignal(void *p);
   static void destruct_SimSignal(void *p);
   static void streamer_SimSignal(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SimSignal*)
   {
      ::SimSignal *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::SimSignal >(0);
      static ::ROOT::TGenericClassInfo 
         instance("SimSignal", ::SimSignal::Class_Version(), "SimSignal.h", 16,
                  typeid(::SimSignal), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::SimSignal::Dictionary, isa_proxy, 16,
                  sizeof(::SimSignal) );
      instance.SetNew(&new_SimSignal);
      instance.SetNewArray(&newArray_SimSignal);
      instance.SetDelete(&delete_SimSignal);
      instance.SetDeleteArray(&deleteArray_SimSignal);
      instance.SetDestructor(&destruct_SimSignal);
      instance.SetStreamerFunc(&streamer_SimSignal);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SimSignal*)
   {
      return GenerateInitInstanceLocal((::SimSignal*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SimSignal*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_SimShower(void *p = 0);
   static void *newArray_SimShower(Long_t size, void *p);
   static void delete_SimShower(void *p);
   static void deleteArray_SimShower(void *p);
   static void destruct_SimShower(void *p);
   static void streamer_SimShower(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SimShower*)
   {
      ::SimShower *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::SimShower >(0);
      static ::ROOT::TGenericClassInfo 
         instance("SimShower", ::SimShower::Class_Version(), "SimShower.h", 16,
                  typeid(::SimShower), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::SimShower::Dictionary, isa_proxy, 16,
                  sizeof(::SimShower) );
      instance.SetNew(&new_SimShower);
      instance.SetNewArray(&newArray_SimShower);
      instance.SetDelete(&delete_SimShower);
      instance.SetDeleteArray(&deleteArray_SimShower);
      instance.SetDestructor(&destruct_SimShower);
      instance.SetStreamerFunc(&streamer_SimShower);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SimShower*)
   {
      return GenerateInitInstanceLocal((::SimShower*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SimShower*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr SimEfield::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *SimEfield::Class_Name()
{
   return "SimEfield";
}

//______________________________________________________________________________
const char *SimEfield::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SimEfield*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int SimEfield::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SimEfield*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SimEfield::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SimEfield*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SimEfield::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SimEfield*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr SimSignal::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *SimSignal::Class_Name()
{
   return "SimSignal";
}

//______________________________________________________________________________
const char *SimSignal::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SimSignal*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int SimSignal::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SimSignal*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SimSignal::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SimSignal*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SimSignal::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SimSignal*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr SimShower::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *SimShower::Class_Name()
{
   return "SimShower";
}

//______________________________________________________________________________
const char *SimShower::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SimShower*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int SimShower::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SimShower*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SimShower::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SimShower*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SimShower::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SimShower*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void SimEfield::Streamer(TBuffer &R__b)
{
   // Stream an object of class SimEfield.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> run_id;
      R__b >> evt_id;
      {
         vector<string> &R__stl =  field_sim;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            string R__t;
            {TString R__str;
             R__str.Streamer(R__b);
             R__t = R__str.Data();}
            R__stl.push_back(R__t);
         }
      }
      {
         vector<string> &R__stl =  refractivity_model;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            string R__t;
            {TString R__str;
             R__str.Streamer(R__b);
             R__t = R__str.Data();}
            R__stl.push_back(R__t);
         }
      }
      R__b >> refractivity_param1;
      R__b >> refractivity_param2;
      R__b >> t_pre;
      R__b >> t_post;
      R__b >> t_bin_size;
      {
         vector<int> &R__stl =  Detectors_det_id;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            int R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<vector<string> > &R__stl =  Detectors_det_type;
         R__stl.clear();
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class std::vector<class std::__cxx11::basic_string<char>, class std::allocator<class std::__cxx11::basic_string<char> > >));
         if (R__tcl1==0) {
            Error("Detectors_det_type streamer","Missing the TClass object for class std::vector<class std::__cxx11::basic_string<char>, class std::allocator<class std::__cxx11::basic_string<char> > >!");
            return;
         }
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            vector<string> R__t;
            R__b.StreamObject(&R__t,R__tcl1);
            R__stl.push_back(R__t);
         }
      }
      {
         vector<vector<float> > &R__stl =  Detectors_det_pos_shc;
         R__stl.clear();
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class std::vector<float, class std::allocator<float> >));
         if (R__tcl1==0) {
            Error("Detectors_det_pos_shc streamer","Missing the TClass object for class std::vector<float, class std::allocator<float> >!");
            return;
         }
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            vector<float> R__t;
            R__b.StreamObject(&R__t,R__tcl1);
            R__stl.push_back(R__t);
         }
      }
      {
         vector<float> &R__stl =  Detectors_t_0;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            float R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<float> &R__stl =  Detectors_p2p;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            float R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<vector<TVector3> > &R__stl =  Detectors_trace;
         R__stl.clear();
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class std::vector<class TVector3, class std::allocator<class TVector3> >));
         if (R__tcl1==0) {
            Error("Detectors_trace streamer","Missing the TClass object for class std::vector<class TVector3, class std::allocator<class TVector3> >!");
            return;
         }
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            vector<TVector3> R__t;
            R__b.StreamObject(&R__t,R__tcl1);
            R__stl.push_back(R__t);
         }
      }
      R__b.CheckByteCount(R__s, R__c, SimEfield::IsA());
   } else {
      R__c = R__b.WriteVersion(SimEfield::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << run_id;
      R__b << evt_id;
      {
         vector<string> &R__stl =  field_sim;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<string>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            {TString R__str((*R__k).c_str());
             R__str.Streamer(R__b);};
            }
         }
      }
      {
         vector<string> &R__stl =  refractivity_model;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<string>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            {TString R__str((*R__k).c_str());
             R__str.Streamer(R__b);};
            }
         }
      }
      R__b << refractivity_param1;
      R__b << refractivity_param2;
      R__b << t_pre;
      R__b << t_post;
      R__b << t_bin_size;
      {
         vector<int> &R__stl =  Detectors_det_id;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<int>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<vector<string> > &R__stl =  Detectors_det_type;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class std::vector<class std::__cxx11::basic_string<char>, class std::allocator<class std::__cxx11::basic_string<char> > >));
         if (R__tcl1==0) {
            Error("Detectors_det_type streamer","Missing the TClass object for class std::vector<class std::__cxx11::basic_string<char>, class std::allocator<class std::__cxx11::basic_string<char> > >!");
            return;
         }
            vector<vector<string> >::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b.StreamObject((vector<string>*)&(*R__k),R__tcl1);
            }
         }
      }
      {
         vector<vector<float> > &R__stl =  Detectors_det_pos_shc;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class std::vector<float, class std::allocator<float> >));
         if (R__tcl1==0) {
            Error("Detectors_det_pos_shc streamer","Missing the TClass object for class std::vector<float, class std::allocator<float> >!");
            return;
         }
            vector<vector<float> >::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b.StreamObject((vector<float>*)&(*R__k),R__tcl1);
            }
         }
      }
      {
         vector<float> &R__stl =  Detectors_t_0;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<float>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<float> &R__stl =  Detectors_p2p;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<float>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<vector<TVector3> > &R__stl =  Detectors_trace;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class std::vector<class TVector3, class std::allocator<class TVector3> >));
         if (R__tcl1==0) {
            Error("Detectors_trace streamer","Missing the TClass object for class std::vector<class TVector3, class std::allocator<class TVector3> >!");
            return;
         }
            vector<vector<TVector3> >::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b.StreamObject((vector<TVector3>*)&(*R__k),R__tcl1);
            }
         }
      }
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_SimEfield(void *p) {
      return  p ? new(p) ::SimEfield : new ::SimEfield;
   }
   static void *newArray_SimEfield(Long_t nElements, void *p) {
      return p ? new(p) ::SimEfield[nElements] : new ::SimEfield[nElements];
   }
   // Wrapper around operator delete
   static void delete_SimEfield(void *p) {
      delete ((::SimEfield*)p);
   }
   static void deleteArray_SimEfield(void *p) {
      delete [] ((::SimEfield*)p);
   }
   static void destruct_SimEfield(void *p) {
      typedef ::SimEfield current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_SimEfield(TBuffer &buf, void *obj) {
      ((::SimEfield*)obj)->::SimEfield::Streamer(buf);
   }
} // end of namespace ROOT for class ::SimEfield

//______________________________________________________________________________
void SimSignal::Streamer(TBuffer &R__b)
{
   // Stream an object of class SimSignal.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> run_id;
      R__b >> evt_id;
      {
         vector<string> &R__stl =  signal_sim;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            string R__t;
            {TString R__str;
             R__str.Streamer(R__b);
             R__t = R__str.Data();}
            R__stl.push_back(R__t);
         }
      }
      {
         vector<int> &R__stl =  Detectors_det_id;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            int R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<vector<string> > &R__stl =  Detectors_det_type;
         R__stl.clear();
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class std::vector<class std::__cxx11::basic_string<char>, class std::allocator<class std::__cxx11::basic_string<char> > >));
         if (R__tcl1==0) {
            Error("Detectors_det_type streamer","Missing the TClass object for class std::vector<class std::__cxx11::basic_string<char>, class std::allocator<class std::__cxx11::basic_string<char> > >!");
            return;
         }
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            vector<string> R__t;
            R__b.StreamObject(&R__t,R__tcl1);
            R__stl.push_back(R__t);
         }
      }
      {
         vector<vector<float> > &R__stl =  Detectors_det_pos_shc;
         R__stl.clear();
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class std::vector<float, class std::allocator<float> >));
         if (R__tcl1==0) {
            Error("Detectors_det_pos_shc streamer","Missing the TClass object for class std::vector<float, class std::allocator<float> >!");
            return;
         }
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            vector<float> R__t;
            R__b.StreamObject(&R__t,R__tcl1);
            R__stl.push_back(R__t);
         }
      }
      {
         vector<float> &R__stl =  Detectors_t_0;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            float R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<float> &R__stl =  Detectors_p2p;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            float R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<vector<TVector3> > &R__stl =  Detectors_trace;
         R__stl.clear();
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class std::vector<class TVector3, class std::allocator<class TVector3> >));
         if (R__tcl1==0) {
            Error("Detectors_trace streamer","Missing the TClass object for class std::vector<class TVector3, class std::allocator<class TVector3> >!");
            return;
         }
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            vector<TVector3> R__t;
            R__b.StreamObject(&R__t,R__tcl1);
            R__stl.push_back(R__t);
         }
      }
      R__b.CheckByteCount(R__s, R__c, SimSignal::IsA());
   } else {
      R__c = R__b.WriteVersion(SimSignal::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << run_id;
      R__b << evt_id;
      {
         vector<string> &R__stl =  signal_sim;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<string>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            {TString R__str((*R__k).c_str());
             R__str.Streamer(R__b);};
            }
         }
      }
      {
         vector<int> &R__stl =  Detectors_det_id;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<int>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<vector<string> > &R__stl =  Detectors_det_type;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class std::vector<class std::__cxx11::basic_string<char>, class std::allocator<class std::__cxx11::basic_string<char> > >));
         if (R__tcl1==0) {
            Error("Detectors_det_type streamer","Missing the TClass object for class std::vector<class std::__cxx11::basic_string<char>, class std::allocator<class std::__cxx11::basic_string<char> > >!");
            return;
         }
            vector<vector<string> >::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b.StreamObject((vector<string>*)&(*R__k),R__tcl1);
            }
         }
      }
      {
         vector<vector<float> > &R__stl =  Detectors_det_pos_shc;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class std::vector<float, class std::allocator<float> >));
         if (R__tcl1==0) {
            Error("Detectors_det_pos_shc streamer","Missing the TClass object for class std::vector<float, class std::allocator<float> >!");
            return;
         }
            vector<vector<float> >::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b.StreamObject((vector<float>*)&(*R__k),R__tcl1);
            }
         }
      }
      {
         vector<float> &R__stl =  Detectors_t_0;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<float>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<float> &R__stl =  Detectors_p2p;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<float>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<vector<TVector3> > &R__stl =  Detectors_trace;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class std::vector<class TVector3, class std::allocator<class TVector3> >));
         if (R__tcl1==0) {
            Error("Detectors_trace streamer","Missing the TClass object for class std::vector<class TVector3, class std::allocator<class TVector3> >!");
            return;
         }
            vector<vector<TVector3> >::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b.StreamObject((vector<TVector3>*)&(*R__k),R__tcl1);
            }
         }
      }
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_SimSignal(void *p) {
      return  p ? new(p) ::SimSignal : new ::SimSignal;
   }
   static void *newArray_SimSignal(Long_t nElements, void *p) {
      return p ? new(p) ::SimSignal[nElements] : new ::SimSignal[nElements];
   }
   // Wrapper around operator delete
   static void delete_SimSignal(void *p) {
      delete ((::SimSignal*)p);
   }
   static void deleteArray_SimSignal(void *p) {
      delete [] ((::SimSignal*)p);
   }
   static void destruct_SimSignal(void *p) {
      typedef ::SimSignal current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_SimSignal(TBuffer &buf, void *obj) {
      ((::SimSignal*)obj)->::SimSignal::Streamer(buf);
   }
} // end of namespace ROOT for class ::SimSignal

//______________________________________________________________________________
void SimShower::Streamer(TBuffer &R__b)
{
   // Stream an object of class SimShower.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> run_id;
      R__b >> evt_id;
      {
         vector<string> &R__stl =  shower_type;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            string R__t;
            {TString R__str;
             R__str.Streamer(R__b);
             R__t = R__str.Data();}
            R__stl.push_back(R__t);
         }
      }
      R__b >> shower_energy;
      R__b >> shower_azimuth;
      R__b >> shower_zenith;
      {
         vector<float> &R__stl =  shower_core_pos;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            float R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      R__b >> rnd_seed;
      R__b >> energy_in_neutrinos;
      {
         vector<string> &R__stl =  atmos_model;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            string R__t;
            {TString R__str;
             R__str.Streamer(R__b);
             R__t = R__str.Data();}
            R__stl.push_back(R__t);
         }
      }
      {
         vector<float> &R__stl =  atmos_model_param;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            float R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<float> &R__stl =  magnetic_field;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            float R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<string> &R__stl =  date;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            string R__t;
            {TString R__str;
             R__str.Streamer(R__b);
             R__t = R__str.Data();}
            R__stl.push_back(R__t);
         }
      }
      {
         vector<string> &R__stl =  site;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            string R__t;
            {TString R__str;
             R__str.Streamer(R__b);
             R__t = R__str.Data();}
            R__stl.push_back(R__t);
         }
      }
      {
         vector<float> &R__stl =  site_lat_long;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            float R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      R__b >> ground_alt;
      R__b >> prim_energy;
      {
         vector<string> &R__stl =  prim_type;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            string R__t;
            {TString R__str;
             R__str.Streamer(R__b);
             R__t = R__str.Data();}
            R__stl.push_back(R__t);
         }
      }
      {
         vector<float> &R__stl =  prim_injpoint_shc;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            float R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      R__b >> prim_inj_alt_shc;
      {
         vector<float> &R__stl =  prim_inj_dir_shc;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            float R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      R__b >> xmax_grams;
      {
         vector<double> &R__stl =  xmax_pos_shc;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            double R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      R__b >> xmax_alt;
      {
         vector<float> &R__stl =  gh_fit_param;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            float R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<string> &R__stl =  hadronic_model;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            string R__t;
            {TString R__str;
             R__str.Streamer(R__b);
             R__t = R__str.Data();}
            R__stl.push_back(R__t);
         }
      }
      {
         vector<string> &R__stl =  low_energy_model;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            string R__t;
            {TString R__str;
             R__str.Streamer(R__b);
             R__t = R__str.Data();}
            R__stl.push_back(R__t);
         }
      }
      {
         vector<float> &R__stl =  cpu_time;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            float R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      R__b.CheckByteCount(R__s, R__c, SimShower::IsA());
   } else {
      R__c = R__b.WriteVersion(SimShower::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << run_id;
      R__b << evt_id;
      {
         vector<string> &R__stl =  shower_type;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<string>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            {TString R__str((*R__k).c_str());
             R__str.Streamer(R__b);};
            }
         }
      }
      R__b << shower_energy;
      R__b << shower_azimuth;
      R__b << shower_zenith;
      {
         vector<float> &R__stl =  shower_core_pos;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<float>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      R__b << rnd_seed;
      R__b << energy_in_neutrinos;
      {
         vector<string> &R__stl =  atmos_model;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<string>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            {TString R__str((*R__k).c_str());
             R__str.Streamer(R__b);};
            }
         }
      }
      {
         vector<float> &R__stl =  atmos_model_param;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<float>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<float> &R__stl =  magnetic_field;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<float>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<string> &R__stl =  date;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<string>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            {TString R__str((*R__k).c_str());
             R__str.Streamer(R__b);};
            }
         }
      }
      {
         vector<string> &R__stl =  site;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<string>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            {TString R__str((*R__k).c_str());
             R__str.Streamer(R__b);};
            }
         }
      }
      {
         vector<float> &R__stl =  site_lat_long;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<float>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      R__b << ground_alt;
      R__b << prim_energy;
      {
         vector<string> &R__stl =  prim_type;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<string>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            {TString R__str((*R__k).c_str());
             R__str.Streamer(R__b);};
            }
         }
      }
      {
         vector<float> &R__stl =  prim_injpoint_shc;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<float>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      R__b << prim_inj_alt_shc;
      {
         vector<float> &R__stl =  prim_inj_dir_shc;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<float>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      R__b << xmax_grams;
      {
         vector<double> &R__stl =  xmax_pos_shc;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<double>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      R__b << xmax_alt;
      {
         vector<float> &R__stl =  gh_fit_param;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<float>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<string> &R__stl =  hadronic_model;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<string>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            {TString R__str((*R__k).c_str());
             R__str.Streamer(R__b);};
            }
         }
      }
      {
         vector<string> &R__stl =  low_energy_model;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<string>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            {TString R__str((*R__k).c_str());
             R__str.Streamer(R__b);};
            }
         }
      }
      {
         vector<float> &R__stl =  cpu_time;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<float>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_SimShower(void *p) {
      return  p ? new(p) ::SimShower : new ::SimShower;
   }
   static void *newArray_SimShower(Long_t nElements, void *p) {
      return p ? new(p) ::SimShower[nElements] : new ::SimShower[nElements];
   }
   // Wrapper around operator delete
   static void delete_SimShower(void *p) {
      delete ((::SimShower*)p);
   }
   static void deleteArray_SimShower(void *p) {
      delete [] ((::SimShower*)p);
   }
   static void destruct_SimShower(void *p) {
      typedef ::SimShower current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_SimShower(TBuffer &buf, void *obj) {
      ((::SimShower*)obj)->::SimShower::Streamer(buf);
   }
} // end of namespace ROOT for class ::SimShower

namespace ROOT {
   static TClass *vectorlEvectorlEstringgRsPgR_Dictionary();
   static void vectorlEvectorlEstringgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEstringgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEstringgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEstringgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEstringgRsPgR(void *p);
   static void destruct_vectorlEvectorlEstringgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<string> >*)
   {
      vector<vector<string> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<string> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<string> >", -2, "vector", 386,
                  typeid(vector<vector<string> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEstringgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<vector<string> >) );
      instance.SetNew(&new_vectorlEvectorlEstringgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEstringgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEstringgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEstringgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEstringgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<string> > >()));

      ::ROOT::AddClassAlternate("vector<vector<string> >","std::vector<std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >, std::allocator<std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<vector<string> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEstringgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<string> >*)0x0)->GetClass();
      vectorlEvectorlEstringgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEstringgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEstringgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<string> > : new vector<vector<string> >;
   }
   static void *newArray_vectorlEvectorlEstringgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<string> >[nElements] : new vector<vector<string> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEstringgRsPgR(void *p) {
      delete ((vector<vector<string> >*)p);
   }
   static void deleteArray_vectorlEvectorlEstringgRsPgR(void *p) {
      delete [] ((vector<vector<string> >*)p);
   }
   static void destruct_vectorlEvectorlEstringgRsPgR(void *p) {
      typedef vector<vector<string> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<string> >

namespace ROOT {
   static TClass *vectorlEvectorlEfloatgRsPgR_Dictionary();
   static void vectorlEvectorlEfloatgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEfloatgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEfloatgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEfloatgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEfloatgRsPgR(void *p);
   static void destruct_vectorlEvectorlEfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<float> >*)
   {
      vector<vector<float> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<float> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<float> >", -2, "vector", 386,
                  typeid(vector<vector<float> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEfloatgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<vector<float> >) );
      instance.SetNew(&new_vectorlEvectorlEfloatgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEfloatgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEfloatgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEfloatgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<float> > >()));

      ::ROOT::AddClassAlternate("vector<vector<float> >","std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<vector<float> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<float> >*)0x0)->GetClass();
      vectorlEvectorlEfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEfloatgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<float> > : new vector<vector<float> >;
   }
   static void *newArray_vectorlEvectorlEfloatgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<float> >[nElements] : new vector<vector<float> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEfloatgRsPgR(void *p) {
      delete ((vector<vector<float> >*)p);
   }
   static void deleteArray_vectorlEvectorlEfloatgRsPgR(void *p) {
      delete [] ((vector<vector<float> >*)p);
   }
   static void destruct_vectorlEvectorlEfloatgRsPgR(void *p) {
      typedef vector<vector<float> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<float> >

namespace ROOT {
   static TClass *vectorlEvectorlETVector3gRsPgR_Dictionary();
   static void vectorlEvectorlETVector3gRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlETVector3gRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlETVector3gRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlETVector3gRsPgR(void *p);
   static void deleteArray_vectorlEvectorlETVector3gRsPgR(void *p);
   static void destruct_vectorlEvectorlETVector3gRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<TVector3> >*)
   {
      vector<vector<TVector3> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<TVector3> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<TVector3> >", -2, "vector", 386,
                  typeid(vector<vector<TVector3> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlETVector3gRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<vector<TVector3> >) );
      instance.SetNew(&new_vectorlEvectorlETVector3gRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlETVector3gRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlETVector3gRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlETVector3gRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlETVector3gRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<TVector3> > >()));

      ::ROOT::AddClassAlternate("vector<vector<TVector3> >","std::vector<std::vector<TVector3, std::allocator<TVector3> >, std::allocator<std::vector<TVector3, std::allocator<TVector3> > > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<vector<TVector3> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlETVector3gRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<TVector3> >*)0x0)->GetClass();
      vectorlEvectorlETVector3gRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlETVector3gRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlETVector3gRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<TVector3> > : new vector<vector<TVector3> >;
   }
   static void *newArray_vectorlEvectorlETVector3gRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<TVector3> >[nElements] : new vector<vector<TVector3> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlETVector3gRsPgR(void *p) {
      delete ((vector<vector<TVector3> >*)p);
   }
   static void deleteArray_vectorlEvectorlETVector3gRsPgR(void *p) {
      delete [] ((vector<vector<TVector3> >*)p);
   }
   static void destruct_vectorlEvectorlETVector3gRsPgR(void *p) {
      typedef vector<vector<TVector3> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<TVector3> >

namespace ROOT {
   static TClass *vectorlEstringgR_Dictionary();
   static void vectorlEstringgR_TClassManip(TClass*);
   static void *new_vectorlEstringgR(void *p = 0);
   static void *newArray_vectorlEstringgR(Long_t size, void *p);
   static void delete_vectorlEstringgR(void *p);
   static void deleteArray_vectorlEstringgR(void *p);
   static void destruct_vectorlEstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<string>*)
   {
      vector<string> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<string>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<string>", -2, "vector", 386,
                  typeid(vector<string>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEstringgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<string>) );
      instance.SetNew(&new_vectorlEstringgR);
      instance.SetNewArray(&newArray_vectorlEstringgR);
      instance.SetDelete(&delete_vectorlEstringgR);
      instance.SetDeleteArray(&deleteArray_vectorlEstringgR);
      instance.SetDestructor(&destruct_vectorlEstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<string> >()));

      ::ROOT::AddClassAlternate("vector<string>","std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<string>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<string>*)0x0)->GetClass();
      vectorlEstringgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEstringgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<string> : new vector<string>;
   }
   static void *newArray_vectorlEstringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<string>[nElements] : new vector<string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEstringgR(void *p) {
      delete ((vector<string>*)p);
   }
   static void deleteArray_vectorlEstringgR(void *p) {
      delete [] ((vector<string>*)p);
   }
   static void destruct_vectorlEstringgR(void *p) {
      typedef vector<string> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<string>

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = 0);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 386,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));

      ::ROOT::AddClassAlternate("vector<int>","std::vector<int, std::allocator<int> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<int>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<int>*)0x0)->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete ((vector<int>*)p);
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] ((vector<int>*)p);
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace ROOT {
   static TClass *vectorlEfloatgR_Dictionary();
   static void vectorlEfloatgR_TClassManip(TClass*);
   static void *new_vectorlEfloatgR(void *p = 0);
   static void *newArray_vectorlEfloatgR(Long_t size, void *p);
   static void delete_vectorlEfloatgR(void *p);
   static void deleteArray_vectorlEfloatgR(void *p);
   static void destruct_vectorlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<float>*)
   {
      vector<float> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<float>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<float>", -2, "vector", 386,
                  typeid(vector<float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<float>) );
      instance.SetNew(&new_vectorlEfloatgR);
      instance.SetNewArray(&newArray_vectorlEfloatgR);
      instance.SetDelete(&delete_vectorlEfloatgR);
      instance.SetDeleteArray(&deleteArray_vectorlEfloatgR);
      instance.SetDestructor(&destruct_vectorlEfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<float> >()));

      ::ROOT::AddClassAlternate("vector<float>","std::vector<float, std::allocator<float> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<float>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<float>*)0x0)->GetClass();
      vectorlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEfloatgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<float> : new vector<float>;
   }
   static void *newArray_vectorlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<float>[nElements] : new vector<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEfloatgR(void *p) {
      delete ((vector<float>*)p);
   }
   static void deleteArray_vectorlEfloatgR(void *p) {
      delete [] ((vector<float>*)p);
   }
   static void destruct_vectorlEfloatgR(void *p) {
      typedef vector<float> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<float>

namespace ROOT {
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = 0);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 386,
                  typeid(vector<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));

      ::ROOT::AddClassAlternate("vector<double>","std::vector<double, std::allocator<double> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<double>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<double>*)0x0)->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete ((vector<double>*)p);
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] ((vector<double>*)p);
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace ROOT {
   static TClass *vectorlETVector3gR_Dictionary();
   static void vectorlETVector3gR_TClassManip(TClass*);
   static void *new_vectorlETVector3gR(void *p = 0);
   static void *newArray_vectorlETVector3gR(Long_t size, void *p);
   static void delete_vectorlETVector3gR(void *p);
   static void deleteArray_vectorlETVector3gR(void *p);
   static void destruct_vectorlETVector3gR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TVector3>*)
   {
      vector<TVector3> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TVector3>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TVector3>", -2, "vector", 386,
                  typeid(vector<TVector3>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETVector3gR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TVector3>) );
      instance.SetNew(&new_vectorlETVector3gR);
      instance.SetNewArray(&newArray_vectorlETVector3gR);
      instance.SetDelete(&delete_vectorlETVector3gR);
      instance.SetDeleteArray(&deleteArray_vectorlETVector3gR);
      instance.SetDestructor(&destruct_vectorlETVector3gR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TVector3> >()));

      ::ROOT::AddClassAlternate("vector<TVector3>","std::vector<TVector3, std::allocator<TVector3> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TVector3>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETVector3gR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TVector3>*)0x0)->GetClass();
      vectorlETVector3gR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETVector3gR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETVector3gR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TVector3> : new vector<TVector3>;
   }
   static void *newArray_vectorlETVector3gR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TVector3>[nElements] : new vector<TVector3>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETVector3gR(void *p) {
      delete ((vector<TVector3>*)p);
   }
   static void deleteArray_vectorlETVector3gR(void *p) {
      delete [] ((vector<TVector3>*)p);
   }
   static void destruct_vectorlETVector3gR(void *p) {
      typedef vector<TVector3> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TVector3>

namespace {
  void TriggerDictionaryInitialization_SimEventDict_Impl() {
    static const char* headers[] = {
"SimEfield.h",
"SimSignal.h",
"SimShower.h",
0
    };
    static const char* includePaths[] = {
"/home/mapx/anaconda3/envs/PyROOT/include/",
"/mnt/sdb2/users/m/mapx/MySpace/GRANDROOT_V1/Event/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "SimEventDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$SimEfield.h")))  SimEfield;
class __attribute__((annotate("$clingAutoload$SimSignal.h")))  SimSignal;
class __attribute__((annotate("$clingAutoload$SimShower.h")))  SimShower;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "SimEventDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "SimEfield.h"
#include "SimSignal.h"
#include "SimShower.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"SimEfield", payloadCode, "@",
"SimShower", payloadCode, "@",
"SimSignal", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("SimEventDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_SimEventDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_SimEventDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_SimEventDict() {
  TriggerDictionaryInitialization_SimEventDict_Impl();
}
