\mainpage
vvopensource
============


Introduction
------------

This is a fork of the project VVopensource. See original project here: https://github.com/mrRay/vvopensource vvopensource. 
The reason for the fork is that I have modified the ISF Editor with some new features.

ISF Editor is Mac application that lets you select between a whole number of image filters and apply the to your camera feed or Syphon source. The result is published as a Syphon feed. The filters are actually shader code, and you can import from shadertoy or edit directly in this app.

I have modified ISF Editor to take in OSC signals so that it can be controlled from outside. This is handy for live visual performance. Any OSC device or app can be the source but it plays nicely together with the Mac app Vezer.

OSC setup
---------
At the bottom of the main ISF Editor window you will see what address and port receives OSC messages. Next to it you will see the messages that come in. To control a filter slider you send a number between 0-1 to the address that is the name of the slider. 
E.g. if you have selected the ASCII Art filter you can send 0.5 to /size. 

For a color selector you can send a special formatted color message. You might want to take a look at the OSCTestApp (included in this project) and send color from there. You can also send color from the app Vezer.

Other types of input such as point2d are not able to receive OSC data at this point.

It is also posiible to select a filter from the list using OSC. You do this by sending a decimal number. 0.00 is the first filter. 0.01 is the second and so forth. The reason for this format is that I want all OSC values to be between 0-1 which is a convention in many devices and OSC apps.

How to get help
---------------
If the problem has to do with OSC input, open an issue here. If you have other issues, go to the original project https://github.com/mrRay/vvopensource here, and download his ISF Editor and see if the problem is still there. If so open an issue over there.

