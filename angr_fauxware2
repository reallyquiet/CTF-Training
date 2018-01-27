#!/usr/bin/env python

import angr

# Look at fauxware.c! This is the source code for a "faux firmware" (@zardus
# really likes the puns) that's meant to be a simple representation of a
# firmware that can authenticate users but also has a backdoor - the backdoor
# is that anybody who provides the string "SOSNEAKY" as their password will be
# automatically authenticated.

def basic_symbolic_execution():
    
    p = angr.Project('fauxware')

    state = p.factory.entry_state()
    
    sm = p.factory.simulation_manager(state)

    sm.explore(find=lambda s: "Welcome" in s.posix.dumps(1))
    
    print sm
    return sm.found[0].posix.dumps(0)


if __name__ == '__main__':
    print basic_symbolic_execution()
