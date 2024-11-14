#include <ESP8266WiFi.h>

//const char* ssid = "FeliWiFi-Fibe-2.4";       // Cambia por tu SSID
//const char* password = "feliwifi";  // Cambia por tu contraseña

const char* ssid = "Cooperadora Alumnos";       // Cambia por tu SSID
const char* password = "";  // Cambia por tu contraseña

WiFiServer server(80);

String json = "NO hay datos";

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
  // Comprobar si hay datos disponibles desde el RP2040 por UART
  if (Serial.available()) {
    json = Serial.readStringUntil('\n');  // Leer el JSON completo
    Serial.println("Datos recibidos por UART:");
    Serial.println(json);
  }

  // Gestionar los clientes que se conectan al servidor web
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Cliente conectado");
    client.print("Servidor activo\r\n");

    // Esperar a que llegue una petición HTTP completa
    while (client.connected()) {
      if (client.available()) {
        String request = client.readStringUntil('\r');
        Serial.println("Petición HTTP recibida:");
        Serial.println(request);

        client.flush();

        // Si es una petición GET al recurso raíz
        if (request.startsWith("GET / ")) {
          // Enviar la respuesta HTTP con los datos JSON
          client.print("HTTP/1.1 200 OK\r\n");
          client.print("Content-Type: application/json\r\n\r\n");
          client.print(json);  // Enviar el JSON recibido desde UART
          Serial.println("JSON enviado al cliente: " + json);
        } else {
          // Responder con 404 si se solicita un recurso no válido
          client.print("HTTP/1.1 404 Not Found\r\n");
          client.print("Content-Type: text/plain\r\n\r\n");
          client.print("Recurso no encontrado");
          Serial.println("Recurso no encontrado");
        }
        //break;  // Salir tras procesar la petición
      }
    }

    delay(1);  // Breve pausa antes de cerrar la conexión
    client.stop();  // Cerrar la conexión con el cliente
    Serial.println("Cliente desconectado");
  }
}