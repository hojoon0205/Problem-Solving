f = open("gen2.out", "r")
l = f.readline()

arr = l.split(", ")
#print(len(arr))
arr = arr[:-1]

nums = [ int(x) for x in arr ]
for i in range(len(nums)-2):
    if nums[i] + nums[i+1] != nums[i+2] and nums[i] + nums[i+1] != nums[i+2] + 9099099909999099999:
        print(nums[i]+nums[i+1]-nums[i+2])