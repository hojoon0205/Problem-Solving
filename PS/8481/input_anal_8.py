f = open("gen8.out","r")
lines = f.readlines()

cnt = 0
for line in lines:
    cnt += line.count('#')
print(cnt)

bi = -1
bj = -1
ci = 500
cj = 500
ti = -1
tj = -1

s = ""

if lines[ci][cj] == '#':
    print("correct")

for i in range(cnt):
    c = 0
    if lines[ci-1][cj] == '#' and (bi != ci-1 or bj != cj):
        ti, tj = ci-1, cj
        c+=1
        s += "1"
    if lines[ci+1][cj] == '#' and (bi != ci+1 or bj != cj):
        ti, tj = ci+1, cj
        c+=1
        s += "2"
    if lines[ci][cj-1] == '#' and (bi != ci or bj != cj-1):
        ti, tj = ci, cj-1
        c+=1
        s += "3"
    if lines[ci][cj+1] == '#' and (bi != ci or bj != cj+1):
        ti, tj = ci, cj+1
        c+=1
        s += "4"
    if lines[ci-1][cj-1] == '#' and (bi != ci-1 or bj != cj-1):
        ti, tj = ci-1, cj-1
        c+=1
        s += "5"
    if lines[ci-1][cj+1] == '#' and (bi != ci-1 or bj != cj+1):
        ti, tj = ci-1, cj+1
        c+=1
        s += "6"
    if lines[ci+1][cj-1] == '#' and (bi != ci+1 or bj != cj-1):
        ti, tj = ci+1, cj-1
        c+=1
        s += "7"
    if lines[ci+1][cj+1] == '#' and (bi != ci+1 or bj != cj+1):
        ti, tj = ci+1, cj+1
        c+=1
        s += "8"
    if c != 1:
        print("error", i, c)
        break
    bi,bj,ci,cj = ci,cj,ti,tj

print(s)