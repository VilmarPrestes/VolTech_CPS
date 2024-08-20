#include "recorder.h"

Recorder::Recorder(const QString &nome, const QString &login, const QString &senha, int canal,
                   const QString &ip, const QString &streaming, const QString &protocol)
    : nome(nome), login(login), senha(senha), canal(canal), ip(ip), streaming(streaming),
    protocol(protocol) {}

void Recorder::addCamera(const Camera &camera) {
    cameras.append(camera);
}

QList<Camera> Recorder::getCameras() const {
    return cameras;
}
