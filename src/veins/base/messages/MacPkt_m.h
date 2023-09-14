//
// Generated file, do not edit! Created by opp_msgtool 6.0 from veins/base/messages/MacPkt.msg.
//

#ifndef __VEINS_MACPKT_M_H
#define __VEINS_MACPKT_M_H

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

class MacPkt;

}  // namespace veins

#include "veins/base/utils/SimpleAddress_m.h" // import veins.base.utils.SimpleAddress


namespace veins {

/**
 * Class generated from <tt>veins/base/messages/MacPkt.msg:40</tt> by opp_msgtool.
 * <pre>
 * // A basic MAC (Media Access Control) packet format definition
 * // 
 * // subclass if you want to create your own MAC layer packet class
 * //
 * // The basic MAC packet only provides source and destination address
 * //
 * // \@author Daniel Willkomm
 * packet MacPkt
 * {
 *     LAddress::L2Type destAddr; // destination mac address
 *     LAddress::L2Type srcAddr;  // source mac address
 *     long sequenceId; // Sequence Number to detect duplicate messages
 * }
 * </pre>
 */
class VEINS_API MacPkt : public ::omnetpp::cPacket
{
  protected:
    LAddress::L2Type destAddr;
    LAddress::L2Type srcAddr;
    long sequenceId = 0;

  private:
    void copy(const MacPkt& other);

  protected:
    bool operator==(const MacPkt&) = delete;

  public:
    MacPkt(const char *name=nullptr, short kind=0);
    MacPkt(const MacPkt& other);
    virtual ~MacPkt();
    MacPkt& operator=(const MacPkt& other);
    virtual MacPkt *dup() const override {return new MacPkt(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const LAddress::L2Type& getDestAddr() const;
    virtual LAddress::L2Type& getDestAddrForUpdate() { return const_cast<LAddress::L2Type&>(const_cast<MacPkt*>(this)->getDestAddr());}
    virtual void setDestAddr(const LAddress::L2Type& destAddr);

    virtual const LAddress::L2Type& getSrcAddr() const;
    virtual LAddress::L2Type& getSrcAddrForUpdate() { return const_cast<LAddress::L2Type&>(const_cast<MacPkt*>(this)->getSrcAddr());}
    virtual void setSrcAddr(const LAddress::L2Type& srcAddr);

    virtual long getSequenceId() const;
    virtual void setSequenceId(long sequenceId);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MacPkt& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MacPkt& obj) {obj.parsimUnpack(b);}


}  // namespace veins


namespace omnetpp {

template<> inline veins::MacPkt *fromAnyPtr(any_ptr ptr) { return check_and_cast<veins::MacPkt*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __VEINS_MACPKT_M_H
