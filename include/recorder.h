#ifndef RECORDER_H
#define RECORDER_H

#include <QString>
#include <QList>
#include "camera.h"

class Recorder {
public:
    Recorder(const QString &nome, const QString &login, const QString &senha, int canal,
             const QString &ip, const QString &streaming, const QString &protocol);

    void addCamera(const Camera &camera);
    QList<Camera> getCameras() const;

private:
    QString nome;
    QString login;
    QString senha;
    int canal;
    QString ip;
    QString streaming;
    QString protocol;
    QList<Camera> cameras;
};

#endif // RECORDER_H
