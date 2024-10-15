void loop() {
  // Recepción de datos desde el microcontrolador (vía serial)
  if (Serial.available()) {
    datosRegistrados = Serial.readStringUntil('\n');
    Serial.println("Datos recibidos: " + datosRegistrados);
  }

  // Verificar si hay un cliente conectado al servidor web
  WiFiClient client = server.available();
  if (client) {
    String req = client.readStringUntil('\r');
    client.flush();

    // Enviar los datos almacenados al cliente
    String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    s += "<!DOCTYPE HTML>\r\n<html>";
    s += "<p>Datos registrados: " + datosRegistrados + "</p>";
    s += "</html>";

    client.print(s);
    delay(1);
    Serial.println("Datos enviados al cliente");
  }
}