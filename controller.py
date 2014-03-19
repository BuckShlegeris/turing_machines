from subprocess import Popen, PIPE, STDOUT



def make_and_run_tm(number_of_states):
    p = Popen(['./tm'], stdout=PIPE, stdin=PIPE, stderr=PIPE)
    stdout_data = p.communicate(input=shortTM)[0]

    return stdout_data

shortTM = """
4
1 1 1 1 1 1
2 1 1 2 1 1
3 1 1 3 1 1
-1 1 1 -1 1 1
"""

print make_and_run_tm(10);