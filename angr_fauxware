#!/usr/bin/env python

import angr

# Look at fauxware.c! This is the source code for a "faux firmware" (@zardus
# really likes the puns) that's meant to be a simple representation of a
# firmware that can authenticate users but also has a backdoor - the backdoor
# is that anybody who provides the string "SOSNEAKY" as their password will be
# automatically authenticated.

def basic_symbolic_execution():
    # 新建一个angr的工程
    p = angr.Project('fauxware')

    # 新建一个SimState的对象
    state = p.factory.entry_state()
    
    # 新建一个SimulationManager对象
    sm = p.factory.simulation_manager(state)

    # 让sm对象一直执行下去，直到执行到可选择的路径个数大于一个，即产生选择分支的时候，再停止
    # 对应程序中authenticate函数的 if (strcmp(password, sneaky) == 0)这个条件判断语句
    sm.step(until=lambda lpg: len(lpg.active) > 1)

    # dump出所有分支的内容
    input_0 = sm.active[0].posix.dumps(0)
    input_1 = sm.active[1].posix.dumps(0)

    if 'SOSNEAKY' in input_0:
        return input_0
    else:
        return input_1

def test():
    pass        # appease our CI infrastructure which expects this file to do something lmao

if __name__ == '__main__':
    print basic_symbolic_execution()
