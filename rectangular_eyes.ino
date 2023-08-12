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
const int eyebrowWidth = 40;
const int eyebrowHeight = 5;
float eyebrowAngle = PI / 6;
const int eyebrowY = 30;
const int eyeX1 = 27;  // X-coordinate of the left eye
const int eyeX2 = 96;  // X-coordinate of the right eye
const int eyeY = 40;   // Y-coordinate of both eyes

bool angry = false;

void drawRectangularEyes() {
  // Draw left eye
  tft.fillRoundRect(eyeX1, eyeY, eyeWidth, eyeHeight,10, ST7735_CYAN);
  tft.drawRoundRect(eyeX1, eyeY, eyeWidth, eyeHeight,10, ST7735_BLACK);

  // Draw right eye
  tft.fillRoundRect(eyeX2, eyeY, eyeWidth, eyeHeight,10, ST7735_CYAN);
  tft.drawRoundRect(eyeX2, eyeY, eyeWidth, eyeHeight,10, ST7735_BLACK);
}

void drawAngryEyes() {
  // Draw left eye
  tft.fillRoundRect(eyeX1, eyeY+10, eyeWidth, eyeHeight/1.4,10, ST7735_CYAN); // Fill the eye with red
  tft.drawRoundRect(eyeX1, eyeY+10, eyeWidth, eyeHeight/1.4,10, ST7735_BLACK);

  // Draw right eye
  tft.fillRoundRect(eyeX2, eyeY+10, eyeWidth, eyeHeight/1.4,10, ST7735_CYAN); // Fill the eye with red
  tft.drawRoundRect(eyeX2, eyeY+10, eyeWidth, eyeHeight/1.4,10, ST7735_BLACK);
  
  // Draw left eyebrow
  // tft.fillRect(eyeX1, eyeY - eyebrowHeight - 2, eyebrowWidth, eyebrowHeight, ST7735_RED);
  drawAngryEyebrow(eyeX1+3,13, eyebrowWidth,eyebrowAngle, eyebrowHeight,ST7735_CYAN);
  // Draw right eyebrow
  // tft.fillRect(eyeX2, eyeY - eyebrowHeight - 2, eyebrowWidth, eyebrowHeight, ST7735_RED);
  drawAngryEyebrow(eyeX2,eyeY - eyebrowHeight - 2, eyebrowWidth,(-eyebrowAngle), eyebrowHeight,ST7735_CYAN);
}

// void drawAngryEyebrow(int startX, int startY, int length, float angle, int height, uint16_t color) {
//   int endX = startX + length * cos(angle);
//   int endY = startY + length * sin(angle);
//   int x0 = endX - height * sin(angle);
//   int y0 = endY + height * cos(angle);
//   int x1 = startX - height * sin(angle);
//   int y1 = startY + height * cos(angle);
  
//   tft.drawLine(startX, startY, endX, endY, color);
//   tft.drawLine(endX, endY, x0, y0, color);
//   tft.drawLine(x0, y0, x1, y1, color);
//   tft.drawLine(x1, y1, startX, startY, color);
// }

void drawAngryEyebrow(int startX, int startY, int length, float angle, int height, uint16_t color) {
  float dx = cos(angle);
  float dy = sin(angle);

  for (int i = 0; i < length; i++) {
    int x1 = startX + i * dx - height * dy / 2;
    int y1 = startY + i * dy + height * dx / 2;
    int x2 = startX + i * dx + height * dy / 2;
    int y2 = startY + i * dy - height * dx / 2;

    tft.fillRect(x1, y1, height, height, color);
    tft.fillRect(x2, y2, height, height, color);
  }
}

void drawHalfCircle(int x, int y, int radius, uint16_t color) {
  for (int i = -radius; i <= radius; i++) {
    int j = sqrt(radius * radius - i * i);
    tft.drawPixel(x + i, y - j, color);
    tft.drawPixel(x + i, y - j - 1, color); // Optional: Fill in the gap
  }
}

void dissapointedEyes(){
//left eye
  tft.fillRoundRect(eyeX1, eyeY, eyeWidth, eyeHeight/2,10, ST7735_CYAN);
  tft.drawRoundRect(eyeX1, eyeY, eyeWidth, eyeHeight/2,10, ST7735_BLACK);
  //right eye
  tft.fillRoundRect(eyeX2, eyeY, eyeWidth, eyeHeight/2,10, ST7735_CYAN);
  tft.drawRoundRect(eyeX2, eyeY, eyeWidth, eyeHeight/2,10, ST7735_BLACK);
}

