#include <QCoreApplication>
#include <QSqlDatabase>
#include <QDebug>
#include "database_functions.h"
#include "camera.h"
#include "recorder.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Conectar ao banco de dados
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("cameras.db");

    if (!db.open()) {
        qDebug() << "Erro ao abrir o banco de dados.";
        return -1;
    } else {
        qDebug() << "Banco de dados conectado.";
    }

    // Criar tabelas
    createTables();

    // Inserir dados de exemplo
    insertRecorder("Recorder 1");
    insertCamera("Camera 1", "login1", "senha1", 1, "192.168.1.1", "stream1", "protocol1", 1);

    // Ler e exibir dados
    QList<Recorder*> recorders = readRecorders();
    QList<Camera*> cameras = readCameras();

    for (const Recorder *recorder : recorders) {
        qDebug() << "Recorder Name:" << recorder->getNome();
    }

    for (const Camera *camera : cameras) {
        qDebug() << "Camera Name:" <<
