#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <WebSocketsServer.h>

// OLED display dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_I2C_ADDR 0x3C
#define OLED_RST_PIN -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST_PIN);

// WiFi credentials
const char *ssid = "SAMSUNG";
const char *password = "sam1223334444";

// WebSocket server on port 81
WebSocketsServer webSocket = WebSocketsServer(81);

// Function to initialize the OLED display
void initDisplay()
{
  if (!display.begin(SCREEN_I2C_ADDR, SCREEN_I2C_ADDR))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Waiting for data..."));
  display.display();
}

// WebSocket event handler
void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length)
{
  if (type == WStype_TEXT)
  {
    String message = String((char *)payload);
    Serial.println("Received: " + message);

    // Display the message on the OLED
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Key Pressed:");
    display.println(message);
    display.display();
  }
}

void setup()
{
  // Start Serial Monitor
  Serial.begin(115200);

  // Initialize OLED display
  initDisplay();

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  Serial.println("IP Address: " + WiFi.localIP().toString());

  // Start WebSocket server
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}

void loop()
{
  // Handle WebSocket communication
  webSocket.loop();
}