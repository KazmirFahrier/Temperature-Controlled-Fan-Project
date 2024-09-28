// Define the pin for the motor control
int motorPin = 9;

// Define the analog pin for the temperature sensor
int tempPin = A0;

// Define the threshold temperature (in degrees Celsius)
float tempThreshold = 30.0; // You can adjust this value as needed

void setup() {
  // Set the motor pin as an output
  pinMode(motorPin, OUTPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the temperature sensor value
  int sensorValue = analogRead(tempPin);

  // Convert the analog sensor value to temperature in degrees Celsius
  // TMP36 outputs 750mV at 25 degrees Celsius and 10mV/degree Celsius
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert analog value to voltage
  float temperatureC = (voltage - 0.5) * 100.0;  // Convert voltage to temperature

  // Print the temperature to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  // Turn the motor on or off based on the temperature
  if (temperatureC >= tempThreshold) {
    digitalWrite(motorPin, HIGH);  // Turn the motor ON
    Serial.println("Motor ON");
  } else {
    digitalWrite(motorPin, LOW);   // Turn the motor OFF
    Serial.println("Motor OFF");
  }

  // Wait for a short time before repeating
  delay(1000);
}
