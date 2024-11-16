#include <ESP8266WiFi.h>
#include "ESPAsyncWebServer.h"
#include <Arduino.h>
#include <ArduinoJson.h>

bool pruebaEnviada = 0;

struct lectura {
  float carga;
  String nombre;
  float corriente;
  float voltage;
  float potencia;
};

lectura sensor_0x40;
lectura sensor_0x41;
lectura sensor_0x44;
lectura sensor_0x45;

const char* ssid = "Cooperadora Alumnos";
const char* password = "";

AsyncWebServer server(80);

void addCORSHeaders(AsyncWebServerResponse* response) {
  response->addHeader("Access-Control-Allow-Origin", "*");
  response->addHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
  response->addHeader("Access-Control-Allow-Headers", "Content-Type, X-Custom-Header");
}

void handleCORS(AsyncWebServerRequest *request) {
  AsyncWebServerResponse* response = request->beginResponse(200);
  addCORSHeaders(response);
  request->send(response);
}

void procesarJson(String json) {
  StaticJsonDocument<256> doc; // JsonDocument específico para tamaño estático
  DeserializationError error = deserializeJson(doc, json);
  if (error) {
    Serial.println("Error al parsear JSON:");
    Serial.println(error.c_str());
    return;
  }

  String nombre = doc["nombre"];  // Ahora se usa el campo "nombre" del JSON
  lectura* sensor = nullptr;

  // Compara el nombre para determinar a qué sensor se refiere
  if (nombre == "Sensor_0x40") {
    sensor = &sensor_0x40;
  } else if (nombre == "Sensor_0x41") {
    sensor = &sensor_0x41;
  } else if (nombre == "Sensor_0x44") {
    sensor = &sensor_0x44;
  } else if (nombre == "Sensor_0x45") {
    sensor = &sensor_0x45;
  }

  if (sensor) {
    sensor->carga = doc["carga"];
    sensor->nombre = nombre;
    sensor->corriente = doc["corriente"];
    sensor->voltage = doc["voltage"];
    sensor->potencia = doc["potencia"];
  } else {
    Serial.println("Sensor no reconocido: " + nombre);
  }
}

String generarRespuestaJson(lectura sensor) {
  StaticJsonDocument<256> doc; // JsonDocument estático
  doc["carga"] = sensor.carga;
  doc["nombre"] = sensor.nombre;
  doc["corriente"] = sensor.corriente;
  doc["voltage"] = sensor.voltage;
  doc["potencia"] = sensor.potencia;

  String response;
  serializeJson(doc, response);
  return response;
}

void setup_servidor() {
  server.on("/", HTTP_OPTIONS, handleCORS);
  server.on("/sensor", HTTP_OPTIONS, handleCORS);
  //server.on("/todos", HTTP_OPTIONS, handleCORS);

  server.on("/sensor", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (!request->hasParam("nombre")) {
      AsyncWebServerResponse* response = request->beginResponse(400, "text/plain", "Falta el parámetro 'nombre'.");
      addCORSHeaders(response);
      request->send(response);
      return;
    }

    String sensorNombre = request->getParam("nombre")->value();
    String responseJson;

    // Compara el nombre recibido en la solicitud para determinar el sensor
    if (sensorNombre == "Sensor_0x40") {
      responseJson = generarRespuestaJson(sensor_0x40);
    } else if (sensorNombre == "Sensor_0x41") {
      responseJson = generarRespuestaJson(sensor_0x41);
    } else if (sensorNombre == "Sensor_0x44") {
      responseJson = generarRespuestaJson(sensor_0x44);
    } else if (sensorNombre == "Sensor_0x45") {
      responseJson = generarRespuestaJson(sensor_0x45);
    }

    else {
      Serial.println("Error: Sensor no encontrado");
      AsyncWebServerResponse* response = request->beginResponse(404, "text/plain", "Sensor no encontrado.");
      addCORSHeaders(response);
      request->send(response);
      return;
    }

    AsyncWebServerResponse* response = request->beginResponse(200, "application/json", responseJson);
    addCORSHeaders(response);
    request->send(response);
  });
  server.begin();
}

void setup() {
  Serial.begin(115200);

  Serial.println("\nConectando a ");
  Serial.print("Setting AP (Access Point)…");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi conectado");
  Serial.println("Dirección IP: ");
  Serial.println(WiFi.localIP());

  Serial.println("\nServidor iniciado");
  setup_servidor();
}

void loop() {
  if (Serial.available()) {
    String json = Serial.readStringUntil('\n');
    Serial.println("Datos recibidos por UART:");
    Serial.println(json);
    procesarJson(json);
  }
  else if (!pruebaEnviada) {
    String json = "{\"nombre\":\"Sensor_0x40\",\"carga\":15.5,\"corriente\":2.3,\"voltage\":5.0,\"potencia\":11.5}";

    Serial.println("Prueba de JSON:");
    Serial.println(json);

    // Procesa el JSON de prueba
    procesarJson(json);

    // Cambia la bandera a true para evitar que se vuelva a enviar
    pruebaEnviada = true;
  }
}