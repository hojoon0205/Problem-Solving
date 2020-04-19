import sys
import random

random.seed(0)

class Photo:
  def __init__(self, num, type, tags):
    self.num = num
    self.type = type
    self.tags = tags

  def __repr__(self):
    return "Photo({},{},{})".format(self.num, self.type, self.tags)

class Slide:
  def __init__(self, photo1, photo2=None):
    self.type = photo1.type
    self.photo1 = photo1
    self.photo2 = photo2
    self.tags = photo1.tags
    if photo2 != None:
      self.tags = self.tags | photo2.tags

  def getScore(self, s):
    left = self.tags - s.tags
    right = s.tags - self.tags
    inter = self.tags & s.tags
    return min(len(left), len(right), len(inter))

photos = []
slides = []

def getInput():
  N = int(input())
  for i in range(N):
    photo = input().split()
    photos.append(Photo(i, photo[0], set(photo[2:])))

def printResult(filename):
  f = open(filename, 'w')
  f.write('{}\n'.format(len(slides)))
  for slide in slides:
    if slide.type == "H":
      f.write('{}\n'.format(slide.photo1.num))
    else:
      f.write('{} {}\n'.format(slide.photo1.num, slide.photo2.num))

def getScore():
  score = 0
  for i in range(len(slides)-1):
    score += slides[i].getScore(slides[i+1])
  return score

########################################

def makeSlides():
  # 2
  random.shuffle(photos)

  tempVert = []
  for photo in photos:
    if photo.type == "H":
      slides.append(Slide(photo))
    else:
      tempVert.append(photo)
      if len(tempVert) == 2:
        slides.append(Slide(tempVert[0], tempVert[1]))
        tempVert = []

  # 1
  slides.sort(key=lambda s: len(s.tags))

# 4
def orderSlides(population):
  global slides

  for i in range(len(slides)-1):
    if i % 1000 == 0:
      print('Ordered {} slides...'.format(i))
    sample = random.sample(range(i+1, len(slides)), min(population, len(slides)-i-1))
    maxScore, idx = -1, 0
    for s in sample:
      score = slides[i].getScore(slides[s])
      if score > maxScore:
        maxScore = score
        idx = s

  slides[i], slides[idx] = slides[idx], slides[i]

# 3
def mutate(tries):
  success = 0

  for i in range(tries):
    if (i % 1000 == 0):
      print('{} mutations: {} successful'.format(i, success))

    a = random.randint(1, len(slides)-2)
    b = random.randint(1, len(slides)-2)

    mutationType = random.randint(1, 2)

    if mutationType == 1:
      scoreDiff = getHDiff(a, b)
      if scoreDiff > 0:
        success += 1
        slides[a], slides[b] = slides[b], slides[a]
    else:
      scoreDiff = getVDiff(a, b)
      if scoreDiff > 0:
        success += 1
        slideA = Slide(slides[a].photo1, slides[b].photo1)
        slideB = Slide(slides[a].photo2, slides[b].photo2)
        slides[a], slides[b] = slideA, slideB

# 6
def getHDiff(a, b):
  old = slides[a-1].getScore(slides[a]) + slides[a].getScore(slides[a+1]) +\
    slides[b-1].getScore(slides[b]) + slides[b].getScore(slides[b+1])
  new = slides[a-1].getScore(slides[b]) + slides[b].getScore(slides[a+1]) +\
    slides[b-1].getScore(slides[a]) + slides[a].getScore(slides[b+1])
  return new - old

# 8
def getVDiff(a, b):
  old = slides[a-1].getScore(slides[a]) + slides[a].getScore(slides[a+1]) +\
    slides[b-1].getScore(slides[b]) + slides[b].getScore(slides[b+1])

  slideA = Slide(slides[a].photo1, slides[b].photo1)
  slideB = Slide(slides[a].photo2, slides[b].photo2)

  new = slides[a-1].getScore(slideA) + slideA.getScore(slides[a+1]) +\
    slides[b-1].getScore(slideB) + slideB.getScore(slides[b+1])
  return new - old

########################################

def main():
  if len(sys.argv) < 2:
    print("Usage: python main.py [outpath]")
    exit(1)
  print("Writing file to {}...".format(sys.argv[1]))

  getInput()
  # print(N, photos[:5])
  makeSlides()
  orderSlides(1)
  mutate(2000000)

  print(getScore())
  printResult(sys.argv[1])

if __name__ == '__main__':
  main()
