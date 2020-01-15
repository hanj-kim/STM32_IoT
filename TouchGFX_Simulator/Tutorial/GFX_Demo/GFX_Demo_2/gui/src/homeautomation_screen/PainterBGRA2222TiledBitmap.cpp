#include <gui/homeautomation_screen/PainterBGRA2222TiledBitmap.hpp>

bool PainterBGRA2222TiledBitmap::renderInit()
{
    bitmapBGRA2222Pointer = 0;

    int bitmapX = (currentX % bitmapRectToFrameBuffer.width);
    int bitmapY = (currentY % bitmapRectToFrameBuffer.height);

    bitmapBGRA2222Pointer = bitmap.getData();
    if (!bitmapBGRA2222Pointer)
    {
        return false;
    }
    bitmapBGRA2222Pointer += (bitmapX + bitmapY * bitmapRectToFrameBuffer.width);

    return true;
}

bool PainterBGRA2222TiledBitmap::renderNext(uint8_t& red, uint8_t& green, uint8_t& blue, uint8_t& alpha)
{
    uint8_t pixel = *bitmapBGRA2222Pointer++;
    blue = ((pixel >> 6) & 0x3) * 0x55;
    green = ((pixel >> 4) & 0x3) * 0x55;
    red = ((pixel >> 2) & 0x3) * 0x55;
    alpha = ((pixel >> 0) & 0x3) * 0x55;
    if ((currentX + 1) % bitmapRectToFrameBuffer.width == 0)
    {
        bitmapBGRA2222Pointer -= bitmapRectToFrameBuffer.width;
    }
    if (painterAlpha < 255)
    {
        // Apply given alpha from setAlpha()
        alpha = (((uint16_t)alpha) * ((uint16_t)painterAlpha)) / 255;
    }
    return true;
}
