/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/demo_screen/DemoViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

DemoViewBase::DemoViewBase() :
    buttonCallback(this, &DemoViewBase::buttonCallbackHandler)
{
    background.setPosition(0, 0, 800, 480);
    background.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));

    hw_input_value.setPosition(0, 147, 800, 156);
    hw_input_value.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    hw_input_value.setLinespacing(0);
    Unicode::snprintf(hw_input_valueBuffer, HW_INPUT_VALUE_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID2).getText());
    hw_input_value.setWildcard(hw_input_valueBuffer);
    hw_input_value.setTypedText(touchgfx::TypedText(T_SINGLEUSEID1));

    hw_input.setXY(360, 146);
    hw_input.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    hw_input.setLinespacing(0);
    hw_input.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3));

    hw_output.setXY(220, 311);
    hw_output.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTON_PRESSED_ID));
    hw_output.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4));
    hw_output.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    hw_output.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    hw_output.setAction(buttonCallback);

    arrow_left.setXY(6, 224);
    arrow_left.setBitmaps(touchgfx::Bitmap(BITMAP_ARROW_LEFT_ID), touchgfx::Bitmap(BITMAP_ARROW_LEFT_ID));
    arrow_left.setAction(buttonCallback);

    arrow_right.setXY(776, 224);
    arrow_right.setBitmaps(touchgfx::Bitmap(BITMAP_ARROW_RIGHT_ID), touchgfx::Bitmap(BITMAP_ARROW_RIGHT_ID));
    arrow_right.setAction(buttonCallback);

    add(background);
    add(hw_input_value);
    add(hw_input);
    add(hw_output);
    add(arrow_left);
    add(arrow_right);
}

void DemoViewBase::setupScreen()
{

}

void DemoViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &hw_output)
    {
        //ButtonClicked
        //When hw_output clicked call virtual function
        //Call buttonClicked
        buttonClicked();
    }
    else if (&src == &arrow_left)
    {
        //GoBack
        //When arrow_left clicked change screen to Introduction
        //Go to Introduction with screen transition towards West
        application().gotoIntroductionScreenSlideTransitionWest();
    }
    else if (&src == &arrow_right)
    {
        //GoForward
        //When arrow_right clicked change screen to Introduction
        //Go to Introduction with screen transition towards East
        application().gotoIntroductionScreenSlideTransitionEast();
    }
}
