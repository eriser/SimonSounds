#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "OptionScreen.h"
#include "PlayingScreen.h"

//==============================================================================

class MainContentComponent   : public AudioAppComponent, public Timer
{
public:
    //==============================================================================
    MainContentComponent()
    {
      optionScreen = new OptionScreen(*this);
        
        //addAndMakeVisible(optionScreen);
 //       addChildComponent(playingScreen);
        setSize (400, 600);

        setAudioChannels (2, 2);
    }

    ~MainContentComponent()
    {
        shutdownAudio();
    }

    //==============================================================================
    
    void createGui ()
    {
        //do some stuff
        calculateSequence();
 //       playingScreen.addElements(optionScreen.numNotes,optionScreen.noteMode, optionScreen.relativeMode)
   //     playingScreen->setVisible(true);
    }
    //==============================================================================
    
    void calculateSequence ()
    {
        
        playingLoop();
    }
    //==============================================================================
    
    void playingLoop ()
    {
        //set the timer for 1 beat in ms
     //   startTimer(60000/BPM);
        
        //
        for (int seqCount=0;seqCount < 300;seqCount++){
            
        
        }
    }
    //==============================================================================
    
    void timerCallback () override
    {

    }
    //==============================================================================
    
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
        // This function will be called when the audio device is started, or when
        // its settings (i.e. sample rate, block size, etc) are changed.

        // You can use this function to initialise any resources you might need,
        // but be careful - it will be called on the audio thread, not the GUI thread.

        // For more details, see the help for AudioProcessor::prepareToPlay()
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
//        const float level = gain; // gain is updated every block
        // getting the audio output buffer to be filled
        // computing one block
//        float* const buffer = bufferToFill.buffer->getWritePointer (0, bufferToFill.startSample);
//        for (int sample = 0; sample < bufferToFill.numSamples; ++sample)
//        {
//            sineCarrier.setFrequency(smooth[0].tick(freq) + sineModulator.tick() * smooth[3].tick(index));
//            buffer[sample] = sineCarrier.tick() * smooth[1].tick(level) * smooth[2].tick(onOff); // computing sample
//        }
//        int lengthOfOneBeatInSamples = (int)((sampleRate*60.0f)/speedButton.getValue());
//        int alternator = 1;
//        
//        if (playSequence == true){
//            for(int i=0;i < bufferSize;i++){
//                totalSamples++;
//                if(totalSamples%lengthOfOneBeatInSamples == 0){
//                    
//                    if (alternator == 1){
//                        
//                        output[i*nChannels] = output[i*nChannels + 1]; //something with pitchcounter
//                    }
//                    else{
//                        output[i*nChannels] = output[i*nChannels + 1] = 0;
//                    }
//                    alternator *= -1;
//                }
//            }
//        }
        
    }

    void releaseResources() override
    {
        // This will be called when the audio device stops, or when it is being
        // restarted due to a setting change.

        // For more details, see the help for AudioProcessor::releaseResources()
    }

    //==============================================================================
    void paint (Graphics& g) override
    {
        g.fillAll (Colours::black);
    }

    void resized() override
    {
        optionScreen.setBounds(0, 0, getWidth(), getHeight());
   //     playingScreen->setBounds(0, 0, getWidth(), getHeight());
    }


private:
    //==============================================================================
        float gain = .8;
        float seqArray[300];
        OptionScreen optionScreen;
    //    PlayingScreen* playingScreen;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
