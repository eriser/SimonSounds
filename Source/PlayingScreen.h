#ifndef __JUCE_HEADER_97AF0122717C170__
#define __JUCE_HEADER_97AF0122717C170__

#include "../JuceLibraryCode/JuceHeader.h"

class PlayingScreen  : public Component,
                       public ButtonListener
{
public:
    //==============================================================================
    PlayingScreen ();
    ~PlayingScreen();

    //==============================================================================

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;

private:
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

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlayingScreen)
};
#endif   // __JUCE_HEADER_97AF0122717C170__
