#include <list>
#include <cstdint>

class MITTSController {

protected:
    //these will be hard-coded for now, set the param for the controller
    uint32_t *binStore;
    uint32_t *binCredits;
    uint32_t numBins;
    uint64_t timeInterval;
    uint64_t replenishPeriod;
    //how long since last request?
    uint64_t lastRequestTime;
    
    typedef struct MittsElem{
        uint64_t requestTime;
        uint64_t scheduleTime;
        uint32_t *binStore;
    } MittsElem_t;

public:
    //Event *replBins;
    
    MITTSController(void);
    bool blockRequest(void);
    void replenishBins(void);
    uint64_t getReplenishTime(void);

    ~MITTSController(void);
private:
    uint32_t getBin(uint64_t);
    std::list<MittsElem_t> mittsList;

};

MITTSController::MITTSController(){

    this->lastRequestTime = 0;
    this->numBins = 1;
    this->timeInterval = 100;
    this->replenishPeriod = 50000;
    this->binCredits = new uint32_t[this->numBins];
    this->binStore = new uint32_t[this->numBins];
    for(int i = 0; i < this->numBins; i++){
        binCredits[i] = 1;
    }

    this->replenishBins();
}

bool MITTSController::blockRequest(){
    //this is our inter-arrival time, need to place it to a bin now
    uint64_t currentTick = curTick();
    uint64_t requestPeriod = currentuint64_t - this->lastRequestTime;
    this->lastRequestTime = currentuint64_t;

    uint32_t binToDeduct = getBin(requestPeriod);
    //if the bin has no more credits, then block the request
    if(this->binStore[binToDeduct] > 0){
        binStore[binToDeduct]--;
        return false;
    } else {
        return true;
    } 
}

void MITTSController::replenishBins(){
    for(uint32_t i = 0; i < this->numBins; i++){
        binStore[i] = this->binCredits[i];
    }
}

uint64_t MITTSController::getReplenishTime(){
    return this->replenishPeriod;
}

uint32_t MITTSController::getBin(uint64_t interArrivalTime){
    uint32_t index = 0;

    while(interArrivalTime >= timeInterval){
        index++;
        interArrivalTime -= timeInterval;
    }

    if(index >= this->numBins){
        index = this->numBins-1;
    }

    return index;
}

MITTSController::~MITTSController(){
    delete binStore;
    delete binCredits; 
}