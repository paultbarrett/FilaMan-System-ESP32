#include "commonFS.h"
#include <LittleFS.h>

bool removeJsonValue(const char* filename) {
    File file = LittleFS.open(filename, "r");
    if (!file) {
        return true;
    }
    file.close();
    if (!LittleFS.remove(filename)) {
        Serial.print("Fehler beim Löschen der Datei: ");
        Serial.println(filename);
        return false;
    }
    return true;
}

bool saveJsonValue(const char* filename, const JsonDocument& doc) {
    File file = LittleFS.open(filename, "w");
    if (!file) {
        Serial.print("Fehler beim Öffnen der Datei zum Schreiben: ");
        Serial.println(filename);
        return false;
    }

    if (serializeJson(doc, file) == 0) {
        Serial.println("Fehler beim Serialisieren von JSON.");
        file.close();
        return false;
    }

    file.close();
    return true;
}

bool loadJsonValue(const char* filename, JsonDocument& doc) {
    File file = LittleFS.open(filename, "r");
    if (!file) {
        Serial.print("Fehler beim Öffnen der Datei zum Lesen: ");
        Serial.println(filename);
        return false;
    }
    DeserializationError error = deserializeJson(doc, file);
    file.close();
    if (error) {
        Serial.print("Fehler beim Deserialisieren von JSON: ");
        Serial.println(error.f_str());
        return false;
    }
    return true;
}

String readFile(const char* filename) {
    File file = LittleFS.open(filename, "r");
    if (!file) {
        Serial.print("Fehler beim Öffnen der Datei: ");
        Serial.println(filename);
        return "";
    }
    
    // Effizient: Speicher vorab allokieren und in Blöcken lesen
    // Alte Implementierung war O(n²) wegen Byte-für-Byte String-Konkatenation
    size_t fileSize = file.size();
    String content;
    content.reserve(fileSize + 1);  // Speicher vorab allokieren
    
    // Lese in 512-Byte Blöcken statt Byte für Byte
    char buffer[512];
    while (file.available()) {
        size_t bytesRead = file.readBytes(buffer, sizeof(buffer));
        content.concat(buffer, bytesRead);
    }
    
    file.close();
    return content;
}

void initializeFileSystem() {
    if (!LittleFS.begin(true)) {
        Serial.println("LittleFS Mount Failed");
        return;
    }
    Serial.printf("LittleFS Total: %u bytes\n", LittleFS.totalBytes());
    Serial.printf("LittleFS Used: %u bytes\n", LittleFS.usedBytes());
    Serial.printf("LittleFS Free: %u bytes\n", LittleFS.totalBytes() - LittleFS.usedBytes());
}