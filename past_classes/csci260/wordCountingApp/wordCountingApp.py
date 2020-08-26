import tweepy

# Consumer Keys
TOKEN = 'bsXNLJroI35M306xLEa74o5L6'
SECRET = 'KIAbyjzwyBpskwG5K6FYk3dW2jVdtjtAmOUAh8B7ozwBPzjNXl'

# Create OAuthHandler Instance
auth = tweepy.OAuthHandler(TOKEN, SECRET)

def getAuth():
	'''
	Request token_url from twitterAPI. Then use that to get consumer keys. 
	Should only need to do once, save the keys to a file and reuse them.
	Only re-call this method if something gets messed up and we need new keys.
	
	Saves data to "token.data"
	'''

	# Request token_url from twitterAPI
	redirect_url = ''
	try:
		redirect_url = auth.get_authorization_url()
	except tweepy.TweepError:
		print('Error! Failed to get request token. Exiting...')
		exit()
		
	print('TwitterAPI URL is: ' + redirect_url)
	verifier = input('Enter Verifier from URL: ')
	
	try:
		auth.get_access_token(verifier)
	except tweepy.TweepError:
		print('Error! Failed to get access token. Exiting...')
		exit()
	
	tokenFile = open('token.data', 'w')
	tokenFile.write(auth.access_token + '\n' + auth.access_token_secret)
	tokenFile.close()
	return auth.access_token, auth.access_token_secret
	
def main():
	tokenFile = None
	access_token = None
	access_token_secret = None
	# Try opening file to get access tokens, else run authorization method
	try:
		tokenFile = open('token.data', 'r')
	except FileNotFoundError:
		print('Consumer Token Data missing. Running authorization script')
		access_token, access_token_secret = getAuth()
	# if access_token is None, then the file was opened
	if access_token is None:
		access_token = tokenFile.readline().strip()
		access_token_secret = tokenFile.readline().strip()
		auth.set_access_token(access_token, access_token_secret)
	# For checking purposes
	#print(access_token + '\n' + access_token_secret)
	
	# Actually access the API!
	api = tweepy.API(auth)
	
	

main()
		
