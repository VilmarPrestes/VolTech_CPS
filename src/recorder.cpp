#include "recorder.h"

Recorder::Recorder(int id, const QString &nome)
    : id(id), nome(nome) {}

int Recorder::getId() const { return id; }
QString Recorder::getNome() const { return nome; }

void Recorder::addCamera(Camera *camera) {
    cameras.append(camera);
    camera->setRecorder(this);
}

QList<Camera*> Recorder::getCameras() const {
    return cameras;
}
