#include <ESP8266WiFi.h>

const char* ssid = "FeliWiFi-Fibe-2.4";       // Cambia por tu SSID
const char* password = "feliwifi";  // Cambia por tu contraseña

WiFiServer server(80);

String datosRegistrados = "No hay datos aun";

void setup() {
  Serial.begin(115200);
  delay(10);

  // Conexión a la red WiFi
  Serial.println();
  Serial.println("Conectando a ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Dirección IP: ");
  Serial.println(WiFi.localIP());

  // Iniciar el servidor
  server.begin();
  Serial.println("Servidor iniciado");
}

void loop() {
  // Recepción de datos desde el microcontrolador (vía serial)
  if (Serial.available()) {
    datosRegistrados = Serial.readStringUntil('\n');
    Serial.println("Datos recibidos: " + datosRegistrados);
  }
  // Comprobar si hay clientes
  WiFiClient client = server.available();
  if (client) {
    String req = client.readStringUntil('\r');
    client.flush();

  //Enviar los datos almacenados al cliente
    String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    s += "<!DOCTYPE HTML>\r\n<html>";
    s += "<p>Datos registrados: " + datosRegistrados + "</p>";
    s += "</html>";

    client.print(s);
    delay(1);
    Serial.println("Datos enviados al cliente");
  }
}
