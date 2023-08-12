#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS     10
#define TFT_RST    8
#define TFT_DC     9

// Initialize the TFT display
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

const int eyeWidth = 40;
const int eyeHeight = 40;
const int eyeX1 = 23;  // X-coordinate of the left eye
const int eyeX2 = 99;  // X-coordinate of the right eye
const int eyeY = 40;   // Y-coordinate of both eyes



void drawRectangularEyes() {
  // Draw left eye
  tft.fillRect(eyeX1, eyeY, eyeWidth, eyeHeight, ST7735_MAGENTA);
  tft.drawRect(eyeX1, eyeY, eyeWidth, eyeHeight, ST7735_BLACK);

  // Draw right eye
  tft.fillRect(eyeX2, eyeY, eyeWidth, eyeHeight, ST7735_MAGENTA);
  tft.drawRect(eyeX2, eyeY, eyeWidth, eyeHeight, ST7735_BLACK);
}

void drawAngryEyes() {
  // Draw left eye
  tft.fillRect(eyeX1, eyeY, eyeWidth, eyeHeight, ST7735_RED); // Fill the eye with red
  tft.drawRect(eyeX1, eyeY, eyeWidth, eyeHeight, ST7735_BLACK);

  // Draw right eye
  tft.fillRect(eyeX2, eyeY, eyeWidth, eyeHeight, ST7735_RED); // Fill the eye with red
  tft.drawRect(eyeX2, eyeY, eyeWidth, eyeHeight, ST7735_BLACK);

  // Draw left eyebrow
  tft.fillRect(eyeX1 - eyebrowWidth / 2, eyeY - eyebrowHeight - 2, eyebrowWidth, eyebrowHeight, ST7735_BLACK);

  // Draw right eyebrow
  tft.fillRect(eyeX2 - eyebrowWidth / 2, eyeY - eyebrowHeight - 2, eyebrowWidth, eyebrowHeight, ST7735_BLACK);
}

void setup() {
  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST7735_BLACK);
  tft.setRotation(3); // Adjust the rotation of screen if needed
  Serial.begin(9600);
  Serial.println("Initialized");
  delay(500);  // Delay for stability
}

void loop() {
  drawRectangularEyes();
  delay(5000);  // Display the eyes for 5 seconds
  tft.fillScreen(ST7735_BLACK);  // Clear the screen
  delay(100);  // Wait for 1 second before repeating
}

