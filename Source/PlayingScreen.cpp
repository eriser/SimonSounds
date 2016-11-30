#include "PlayingScreen.h"

//==============================================================================
PlayingScreen::PlayingScreen ()
{

}

PlayingScreen::~PlayingScreen()
{

    playButton = nullptr;
    playButton2 = nullptr;
    playButton3 = nullptr;
    playButton4 = nullptr;
    playButton5 = nullptr;
    playButton6 = nullptr;
    playButton7 = nullptr;
    playButton8 = nullptr;
    playButton9 = nullptr;
    playButton10 = nullptr;
    playButton11 = nullptr;
    playButton12 = nullptr;

}
//==============================================================================
void PlayingScreen::addElements(int numNotes, bool noteMode, bool relativeMode){
   
    for (int i=0;i < numNotes;i++){
        addAndMakeVisible (playButton = new TextButton ("playButton"));
        if (noteMode){
            if(relativeMode){
            
            }
            else{
        
            }
        }else{ //chordMode
            if(relativeMode){
                
            }
            else{
                
            }
        }
        playButton->setButtonText (TRANS("1"));
        
        
        playButton->addListener (this);
    }

}

//==============================================================================
void PlayingScreen::paint (Graphics& g)
{
    g.fillAll (Colour (0xff292929));
}

void PlayingScreen::resized()
{

    playButton->setBounds (16, 64, 71, 72);
    playButton2->setBounds (112, 64, 71, 72);
    playButton3->setBounds (208, 64, 71, 72);
    playButton4->setBounds (304, 64, 71, 72);
    playButton5->setBounds (16, 240, 71, 72);
    playButton6->setBounds (112, 240, 71, 72);
    playButton7->setBounds (208, 240, 71, 72);
    playButton8->setBounds (304, 240, 71, 72);
    playButton9->setBounds (16, 400, 71, 72);
    playButton10->setBounds (112, 400, 71, 72);
    playButton11->setBounds (208, 400, 71, 72);
    playButton12->setBounds (296, 400, 71, 72);

}

void PlayingScreen::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == playButton)
    {
     //   optionScreen.setVisible(true);
    }
    else if (buttonThatWasClicked == playButton2)
    {
        //[UserButtonCode_playButton2] -- add your button handler code here..
        //[/UserButtonCode_playButton2]
    }
    else if (buttonThatWasClicked == playButton3)
    {
        //[UserButtonCode_playButton3] -- add your button handler code here..
        //[/UserButtonCode_playButton3]
    }
    else if (buttonThatWasClicked == playButton4)
    {
        //[UserButtonCode_playButton4] -- add your button handler code here..
        //[/UserButtonCode_playButton4]
    }
    else if (buttonThatWasClicked == playButton5)
    {
        //[UserButtonCode_playButton5] -- add your button handler code here..
        //[/UserButtonCode_playButton5]
    }
    else if (buttonThatWasClicked == playButton6)
    {
        //[UserButtonCode_playButton6] -- add your button handler code here..
        //[/UserButtonCode_playButton6]
    }
    else if (buttonThatWasClicked == playButton7)
    {
        //[UserButtonCode_playButton7] -- add your button handler code here..
        //[/UserButtonCode_playButton7]
    }
    else if (buttonThatWasClicked == playButton8)
    {
        //[UserButtonCode_playButton8] -- add your button handler code here..
        //[/UserButtonCode_playButton8]
    }
    else if (buttonThatWasClicked == playButton9)
    {
        //[UserButtonCode_playButton9] -- add your button handler code here..
        //[/UserButtonCode_playButton9]
    }
    else if (buttonThatWasClicked == playButton10)
    {
        //[UserButtonCode_playButton10] -- add your button handler code here..
        //[/UserButtonCode_playButton10]
    }
    else if (buttonThatWasClicked == playButton11)
    {
        //[UserButtonCode_playButton11] -- add your button handler code here..
        //[/UserButtonCode_playButton11]
    }
    else if (buttonThatWasClicked == playButton12)
    {
        //[UserButtonCode_playButton12] -- add your button handler code here..
        //[/UserButtonCode_playButton12]
    }

}


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PlayingScreen" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff292929"/>
  <TEXTBUTTON name="playButton" id="463150106355819f" memberName="playButton"
              virtualName="" explicitFocusOrder="0" pos="16 64 71 72" buttonText="1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="playButton" id="4521706d62f4deab" memberName="playButton2"
              virtualName="" explicitFocusOrder="0" pos="112 64 71 72" buttonText="1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="playButton" id="781d7893b7c13bab" memberName="playButton3"
              virtualName="" explicitFocusOrder="0" pos="208 64 71 72" buttonText="1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="playButton" id="976edf30fb226b2a" memberName="playButton4"
              virtualName="" explicitFocusOrder="0" pos="304 64 71 72" buttonText="1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="playButton" id="3f4fecff298843f7" memberName="playButton5"
              virtualName="" explicitFocusOrder="0" pos="16 240 71 72" buttonText="1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="playButton" id="3eece941aa5b998c" memberName="playButton6"
              virtualName="" explicitFocusOrder="0" pos="112 240 71 72" buttonText="1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="playButton" id="7bcad3e03f27d55f" memberName="playButton7"
              virtualName="" explicitFocusOrder="0" pos="208 240 71 72" buttonText="1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="playButton" id="e4dd1dd7bbb45177" memberName="playButton8"
              virtualName="" explicitFocusOrder="0" pos="304 240 71 72" buttonText="1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="playButton" id="d39403d005c04841" memberName="playButton9"
              virtualName="" explicitFocusOrder="0" pos="16 432 71 72" buttonText="1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="playButton" id="a1a36f0e92ed6da3" memberName="playButton10"
              virtualName="" explicitFocusOrder="0" pos="112 432 71 72" buttonText="1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="playButton" id="bdc808d6f928551" memberName="playButton11"
              virtualName="" explicitFocusOrder="0" pos="208 432 71 72" buttonText="1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="playButton" id="23722a67baf08a5f" memberName="playButton12"
              virtualName="" explicitFocusOrder="0" pos="296 432 71 72" buttonText="1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
