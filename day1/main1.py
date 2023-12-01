with open("input") as f:
    ans = 0
    lines = [x for x in f.readlines()]
    for line in lines:
        nums = [x for x in line if x.isdigit()]
        ans += 10*int(nums[0])+int(nums[-1])
    print(ans)
