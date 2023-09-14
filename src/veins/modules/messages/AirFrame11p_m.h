//
// Generated file, do not edit! Created by opp_msgtool 6.0 from veins/modules/messages/AirFrame11p.msg.
//

#ifndef __VEINS_AIRFRAME11P_M_H
#define __VEINS_AIRFRAME11P_M_H

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

class AirFrame11p;

}  // namespace veins

#include "veins/base/messages/AirFrame_m.h" // import veins.base.messages.AirFrame


namespace veins {

/**
 * Class generated from <tt>veins/modules/messages/AirFrame11p.msg:30</tt> by opp_msgtool.
 * <pre>
 * //
 * // Extension of base AirFrame message to have the underMinPowerLevel field
 * //
 * message AirFrame11p extends AirFrame
 * {
 *     bool underMinPowerLevel = false;
 *     bool wasTransmitting = false;
 * }
 * </pre>
 */
class VEINS_API AirFrame11p : public ::veins::AirFrame
{
  protected:
    bool underMinPowerLevel = false;
    bool wasTransmitting = false;

  private:
    void copy(const AirFrame11p& other);

  protected:
    bool operator==(const AirFrame11p&) = delete;

  public:
    AirFrame11p(const char *name=nullptr, short kind=0);
    AirFrame11p(const AirFrame11p& other);
    virtual ~AirFrame11p();
    AirFrame11p& operator=(const AirFrame11p& other);
    virtual AirFrame11p *dup() const override {return new AirFrame11p(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual bool getUnderMinPowerLevel() const;
    virtual void setUnderMinPowerLevel(bool underMinPowerLevel);

    virtual bool getWasTransmitting() const;
    virtual void setWasTransmitting(bool wasTransmitting);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const AirFrame11p& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, AirFrame11p& obj) {obj.parsimUnpack(b);}


}  // namespace veins


namespace omnetpp {

template<> inline veins::AirFrame11p *fromAnyPtr(any_ptr ptr) { return check_and_cast<veins::AirFrame11p*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __VEINS_AIRFRAME11P_M_H
