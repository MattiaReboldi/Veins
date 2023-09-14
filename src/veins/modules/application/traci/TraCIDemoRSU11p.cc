//
// Copyright (C) 2016 David Eckhoff <david.eckhoff@fau.de>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "veins/modules/application/traci/TraCIDemoRSU11p.h"

#include "veins/modules/application/traci/TraCIDemo11pMessage_m.h"

using namespace veins;
using timestamp = omnetpp::simtime_t;
using macaddress = LAddress::L2Type;
using tuple = std::tuple<macaddress,timestamp>;

Define_Module(veins::TraCIDemoRSU11p);

void TraCIDemoRSU11p::onWSA(DemoServiceAdvertisment* wsa)
{
    // if this RSU receives a WSA for service 42, it will tune to the chan
    if (wsa->getPsid() == 42) {
        mac->changeServiceChannel(static_cast<Channel>(wsa->getTargetChannel()));
    }
}

void TraCIDemoRSU11p::onWSM(BaseFrame1609_4* frame)
{
    TraCIDemo11pMessage* wsm = check_and_cast<TraCIDemo11pMessage*>(frame);


    if (avoidDuplicates) {
        //decide to propagate if not already in the set of received messages
        tuple key = std::make_tuple(wsm->getSenderAddress(), wsm->getTimestamp());
        if (std::find(rcvd_messages.begin(), rcvd_messages.end(), key) != rcvd_messages.end()) {
            //message already in the list, we propagated it already, stop here!
            EV << "not propagating " << std::get<0>(key) << "," << std::get<1>(key) << "\n";
            return;
        } else {
            EV << "adding " << std::get<0>(key) << "," << std::get<1>(key) << " to rcvd_messages\n";
            rcvd_messages.insert(key);
            sendDelayedDown(wsm->dup(),  uniform(0.1, 0.2));
        }
    }




}
