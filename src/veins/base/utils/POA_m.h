//
// Generated file, do not edit! Created by opp_msgtool 6.0 from veins/base/utils/POA.msg.
//

#ifndef __VEINS_POA_M_H
#define __VEINS_POA_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef VEINS_API
#  if defined(VEINS_EXPORT)
#    define VEINS_API  OPP_DLLEXPORT
#  elif defined(VEINS_IMPORT)
#    define VEINS_API  OPP_DLLIMPORT
#  else
#    define VEINS_API
#  endif
#endif


namespace veins {


}  // namespace veins

#include "veins/common_m.h" // import veins.common

// cplusplus {{
#include "veins/base/utils/POA.h"
// }}


namespace veins {


}  // namespace veins


namespace omnetpp {

inline any_ptr toAnyPtr(const veins::POA *p) {if (auto obj = as_cObject(p)) return any_ptr(obj); else return any_ptr(p);}
template<> inline veins::POA *fromAnyPtr(any_ptr ptr) { return ptr.get<veins::POA>(); }

}  // namespace omnetpp

#endif // ifndef __VEINS_POA_M_H

