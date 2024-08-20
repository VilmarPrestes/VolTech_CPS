#ifndef RECORDER_H
#define RECORDER_H

#include <QString>
#include <QList>
#include "camera.h"

class Recorder {
public:
    Recorder(int id, const QString &nome);

    int getId() const;
    QString getNome() const;
    void addCamera(Camera *camera);
    QList<Camera*> getCameras() const;

private:
    int id;
    QString nome;
    QList<Camera*> cameras;
};

#endif // RECORDER_H
