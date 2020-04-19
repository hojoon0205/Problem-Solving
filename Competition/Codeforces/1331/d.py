from urllib.request import urlopen
A = input()
B = '/b'+A[1:]+'.txt'
url = 'http://oeis.org/'+A+B
fp = urlopen(url)
s = fp.readlines()[1][2:-1]
print(s.decode())