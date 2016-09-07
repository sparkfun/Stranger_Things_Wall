#!/usr/bin/python
from TwitterSearch import *
import re
import serial
from time import sleep
from credentials import *

regex = re.compile('[^a-zA-Z]')
sft = re.compile('#sparkfunthings')
myPort = serial.Serial('/dev/ttyUSB0', 115200, timeout = 10)
myPort.write("Hello, world!")

try:
    tso = TwitterSearchOrder() # create a TwitterSearchOrder object
    tso.set_keywords(['#sparkfunthings']) # let's define all words we would like to have a look for
    tso.set_include_entities(False) # and don't give us all those entity information

    # it's about time to create a TwitterSearch object with our secret tokens
    ts = TwitterSearch(
        consumer_key = twitter_consumer_key,
        consumer_secret = twitter_consumer_secret,
        access_token = twitter_access_token,
        access_token_secret = twitter_access_token_secret
     )

     # this is where the fun actually starts :)
    for tweet in ts.search_tweets_iterable(tso):
	no_hashtag = sft.sub('',  tweet['text'])
	text_only = regex.sub('', no_hashtag).encode('ascii', 'ignore')
	print type(text_only)
	for character in text_only:
		print character
		myPort.write(character)
		sleep(0.5)
##        print( '@%s tweeted: %s' % ( tweet['user']['screen_name'], tweet['text'] ) )

except TwitterSearchException as e: # take care of all those ugly errors if there are some
    print(e)

myPort.close()
