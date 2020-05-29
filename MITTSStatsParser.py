activeCores = 2                           #number of cores
step = 1000000
fp = open('out.txt', 'r')
line = fp.readline()
vals = []
vals.append(0)
vals.append(0)
time = 0
lastTime = 0
iter = 0
while line:
    if "system.membus" in line:
        list = line.split(': ')
        #print(list[0] + ',' + list[3][:-1])
        time = int(list[0])

        if time - lastTime < step:
            vals[int(list[3][:-1])] = vals[int(list[3][:-1])] + 1
        else:
            print(str(iter*step) + ',' + str(vals[0]) + ',' + str(vals[1]))
            vals[0] = 0
            vals[1] = 0
            lastTime = time
            iter = iter + 1

    if "suspend contextId" in line:
        activeCores = activeCores - 1

    if activeCores == 1:
        break

    line = fp.readline()

fp.close()
