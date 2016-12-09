/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_B6210BBE8F3E093A__
#define __JUCE_HEADER_B6210BBE8F3E093A__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class OptionScreen  : public Component,
                      public ComboBoxListener,
                      public SliderListener,
                      public ButtonListener
{
public:
    //==============================================================================
    OptionScreen ();
    ~OptionScreen();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ComboBox> keySelector;
    ScopedPointer<ComboBox> octaveSelector;
    ScopedPointer<Slider> bpmSlider;
    ScopedPointer<Slider> numNotesSlider;
    ScopedPointer<ComboBox> inputSelector;
    ScopedPointer<TextButton> startButton;
    ScopedPointer<TextButton> noteButton;
    ScopedPointer<TextButton> chordButton;
    ScopedPointer<TextButton> relativeButton;
    ScopedPointer<TextButton> absoluteButton;
    ScopedPointer<Label> totalItemsLabel;
    ScopedPointer<Label> bpmLabel;
    ScopedPointer<Label> octaveLabel;
    ScopedPointer<Label> keyLabel;
    ScopedPointer<Label> inputLabel;
    ScopedPointer<Label> highScoreLabel;
    ScopedPointer<Label> highScoreBox;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OptionScreen)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_B6210BBE8F3E093A__
