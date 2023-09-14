//
// Generated file, do not edit! Created by opp_msgtool 6.0 from veins/modules/messages/BaseFrame1609_4.msg.
//

#ifndef __VEINS_BASEFRAME1609_4_M_H
#define __VEINS_BASEFRAME1609_4_M_H

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

class BaseFrame1609_4;

}  // namespace veins

#include "veins/base/utils/SimpleAddress_m.h" // import veins.base.utils.SimpleAddress


namespace veins {

/**
 * Class generated from <tt>veins/modules/messages/BaseFrame1609_4.msg:27</tt> by opp_msgtool.
 * <pre>
 * packet BaseFrame1609_4
 * {
 *     //Channel Number on which this packet was sent
 *     int channelNumber;
 *     //User priority with which this packet was sent (note the AC mapping rules in Mac1609_4::mapUserPriority)
 *     int userPriority = 7;
 *     //Unique number to identify the service
 *     int psid = 0;
 *     //Recipient of frame (-1 for any)
 *     LAddress::L2Type recipientAddress = -1;
 * }
 * </pre>
 */
class VEINS_API BaseFrame1609_4 : public ::omnetpp::cPacket
{
  protected:
    int channelNumber = 0;
    int userPriority = 7;
    int psid = 0;
    LAddress::L2Type recipientAddress = -1;

  private:
    void copy(const BaseFrame1609_4& other);

  protected:
    bool operator==(const BaseFrame1609_4&) = delete;

  public:
    BaseFrame1609_4(const char *name=nullptr, short kind=0);
    BaseFrame1609_4(const BaseFrame1609_4& other);
    virtual ~BaseFrame1609_4();
    BaseFrame1609_4& operator=(const BaseFrame1609_4& other);
    virtual BaseFrame1609_4 *dup() const override {return new BaseFrame1609_4(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getChannelNumber() const;
    virtual void setChannelNumber(int channelNumber);

    virtual int getUserPriority() const;
    virtual void setUserPriority(int userPriority);

    virtual int getPsid() const;
    virtual void setPsid(int psid);

    virtual const LAddress::L2Type& getRecipientAddress() const;
    virtual LAddress::L2Type& getRecipientAddressForUpdate() { return const_cast<LAddress::L2Type&>(const_cast<BaseFrame1609_4*>(this)->getRecipientAddress());}
    virtual void setRecipientAddress(const LAddress::L2Type& recipientAddress);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BaseFrame1609_4& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BaseFrame1609_4& obj) {obj.parsimUnpack(b);}


}  // namespace veins


namespace omnetpp {

template<> inline veins::BaseFrame1609_4 *fromAnyPtr(any_ptr ptr) { return check_and_cast<veins::BaseFrame1609_4*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __VEINS_BASEFRAME1609_4_M_H

