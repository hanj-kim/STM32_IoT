/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/introduction_screen/IntroductionViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

IntroductionViewBase::IntroductionViewBase()
{
    background.setPosition(0, 0, 800, 480);
    background.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));

    headline.setPosition(1, 73, 800, 298);
    headline.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    headline.setLinespacing(0);
    headline.setTypedText(touchgfx::TypedText(T_INTRODUCTION));

    arrow_left.setXY(6, 224);
    arrow_left.setBitmap(touchgfx::Bitmap(BITMAP_ARROW_LEFT_ID));

    arrow_right.setXY(776, 224);
    arrow_right.setBitmap(touchgfx::Bitmap(BITMAP_ARROW_RIGHT_ID));

    add(background);
    add(headline);
    add(arrow_left);
    add(arrow_right);
}

void IntroductionViewBase::setupScreen()
{

}

//Handles when a key is pressed
void IntroductionViewBase::handleKeyEvent(uint8_t key)
{
    if(0 == key)
    {
        //Interaction1
        //When hardware button 0 clicked change screen to Demo
        //Go to Demo with screen transition towards West
        application().gotoDemoScreenSlideTransitionWest();
    }
}
