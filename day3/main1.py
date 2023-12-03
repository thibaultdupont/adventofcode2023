with open("input") as f:
    ans = 0
    lines = [x.rstrip() for x in f.readlines()]
    for ln, l in enumerate(lines):
        valid=False
        current=0
        for cn, c in enumerate(l):
            if c.isdecimal():
                if l[cn-1].isdecimal():
                    current*=10
                current+=int(c)
                if not valid:
                    for i in range(-1,2):
                        for j in range(-1,2):
                            if ln+j>=0 and ln+j<len(lines) and cn+i>=0 and cn+i<len(l):
                                nc = lines[ln+j][cn+i]
                                if not nc.isdecimal() and nc!='.':
                                    valid = True
            else:
                if valid :
                    ans+=current
                valid=False
                current = 0
        if valid :
            ans+=current
    print(ans)
