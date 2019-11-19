import os
import random
import difflib

d_corewar_path = "data/"
d_corewar = d_corewar_path + "corewar"
compiled_champ_path = d_corewar_path + "compiled/"
c_corewar_path = "./"
c_corewar = c_corewar_path + "corewar"

chmps = ['NoIdea.cor', 'Douceur_power.cor']
lst_chmps = [f for f in os.listdir(compiled_champ_path) if f[-4:] == ".cor"]

def check_chmp_name(chmp):
    if chmp[-4:] == ".cor":
        return chmp in lst_chmps
    else:
        return chmp + ".cor" in lst_chmps

def get_chmps():
    global chmps
    chmps = []
    for i in range(1, 5):
        chmp = input("Enter name of chmp n{}: ".format(i))
        if chmp:
            chmp = chmp if chmp[-4:] == '.cor' else chmp + '.cor'
        if chmp == "rnd.cor" or (not chmp and len(chmps) < 1):
            chmps.append(random.choice(lst_chmps))
        elif check_chmp_name(chmp):
            chmps.append(chmp)
        elif not chmp:
            break
        else:
            print("No such champion")

get_chmps()
cycle_num = int(input("Enter cap of cycles to test: "))
print(chmps)

corwar_command = "{version} {dump} {dump_n} {chmps} > {file}"

def run_corewars(cycle):
    os.system(corwar_command.format(version=d_corewar, dump="-d", dump_n=cycle,
                            v_arg="31", chmps=" ".join(chmps), file="d_test"))
    os.system(corwar_command.format(version=c_corewar, dump="-dump", dump_n=cycle,
                            v_arg="", chmps=" ".join(chmps), file="c_test"))
    with open("d_test", "r") as d_test, open("c_test", 'r') as c_test:
        d_content = d_test.readlines()
        c_content = c_test.readlines()
    return [line for line in difflib.unified_diff(d_content, c_content,
                                         fromfile="d_test", tofile="c_test",
                                         lineterm='', n=0)]

print("Testing {} champions".format(", ".join(chmps)))
chmps = [compiled_champ_path + l for l in chmps]
print(chmps)
if not run_corewars(cycle_num):
    print("It seems to be ok")
    exit()

cycle_top = cycle_num
cycle_bot = 0
while True:
    cmp_res = []
    if cycle_top - cycle_bot < 2:
        print("Error in cycle {}".format(cycle_top))
        for line in cmp_res:
            print(line)
        break
    cycle = (cycle_bot + cycle_top) // 2
    cmp_res = run_corewars(cycle)
    if not cmp_res:
        cycle_bot = cycle
    elif cmp_res:
        cycle_top = cycle
