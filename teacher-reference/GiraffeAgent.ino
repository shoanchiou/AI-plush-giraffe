/*
 * GiraffeAgent.ino
 * Reference AMB82-Mini firmware architecture for an AI plush toy.
 *
 * IMPORTANT:
 * - This is intentionally a hardware-adapter reference, not a drop-in claim
 *   for every AMB82 Arduino core/peripheral combination.
 * - Replace the TODO adapter functions with the current Ameba camera/NN,
 *   PWM/servo, LED and audio APIs used by your hardware.
 * - Keep physical limits in firmware. Never accept arbitrary PWM/GPIO commands.
 */

#include <WiFi.h>

// ---------- Network configuration ----------
// For a real project, move credentials to a non-committed secrets header.
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

WiFiServer server(8080);

// ---------- Safe semantic state ----------
enum Emotion {
  EMOTION_HAPPY,
  EMOTION_CURIOUS,
  EMOTION_THINKING,
  EMOTION_SLEEPY
};

Emotion currentEmotion = EMOTION_HAPPY;

// ---------- Forward declarations ----------
void sendJson(WiFiClient &client, int statusCode, const String &json);
void sendCorsPreflight(WiFiClient &client);
String getRequestPath(const String &requestLine);
String runVision();
void nodHead();
void shakeHead();
void waveHead();
void setEmotion(Emotion e);
bool playSound(const String &soundId);
void stopAllMotion();

void setup() {
  Serial.begin(115200);
  delay(500);

  // TODO: initialize camera + AmebaNN pipeline.
  // TODO: initialize bounded servo/motion controller.
  // TODO: initialize RGB/status LEDs.
  // TODO: initialize audio output and microSD.

  WiFi.begin(ssid, pass);
  Serial.print("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print('.');
  }

  Serial.println();
  Serial.print("Giraffe IP: ");
  Serial.println(WiFi.localIP());

  server.begin();
  Serial.println("Giraffe Agent API listening on port 8080");
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  client.setTimeout(1000);
  String requestLine = client.readStringUntil('\r');
  client.readStringUntil('\n');

  Serial.println(requestLine);

  // Drain headers. This small reference server supports GET/OPTIONS only.
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r" || line.length() == 0) break;
  }

  if (requestLine.startsWith("OPTIONS ")) {
    sendCorsPreflight(client);
    client.stop();
    return;
  }

  if (!requestLine.startsWith("GET ")) {
    sendJson(client, 405, "{\"ok\":false,\"error\":\"method_not_allowed\"}");
    client.stop();
    return;
  }

  String path = getRequestPath(requestLine);

  if (path == "/status") {
    String body = "{\"ok\":true,\"device\":\"giraffe\","
                  "\"camera\":true,\"audio\":true,\"motion\":true}";
    sendJson(client, 200, body);
  }
  else if (path == "/look") {
    sendJson(client, 200, runVision());
  }
  else if (path == "/nod") {
    nodHead();
    sendJson(client, 200, "{\"ok\":true,\"action\":\"nod\"}");
  }
  else if (path == "/shake") {
    shakeHead();
    sendJson(client, 200, "{\"ok\":true,\"action\":\"shake\"}");
  }
  else if (path == "/wave") {
    waveHead();
    sendJson(client, 200, "{\"ok\":true,\"action\":\"wave\"}");
  }
  else if (path == "/emotion/happy") {
    setEmotion(EMOTION_HAPPY);
    sendJson(client, 200, "{\"ok\":true,\"emotion\":\"happy\"}");
  }
  else if (path == "/emotion/curious") {
    setEmotion(EMOTION_CURIOUS);
    sendJson(client, 200, "{\"ok\":true,\"emotion\":\"curious\"}");
  }
  else if (path == "/emotion/thinking") {
    setEmotion(EMOTION_THINKING);
    sendJson(client, 200, "{\"ok\":true,\"emotion\":\"thinking\"}");
  }
  else if (path == "/emotion/sleepy") {
    setEmotion(EMOTION_SLEEPY);
    sendJson(client, 200, "{\"ok\":true,\"emotion\":\"sleepy\"}");
  }
  else if (path.startsWith("/play/")) {
    String soundId = path.substring(6);

    // Whitelist known sound IDs instead of accepting file paths.
    if (playSound(soundId)) {
      sendJson(client, 200, "{\"ok\":true,\"action\":\"play\",\"sound\":\"" + soundId + "\"}");
    } else {
      sendJson(client, 400, "{\"ok\":false,\"error\":\"unknown_sound\"}");
    }
  }
  else if (path == "/stop") {
    stopAllMotion();
    sendJson(client, 200, "{\"ok\":true,\"action\":\"stop\"}");
  }
  else {
    sendJson(client, 404, "{\"ok\":false,\"error\":\"unknown_command\"}");
  }

  delay(1);
  client.stop();
}

