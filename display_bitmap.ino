#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeMonoBoldOblique24pt7b.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define bitmap_height   62
#define bitmap_width    62
static const unsigned char PROGMEM bitmap[] =
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x03, 0xfc, 0x00, 0x00, 
	0x00, 0x03, 0xff, 0x80, 0x07, 0xff, 0x00, 0x00, 0x00, 0x07, 0x87, 0xe0, 0x1f, 0x0f, 0xc0, 0x00, 
	0x00, 0x1e, 0x00, 0xf0, 0x3c, 0x01, 0xe0, 0x00, 0x00, 0x3c, 0x00, 0x38, 0x70, 0x00, 0xf0, 0x00, 
	0x00, 0x30, 0x00, 0x1c, 0xe0, 0x00, 0x30, 0x00, 0x00, 0x70, 0x00, 0x0c, 0xc0, 0x00, 0x38, 0x00, 
	0x00, 0x60, 0x00, 0x0f, 0xc0, 0x00, 0x18, 0x00, 0x00, 0xe0, 0x00, 0x07, 0x80, 0x00, 0x1c, 0x00, 
	0x00, 0xe0, 0x00, 0x07, 0x80, 0x00, 0x1c, 0x00, 0x00, 0xc0, 0x00, 0x03, 0x00, 0x00, 0x0c, 0x00, 
	0x00, 0xc0, 0x00, 0x02, 0x00, 0x00, 0x0c, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 
	0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 
	0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 
	0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 
	0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 
	0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 
	0x00, 0x0e, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 
	0x00, 0x03, 0x80, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00, 0x0e, 0x00, 0x00, 
	0x00, 0x00, 0xe0, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x38, 0x00, 0x00, 
	0x00, 0x00, 0x38, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x01, 0xe0, 0x00, 0x00, 
	0x00, 0x00, 0x0f, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x07, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xc0, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x3c, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x78, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0xf0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  // Clear the buffer
  display.clearDisplay();
}

void loop() {
  showBitmap();
  //display.invertDisplay(true);
}

void showBitmap(void) {
  display.clearDisplay();

  display.drawBitmap(35, 0, bitmap, bitmap_height, bitmap_width, WHITE);
  display.display();
  delay(1000);
}