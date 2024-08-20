#ifndef CAMERA_H
#define CAMERA_H

#include <QString>

class Camera {
public:
    Camera(const QString &nome, const QString &login, const QString &senha, int canal,
           const QString &ip, const QString &streaming, const QString &protocol, int record_id);

    QString getNome() const;
    QString getLogin() const;
    QString getSenha() const;
    int getCanal() const;
    QString getIp() const;
    QString getStreaming() const;
    QString getProtocol() const;
    int getRecordId() const;

private:
    QString nome;
    QString login;
    QString senha;
    int canal;
    QString ip;
    QString streaming;
    QString protocol;
    int record_id;
};

#endif // CAMERA_H
