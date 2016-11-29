#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "OptionScreen.h"

class MainContentComponent   :  public AudioAppComponent

{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();
    
    void paint (Graphics&) override;
    void resized() override;
    
private:
       OptionScreen optionScreen;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
