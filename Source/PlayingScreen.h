/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.2.4

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_97AF0122717C170__
#define __JUCE_HEADER_97AF0122717C170__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//#include "OptionScreen.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PlayingScreen  : public Component,
                       public ButtonListener
{
public:
    //==============================================================================
    PlayingScreen ();
    ~PlayingScreen();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextButton> playButton;
    ScopedPointer<TextButton> playButton2;
    ScopedPointer<TextButton> playButton3;
    ScopedPointer<TextButton> playButton4;
    ScopedPointer<TextButton> playButton5;
    ScopedPointer<TextButton> playButton6;
    ScopedPointer<TextButton> playButton7;
    ScopedPointer<TextButton> playButton8;
    ScopedPointer<TextButton> playButton9;
    ScopedPointer<TextButton> playButton10;
    ScopedPointer<TextButton> playButton11;
    ScopedPointer<TextButton> playButton12;
    
//    OptionScreen optionScreen;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlayingScreen)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_97AF0122717C170__
