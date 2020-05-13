
MITTSL1Cache::MITTSL1Cache(const CacheParams *p) : Cache(p) {
    schedule(this->mitts.incrementCounter, 1);
    schedule(this->mitts.replenishBins, getReplenishTime);
}