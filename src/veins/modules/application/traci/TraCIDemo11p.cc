//
// Copyright (C) 2006-2011 Christoph Sommer <christoph.sommer@uibk.ac.at>
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

#include "veins/modules/application/traci/TraCIDemo11p.h"

#include "veins/modules/application/traci/TraCIDemo11pMessage_m.h"

using namespace veins;
using timestamp = omnetpp::simtime_t;
using macaddress = LAddress::L2Type;
using tuple = std::tuple<macaddress,timestamp>;


Define_Module(veins::TraCIDemo11p);

void TraCIDemo11p::initialize(int stage)
{
    DemoBaseApplLayer::initialize(stage);
    if (stage == 0) {

        lastDroveAt = simTime();
        currentSubscribedServiceId = -1;
        avoidDuplicates = par("avoidDuplicates").boolValue();
        TTL = par("TTL").intValue();
    }
}

void TraCIDemo11p::onWSA(DemoServiceAdvertisment* wsa)
{
    if (currentSubscribedServiceId == -1) {
        mac->changeServiceChannel(static_cast<Channel>(wsa->getTargetChannel()));
        currentSubscribedServiceId = wsa->getPsid();
        if (currentOfferedServiceId != wsa->getPsid()) {
            stopService();
            startService(static_cast<Channel>(wsa->getTargetChannel()), wsa->getPsid(), "Mirrored Traffic Service");
        }
    }
}

void TraCIDemo11p::onWSM(BaseFrame1609_4* frame)
{
    TraCIDemo11pMessage* wsm = check_and_cast<TraCIDemo11pMessage*>(frame);

    EV << getName() << ": receiving MSG <" << wsm->getSenderAddress() << ","
              << wsm->getTimestamp() << "," << wsm->getTTL()<<">\n";

    // turn GREEN a car as soon as it receives a WSM
    traciVehicle->setColor(TraCIColor(0, 255, 0, 255));

    findHost()->getDisplayString().setTagArg("i", 1, "green");


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
            }
        }

        //otherwise, decide if to propagate or not according to TTL
        int currentTTL = wsm->getTTL();
        if (currentTTL > 0) {
            wsm->setTTL(currentTTL - 1);
            scheduleAt(simTime() + 2 + uniform(0.01, 0.2), wsm->dup());
        }



    if (traciVehicle->getSpeed() != 0){


        traciVehicle->setSpeed(55);
        traciVehicle->changeLane(0,3);
        simtime_t endAccident=79;
        if(simTime()>= endAccident){
            traciVehicle->setSpeed(-1);

        }
    }








}

void TraCIDemo11p::handleSelfMsg(cMessage* msg)
{
    if (TraCIDemo11pMessage* wsm = dynamic_cast<TraCIDemo11pMessage*>(msg)) {
        std::cout << "Car="<< getParentModule()->getIndex() << " sending <" << wsm->getSenderAddress() << ","
                << wsm->getTimestamp() << "," << wsm->getTTL() << ">\n";

        sendDown(wsm->dup());
        delete(wsm);
    }
    else{
        DemoBaseApplLayer::handleSelfMsg(msg);
    }
}

void TraCIDemo11p::handlePositionUpdate(cObject* obj)
{
    DemoBaseApplLayer::handlePositionUpdate(obj);

    // stopped for for at least 10s?
    if (mobility->getSpeed() < 1) {
        if (simTime() - lastDroveAt >= 2) {
            findHost()->getDisplayString().setTagArg("i", 1, "red");


            TraCIDemo11pMessage* wsm = new TraCIDemo11pMessage();
            populateWSM(wsm);
            wsm->setDemoData(mobility->getRoadId().c_str());
            wsm->setTimestamp(simTime());
            wsm->setSenderAddress(myId);
            wsm->setTTL(TTL);


            sendDown(wsm);
        }
    }
    else {
        lastDroveAt = simTime();
    }
}