String getRequestPath(const String &requestLine) {
  int firstSpace = requestLine.indexOf(' ');
  int secondSpace = requestLine.indexOf(' ', firstSpace + 1);
  if (firstSpace < 0 || secondSpace < 0) return "/";
  return requestLine.substring(firstSpace + 1, secondSpace);
}

void sendJson(WiFiClient &client, int statusCode, const String &json) {
  const char *statusText = "OK";
  if (statusCode == 400) statusText = "Bad Request";
  else if (statusCode == 404) statusText = "Not Found";
  else if (statusCode == 405) statusText = "Method Not Allowed";

  client.print("HTTP/1.1 ");
  client.print(statusCode);
  client.print(' ');
  client.println(statusText);
  client.println("Content-Type: application/json; charset=utf-8");
  client.println("Access-Control-Allow-Origin: *");
  client.println("Cache-Control: no-store");
  client.println("Connection: close");
  client.print("Content-Length: ");
  client.println(json.length());
  client.println();
  client.print(json);
}

void sendCorsPreflight(WiFiClient &client) {
  client.println("HTTP/1.1 204 No Content");
  client.println("Access-Control-Allow-Origin: *");
  client.println("Access-Control-Allow-Methods: GET, OPTIONS");
  client.println("Access-Control-Allow-Headers: Content-Type");
  client.println("Access-Control-Max-Age: 600");
  client.println("Connection: close");
  client.println();
}

// ---------------------------------------------------------------------------
// Hardware adapters
// ---------------------------------------------------------------------------

String runVision() {
  /*
   * TODO: Replace with AMB82 camera + AmebaNN inference.
   * Keep the result compact. Do not stream continuous images to the agent.
   *
   * Example desired result:
   * {"ok":true,"objects":[{"label":"person","confidence":0.94}]}
   */
  return "{\"ok\":true,\"objects\":[{\"label\":\"person\",\"confidence\":0.94}]}";
}

void nodHead() {
  // TODO: Implement a short bounded servo trajectory.
  // Example policy: center -> small down angle -> center.
}

void shakeHead() {
  // TODO: Implement center -> small left -> small right -> center.
}

void waveHead() {
  // TODO: Implement a gentle bounded ear/head gesture.
}

void setEmotion(Emotion e) {
  currentEmotion = e;

  // TODO: Map emotion to LED pattern + OPTIONAL bounded gesture.
  // Avoid making emotion states directly control unrestricted actuators.
}

bool playSound(const String &soundId) {
  // Strict whitelist prevents path traversal or arbitrary file selection.
  if (soundId == "hello") {
    // TODO: play /audio/hello.wav from microSD.
    return true;
  }
  if (soundId == "giggle") {
    // TODO: play /audio/giggle.wav.
    return true;
  }
  if (soundId == "goodbye") {
    // TODO: play /audio/goodbye.wav.
    return true;
  }
  return false;
}

void stopAllMotion() {
  // TODO: Immediately return motion subsystem to its safe/idle state.
}
