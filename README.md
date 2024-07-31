# Arduino-Projects

1. Moisture Meters for the Arduino Uno. Can use 6 capacitive moisture meters to read off the plants and have an LED turn on if watering is necessary.
2. Moisture Meters for the ESP32 NodeMCU (Picture Below). My current code uses 10 moisture meters and 2 ESP32s to continuously check the water levels of the plants and upload them to a website on my local network. The Sender ESP32 receives the data from all the meters and sends them to the Receiver ESP32 via the RX/TX pins. The Receiver ESP32 then connects to my wifi and makes the website which anyone could check when connected to the same wifi. Theoretically, you could use up to 22 moisture meters if you connect 16 of them to all of the ADC pins on the Sender ESP32 and 6 to the ADC1 pins of the Receiver ESP32. (NOTE: When working with wifi you are unable to use ADC2 pins which is why I had to use 2 ESP32s)
![image](https://github.com/user-attachments/assets/d3a6f77f-97d3-4949-92ef-7b31fe66874b)
