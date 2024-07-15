#include <WiFi.h>

WiFiServer server(80);

const char *ssid = "";
const char *password = "";

const int dry1 = 2836;
const int wet1 = 937;

const int dry2 = 2845;
const int wet2 = 963;

const int dry3 = 2848;
const int wet3 = 965;

const int dry4 = 2909;
const int wet4 = 1043;

const int dry5 = 2841;
const int wet5 = 977;

const int dry6 = 2832;
const int wet6 = 979;

const int dry7 = 2797;
const int wet7 = 958;

const int dry8 = 2914;
const int wet8 = 1056;

const int dry9 = 2896;
const int wet9 = 1054;

const int dry10 = 2886;
const int wet10 = 1024;

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  int Analog1 = analogRead(36);
  delay(100); // Small delay between readings
  int Analog2 = analogRead(39);
  delay(100);
  int Analog3 = analogRead(34);
  delay(100);
  int Analog4 = analogRead(35);
  delay(100);
  int Analog5 = analogRead(32);
  delay(100);
  int Analog6 = analogRead(33);
  delay(100);
  int Analog7 = analogRead(25);
  delay(100);
  int Analog8 = analogRead(26);
  delay(100);
  int Analog9 = analogRead(27);
  delay(100);
  int Analog10 = analogRead(14);

  Serial.print("Analog1 (Monstera): ");
  Serial.println(Analog1);
  Serial.print("Analog2 (Pothos): ");
  Serial.println(Analog2);
  Serial.print("Analog3 (Pitcher): ");
  Serial.println(Analog3);
  Serial.print("Analog4 (Venus): ");
  Serial.println(Analog4);
  Serial.print("Analog5 (Aloe): ");
  Serial.println(Analog5);
  Serial.print("Analog6 (False Aralia): ");
  Serial.println(Analog6);
  Serial.print("Analog7 (Nerve Plant): ");
  Serial.println(Analog7);
  Serial.print("Analog8 (Monstera 2): ");
  Serial.println(Analog8);
  Serial.print("Analog9 (Hoya): ");
  Serial.println(Analog9);
  Serial.print("Analog10 (Monstera 3): ");
  Serial.println(Analog10);

  int MonsteraHumidity = map(Analog1, wet1, dry1, 100, 0);      
  int PothosHumidity = map(Analog2, wet2, dry2, 100, 0);        
  int PitcherHumidity = map(Analog3, wet3, dry3, 100, 0);       
  int VenusHumidity = map(Analog4, wet4, dry4, 100, 0);         
  int AloeHumidity = map(Analog5, wet5, dry5, 100, 0);          
  int FalseAraliaHumidity = map(Analog6, wet6, dry6, 100, 0);   
  int NervePlantHumidity = map(Analog7, wet7, dry7, 100, 0);    
  int Monstera2Humidity = map(Analog8, wet8, dry8, 100, 0);     
  int HoyaHumidity = map(Analog9, wet9, dry9, 100, 0);          
  int Monstera3Humidity = map(Analog10, wet10, dry10, 100, 0);  

  if (client) {
    Serial.println("New Client.");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            client.println("<!DOCTYPE html><html>");
            client.println("<head><title>ESP32 Moisture Meters</title>");
            client.println("<style>");
            client.println("body { font-family: Arial, sans-serif; background-color: #f0f0f0; margin: 20px; }");
            client.println(".container { max-width: 800px; margin: auto; padding: 20px; background-color: #fff; border-radius: 8px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); }");
            client.println(".sensor { margin-bottom: 20px; padding: 15px; background-color: #f9f9f9; border-radius: 8px; }");
            client.println(".sensor h2 { margin-top: 0; font-size: 1.5rem; color: #333; }");
            client.println(".sensor .reading { font-size: 1.2rem; margin-top: 10px; padding: 10px; border-radius: 4px; }");
            client.println(".sensor .humidity { font-weight: bold; margin-left: 10px; }");
            client.println(".green { border: 5px solid #8bc34a; }");
            client.println(".red { border: 5px solid #f44336; }");
            client.println("</style>");
            client.println("</head>");
            client.println("<body>");
            client.println("<div class='container'>");
            client.println("<h1>ESP32 Moisture Meters</h1>");

            // Monstera
            client.println("<div class='sensor " + getColor(MonsteraHumidity, 40) + "'>");
            client.println("<h2>Monstera</h2>");
            client.println("<div class='reading'>Moisture Level: <span class='humidity'>" + String(MonsteraHumidity) + "%</span></div>");
            client.println("</div>");

            // Pothos
            client.println("<div class='sensor " + getColor(PothosHumidity, 40) + "'>");
            client.println("<h2>Pothos</h2>");
            client.println("<div class='reading'>Moisture Level: <span class='humidity'>" + String(PothosHumidity) + "%</span></div>");
            client.println("</div>");

            // Pitcher
            client.println("<div class='sensor " + getColor(PitcherHumidity, 55) + "'>");
            client.println("<h2>Pitcher</h2>");
            client.println("<div class='reading'>Moisture Level: <span class='humidity'>" + String(PitcherHumidity) + "%</span></div>");
            client.println("</div>");

            // Venus
            client.println("<div class='sensor " + getColor(VenusHumidity, 50) + "'>");
            client.println("<h2>Venus</h2>");
            client.println("<div class='reading'>Moisture Level: <span class='humidity'>" + String(VenusHumidity) + "%</span></div>");
            client.println("</div>");

            // Aloe
            client.println("<div class='sensor " + getColor(AloeHumidity, 10) + "'>");
            client.println("<h2>Aloe</h2>");
            client.println("<div class='reading'>Moisture Level: <span class='humidity'>" + String(AloeHumidity) + "%</span></div>");
            client.println("</div>");

            // False Aralia
            client.println("<div class='sensor " + getColor(FalseAraliaHumidity, 55) + "'>");
            client.println("<h2>False Aralia</h2>");
            client.println("<div class='reading'>Moisture Level: <span class='humidity'>" + String(FalseAraliaHumidity) + "%</span></div>");
            client.println("</div>");

            // Nerve Plant
            client.println("<div class='sensor " + getColor(NervePlantHumidity, 40) + "'>");
            client.println("<h2>Nerve Plant</h2>");
            client.println("<div class='reading'>Moisture Level: <span class='humidity'>" + String(NervePlantHumidity) + "%</span></div>");
            client.println("</div>");

            // Monstera 2
            client.println("<div class='sensor " + getColor(Monstera2Humidity, 40) + "'>");
            client.println("<h2>Monstera 2</h2>");
            client.println("<div class='reading'>Moisture Level: <span class='humidity'>" + String(Monstera2Humidity) + "%</span></div>");
            client.println("</div>");

            // Hoya
            client.println("<div class='sensor " + getColor(HoyaHumidity, 60) + "'>");
            client.println("<h2>Hoya</h2>");
            client.println("<div class='reading'>Moisture Level: <span class='humidity'>" + String(HoyaHumidity) + "%</span></div>");
            client.println("</div>");

            // Monstera 3
            client.println("<div class='sensor " + getColor(Monstera3Humidity, 40) + "'>");
            client.println("<h2>Monstera 3</h2>");
            client.println("<div class='reading'>Moisture Level: <span class='humidity'>" + String(Monstera3Humidity) + "%</span></div>");
            client.println("</div>");

            client.println("</div></body></html>");

            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    client.stop();
    Serial.println("Client Disconnected.");
  }
  delay(1000);
}

String getColor(int humidity, int threshold) {
  if (humidity >= threshold) {
    return "green";
  } else {
    return "red";
  }
}
