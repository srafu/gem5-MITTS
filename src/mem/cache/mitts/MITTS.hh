
class MITTSController {

protected:
    //these will be hard-coded for now, set the param for the controller
    int *binStore;
    int *binCredits;
    int numBins;
    int timeInterval;
    int replenishPeriod;
    //how long since last request?
    int lastRequestTime;

public:
    MITTSController(void);
    bool blockRequest(void);
    void replenishBins(void);
    void incrementCounter(void);
    int getReplenishTime(void);
    ~MITTSController(void);
private:
    int getBin(int);

};
