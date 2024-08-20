#include "camera.h"

Camera::Camera(const QString &nome, const QString &login, const QString &senha, int canal,
               const QString &ip, const QString &streaming, const QString &protocol, int record_id)
    : nome(nome), login(login), senha(senha), canal(canal), ip(ip), streaming(streaming),
    protocol(protocol), record_id(record_id) {}

// Implementações dos métodos "getters"
