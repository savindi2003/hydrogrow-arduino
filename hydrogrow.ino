#include <HTTPClient.h>
#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  pinMode(35, INPUT);   // Moisture sensor pin
 

  // Connect to Wi-Fi
  WiFi.begin("Dialog 4G 633", "8497f3e3");

  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi!");
}

void handleSecondRequest(const String& responseText1) {
  HTTPClient requestActions;
  String url2 = "http://192.168.8.187:8080/HydroGrow/ControlPump";
  requestActions.begin(url2);

  int actionStatusCode = requestActions.GET();
  if (actionStatusCode > 0) {
    Serial.printf("Second Request Status: %d\n", actionStatusCode);
    if (actionStatusCode == HTTP_CODE_OK) {
      String responseText = requestActions.getString();
      responseText.trim(); // Clean response
      Serial.println("Second Response: " + responseText);

      // Handle conditions using both responseText and responseText1
      if (responseText.equalsIgnoreCase("start") && responseText1.equalsIgnoreCase("off")) {
        Serial.println("Auto off");
         // Turn off the pump
      } else if (responseText.equalsIgnoreCase("start")) {
         // Turn pump ON
        Serial.println("Water pump on!");
      } else if (responseText.equalsIgnoreCase("stop")) {
        // Turn pump OFF
        Serial.println("Water pump off!");
      } else {
        Serial.printf("Unexpected response: %s\n", responseText.c_str());
      }

      // Log the current pump state
      
    }
  } else {
    Serial.printf("Second Request Failed: %s\n", requestActions.errorToString(actionStatusCode).c_str());
  }
  requestActions.end();
}

void loop() {
  int rawValue = analogRead(34);   //Analog-to-Digital Converter  0 - 4095
  int percentage = map(rawValue, 0, 4095, 100, 0);  //0 to 4095 - 100 to 0 
  percentage = constrain(percentage, 0, 100);

  Serial.printf("Raw Value: %d | Moisture Percentage: %d%%\n", rawValue, percentage);

  int count = (percentage < 30) ? 1 : ((percentage > 60) ? 2 : 0);

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient request;

    // First Request
    String url1 = "http://192.168.8.187:8080/HydroGrow/Home?status=" + String(count) + "&percentage=" + String(percentage);
    request.begin(url1);

    String responseText1 = "";
    int statusCode = request.GET();
    if (statusCode > 0) {
      Serial.printf("First Request Status: %d\n", statusCode);
      if (statusCode == HTTP_CODE_OK) {
        responseText1 = request.getString();
        responseText1.trim(); // Clean response
        Serial.println("First Response: " + responseText1);
      }
    } else {
      Serial.printf("First Request Failed: %s\n", request.errorToString(statusCode).c_str());
    }
    request.end();

    // Call second request handler and pass responseText1
    //handleSecondRequest(responseText1);
  } else {
    Serial.println("WiFi not connected!");
  }

  delay(2000); // Wait 2 seconds
}






