#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "faust/Square.h"
#include <aubio/aubio.h>

//#include "OptionScreen.h"
//#include "PlayingScreen.h"

//==============================================================================

class MainContentComponent   :  public AudioAppComponent,
                                public Timer,
                                public ComboBoxListener,
                                public SliderListener,
                                public ButtonListener,
                                public MidiInputCallback,
                                public MidiKeyboardStateListener
{
public:
    //==============================================================================
    MainContentComponent()
    {
        startTime = Time::getMillisecondCounterHiRes() * 0.001;
        lastInputIndex = 0;
        
        cachedImage_background = ImageCache::getFromMemory (BinaryData::background_jpg, BinaryData::background_jpgSize);
        
        addAndMakeVisible (keySelector = new ComboBox ("keySelector"));
        keySelector->setEditableText (false);
        keySelector->setJustificationType (Justification::centred);
        keySelector->setTextWhenNothingSelected (TRANS("key"));
        keySelector->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
        keySelector->addItem (TRANS("C"), 1);
        keySelector->addItem (TRANS("C#/Db"), 2);
        keySelector->addItem (TRANS("D"), 3);
        keySelector->addItem (TRANS("D#/Eb"), 4);
        keySelector->addItem (TRANS("E"), 5);
        keySelector->addItem (TRANS("F"), 6);
        keySelector->addItem (TRANS("F#/Gb"),7);
        keySelector->addItem (TRANS("G"), 8);
        keySelector->addItem (TRANS("G#/Ab"), 9);
        keySelector->addItem (TRANS("A"), 10);
        keySelector->addItem (TRANS("A#/Bb"), 11);
        keySelector->addItem (TRANS("B"), 12);
        keySelector->addItem (TRANS("None"), 13);
        keySelector->setSelectedId(1);
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
        octaveSelector->setSelectedId(5);
        octaveSelector->addListener (this);
        
        addAndMakeVisible (bpmSlider = new Slider ("bpmSlider"));
        bpmSlider->setRange (40, 140, 5);
        bpmSlider->setSliderStyle (Slider::LinearVertical);
        bpmSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
        bpmSlider->setValue(90);
        bpmSlider->addListener (this);
        
        addAndMakeVisible (numNotesSlider = new Slider ("numNotesSlider"));
        numNotesSlider->setRange (1, 7, 1);
        numNotesSlider->setSliderStyle (Slider::LinearVertical);
        numNotesSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
        numNotesSlider->setValue(7);
        numNotesSlider->addListener (this);
        
        addAndMakeVisible (inputSelector = new ComboBox ("inputSelector"));
        inputSelector->setEditableText (false);
        inputSelector->setJustificationType (Justification::centred);
        inputSelector->setTextWhenNothingSelected (TRANS("choose input method"));
        inputSelector->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
        inputSelector->addListener (this);
        
        const StringArray midiInputs (MidiInput::getDevices());
        inputSelector->addItem (TRANS("Screen Buttons"), 1);
        inputSelector->addItem(TRANS("Internal Mic"), 2);
        inputSelector->addItemList (midiInputs, 3);
        inputSelector->setSelectedId(1); // default
        
        addAndMakeVisible (startButton = new TextButton ("startButton"));
        startButton->setButtonText (TRANS("Start"));
        startButton->addListener (this);

        addChildComponent(noteButton = new TextButton ("noteButton"));
//        addAndMakeVisible (noteButton = new TextButton ("noteButton"));
        noteButton->setButtonText (TRANS("Notes"));
        noteButton->setConnectedEdges (Button::ConnectedOnRight);
        noteButton->setRadioGroupId (1234);
        noteButton->setClickingTogglesState(true);
        noteButton->setToggleState(true, true);
        noteButton->addListener (this);
        
        addChildComponent(chordButton = new TextButton ("chordButton"));
//        addAndMakeVisible (chordButton = new TextButton ("chordButton"));
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
        relativeButton->setToggleState(true, true);
        relativeButton->addListener (this);
        relativeButton->setColour (TextButton::buttonOnColourId, Colour (0xff656566));
        
        addAndMakeVisible (absoluteButton = new TextButton ("absoluteButton"));
        absoluteButton->setButtonText (TRANS("Absolute"));
        absoluteButton->setConnectedEdges (Button::ConnectedOnLeft);
        absoluteButton->setRadioGroupId (2345);
        absoluteButton->setClickingTogglesState(true);
        absoluteButton->addListener (this);
        absoluteButton->setColour (TextButton::buttonOnColourId, Colour (0xff656566));
        
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
        
        addAndMakeVisible (octaveLabel = new Label ("octaveLabel",
                                                    TRANS("Octave")));
        octaveLabel->setFont (Font (15.00f, Font::plain));
        octaveLabel->setJustificationType (Justification::centred);
        octaveLabel->setEditable (false, false, false);
        octaveLabel->setColour (Label::textColourId, Colours::white);
        octaveLabel->setColour (TextEditor::textColourId, Colours::black);
        octaveLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
        
        addAndMakeVisible (keyLabel = new Label ("keyLabel",
                                                 TRANS("Key")));
        keyLabel->setFont (Font (15.00f, Font::plain));
        keyLabel->setJustificationType (Justification::centred);
        keyLabel->setEditable (false, false, false);
        keyLabel->setColour (Label::textColourId, Colours::white);
        keyLabel->setColour (TextEditor::textColourId, Colours::black);
        keyLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
        
        addAndMakeVisible (inputLabel = new Label ("inputLabel",
                                                   TRANS("Input")));
        inputLabel->setFont (Font (15.00f, Font::plain));
        inputLabel->setJustificationType (Justification::centred);
        inputLabel->setEditable (false, false, false);
        inputLabel->setColour (Label::textColourId, Colours::white);
        inputLabel->setColour (TextEditor::textColourId, Colours::black);
        inputLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
        
        addAndMakeVisible (highScoreLabel = new Label ("highScoreLabel",
                                                       TRANS("High Score:")));
        highScoreLabel->setFont (Font (15.00f, Font::plain));
        highScoreLabel->setJustificationType (Justification::centred);
        highScoreLabel->setEditable (false, false, false);
        highScoreLabel->setColour (Label::textColourId, Colours::white);
        highScoreLabel->setColour (TextEditor::textColourId, Colours::black);
        highScoreLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
        
        addAndMakeVisible (highScoreBox = new Label ("highScoreBox",
                                                     TRANS("0")));
        highScoreBox->setFont (Font (15.00f, Font::plain));
        highScoreBox->setJustificationType (Justification::centred);
        highScoreBox->setEditable (false, false, false);
        highScoreBox->setColour (Label::textColourId, Colours::white);
        highScoreBox->setColour (TextEditor::textColourId, Colours::black);
        highScoreBox->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
        
        for (int i=0;i<12;i++){
            playButton.add(new TextButton ("playButton" + String(i)));
            playButton[i]->addListener(this);
            addChildComponent(playButton[i]);
        }

        setSize (375, 600);
        setAudioChannels (1, 2);
        
        relChromNoteLabels.add("U");
        relChromNoteLabels.add("m2");
        relChromNoteLabels.add("M2");
        relChromNoteLabels.add("m3");
        relChromNoteLabels.add("M3");
        relChromNoteLabels.add("P4");
        relChromNoteLabels.add("TT");
        relChromNoteLabels.add("P5");
        relChromNoteLabels.add("m6");
        relChromNoteLabels.add("M6");
        relChromNoteLabels.add("m7");
        relChromNoteLabels.add("M7");
        
        relMajNoteLabels.add("U");
        relMajNoteLabels.add("M2");
        relMajNoteLabels.add("M3");
        relMajNoteLabels.add("P4");
        relMajNoteLabels.add("P5");
        relMajNoteLabels.add("M6");
        relMajNoteLabels.add("M7");
        
    }

    ~MainContentComponent()
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
        octaveLabel = nullptr;
        keyLabel = nullptr;
        inputLabel = nullptr;
        highScoreLabel = nullptr;
        highScoreBox = nullptr;
        closeAubioPitch();
        shutdownAudio();
    }
    
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override
    {
        if (comboBoxThatHasChanged == keySelector)
        {
            key = keySelector->getSelectedItemIndex();
            if (key == 12){
                numNotesSlider->setRange (1, 12, 1);
            }else{
                numNotesSlider->setRange (1, 7, 1);
            }
        }
        else if (comboBoxThatHasChanged == octaveSelector)
        {
            octave = octaveSelector->getSelectedItemIndex();
        }
        else if (comboBoxThatHasChanged == inputSelector)
        {
            input = inputSelector->getSelectedItemIndex();
            if (input >1){
                setMidiInput(input);
            }
        }
    }
    
    void sliderValueChanged (Slider* sliderThatWasMoved) override
    {
        if (sliderThatWasMoved == bpmSlider)
        {
            BPM = bpmSlider->getValue();
        }
        else if (sliderThatWasMoved == numNotesSlider)
        {
            numNotes = numNotesSlider->getValue();
        }
    }
    
    void buttonClicked (Button* buttonThatWasClicked) override
    {
        
        if (buttonThatWasClicked == startButton)
        {
            startPressed();
        }
        else if (buttonThatWasClicked == noteButton)
        {
            noteMode = true;
        }
        else if (buttonThatWasClicked == chordButton)
        {
            noteMode = false;
        }
        else if (buttonThatWasClicked == relativeButton)
        {
            relativeMode = true;
        }
        else if (buttonThatWasClicked == absoluteButton)
        {
            relativeMode = false;
        }
        
        for (int i=0;i<12;i++){
            if (buttonThatWasClicked == playButton[i]){
                //check for match
                if (input == 0){
                    if (playButton[i]->getName().getIntValue() == pitchSequence[seqCount])
                        match = true;
                    else{
                        match = false;
                    }
                }
            }
        }
    }
    
    void buttonStateChanged(Button* buttonThatWasChanged) override
    {
        for (int i=0;i<12;i++){
            if (buttonThatWasChanged == playButton[i] && waitForPlayer){
                if (buttonThatWasChanged->isDown()){
                    //play note
                    squareControl.setParamValue("/square/freq",getMidiNoteInHertz(playButton[i]->getName().getIntValue(), 440));
                    squareControl.setParamValue("/square/gate", 1);
                }else{
                    squareControl.setParamValue("/square/gate", 0);
                }
            }
        }
    }
    //==============================================================================
    void hideOptionScreen(){
        
        keySelector->setVisible(false);
        octaveSelector->setVisible(false);
        bpmSlider->setVisible(false);
        numNotesSlider->setVisible(false);
        inputSelector->setVisible(false);
        startButton->setVisible(false);
        noteButton->setVisible(false);
        chordButton->setVisible(false);
        relativeButton->setVisible(false);
        absoluteButton->setVisible(false);
        totalItemsLabel->setVisible(false);
        bpmLabel->setVisible(false);
        keyLabel->setVisible(false);
        octaveLabel->setVisible(false);
        inputLabel->setVisible(false);
        highScoreLabel->setVisible(false);
        highScoreBox->setVisible(false);
    }
    //==============================================================================
    void displayOptionScreen(){
        
        keySelector->setVisible(true);
        octaveSelector->setVisible(true);
        bpmSlider->setVisible(true);
        numNotesSlider->setVisible(true);
        inputSelector->setVisible(true);
        startButton->setVisible(true);
//        noteButton->setVisible(true);
//        chordButton->setVisible(true);
        relativeButton->setVisible(true);
        absoluteButton->setVisible(true);
        totalItemsLabel->setVisible(true);
        bpmLabel->setVisible(true);
        keyLabel->setVisible(true);
        octaveLabel->setVisible(true);
        inputLabel->setVisible(true);
        highScoreLabel->setVisible(true);
        highScoreBox->setVisible(true);
    }
    //==============================================================================
    void hidePlayingScreen(){
        
        for(int i=0;i<12;i++){
            playButton[i]->setVisible(false);
        }
    }
    //==============================================================================
    void displayPlayingScreen(){
        
        for(int i=0;i<numNotes;i++){
            playButton[i]->setVisible(true);
        }
        
    }
    //==============================================================================
    void startPressed ()
    {
        calculateSequence();
        hideOptionScreen();
        displayPlayingScreen();
        playingLoop();
    }
    //==============================================================================
    
    void calculateSequence ()
    {
        //set parameters based on length of scale - major or chromatic
        if (key == 12){
            rootNote = (octave * 12) + 12;
            baseScale.resize(12);
            baseScale = {0,1,2,3,4,5,6,7,8,9,10,11};
        }
        else{
            rootNote = key + (octave * 12) + 12;
            baseScale.resize(8);
            baseScale = {0,2,4,5,7,9,11};
        }
        
        //set the correct scale - will only fill until the number of items selected on the option screen
        currentScale.resize(numNotes);
        for (int i=0;i<numNotes;i++){
            currentScale[i] = rootNote + baseScale[i];
            //setup buttons
            if (relativeMode){
                if (key == 12) {
                    playButton[i]->setButtonText(relChromNoteLabels[i]);
                }else{
                    playButton[i]->setButtonText(relMajNoteLabels[i]);
                }
            }else{
                playButton[i]->setButtonText(getMidiNoteName(currentScale[i],false,false,false));
            }
            playButton[i]->setName(String(currentScale[i]));
        }

        //when in relative mode the sequence should start with the reference pitch
        if (relativeMode){
            pitchSequence[0] = rootNote;
            for(int i=1;i<300;i++){
                pitchSequence[i] = currentScale[rand() % numNotes];
            }
        }else{
            for(int i=0;i<300;i++){
                pitchSequence[i] = currentScale[rand() % numNotes];
            }
        }
    }


    //==============================================================================
    
    void playingLoop ()
    {

        currCount = 1;
        seqCount = 0;
        alt = 1;
        waitForPlayer = false;
        //timerCounter = 0;
        
        //set the timer for 1 beat in ms
        startTimer((int)60000/BPM);
    }
    //==============================================================================
    
    void timerCallback () override
    {   //computer is playing
        //    timerCounter++;
        if (!waitForPlayer){
            if (seqCount<currCount){
                if (alt == 1){
                    squareControl.setParamValue("/square/freq",getMidiNoteInHertz(pitchSequence[seqCount], 440));
                    squareControl.setParamValue("/square/gate", 1);
                }
                else{
                    squareControl.setParamValue("/square/gate", 0);
                    seqCount++;
                }
                
            }
            if (seqCount == currCount){
                seqCount = 0;
                waitForPlayer = true;
            }
        //player is inputting
        }else{
            if (seqCount<currCount){
                if (alt == 1){
                    //wait a beat for input
                  //  match = false;
                }else {
                    if (match){
                        seqCount++;
                        if (seqCount > highScore){
                            highScore = seqCount;
                            highScoreBox->setText(String(highScore), dontSendNotification);
                        }
                        match = false;
                    }else{
                        stopTimer();
                        hidePlayingScreen();
                        displayOptionScreen();
                    }

                }
            }
            if (seqCount == currCount){
                seqCount = 0;
                currCount++;
                waitForPlayer = false;
            }
        }
        alt *= -1;
    }
    
    //==============================================================================
    double getMidiNoteInHertz (const int noteNumber, const double frequencyOfA) noexcept
    {
        return frequencyOfA * pow (2.0, (noteNumber - 69) / 12.0);
    }
    
    //==============================================================================
    String getMidiNoteName (int note, bool useSharps, bool includeOctaveNumber, int octaveNumForMiddleC)
    {
        static const char* const sharpNoteNames[] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
        static const char* const flatNoteNames[]  = { "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B" };
        
        if (isPositiveAndBelow (note, (int) 128))
        {
            String s (useSharps ? sharpNoteNames [note % 12]
                      : flatNoteNames  [note % 12]);
            
            if (includeOctaveNumber)
                s << (note / 12 + (octaveNumForMiddleC - 5));
            
            return s;
        }
        
        return String();
    }
    //==============================================================================
    void setMidiInput (int index)
    {
        index -= 2;
        const StringArray list (MidiInput::getDevices());
        
        deviceManager.removeMidiInputCallback (list[lastInputIndex], this);
        
        const String newInput (list[index]);
        
        if (! deviceManager.isMidiInputEnabled (newInput))
            deviceManager.setMidiInputEnabled (newInput, true);
        
        deviceManager.addMidiInputCallback (newInput, this);
 //       midiInputList.setSelectedId (index + 1, dontSendNotification);
        
        lastInputIndex = index;
    }
    //==============================================================================
    void handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message) override
    {
        if (message.isNoteOn()){
            if (message.getNoteNumber() == pitchSequence[seqCount]){
                match = true;
            }else{
                match = false;
            }
        }
        const ScopedValueSetter<bool> scopedInputFlag (isAddingFromMidiInput, true);
        keyboardState.processNextMidiEvent (message);
    }
    //==============================================================================
    void handleNoteOn (MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) override
    {
        //keeping in case I wan't to add a midi keyboard later
        if (! isAddingFromMidiInput)
        {
            MidiMessage m (MidiMessage::noteOn (midiChannel, midiNoteNumber, velocity));
            m.setTimeStamp (Time::getMillisecondCounterHiRes() * 0.001);
        }
    }
    //==============================================================================
    void handleNoteOff (MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) override
    {
        if (! isAddingFromMidiInput)
        {
            MidiMessage m (MidiMessage::noteOff (midiChannel, midiNoteNumber));
            m.setTimeStamp (Time::getMillisecondCounterHiRes() * 0.001);
        }
    }
    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
        currentSampleRate = sampleRate;
        setupAubioPitch("yinfft", 8*samplesPerBlockExpected, samplesPerBlockExpected, sampleRate);
        
