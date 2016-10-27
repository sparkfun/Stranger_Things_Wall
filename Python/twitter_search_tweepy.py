import tweepy
import yaml

conf = yaml.load(open('conf/cred.yml'))

class MyStreamListener(tweepy.StreamListener):

    def on_status(self, status):
        print(status.text)

    def on_error(self, status_code):
        if status_code == 420:
            #returning False in on_data disconnects the stream
            return False

def main():
    auth=tweepy.OAuthHandler(conf['consumer_key'], conf['consumer_secret'])
    auth.set_access_token(conf['access_token'], conf['access_token_secret'])

    api = tweepy.API(auth)

    while(True):
        try:
            myStreamListener = MyStreamListener()
            myStream = tweepy.Stream(auth = api.auth, listener=myStreamListener)
            myStream.filter(track=['#halloween'])
        except UnicodeEncodeError as e:
            print("\n")
            print(e)
            print("\n")
   

main()
