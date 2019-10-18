#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

const char* ssid = "XyZ"; //Your Network SSID
const char* password = "1234567890"; //Your Network Password

//
const char* IFTTT_URL="maker.ifttt.com";
const char* IFTTT_KEY="c_QxEnZGw7ieOc28-jWDIR";
const char* IFTTT_EVENT="MQ2sensor";
//


WiFiClient client;
unsigned long myChannelNumber = 884948; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "4RAEZD7Z9E5NE630"; //Your Write API Key

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  // Connect to WiFi network
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected...");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() { // run over and over
  if(!client.connect(IFTTT_URL,80)){
    Serial.println("Connection Failed!");
    return;
  }
  if (Serial.available()>0) {
    String content=Serial.readStringUntil('\n');
    Serial.println(content);
    String SfingerID = getValue(content, ',', 0);
    String Sconfidence = getValue(content, ',', 1);
    int fingerID=SfingerID.toInt();
    int confidence=Sconfidence.toInt();

//        String url="https://maker.ifttt.com/trigger/smokeDetect/with/key/c_QxEnZGw7ieOc28-jWDIR";
//        client.print(String("POST ") + url + " HTTP/1.1\r\n" +
//             "Host: " + IFTTT_URL + "\r\n" + 
//             "Connection: close\r\n\r\n");

    
    ThingSpeak.setField(1, fingerID);
    ThingSpeak.setField(2, confidence);
    ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  }
}
String getValue(String data, char separator, int index){
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
