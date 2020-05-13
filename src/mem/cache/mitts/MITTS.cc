#include "MITTS.hh"

MITTSController::MITTSController(){
    this->lastRequestTime = 0;
    this->numBins = 10;
    this->timeInterval = 10;
    this->binCredits = new int[this->numBins];
    this->binStore = new int[this->numBins];
    for(int i = 0; i < this->numBins; i++){
        binCredits[i] = 5;
    }

    replenishBins();
}

bool MITTSController::blockRequest(int requestTime){
    //this is our inter-arrival time, need to place it to a bin now
    int requestPeriod = this->lastRequestTime;
    this->lastRequestTime = 0;

    int binToDeduct = getBin(requestTime);
    //if the bin has no more credits, then block the request
    if(this->binStore[binToDeduct] > 0){
        binStore[binToDeduct]--;
        return false;
    } else {
        return true;
    } 
}

void MITTSController::replenishBins(){
    for(int i = 0; i < this->numBins; i++){
        binStore[i] = this->binCredits[i];
    }
}

void MITTSController::incrementCounter(){
    this->lastRequestTime++;
}

int MITTSController::getReplenishTime(){
    return this->replenishPeriod;
}

int MITTSController::getBin(int interArrivalTime){
    int index = 0;

    while(interArrivalTime >= timeInterval){
        index++;
        interArrivalTime -= timeInterval;
    }

    return index;
}

MITTSController::~MITTSController(){
    delete binStore;
    delete binCredits; 
}
