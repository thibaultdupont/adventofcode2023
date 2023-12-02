with open("input") as f:
    ans = 0
    lines = [x.rstrip() for x in f.readlines()]
    for idx, line in enumerate(lines):
        subsets = [x.split(',') for x in line.split(':')[1].split(';')]
        num_color = {'red':0, 'green':0, 'blue':0}
        for subset in subsets:
            for color in subset:
                cpt = int(color.split()[0])
                c = color.split()[1]
                num_color[c] = max(cpt, num_color[c])
            power=1
        for x in num_color.values():
            power *= x
        ans += power
    print(ans)
