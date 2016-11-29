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

#include "OptionScreen.h"


//==============================================================================
OptionScreen::OptionScreen ()
{

    addAndMakeVisible (keySelector = new ComboBox ("keySelector"));
    keySelector->setEditableText (false);
    keySelector->setJustificationType (Justification::centred);
    keySelector->setTextWhenNothingSelected (TRANS("key"));
    keySelector->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    keySelector->addItem (TRANS("None"), 1);
    keySelector->addItem (TRANS("C"), 2);
    keySelector->addItem (TRANS("C#/Db"), 3);
    keySelector->addItem (TRANS("D"), 4);
    keySelector->addItem (TRANS("D#/Eb"), 5);
    keySelector->addItem (TRANS("E"), 6);
    keySelector->addItem (TRANS("F"), 7);
    keySelector->addItem (TRANS("F#/Gb"), 8);
    keySelector->addItem (TRANS("G"), 9);
    keySelector->addItem (TRANS("G#/Ab"), 10);
    keySelector->addItem (TRANS("A"), 11);
    keySelector->addItem (TRANS("A#/Bb"), 12);
    keySelector->addItem (TRANS("B"), 13);
    keySelector->addListener (this);

    addAndMakeVisible (octaveSelector = new ComboBox ("octaveSelector"));
    octaveSelector->setEditableText (false);
    octaveSelector->setJustificationType (Justification::centred);
    octaveSelector->setTextWhenNothingSelected (TRANS("octave"));
    octaveSelector->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    octaveSelector->addItem (TRANS("0"), 1);
    octaveSelector->addItem (TRANS("1"), 2);
    octaveSelector->addItem (TRANS("2"), 3);
    octaveSelector->addItem (TRANS("3"), 4);
    octaveSelector->addItem (TRANS("4"), 5);
    octaveSelector->addItem (TRANS("5"), 6);
    octaveSelector->addItem (TRANS("6"), 7);
    octaveSelector->addItem (TRANS("7"), 8);
    octaveSelector->addItem (TRANS("8"), 9);
    octaveSelector->addListener (this);

    addAndMakeVisible (bpmSlider = new Slider ("bpmSlider"));
    bpmSlider->setRange (40, 140, 5);
    bpmSlider->setSliderStyle (Slider::LinearVertical);
    bpmSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    bpmSlider->addListener (this);

    addAndMakeVisible (numNotesSlider = new Slider ("numNotesSlider"));
    numNotesSlider->setRange (1, 12, 1);
    numNotesSlider->setSliderStyle (Slider::LinearVertical);
    numNotesSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    numNotesSlider->addListener (this);

    addAndMakeVisible (inputSelector = new ComboBox ("inputSelector"));
    inputSelector->setEditableText (false);
    inputSelector->setJustificationType (Justification::centred);
    inputSelector->setTextWhenNothingSelected (TRANS("choose input method"));
    inputSelector->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    inputSelector->addListener (this);

    addAndMakeVisible (startButton = new TextButton ("startButton"));
    startButton->setButtonText (TRANS("Start"));
    startButton->addListener (this);

    addAndMakeVisible (noteButton = new TextButton ("noteButton"));
    noteButton->setButtonText (TRANS("Notes"));
    noteButton->setConnectedEdges (Button::ConnectedOnRight);
    noteButton->setRadioGroupId (1234);
    noteButton->setClickingTogglesState(true);
    noteButton->addListener (this);

    addAndMakeVisible (chordButton = new TextButton ("chordButton"));
    chordButton->setButtonText (TRANS("Chords"));
    chordButton->setConnectedEdges (Button::ConnectedOnLeft);
    chordButton->setRadioGroupId (1234);
    chordButton->setClickingTogglesState(true);
    chordButton->addListener (this);

    addAndMakeVisible (relativeButton = new TextButton ("relativeButton"));
    relativeButton->setButtonText (TRANS("Relative"));
    relativeButton->setConnectedEdges (Button::ConnectedOnRight);
    relativeButton->setRadioGroupId (2345);
    relativeButton->setClickingTogglesState(true);
    relativeButton->addListener (this);

    addAndMakeVisible (absoluteButton = new TextButton ("absoluteButton"));
    absoluteButton->setButtonText (TRANS("Absolute"));
    absoluteButton->setConnectedEdges (Button::ConnectedOnLeft);
    absoluteButton->setRadioGroupId (2345);
    absoluteButton->setClickingTogglesState(true);
    absoluteButton->addListener (this);

    addAndMakeVisible (totalItemsLabel = new Label ("totalItemsLabel",
                                                    TRANS("Total Items")));
    totalItemsLabel->setFont (Font (15.00f, Font::plain));
    totalItemsLabel->setJustificationType (Justification::centred);
    totalItemsLabel->setEditable (false, false, false);
    totalItemsLabel->setColour (Label::textColourId, Colours::white);
    totalItemsLabel->setColour (TextEditor::textColourId, Colours::black);
    totalItemsLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (bpmLabel = new Label ("bpmLabel",
                                             TRANS("BPM")));
    bpmLabel->setFont (Font (15.00f, Font::plain));
    bpmLabel->setJustificationType (Justification::centred);
    bpmLabel->setEditable (false, false, false);
    bpmLabel->setColour (Label::textColourId, Colours::white);
    bpmLabel->setColour (TextEditor::textColourId, Colours::black);
    bpmLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    
    addChildComponent(playingScreen);
    setSize (400, 600);

}

