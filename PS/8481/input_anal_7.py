f = open("gen7.out","r")
lines = f.readlines()

pre_lines = lines[:468]
post_lines = lines[468:]

i = 0
cnt = 0
while i < len(pre_lines) :
    if len(pre_lines[i]) <= 2:
        i+=6
        continue
    front_c = pre_lines[i][0]+pre_lines[i+1][0]+pre_lines[i+2][0]+pre_lines[i+3][0]+pre_lines[i+4][0]
    secon_c = pre_lines[i][1]+pre_lines[i+1][1]+pre_lines[i+2][1]+pre_lines[i+3][1]+pre_lines[i+4][1]
    if front_c+secon_c == "...#....##":
        cnt += 1
        for j in range(i, i+6):
            pre_lines[j] = pre_lines[j][2:]
    else:
        for j in range(i, i+6):
            pre_lines[j] = pre_lines[j][1:]
print(cnt)

i = 0
cc = 0
POST_str = ""
while i < len(post_lines):
    front_c = post_lines[i+1][0] + post_lines[i+2][0] + post_lines[i+3][0] + post_lines[i+4][0] + post_lines[i+5][0]
    # 0
    if front_c == ".###.":
        cc+=1
        POST_str += "0"
        for j in range(i, i+6):
            post_lines[j] = post_lines[j][7:]
    # 1
    elif front_c == "#....":
        cc+=1
        POST_str += "1"
        for j in range(i, i+6):
            post_lines[j] = post_lines[j][4:]
    # 2
    elif front_c == ".#..#":
        cc+=1
        POST_str += "2"
        for j in range(i, i+6):
            post_lines[j] = post_lines[j][7:]
    # 9
    elif front_c == ".#...":
        cc+=1
        POST_str += "9"
        for j in range(i, i+6):
            post_lines[j] = post_lines[j][7:]
    else:
        print(cc)
        cc=0
        i += 6

print(POST_str)