//      initialize faust objects
        square.init(sampleRate);
        square.buildUserInterface(&squareControl);
        
        square.init(sampleRate);
        square.buildUserInterface(&squareControl);

//      print parameters
//        for(int i=0; i<outputSquareControl.getParamsCount(); i++){
//            std::cout << outputSquareControl.getParamAdress(i) << "\n";
//        }
        
//      setting default values
        squareControl.setParamValue("/square/gain",0.3);
        squareControl.setParamValue("/square/gain",0.3);
        
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        blockSize = bufferToFill.buffer->getNumSamples();
        if (input == 1 && waitForPlayer){
            float* inBuffer = bufferToFill.buffer->getWritePointer (0, bufferToFill.startSample);
            audioIn(inBuffer, bufferToFill.buffer->getNumSamples(), 1);
//          to make it easier, it just has to hear the pitch in one audio block
            if (latestPitch > pitchSequence[seqCount]-.5 &&
                latestPitch < pitchSequence[seqCount]+.5){
                match = true;
            }
        }
        
        bufferToFill.clearActiveBufferRegion();
        audioBuffer = bufferToFill.buffer->getArrayOfWritePointers();
        square.compute(blockSize, NULL, audioBuffer);
    }

    void releaseResources() override
    {

    }
    
    //==============================================================================
    void paint (Graphics& g) override
    {
        //background image
        g.drawImage (cachedImage_background,
                     0, 0, getWidth(), getHeight(),
                     0, 0, cachedImage_background.getWidth(), cachedImage_background.getHeight());
//        g.fillAll (Colour (0xff292929));

    }
    
    //==============================================================================
    void resized() override
    {
        playButton[0]->setBounds (24, 56, 71, 72);
        playButton[1]->setBounds (152, 56, 71, 72);
        playButton[2]->setBounds (272, 56, 71, 72);
        playButton[3]->setBounds (24, 184, 71, 72);
        playButton[4]->setBounds (152, 184, 71, 72);
        playButton[5]->setBounds (272, 184, 71, 72);
        playButton[6]->setBounds (24, 328, 71, 72);
        playButton[7]->setBounds (152, 328, 71, 72);
        playButton[8]->setBounds (272, 328, 71, 72);
        playButton[9]->setBounds (24, 456, 71, 72);
        playButton[10]->setBounds (152, 456, 71, 72);
        playButton[11]->setBounds (272, 456, 71, 72);
        
        keySelector->setBounds (120, 160, 72, 40);
        octaveSelector->setBounds (32, 160, 72, 40);
        bpmSlider->setBounds (208, 152, 56, 144);
        numNotesSlider->setBounds (280, 152, 56, 144);
        inputSelector->setBounds (32, 352, 312, 32);
        startButton->setBounds (24, 448, 328, 72);
        noteButton->setBounds (32, 72, 72, 24);
        chordButton->setBounds (104, 72, 72, 24);
        relativeButton->setBounds (120, 48, 72, 24);
        absoluteButton->setBounds (192, 48, 72, 24);
//        relativeButton->setBounds (200, 72, 72, 24);
//        absoluteButton->setBounds (272, 72, 72, 24);
        totalItemsLabel->setBounds (272, 120, 72, 24);
        bpmLabel->setBounds (208, 120, 56, 24);
        octaveLabel->setBounds (40, 120, 56, 24);
        keyLabel->setBounds (128, 120, 56, 24);
        inputLabel->setBounds (160, 312, 56, 24);
        highScoreLabel->setBounds (88, 8, 88, 24);
        highScoreBox->setBounds (200, 8, 56, 24);
    }
    //==============================================================================
    void setupAubioBlock(std::string method, int buf_s, int hop_s, int samplerate)
    {
        hop_size = (uint_t)hop_s;
        buf_size = (uint_t)buf_s;
        aubio_input = new_fvec(hop_size);
        aubio_output = new_fvec(1);
        curpos = 0;
    }

    //==============================================================================
    void setupAubioPitch(std::string method, int buf_s, int hop_s, int samplerate)
    {
        setupAubioBlock(method, buf_s, hop_s, samplerate);
        pitch = new_aubio_pitch((char_t*)method.c_str(), buf_size, hop_size, samplerate);
        aubio_pitch_set_unit(pitch, (char_t*)"midi");
        //aubio_pitch_set_tolerance(pitch, 0.7);
    }
    
    //==============================================================================
    void closeAubioPitch()
    {
        if (pitch) del_aubio_pitch(pitch);
        cleanup();
    }
    
    //==============================================================================
    void blockAudioIn()
    {
        aubio_pitch_do(pitch, aubio_input, aubio_output);
        //ofLogNotice() << "found pitch: " << aubio_output->data[0];
        pitchConfidence = aubio_pitch_get_confidence(pitch);
        latestPitch = aubio_output->data[0];
    }
    //==============================================================================
    void audioIn(float * input, int bufferSize, int nChannels)
    {
        uint_t i, j;
        for (i = 0; i < bufferSize; i++) {
            // downmix into aubio_input
            aubio_input->data[curpos] = 0.;
            for (j = 0; j < nChannels; j++) {
                aubio_input->data[curpos] += input[i * nChannels + j];
            }
            aubio_input->data[curpos] /= (smpl_t)nChannels;
            // run aubio block when appropriate
            curpos += 1;
            if (curpos == hop_size)
            {
                blockAudioIn();
                curpos = 0;
            }
        }
    }
    //==============================================================================
    void cleanup()
    {
        if (aubio_input) del_fvec(aubio_input);
        if (aubio_output) del_fvec(aubio_output);
    }

