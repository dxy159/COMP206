import sys
import os
import re

wordPairCount = {}

def normalize(word):
	if '-' in word:
		word.replace('-', ' ').split(' ')
	word = re.sub('[^a-zA-Z]+', '', word)
	word = word.lower()
	return word


try:
	with open(sys.argv[1]) as file:
		for line in file:
			for word1 in line.split():
				word1 = normalize(word1)

				for word2 in line.split():
					word2 = normalize(word2)

					if (word1 == word2):
						continue
					pair = (word1, word2)

					if pair in wordPairCount:
						wordPairCount[pair] += 1
					else:
						wordPairCount[pair] = 1

except IOError:
	print "I/O error"

for wordPair in sorted(wordPairCount.items(), key = lambda x: x[1], reverse=True):
	output = "%s-%s:%d" % (wordPair[0][0], wordPair[0][1], wordPair[1])
	print output





