#include "MITTS.hh"
#include "mem/cache/cache.hh"
#include "sim/sim_object.hh"

class MITTSL1Cache : public Cache {

    protected:
        MITTSController mitts;
        EventFunctionWrapper counterEvent;
        EventFunctionWrapper replenishEvent;
        const Tick counterLatency;
        const Tick replenishLatency;
    public:
        MITTSL1Cache(const CachParams *p);
    private:

}