with open("input") as f:
    max_color = {'red':12, 'green':13, 'blue':14}
    ans = 0
    lines = [x.rstrip() for x in f.readlines()]
    for idx, line in enumerate(lines):
        subsets = [x.split(',') for x in line.split(':')[1].split(';')]
        valid = True
        for subset in subsets:
            for color in subset:
                cpt = int(color.split()[0])
                c = color.split()[1]
                if cpt>max_color[c]:
                    valid = False
        if valid :
            ans += idx+1
    print(ans)
