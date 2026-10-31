
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

// defind ball
struct Ball {
  int x;
  int y;
  int radius;
  int speedX;
  int speedY;
};

// Create the ball object and set its starting values
Ball ball = {20, 20, 4, 2, 1};

void setup() {
  // Start the OLED
  if (!display.begin(
        SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true) {
      delay(10);
    }
  }

  display.clearDisplay();

  // init the ball
  display.drawCircle(ball.x, ball.y, ball.radius, SSD1306_WHITE);
  display.fillCircle(ball.x, ball.y, ball.radius, SSD1306_WHITE);

  // display   
  display.display();

}


void loop() {
  // The face stays on the screen
  display.clearDisplay();
    // init the ball
  display.drawCircle(ball.x, ball.y, ball.radius, SSD1306_WHITE);
  display.fillCircle(ball.x, ball.y, ball.radius, SSD1306_WHITE);

  // limit the ball position
  if (ball.x + ball.radius >= SCREEN_WIDTH or ball.x - ball.radius <= 0)
  {
    ball.speedX = ball.speedX * -1;
  };

  if (ball.y + ball.radius >= SCREEN_HEIGHT or ball.y - ball.radius <= 0)
  {
    ball.speedY = ball.speedY * -1;
  };

  ball.x += ball.speedX;
  ball.y += ball.speedY;
  display.display();
}
