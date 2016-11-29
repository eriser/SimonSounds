/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    
//    addAndMakeVisible (startButton = new TextButton ("startButton"));
//    startButton->setButtonText (TRANS("Start"));
//    startButton->addListener (this);
    addAndMakeVisible(optionScreen);
 //   addAndMakeVisible(playingScreen);
    setSize (400, 600);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
}

void MainContentComponent::resized()
{
       // startButton->setBounds (24, 448, 328, 72);
   optionScreen.setBounds(0, 0, getWidth(), getHeight());
   // playingScreen.setBounds(0, 0, getWidth(), getHeight());
}

//void MainContentComponent::buttonClicked (Button* buttonThatWasClicked)
//{
//    
//    if (buttonThatWasClicked == startButton)
//    {
//         //  addAndMakeVisible(optionScreen);
//        // playingScreen.setVisible(true);
//         addAndMakeVisible(playingScreen);
//    }
//}