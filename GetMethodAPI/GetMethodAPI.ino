#include <WiFi.h>
#include <HTTPClient.h>

// Wokwi simulated WiFi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Connect to Wokwi WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wokwi WiFi!");
  Serial.println("Enter post ID (1-100) to fetch:");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); 
    input.trim(); 
    int postId = input.toInt();

    if (postId > 0) {
      fetchPost(postId);
    } else {
      Serial.println("Invalid ID. Enter a number between 1 and 100.");
    }
  }
}

void fetchPost(int id) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "https://jsonplaceholder.typicode.com/posts/" + String(id);
    http.begin(url);

    int httpCode = http.GET();
    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println("\nResponse:");
      Serial.println(payload);
    } else {
      Serial.print("Error in HTTP request, code: ");
      Serial.println(httpCode);
    }

    http.end();
  } else {
    Serial.println("WiFi disconnected.");
  }

  Serial.println("\nEnter another post ID:");
}