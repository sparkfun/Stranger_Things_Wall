'''
This file uses the tweepy library to stream all public tweets with the hashtag
#halloween.. I probably should change it so the hashtag to search for can be
entered by the user but I haven't done that yet.

To run this code you need a 'cred.yml' file in a sibling directory named 'conf'
This yml file needs four entries:
consumer_key
consumer_secret
access_token
access_token-secret

yaml format is super easy. Learn about it here: http://www.yaml.org/

'''

import tweepy
import yaml

conf = yaml.load(open('conf/cred.yml'))

#override the tweepy stream listener class 
class MyStreamListener(tweepy.StreamListener):

    def on_status(self, status):
        #when you retrieve a status, print it out
        print(status.text)

    def on_error(self, status_code):
        if status_code == 420:
            #returning False in on_data disconnects the stream
            return False

def main():
    #authorize the connection to twitter
    auth=tweepy.OAuthHandler(conf['consumer_key'], conf['consumer_secret'])
    auth.set_access_token(conf['access_token'], conf['access_token_secret'])

    api = tweepy.API(auth)

    while(True):
        try:
            #stream tweets indefinitely
            myStreamListener = MyStreamListener()
            myStream = tweepy.Stream(auth = api.auth, listener=myStreamListener)
            myStream.filter(track=['#halloween'])
        except UnicodeEncodeError as e:
            print("\n")
            print(e)
            print("\n")
   

main()
