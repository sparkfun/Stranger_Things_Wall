#!/usr/bin/pyt:hon
from TwitterSearch import *
import re
import serial
from time import sleep
#from credentials import *
import credentials

regex = re.compile('[^a-zA-Z]')
sft = re.compile('#cathings')
myPort = serial.Serial('/dev/ttyUSB0', 115200, timeout = 10)
myPort.write("Hello, world!")

tweet_id_list = []

while True:
	try:
		print "Searching..."
		tso = TwitterSearchOrder() # create a TwitterSearchOrder object
		tso.set_keywords(['#cathings']) # let's define all words we would like to have a look for
		tso.set_include_entities(False) # and don't give us all those entity information
                consumer_key = credentials.login['consumer_key'] 
                consumer_secret = credentials.login['consumer_secret']
                access_token = credentials.login['access_token']
                access_token_secret = credentials.login['access_token_secret'

	    # it's about time to create a TwitterSearch object with our secret tokens
		ts = TwitterSearch(consumer_key, consumer_secret, access_token, access_token_secret)
                print "duh"

	     # this is where the fun actually starts :)
		for tweet in ts.search_tweets_iterable(tso):
			if tweet['id'] not in tweet_id_list:
				no_hashtag = sft.sub('',  tweet['text'])
				text_only = regex.sub('', no_hashtag).encode('ascii', 'ignore')
				tweet_id_list.append(tweet['id'])
				for character in text_only:
					print character
					myPort.write(character)
					sleep(0.5)

	except TwitterSearchException as e: # take care of all those ugly errors if there are some
	    print(e)

	sleep(60)

myPort.close()
