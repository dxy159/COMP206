import sys
import os
import re

wordCount = {}

try:
	with open(sys.argv[1]) as file:
		for line in file:
			for word in line.split():
				if '-' in word:
					word.replace('-', ' ').split(' ')
				word = re.sub('[^a-zA-Z]+', '', word)
				word = word.lower()
				if word in wordCount:
					wordCount[word] += 1
				else:
					wordCount[word] = 1

except IOError:
	print "I/O error"

for word in sorted(wordCount.items(), key = lambda x: x[1], reverse=True):
	output = "%s:%d" % (word[0], word[1])
	print output