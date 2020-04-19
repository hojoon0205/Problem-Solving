f = open("gen9.out","r")
lines = f.readlines()

# 1003 x 1003

chk = []
for i in range(1003):
    l = []
    for j in range(1003):
        l.append(False)
    chk.append(l)

ans = 0
for i in range(1003):
    for j in range(1003):
        if chk[i][j] or lines[i][j]!='#':
            continue
        x,y = i,j
        ans += 1
        if lines[x+1][y]=='#' and lines[x+2][y]=='#':
            c = 0
            while lines[x][y] == '#':
                c += 1
                chk[x][y] = True
                x += 1
            print("{" + str(i) + "," + str(j) + ",0," + str(c) + "},", end="")
        elif lines[x][y+1]=='#' and lines[x][y+2]=='#':
            c = 0
            while lines[x][y] == '#':
                c += 1
                chk[x][y] = True
                y += 1
            print("{" + str(i) + "," + str(j) + ",1," + str(c) + "},", end="")
        elif lines[x+1][y-1]=='#' and lines[x+2][y-2]=='#':
            c = 0
            while lines[x][y] == '#':
                c += 1
                chk[x][y] = True
                x += 1
                y -= 1
            print("{" + str(i) + "," + str(j) + ",2," + str(c) + "},", end="")
        elif lines[x+1][y+1]=='#' and lines[x+2][y+2]=='#':
            c = 0
            while lines[x][y] == '#':
                c += 1
                chk[x][y] = True
                x += 1
                y += 1
            print("{" + str(i) + "," + str(j) + ",3," + str(c) + "},", end="")

#print(ans)

for i in range(1003):
    for j in range(1003):
        if lines[i][j]=='#' and chk[i][j]==False:
            print("Error")