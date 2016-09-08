Stranger Things Wall project
============================

Send your own messages from the upside down with this creepy project!

Using [individually addressable LEDs](https://www.sparkfun.com/products/12986),
we've recreated Joyce's Christmas light message board from the Netflix original
series "Stranger Things". In this repository, you'll find the code necessary to
enable a string of LEDs to capture and display tweets.

You'll need some kind of Arduino to communicate with the LEDs (we used a
[Pro Mini](https://www.sparkfun.com/products/11113) and some kind of PC that
can run Python (we used a [pcDuino3](https://www.sparkfun.com/products/12856)
because of its built in WiFi and native Python support, and because we had one
lying around unused, but any internet enabled SBC should work).

The Arduino code was written in the Arduino.cc IDE v1.6.9, and the Python code
is running under Python 2.7.3. You'll need the Adafruit Neopixel library, which
can be found in the Library Manager inside the Arduino IDE, and
[TwitterSearch](https://pypi.python.org/pypi/TwitterSearch/) Python library,
which can be easily installed via pip.

Additionally, you'll have to create your own "credentials.py" file with your
Twitter application credential details; see
[apps.twitter.com](apps.twitter.com) for more information on doing just that.

Have fun, and if you make your own version, please send us pictures!

