activeCores = 2                           #number of cores
fp = open('out.txt', 'r')

line = fp.readline()
while line:
    if "system.membus" in line:
        list = line.split(': ')
        print(list[0] + ',' + list[3][:-1])

    if "suspend contextId" in line:
        activeCores = activeCores - 1

    if activeCores == 1:
        break

    line = fp.readline()

fp.close()
