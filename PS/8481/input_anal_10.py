import numpy as np

f = open("gen10.out","r")
lines = f.readlines()
lines = lines[94:]

#print(lines[:5])

As = []
Bs = []
A = []
B = []
for line in lines:
    if len(line) < 5:
        As.append(np.matrix(A))
        Bs.append(np.matrix(B))
        A = []
        B = []
        continue
    sw = True
    Al = []
    Bl = []
    while len(line) > 0:
        if line[0:2] == " 0":
            if not sw:
                Al.append(0)
            else:
                Bl.append(0)
            line = line[2:]
        elif line[0:2] == " 1":
            if not sw:
                Al.append(1)
            else:
                Bl.append(1)
            line = line[2:]
        elif line[0:6] == "      " or line[0] == 'A' or line[0] == 'B':
            sw = not sw
            line = line[5:]
        else:
            line = line[1:]
    A.append(Al)
    B.append(Bl)

# print(As[69])
# print(Bs[69])
# print(len(As))

for N in range(10000):
    if np.array_equal((As[11]**N)%2, Bs[11]):
        print(N)

N = 9099099909999099999
while True:
    if N // 1000000 > (N-126) // 1000000:
        print("Testing.......", N)
    chk = True
    for i in range(len(As)):
        if not np.array_equal((As[i]**(N))%2,Bs[i]):
            chk = False
            break
    if chk:
        print(N, "Found!!!")
        break
    N += 126