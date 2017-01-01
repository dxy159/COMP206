import sys
import os
import re
import random

wordPairs = []
sentenceEnders = []

def normalize(word):
	if '-' in word:
		word.replace('-', ' ').split(' ')
	word = re.sub('[^a-zA-Z]+', '', word)
	word = word.lower()
	return word

try:
	for i in range(1, len(sys.argv)):
		with open(sys.argv[i]) as file:
			for line in file:

				for word1 in line.split():

					if '.' in word1:
						sentenceEnders.append(normalize(word1))

					word1 = normalize(word1)

					for word2 in line.split():
						word2 = normalize(word2)

						if (word1 == word2):
							continue
						
						wordPairs.append((word1, word2))


except IOError:
	print "I/O error"


while (1):
	message = raw_input("Send:\t")
	QN = message.split()[-1]
	response = "Received:\t"

	Ri = ""
	Rj = ""
	isEnd = False

	for i in range(20):


		if (response == "Received:\t"):
			R1 = ""
			for item in wordPairs:
				if (QN == item[0]):
					R1 = item[1]
				else:
					R1 = wordPairs[random.randint(0, len(wordPairs) - 1)][0]

			Ri = R1
			R1 = R1.capitalize()
			response += (R1 + " ")

		for item in wordPairs:

			if (Ri == item[0]):
				Rj = item[1]
				break

			if (Ri in sentenceEnders) and (Rj in sentenceEnders):
				isEnd = True
				break

		if (isEnd):
			break

		response += (Rj + " ")
		Ri = Rj

	response += "."
	print response



	













