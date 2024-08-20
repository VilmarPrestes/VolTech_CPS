#include "camera.h"
#include "recorder.h"

Camera::Camera(const QString &nome, const QString &login, const QString &senha, int canal,
               const QString &ip, const QString &streaming, const QString &protocol, int recorder_id)
    : nome(nome), login(login), senha(senha), canal(canal), ip(ip), streaming(streaming),
    protocol(protocol), recorder_id(recorder_id), recorder(nullptr) {}

QString Camera::getNome() const { return nome; }
QString Camera::getLogin() const { return login; }
QString Camera::getSenha() const { return senha; }
int Camera::getCanal() const { return canal; }
QString Camera::getIp() const { return ip; }
QString Camera::getStreaming() const { return streaming; }
QString Camera::getProtocol() const { return protocol; }
int Camera::getRecorderId() const { return recorder_id; }

void Camera::setRecorder(Recorder *recorder) {
    this->recorder = recorder;
}

Recorder* Camera::getRecorder() const {
    return recorder;
}
