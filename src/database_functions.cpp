#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "database_functions.h"

void createTables() {
    QSqlQuery query;

    if (!query.exec("CREATE TABLE IF NOT EXISTS Recorder ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "nome TEXT)")) {
        qDebug() << "Erro ao criar tabela Recorder:" << query.lastError().text();
    }

    if (!query.exec("CREATE TABLE IF NOT EXISTS Camera ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "nome TEXT, "
                    "login TEXT, "
                    "senha TEXT, "
                    "canal INTEGER, "
                    "ip TEXT, "
                    "streaming TEXT, "
                    "protocol TEXT, "
                    "recorder_id INTEGER, "
                    "FOREIGN KEY(recorder_id) REFERENCES Recorder(id))")) {
        qDebug() << "Erro ao criar tabela Camera:" << query.lastError().text();
    }
}

bool insertRecorder(const QString &nome) {
    QSqlQuery query;
    query.prepare("INSERT INTO Recorder (nome) VALUES (:nome)");
    query.bindValue(":nome", nome);

    if (!query.exec()) {
        qDebug() << "Erro ao inserir Recorder:" << query.lastError().text();
        return false;
    }
    return true;
}

bool insertCamera(const QString &nome, const QString &login, const QString &senha, int canal,
                  const QString &ip, const QString &streaming, const QString &protocol, int recorder_id) {
    QSqlQuery query;
    query.prepare("INSERT INTO Camera (nome, login, senha, canal, ip, streaming, protocol, recorder_id) "
                  "VALUES (:nome, :login, :senha, :canal, :ip, :streaming, :protocol, :recorder_id)");
    query.bindValue(":nome", nome);
    query.bindValue(":login", login);
    query.bindValue(":senha", senha);
    query.bindValue(":canal", canal);
    query.bindValue(":ip", ip);
    query.bindValue(":streaming", streaming);
    query.bindValue(":protocol", protocol);
    query.bindValue(":recorder_id", recorder_id);

    if (!query.exec()) {
        qDebug() << "Erro ao inserir Camera:" << query.lastError().text();
        return false;
    }
    return true;
}

QList<Recorder*> readRecorders() {
    QList<Recorder*> recorders;
    QSqlQuery query("SELECT * FROM Recorder");

    while (query.next()) {
        int id = query.value("id").toInt();
        QString nome = query.value("nome").toString();
        Recorder *recorder = new Recorder(id, nome);
        recorders.append(recorder);
    }

    return recorders;
}

QList<Camera*> readCameras() {
    QList<Camera*> cameras;
    QSqlQuery query("SELECT * FROM Camera");

    while (query.next()) {
        QString nome = query.value("nome").toString();
        QString login = query.value("login").toString();
        QString senha = query.value("senha").toString();
        int canal = query.value("canal").toInt();
        QString ip = query.value("ip").toString();
        QString streaming = query.value("streaming").toString();
        QString protocol = query.value("protocol").toString();
        int recorder_id = query.value("recorder_id").toInt();

        Camera *camera = new Camera(nome, login, senha, canal, ip, streaming, protocol, recorder_id);
        cameras.append(camera);
    }

    return cameras;
}
