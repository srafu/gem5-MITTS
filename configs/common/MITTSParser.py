
class MITTSOptions:
    def __init__(self, filePath):
        self.mittsReplenishPeriod = 0
        self.mittsTimeInterval = 0
        self.mittsNumBins = 0
        self.mittsBinCredits = []

        fp = open(filePath)
        line = fp.readline()
        linesRead = 1;
        while line:
            if linesRead == 1:
                mittsReplenishPeriod = long(line);
            elif linesRead == 2:
                mittsTimeInterval = long(line);
            elif linesRead == 3:
                mittsNumBins = int(line);
            elif linesRead == 4
                mittsBinCredits = line;

            linesRead += 1;
            line = fp.readline()

        fp.close()

    def getReplenishPeriod(self):
        return mittsReplenishPeriod
    def getTimeInterval(self):
        return mittsTimeInterval
    def getNumBins(self):
        return mittsNumBins
    def getMittsBinCredits(self):
        return mittsBinCredits


