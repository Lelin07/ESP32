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

<<<<<<< HEAD
// Define built-in LED pin
#define LED_PIN 2

// Define buzzer pin
#define BUZZER_PIN 25

// WiFi credentials
const char *ssid = "YourSSID";
const char *password = "YourPassword";
=======
// WiFi credentials
const char *ssid = "SAMSUNG";
const char *password = "sam1223334444";
>>>>>>> 6fabdbc0169c0491c068af525e3e45ab3e74d7f4

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

<<<<<<< HEAD
    // Blink the built-in LED for 100 milliseconds
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);

    // Activate the buzzer for 200 milliseconds
    digitalWrite(BUZZER_PIN, HIGH);
    delay(50);
    digitalWrite(BUZZER_PIN, LOW);

    // Display the message on the OLED with large text size
    display.clearDisplay();
    display.setTextSize(3); // Set large text size
    int16_t x, y;
    uint16_t width, height;
    display.getTextBounds(message, 0, 0, &x, &y, &width, &height);

    // Center the text on the screen
    int16_t xPos = (SCREEN_WIDTH - width) / 2;
    int16_t yPos = (SCREEN_HEIGHT - height) / 2;
    display.setCursor(xPos, yPos);
=======
    // Display the message on the OLED
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Key Pressed:");
>>>>>>> 6fabdbc0169c0491c068af525e3e45ab3e74d7f4
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

<<<<<<< HEAD
  // Display the local IP address on the OLED at the bottom
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("WiFi Connected!");
  display.setCursor(0, SCREEN_HEIGHT - 10); // Position at the bottom
  display.println(WiFi.localIP().toString());
  display.display();

  // Start WebSocket server
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);

  // Flash LED_PIN twice to indicate readiness
  pinMode(LED_PIN, OUTPUT);
  for (int i = 0; i < 2; i++)
  {
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  }

  // Initialize buzzer pin
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW); // Ensure buzzer is off initially

  // Display a custom message on the OLED screen with large text size
  display.clearDisplay();
  display.setTextSize(3); // Set large text size
  String readyMessage = "Ready!";
  int16_t x, y;
  uint16_t width, height;
  display.getTextBounds(readyMessage, 0, 0, &x, &y, &width, &height);

  // Center the text on the screen
  int16_t xPos = (SCREEN_WIDTH - width) / 2;
  int16_t yPos = (SCREEN_HEIGHT - height) / 2;
  display.setCursor(xPos, yPos);
  display.println(readyMessage);
  display.display();
=======
  // Start WebSocket server
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
>>>>>>> 6fabdbc0169c0491c068af525e3e45ab3e74d7f4
}

void loop()
{
  // Handle WebSocket communication
  webSocket.loop();
}