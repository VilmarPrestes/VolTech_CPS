#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
db.setDatabaseName("cameras.db");

if (!db.open()) {
    qDebug() << "Erro ao abrir o banco de dados.";
} else {
    qDebug() << "Banco de dados conectado.";
}
