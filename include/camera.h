#ifndef CAMERA_H
#define CAMERA_H

#include <QString>

class Recorder; // Declaração antecipada

class Camera {
public:
    Camera(const QString &nome, const QString &login, const QString &senha, int canal,
           const QString &ip, const QString &streaming, const QString &protocol, int recorder_id);

    QString getNome() const;
    QString getLogin() const;
    QString getSenha() const;
    int getCanal() const;
    QString getIp() const;
    QString getStreaming() const;
    QString getProtocol() const;
    int getRecorderId() const;

    void setRecorder(Recorder *recorder);
    Recorder* getRecorder() const;

private:
    QString nome;
    QString login;
    QString senha;
    int canal;
    QString ip;
    QString streaming;
    QString protocol;
    int recorder_id;
    Recorder *recorder;
};

#endif // CAMERA_H
