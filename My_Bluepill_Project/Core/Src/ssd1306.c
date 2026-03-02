#include "ssd1306.h"
#include <string.h>

static I2C_HandleTypeDef *ssd1306_i2c;
static uint8_t SSD1306_Buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];

static uint8_t CurrentX = 0;
static uint8_t CurrentY = 0;

/* Send Command */
static void SSD1306_WriteCommand(uint8_t cmd)
{
    uint8_t data[2];
    data[0] = 0x00;
    data[1] = cmd;
    HAL_I2C_Master_Transmit(ssd1306_i2c, SSD1306_I2C_ADDR << 1, data, 2, HAL_MAX_DELAY);
}

/* Send Data */
static void SSD1306_WriteData(uint8_t* data, uint16_t size)
{
    uint8_t buffer[129];
    buffer[0] = 0x40;
    memcpy(&buffer[1], data, size);
    HAL_I2C_Master_Transmit(ssd1306_i2c, SSD1306_I2C_ADDR << 1, buffer, size + 1, HAL_MAX_DELAY);
}

/* Init */
void SSD1306_Init(I2C_HandleTypeDef *hi2c)
{
    ssd1306_i2c = hi2c;
    HAL_Delay(100);

    SSD1306_WriteCommand(0xAE); // Display OFF
    SSD1306_WriteCommand(0x20);
    SSD1306_WriteCommand(0x00);
    SSD1306_WriteCommand(0xB0);
    SSD1306_WriteCommand(0xC8);
    SSD1306_WriteCommand(0x00);
    SSD1306_WriteCommand(0x10);
    SSD1306_WriteCommand(0x40);
    SSD1306_WriteCommand(0x81);
    SSD1306_WriteCommand(0x7F);
    SSD1306_WriteCommand(0xA1);
    SSD1306_WriteCommand(0xA6);
    SSD1306_WriteCommand(0xA8);
    SSD1306_WriteCommand(0x3F);
    SSD1306_WriteCommand(0xA4);
    SSD1306_WriteCommand(0xD3);
    SSD1306_WriteCommand(0x00);
    SSD1306_WriteCommand(0xD5);
    SSD1306_WriteCommand(0xF0);
    SSD1306_WriteCommand(0xD9);
    SSD1306_WriteCommand(0x22);
    SSD1306_WriteCommand(0xDA);
    SSD1306_WriteCommand(0x12);
    SSD1306_WriteCommand(0xDB);
    SSD1306_WriteCommand(0x20);
    SSD1306_WriteCommand(0x8D);
    SSD1306_WriteCommand(0x14);
    SSD1306_WriteCommand(0xAF); // Display ON

    SSD1306_Fill(0);
    SSD1306_UpdateScreen();
}

/* Fill Screen */
void SSD1306_Fill(uint8_t color)
{
    memset(SSD1306_Buffer, (color ? 0xFF : 0x00), sizeof(SSD1306_Buffer));
}

/* Update Screen */
void SSD1306_UpdateScreen(void)
{
    for(uint8_t i = 0; i < 8; i++)
    {
        SSD1306_WriteCommand(0xB0 + i);
        SSD1306_WriteCommand(0x00);
        SSD1306_WriteCommand(0x10);
        SSD1306_WriteData(&SSD1306_Buffer[SSD1306_WIDTH * i], SSD1306_WIDTH);
    }
}

/* Set Cursor */
void SSD1306_SetCursor(uint8_t x, uint8_t y)
{
    CurrentX = x;
    CurrentY = y;
}

/* Simple Text (very basic, no font table) */
void SSD1306_WriteString(char* str)
{
    while(*str)
    {
        if(CurrentX + 6 >= SSD1306_WIDTH)
        {
            CurrentX = 0;
            CurrentY += 8;
        }

        for(uint8_t i = 0; i < 5; i++)
        {
            SSD1306_Buffer[CurrentX + (CurrentY/8)*SSD1306_WIDTH] = 0x7E;
            CurrentX++;
        }
        CurrentX++;
        str++;
    }
}
