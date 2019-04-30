import json

jsonNum = 100
tweets = []
profanity = []

# Load profanity list
fprofanity = open('Profanity.txt', 'r')
for text in fprofanity:
	profanity += [text.strip().lower()]

# Load tweets
for i in range(1, jsonNum+1):
	temp = open('word' + str(i) + '.json', 'r')
	temp = json.load(temp)
	for tweet in temp['statuses']:
		tweets += [tweet['text'].lower()]
		
profaneTweets = []
uses = {}
for prof in profanity:
	uses.update({prof:0})

for tweet in tweets:
	for word in profanity:
		if ' ' + word + ' ' in tweet:
			uses.update({word:uses[word]+1})
			if tweet not in profaneTweets: 
				profaneTweets += [tweet]

print('\tProfane Tweets:')
print(str(len(profaneTweets)) + '/' + str(len(tweets)))
print('\n\tUses:')
for use in uses:
	print(use + ': ' + str(uses[use]))