OptionScreen::~OptionScreen()
{

    keySelector = nullptr;
    octaveSelector = nullptr;
    bpmSlider = nullptr;
    numNotesSlider = nullptr;
    inputSelector = nullptr;
    startButton = nullptr;
    noteButton = nullptr;
    chordButton = nullptr;
    relativeButton = nullptr;
    absoluteButton = nullptr;
    totalItemsLabel = nullptr;
    bpmLabel = nullptr;

}

//==============================================================================
void OptionScreen::paint (Graphics& g)
{
    g.fillAll (Colour (0xff292929));
}

void OptionScreen::resized()
{

    keySelector->setBounds (120, 160, 72, 40);
    octaveSelector->setBounds (32, 160, 72, 40);
    bpmSlider->setBounds (208, 152, 56, 144);
    numNotesSlider->setBounds (280, 152, 56, 144);
    inputSelector->setBounds (32, 352, 312, 32);
    startButton->setBounds (24, 448, 328, 72);
    noteButton->setBounds (32, 72, 72, 24);
    chordButton->setBounds (104, 72, 72, 24);
    relativeButton->setBounds (200, 72, 72, 24);
    absoluteButton->setBounds (272, 72, 72, 24);
    totalItemsLabel->setBounds (272, 120, 72, 24);
    bpmLabel->setBounds (208, 120, 56, 24);
    
    playingScreen.setBounds(0, 0, getWidth(), getHeight());

}

void OptionScreen::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    if (comboBoxThatHasChanged == keySelector)
    {

    }
    else if (comboBoxThatHasChanged == octaveSelector)
    {

    }
    else if (comboBoxThatHasChanged == inputSelector)
    {

    }
}

void OptionScreen::sliderValueChanged (Slider* sliderThatWasMoved)
{
    if (sliderThatWasMoved == bpmSlider)
    {

    }
    else if (sliderThatWasMoved == numNotesSlider)
    {

    }
}

void OptionScreen::buttonClicked (Button* buttonThatWasClicked)
{

    if (buttonThatWasClicked == startButton)
    {
        playingScreen.setVisible(true);
       // addAndMakeVisible(playingScreen);
    }
    else if (buttonThatWasClicked == noteButton)
    {

    }
    else if (buttonThatWasClicked == chordButton)
    {

    }
    else if (buttonThatWasClicked == relativeButton)
    {

    }
    else if (buttonThatWasClicked == absoluteButton)
    {

    }

}


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="OptionScreen" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff292929"/>
  <COMBOBOX name="keySelector" id="f68564bcc0951f3d" memberName="keySelector"
            virtualName="" explicitFocusOrder="0" pos="120 160 72 40" editable="0"
            layout="36" items="None&#10;C&#10;C#/Db&#10;D&#10;D#/Eb&#10;E&#10;F&#10;F#/Gb&#10;G&#10;G#/Ab&#10;A&#10;A#/Bb&#10;B"
            textWhenNonSelected="key" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="octaveSelector" id="a52f6105131d39be" memberName="octaveSelector"
            virtualName="" explicitFocusOrder="0" pos="32 160 72 40" editable="0"
            layout="36" items="0&#10;1&#10;2&#10;3&#10;4&#10;5&#10;6&#10;7&#10;8"
            textWhenNonSelected="octave" textWhenNoItems="(no choices)"/>
  <SLIDER name="bpmSlider" id="86e2cb1534732a1e" memberName="bpmSlider"
          virtualName="" explicitFocusOrder="0" pos="208 152 56 144" min="40"
          max="140" int="5" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="numNotesSlider" id="f06390861d622f1a" memberName="numNotesSlider"
          virtualName="" explicitFocusOrder="0" pos="280 152 56 144" min="1"
          max="12" int="1" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <COMBOBOX name="inputSelector" id="44ad8119e7cac99a" memberName="inputSelector"
            virtualName="" explicitFocusOrder="0" pos="32 352 312 32" editable="0"
            layout="36" items="" textWhenNonSelected="choose input method"
            textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="startButton" id="d645654c2267cd3c" memberName="startButton"
              virtualName="" explicitFocusOrder="0" pos="24 448 328 72" buttonText="Start"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="noteButton" id="9525589b16fa05b2" memberName="noteButton"
              virtualName="" explicitFocusOrder="0" pos="32 72 72 24" buttonText="Notes"
              connectedEdges="2" needsCallback="1" radioGroupId="1234"/>
  <TEXTBUTTON name="chordButton" id="ee22cef203a74e6" memberName="chordButton"
              virtualName="" explicitFocusOrder="0" pos="104 72 72 24" buttonText="Chords"
              connectedEdges="1" needsCallback="1" radioGroupId="1234"/>
  <TEXTBUTTON name="relativeButton" id="9ff5ccc88396c403" memberName="relativeButton"
              virtualName="" explicitFocusOrder="0" pos="200 72 72 24" buttonText="Relative"
              connectedEdges="2" needsCallback="1" radioGroupId="2345"/>
  <TEXTBUTTON name="absoluteButton" id="604433607ef62522" memberName="absoluteButton"
              virtualName="" explicitFocusOrder="0" pos="272 72 72 24" buttonText="Absolute"
              connectedEdges="1" needsCallback="1" radioGroupId="2345"/>
  <LABEL name="totalItemsLabel" id="7ff5796c5f83c360" memberName="totalItemsLabel"
         virtualName="" explicitFocusOrder="0" pos="272 120 72 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Total Items" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="bpmLabel" id="b68e0822a15180fd" memberName="bpmLabel" virtualName=""
         explicitFocusOrder="0" pos="208 120 56 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="BPM" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
