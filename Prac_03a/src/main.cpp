#include <WiFi.h>
#include <WebServer.h>
 
void handle_root();
// SSID & Password
const char* ssid = "Xiaomi_11T_Pro"; // Enter your SSID here
const char* password = "f5cbd8a82232"; //Enter your Password here
WebServer server(80); // Object of WebServer(HTTP port, 80 is defult)
 
void setup() {
    Serial.begin(115200);
    Serial.println("Try Connecting to ");
    Serial.println(ssid);
// Connect to your wi-fi modem
    WiFi.begin(ssid, password);
// Check wi-fi is connected to wi-fi network
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected successfully");
    Serial.print("Got IP: ");
    Serial.println(WiFi.localIP()); //Show ESP32 IP on serial
    server.on("/", handle_root);
    server.begin();
    Serial.println("HTTP server started");
    delay(100);
}
void loop() {
    server.handleClient();
}
// HTML & CSS contents which display on web server
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1>Excursiones del Vallés Occidental: - Station Mode &#128522;</h1>\
<p> - 1. LA MOLA. LA RUTA MÁS CLÁSICA DEL VALLÈS OCCIDENTAL. </p>\
<p> - 2. EL MONTCAU. OTRA RUTA MUY CONOCIDA DEL VALLÈS OCCIDENTAL. </p>\
<p> - 3. PINS CARGOLATS. </p>\
<p> - 4. LES FORADADES. UNA LUGAR MUY CURIOSO DEL VALLÈS OCCIDENTAL. </p>\
<p> - 5. TORRENT DE COLOBRERS, SABADELL / VALLÈS OCCIDENTAL. </p>\
<p> - 6. COVES DE SIMANYA. </p>\
<p> - 7. PUIG DE LA CREU. UNA ASCENSIÓN SENCILLA DEL VALLÈS OCCIDENTAL. </p>\
<p> - 8. CASTELLSAPERA. </p>\
</body>\
</html>";
// Handle root url (/)
void handle_root() {
server.send(200, "text/html", HTML);
}
