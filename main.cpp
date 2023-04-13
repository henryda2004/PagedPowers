#include <QtCore>
#include <QtXml>
#include "Strategy.h"
#include "Power.h"
#include <iostream>

Strategy cargar_xml(QString n){
    QFile file(n);
    QString fname = file.fileName();
    qDebug() << "Name:" << fname;
    if (!file.open(QIODevice::ReadOnly)) {
        qCritical() << "Failed to open file:" << file.fileName();
    }

    QDomDocument doc;
    if (!doc.setContent(&file)) {
        qCritical() << "Failed to parse XML from file:" << file.fileName();
    }

    QDomElement root = doc.documentElement();
    QDomNodeList powers = root.elementsByTagName("power");

    QDomElement power1 = powers.at(0).toElement();
    QString name1 = power1.attribute("name");
    QString description1 = power1.firstChild().toElement().text();
    QString effect1 = power1.lastChild().toElement().text();

    Power *Poder1 = new Power(name1.toStdString(), description1.toStdString(), effect1.toFloat());

    std::cout<<"Name: " << Poder1->getName() <<std::endl;
    std::cout<<"Description: " << Poder1->getDescription()<<std::endl;
    std::cout<<"Effect: " << Poder1->getEffect() <<std::endl;


    QDomElement power2 = powers.at(1).toElement();
    QString name2 = power2.attribute("name");
    QString description2 = power2.firstChild().toElement().text();
    QString effect2 = power2.lastChild().toElement().text();

    Power *Poder2 = new Power(name2.toStdString(), description2.toStdString(), effect2.toFloat());


    std::cout<<"Name: " << Poder2->getName() <<std::endl;
    std::cout<<"Description: " << Poder2->getDescription()<<std::endl;
    std::cout<<"Effect: " << Poder2->getEffect() <<std::endl;

    Strategy strategy(fname.toStdString(), *Poder1, *Poder2);

    std::cout<<"Nombre del poder 1 de estrategia: " << strategy.getPower1().getName() <<std::endl;

    return strategy;
}

bool verificar_si_hay_poder(QString poder, Strategy strategies[]){
    bool exists = false;
    if (strategies[0].getPower1().getName() == poder.toStdString()){
        exists = true;
    }
    if (strategies[0].getPower2().getName() == poder.toStdString()){
        exists = true;
    }
    if (strategies[1].getPower1().getName() == poder.toStdString()){
        exists = true;
    }
    if (strategies[1].getPower2().getName() == poder.toStdString()){
        exists = true;
    }
    std::cout<<"Existe: " << exists <<std::endl;
    return exists;
}

Strategy strategies[2] = {cargar_xml("XML/Estrategia1.xml"), cargar_xml("XML/Estrategia2.xml")};
bool Poder1 = false;
bool Poder2 = false;
bool Poder3 = false;
bool Poder4 = false;
bool Poder5 = false;
bool Poder6 = false;
bool Poder7 = false;
bool Poder8 = false;



void utilizar_poder(QString poder, Strategy strategies[]){
    verificar_si_hay_poder(poder, strategies);
    if (verificar_si_hay_poder(poder, strategies) == 0){
        if (poder == "Poder1" || poder == "Poder2"){
            strategies[0] = cargar_xml("XML/Estrategia1.xml");
        }
        if (poder == "Poder3" || poder == "Poder4"){
            strategies[0] = cargar_xml("XML/Estrategia2.xml");
            std::cout<<"strategies actualizado" << std::endl;
        }
        if (poder == "Poder5" || poder == "Poder6"){
            strategies[0] = cargar_xml("XML/Estrategia3.xml");
        }
        if (poder == "Poder7" || poder == "Poder8"){
            strategies[0] = cargar_xml("XML/Estrategia4.xml");
        }
    }
    verificar_si_hay_poder(poder, strategies);
    if  (poder == "Poder1"){
        Poder1 = true;
    }
    if  (poder == "Poder2"){
        Poder2 = true;
    }
    if  (poder == "Poder3"){
        Poder3 = true;
    }
    if  (poder == "Poder4"){
        Poder4 = true;
    }
    if  (poder == "Poder5"){
        Poder5 = true;
    }
    if  (poder == "Poder6"){
        Poder6 = true;
    }
    if  (poder == "Poder7"){
        Poder7 = true;
    }
    if  (poder == "Poder8"){
        Poder8 = true;
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QString poder_solicitado = "none";
    poder_solicitado = "Poder5";
    utilizar_poder(poder_solicitado, strategies);

    return 0;
}