# SimonSounds
A one-player game for ear training. Mimics the rules of Simon Says.

## Dependencies
*Juce 4.3
*The Aubio Framework, which is included in this repository. It can also be found [here](https://www.aubio.org).

## Installation
Clone to a convenient space, then pull the aubio framework into the project. In JUCE there is a spot for extra frameworks. Sometimes xCode has hiccups with this and you'll need to pull it into that separately. You can drag it straight into the Frameworks folder in the xCode project. If this does not work, go to Build Phases and drag it into the "Link Binary with Libraries" section - even if it is already there. Also be sure to reset your JUCE Modules paths.

If you don't want to build it yourself, download the .dmg file!

## Features
3 ways to interface with the app:
  * Use the buttons on the app itself
  * Connect a MIDI keyboard
  * Use real instrument - yes, it can listen to you!
 
