f = open("gen5.out","r")
lines = f.readlines()[:-1]
#print(lines[-1])

day_month = []
daycount = []
years = []
for l in lines:
    if len(l.split('jest')) == 2:
        continue
    tmp1 = l.split(' to ')
    dm, oth = tmp1[0], tmp1[1]
    day_month.append(dm)
    tmp2 = oth.split(' dzien roku ')
    dc, year = tmp2[0], tmp2[1]
    daycount.append(dc)
    years.append(year[:-1])

day = [ x.split(' ')[:-1] for x in day_month ]
month = [ x.split(' ')[-1] for x in day_month ]

print(len(day))
print(len(set(month)))
print(len(set(daycount)))
print(len(set(years)))

for i in range(366):
    print(i+1, daycount[i])

y = 2000
print(y, years[i])
for i in range(len(years)-1):
    if years[i] != years[i+1]:
        y += 1
        print(y, years[i+1])