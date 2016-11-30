#ifndef __JUCE_HEADER_B6210BBE8F3E093A__
#define __JUCE_HEADER_B6210BBE8F3E093A__

#include "../JuceLibraryCode/JuceHeader.h"
class MainContentComponent;

class OptionScreen  : public Component,
                      public ComboBoxListener,
                      public SliderListener,
                      public ButtonListener
{
public:
    //==============================================================================
    OptionScreen (MainContentComponent&);
    ~OptionScreen();



    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    
    int  key;
    int  octave;
    int  BPM;
    int  numNotes;
    int  input;
    bool noteMode;
    bool relativeMode;
    
private:
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

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OptionScreen)
};


#endif   // __JUCE_HEADER_B6210BBE8F3E093A__
