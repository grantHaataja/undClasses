#Grant Haataja
#Program 1
import random

def fillList( dope ):
	for item in range(20):
		item = random.randint(0,100)
		dope.append(item)

def findHighest( dope ):
	myMax = 0
	for i in range(20):
		if dope[i] > myMax:
			myMax = dope[i]	
	return myMax

def findLowest( dope ):
	myMin = 100
	for i in range(20):
		if dope[i] < myMin:
			myMin = dope[i]	
	return myMin

def findAverage( dope ):
	mySum = 0.0
	myAvg = 0.0
	for i in range(20):
		mySum += dope[i]
	myAvg = mySum / len(dope)
	return myAvg

def printValues( dope ):
	print('\nValues ')
	for i in range(20):
		print('%2d  % 3d' %((i+1),dope[i]) )


#main code
dopeList = []

fillList(dopeList)

highValue = findHighest(dopeList)

print('High value',highValue)

lowValue = findLowest(dopeList)

print('Low value',lowValue)

avgValue = findAverage(dopeList)

print('Average',avgValue)

printValues(dopeList)