private:
    //==============================================================================
    
    int timerCounter = 0;
    
    float   seqArray[300];
    int     currCount;
    int     seqCount;
    int     highScore;
    int     alt;
    bool    waitForPlayer;
    bool    match = false;
    
    OwnedArray<TextButton> playButton;
    
    int  key;
    int  octave;
    int  BPM;
    int  numNotes;
    int  input;
    bool noteMode;
    bool relativeMode;
    
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
    
    std::vector<int> notesAllowed;
    std::vector<int> baseScale;
    std::vector<int> currentScale;
    
    int blockSize;
    double currentSampleRate;
    
    StringArray relMajNoteLabels;
    StringArray relChromNoteLabels;
    StringArray absoluteNoteLabels;
    
    int C0_Scale[7]   = {0,2,4,5,7,9,11};
    int chromatic[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
    int totalNotes;
    int rootNote;
    int pitchSequence[300];
    int pitchesToChooseFrom[12];
    
    float** audioBuffer;
    
    Square square;
    MapUI  squareControl;
    
    // midi vars
    AudioDeviceManager deviceManager;
    MidiKeyboardState keyboardState;
    int lastInputIndex;
    double startTime;
    bool isAddingFromMidiInput = false;
    
    Image cachedImage_background;
    
    // aubio vars
    aubio_pitch_t * pitch;
    float latestPitch;
    float pitchConfidence;
    uint_t buf_size;
    uint_t hop_size;
    uint_t curpos;
    fvec_t * aubio_input;
    fvec_t * aubio_output;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
