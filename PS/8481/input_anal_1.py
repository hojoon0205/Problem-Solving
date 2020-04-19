f = open("gen1.out","r")
l = f.readline()
n = len(l)
cnt = 1
idx = 1
chars = []
string = ""
nums = []
while idx < n:
    if l[idx] != l[idx-1]:# or (len(nums)>2 and cnt > nums[0]):
        #print(l[idx-1], cnt)
        chars.append(l[idx-1])
        string += l[idx-1]
        nums.append(cnt)
        cnt = 1
    else:
        cnt += 1
    idx += 1        

#print(l[n-1], cnt)
chars.append(l[n-1])
string += l[n-1]
nums.append(cnt)

print(len(chars), len(nums))
print(string)
#print(nums)
# for num in nums:
#     if num >= 3000:
#         print(num)
print(nums[:10])
a = [ 2932-x for x in nums ]
print(a)

s = 0
res = ""
for i in range(3000):
    if s >= len(l):
        break
    
    res += l[s]
    r = 2932 - ((i*i)%2932)
    s += r

print(res)