void confusedEyes(){
  //left eye
  tft.fillRoundRect(eyeX1, eyeY, eyeWidth, eyeHeight/2,10, ST7735_CYAN);
  tft.drawRoundRect(eyeX1, eyeY, eyeWidth, eyeHeight/2,10, ST7735_BLACK);
  //right eye
  tft.fillRoundRect(eyeX2, eyeY, eyeWidth, eyeHeight,10, ST7735_CYAN);
  tft.drawRoundRect(eyeX2, eyeY, eyeWidth, eyeHeight,10, ST7735_BLACK);
}

void sadEyes(){
    //left eye
  tft.fillRoundRect(eyeX1+10, eyeY, eyeWidth/2, eyeHeight,3, ST7735_CYAN);
  tft.drawRoundRect(eyeX1+10, eyeY, eyeWidth/2, eyeHeight,3, ST7735_BLACK);
  //right eye
  tft.fillRoundRect(eyeX2, eyeY, eyeWidth/2, eyeHeight,3, ST7735_CYAN);
  tft.drawRoundRect(eyeX2, eyeY, eyeWidth/2, eyeHeight,3, ST7735_BLACK);
}

void cuteEyes(){
    //left eye
  drawHalfCircle(50, 60, 20, ST7735_CYAN);
  drawHalfCircle(50, 60, 19, ST7735_CYAN);
  drawHalfCircle(50, 60, 18, ST7735_CYAN);
  drawHalfCircle(50, 60, 17, ST7735_CYAN);
  drawHalfCircle(50, 60, 16, ST7735_CYAN);
  drawHalfCircle(50, 60, 15, ST7735_CYAN);
  drawHalfCircle(50, 60, 14, ST7735_CYAN);
  drawHalfCircle(50, 60, 13, ST7735_CYAN);
  drawHalfCircle(50, 60, 12, ST7735_CYAN);
  //right eye
  drawHalfCircle(106, 60, 19, ST7735_CYAN);
  drawHalfCircle(106, 60, 18, ST7735_CYAN);
  drawHalfCircle(106, 60, 17, ST7735_CYAN);
  drawHalfCircle(106, 60, 16, ST7735_CYAN);
  drawHalfCircle(106, 60, 20, ST7735_CYAN);
  drawHalfCircle(106, 60, 15, ST7735_CYAN);
  drawHalfCircle(106, 60, 14, ST7735_CYAN);
  drawHalfCircle(106, 60, 13, ST7735_CYAN);
  drawHalfCircle(106, 60, 12, ST7735_CYAN);

}

void normalFace(){
  for(int i=0; i<=5;i++){
  drawRectangularEyes();
  delay(1000);  // Display the eyes for 5 seconds
  tft.fillScreen(ST7735_BLACK);  // Clear the screen
  delay(100); // Wait for 1 second before repeating
  drawRectangularEyes();
  delay(4000);
  tft.fillScreen(ST7735_BLACK);  // Clear the screen
  delay(100);
  }
}

void sadFace(){
  for(int i=0; i<=5;i++){
  sadEyes();
  delay(1000);  // Display the eyes for 5 seconds
  tft.fillScreen(ST7735_BLACK);  // Clear the screen
  delay(100); // Wait for 1 second before repeating
  }
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
  
//  if (angry==false) {
//     normalFace();
//     angry = true;
//     delay(500);  // Keep eyes closed for 1 second
//   } else {
//     drawAngryEyes();
//     angry = false;
//     delay(4000);  // Keep angry eyes for 4 seconds
//   }

// normalFace();
// delay(500);
// drawAngryEyes();
// delay(4000);
  
// tft.fillScreen(ST7735_BLACK);  // Clear the screen
// delay(500);  // Wait for 1 second before repeating

confusedEyes();
delay(4000);
tft.fillScreen(ST7735_BLACK);
delay(500);
dissapointedEyes();
delay(4000);
tft.fillScreen(ST7735_BLACK);
delay(500);
cuteEyes();
delay(4000);
tft.fillScreen(ST7735_BLACK);
delay(100);
normalFace();
delay(4000);
tft.fillScreen(ST7735_BLACK);
delay(100);
sadFace();
delay(4000);
tft.fillScreen(ST7735_BLACK);
delay(100);
drawAngryEyes();
delay(4000);
tft.fillScreen(ST7735_BLACK);
delay(100);
}

