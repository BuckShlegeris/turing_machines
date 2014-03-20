from subprocess import Popen, PIPE, STDOUT
from random import randint


def run_tm(tm):
    p = Popen(['./tm'], stdout=PIPE, stdin=PIPE, stderr=PIPE)
    stdout_data = p.communicate(input=tm)[0]

    return int(stdout_data)

def generate_tm(number_of_states):
    def generate_rule():
        return "%d %d %d"%(randint(-1,number_of_states-1), randint(0,1), randint(0,1))

    return str(number_of_states) + "\n" + "\n".join(generate_rule()
                            for x in range(number_of_states*2))


data = []

for a in range(10000):
    if a%100 == 0:
        print a
    result = run_tm(generate_tm(80))
    if result != -1:
        data.append(result)

maximum = max(data)

for x in range(0,maximum+1):
    val = data.count(x)
    if val:
        print x, data.count(x)

import matplotlib.pyplot as plt
plt.plot(range(0,maximum+1),[data.count(x) for x in range(0,maximum+1)])
plt.ylabel('some numbers')
plt.show()