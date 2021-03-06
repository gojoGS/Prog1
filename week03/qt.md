# [Arecibói üzenet (Qt)](https://github.com/rbesenczi/BHAXBook/tree/master/Conway/Areciboi_uzenet)

A program fordításához telepítsük a Qt5 keretrendszert (*5.12.2-vel tesztelve*).

Ubuntun esetében ezt a következő paranccsal tehetjük:

```bash
sudo apt install qt5-default
```

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Arecibói üzenet (Qt)](#arecibói-üzenet-qthttpsgithubcomrbesenczibhaxbooktreemasterconwayareciboi_uzenet)
  - [Az üzenet](#az-üzenet)
  - [A kép](#a-kép)
  - [Fordítás](#fordítás)
  - [A prorgam részei](#a-prorgam-részei)
    - [main.cpp](#maincpp)
    - [areciboiablak.h](#areciboiablakh)
    - [areciboiablak.cpp](#areciboiablakcpp)

<!-- /code_chunk_output -->

## Az üzenet

Maga az üzenet egy 1679 elemből álló bitsorozat, amit 1974 novemberében az űrbe sugároztak. Olyan információkat tartalmaz, amely  az emberiséggel (a Föld lakossága 1974-ben), a Földön élő szén-alapú életformákkal (a DNS-t felépítő elemek rendszámai) kapcsolatos, vagy az üzenet küldéséről árul el valamit (tartalmazza a Föld relatív helyét a Naphoz képest).

## A kép

Ebből a bináris jelsorozatból úgy csinálunk képet, hogy az egyes biteket színes pixelekként (vagy tetszőleges méretű négyzetekként) kezeljük, és a bit két lehetséges értékéhez egy-egy színt rendelünk. Ha képet szeretnénk, akkor valamilyen felbontást is meg kell határoznunk. Mivel az 1679 csak egyféleképpen lehet felírni két szám szorzataként (ha az 1\*1679-től eltekintünk), az pedig 23\*73. Ez azt jelenti, hogy akármekkorák is lesznek az egyes biteket jelölő négyzetek (egy pixeltől egészen akármeddig), ezeket a négyzeteket 23 oszlopba és 73 sorba fogjuk rendezni.

## Fordítás

Fordítani és futtatni a következő parancsokkal lehet:

```bash
qmake
make
./areciboiablak
```

## A prorgam részei

### main.cpp

```c++
// compile: /opt/Qt/5.14.1/gcc_64/bin/qmake && make -j8
// run: ./areciboiablak
#include <QApplication>
#include "areciboiablak.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AreciboAblak w(23, 73, "00000010101010000000000001010000010100000001001000100010001001011001010101010101010100100100000000000000000000000000000000000001100000000000000000001101000000000000000000011010000000000000000001010100000000000000000011111000000000000000000000000000000001100001110001100001100010000000000000110010000110100011000110000110101111101111101111101111100000000000000000000000000100000000000000000100000000000000000000000000001000000000000000001111110000000000000111110000000000000000000000011000011000011100011000100000001000000000100001101000011000111001101011111011111011111011111000000000000000000000000001000000110000000001000000000001100000000000000010000011000000000011111100000110000001111100000000001100000000000001000000001000000001000001000000110000000100000001100001100000010000000000110001000011000000000000000110011000000000000011000100001100000000011000011000000100000001000000100000000100000100000001100000000100010000000011000000001000100000000010000000100000100000001000000010000000100000000000011000000000110000000011000000000100011101011000000000001000000010000000000000010000011111000000000000100001011101001011011000000100111001001111111011100001110000011011100000000010100000111011001000000101000001111110010000001010000011000000100000110110000000000000000000000000000000000011100000100000000000000111010100010101010101001110000000001010101000000000000000010100000000000000111110000000000000000111111111000000000000111000000011100000000011000000000001100000001101000000000101100000110011000000011001100001000101000001010001000010001001000100100010000000010001010001000000000000100001000010000000000001000000000100000000000000100101000000000001111001111101001111000");
    w.show();

    return a.exec();
}
```

Ahhoz hogy létrehozzunk és megjelenítsünk egy Qt-beli alkalmazást létre kell hoznunk egy `QApplication` objektumot. Az alkalmazásunk úgy fog elindulni, hogy a program a `return a.exec()` utasítással terminál.

Létrehozunk egy `AreciboAblak` objektumot, ami egy ablakként fog majd megjelenni a képernyőnkön. A konstruktorban átadott két adat az a sorok, illetve az oszlopok száma, az ezeket követő abomináció pedig az üzenet bináris alakja.

Ha azt akarjuk hogy az egyik grafikus elemünk megjelenjen, akkor hívjuk meg rajta a `show()` metódust.

### areciboiablak.h

```c++
#ifndef ARECIBOABLAK_H
#define ARECIBOABLAK_H

#include <QMainWindow>
#include <QPainter>

class AreciboAblak : public QMainWindow
{
    Q_OBJECT

public:
    AreciboAblak(int szelesseg = 23, int magassag = 73,
                 std::string uzenet = "00000010101010000000000001010000010100000001001000100010001001011001010101010101010100100100000000000000000000000000000000000001100000000000000000001101000000000000000000011010000000000000000001010100000000000000000011111000000000000000000000000000000001100001110001100001100010000000000000110010000110100011000110000110101111101111101111101111100000000000000000000000000100000000000000000100000000000000000000000000001000000000000000001111110000000000000111110000000000000000000000011000011000011100011000100000001000000000100001101000011000111001101011111011111011111011111000000000000000000000000001000000110000000001000000000001100000000000000010000011000000000011111100000110000001111100000000001100000000000001000000001000000001000001000000110000000100000001100001100000010000000000110001000011000000000000000110011000000000000011000100001100000000011000011000000100000001000000100000000100000100000001100000000100010000000011000000001000100000000010000000100000100000001000000010000000100000000000011000000000110000000011000000000100011101011000000000001000000010000000000000010000011111000000000000100001011101001011011000000100111001001111111011100001110000011011100000000010100000111011001000000101000001111110010000001010000011000000100000110110000000000000000000000000000000000011100000100000000000000111010100010101010101001110000000001010101000000000000000010100000000000000111110000000000000000111111111000000000000111000000011100000000011000000000001100000001101000000000101100000110011000000011001100001000101000001010001000010001001000100100010000000010001010001000000000000100001000010000000000001000000000100000000000000100101000000000001111001111101001111000",
                 QWidget *parent = 0);
    ~AreciboAblak();

protected:
    std::string uzenet;
    int cellaSzelesseg;
    int cellaMagassag;
    int szelesseg;
    int magassag;
    void paintEvent(QPaintEvent*);

};

#endif // ARECIBOABLAK_H
```

Ha a header-guardon és az includeokon túljutunk, akkor láthatjuk, hogy az `AreciboAblak` osztály a `QMainWindow` leszármazottja. Ez annyit jelent, hogy a `QMainWindow` minden funkcióját örökli (például a `show()` metódust), és ezeket kiegészíti a saját elemeivel.

A kosntruktorban határoztunk meg alapártelmezett értékeket a paramétereknek, így ha valaki valameyik paramétert nem adja meg, az itt szereplő értékekel fogunk számolni, azonban ilyen alapértelmezett értéket csak az utolsó n paraméternek adhatunk meg, azaz a következő alak helytelen:

```c++
int function(int a, int b = 0, int c){
    //...
    //...
}
```

A konstruktor paramétere a sorok és oszlopok száma, illetve az üzenet mellett a `parent` nevű paraméter. Ez a paraméter egy pointer arra az grafikus elemre (azaz Widget-re), ami része az applikációnknak és szeretnénk, hogy az `AreciboAblak` hozzá tartozna. Ha ez az érték nulla (vagy nullpointer), akkor a Widget önálló elemként fog megjelenni.

A `Q_OBJECT` egy preprocesszor makro, ami ebben az esetben annyit jelent, hogy ha ezt a szimbólumot elhelyezzük egy osztály privát részében, akkor ezzel jelezzük, hogy szeretnénk magunk kezelni az eventeket.

Az objektum adattagjai között láthatjuk az üzenetet, a szélesságet és a magasságot, ezek szerepeltek a konstruktorban. Ami nem szerepelt a konstruktorban az a `cellaSzelesseg` és a `cellaMagassag`, ami azt tárolja, hogy az üzenet egy bitjét mekkora cellával ábrázoljuk. A `paintEvent` metódust a `QMainWindow`-ból örököljük (pontosabban sokkan mélyebbről, a `QWidget`-ből, de ez részlet kérdés); ez minden esetben meghívódik, ha az ablakot újra meg kell jeleníteni, és definiálni tudjuk benne, hogy ezt hogyan csinálja. Újra megjelenést idézhet elő, ha például az ablak (de akár egy része is elég) eddig el volt fedve valamilyen másik elem által (például egy legördülő menü által), és amikor ez az állapot megszűnik, akkor újra ki kell "festenünk" az ablakot.

### areciboiablak.cpp

```c++
#include "areciboiablak.h"

AreciboAblak::AreciboAblak(int szelesseg, int magassag, std::string uzenet,
                           QWidget *parent)
  : QMainWindow(parent) {
    setWindowTitle("Arecibo");

    this->magassag = magassag;
    this->szelesseg = szelesseg;
    this->uzenet = uzenet;

    cellaSzelesseg = 8;
    cellaMagassag = 8;

    setFixedSize(QSize(szelesseg * cellaSzelesseg, magassag * cellaMagassag));
}

void AreciboAblak::paintEvent(QPaintEvent *) {
    QPainter qpainter(this);

    for (int i = 0; i < magassag; ++i) {
        for (int j = 0; j < szelesseg; ++j) {

            if (uzenet.at(i * szelesseg + j) == '1')
                qpainter.fillRect(j * cellaSzelesseg, i * cellaMagassag,
                                  cellaSzelesseg, cellaMagassag, Qt::black);
            else
                qpainter.fillRect(j * cellaSzelesseg, i * cellaMagassag,
                                  cellaSzelesseg, cellaMagassag, Qt::white);

            qpainter.setPen(QPen(Qt::gray, 1));
            qpainter.drawRect(j * cellaSzelesseg, i * cellaMagassag,
                              cellaSzelesseg, cellaMagassag);
        }
    }

    qpainter.end();
}

AreciboAblak::~AreciboAblak() {}
```

Láthatjuk, hogy bár a kosntruktorban paraméterként nem jelentek meg a cella méretek, hardcodeolt értéket adunk nekik. A konstruktor utolsó sora megakadályozza, hogy átméretezzük az ablakot.

Az program lelke a `paintEvent` metódusban van. Egy `QPainter` objektummal végigiterálunk az üzenet bitjein. Mivel az üzenetet egy stringben tároltuk el, azaz egy egydimenziós adatszerkezetben, a kirajzolás pedig két dimenzióban fog történni, ezért azoszlopfolytonos bejárás módszerével fogunk a *tömbből* *mátrixot* csinálni. Minden elemről eldöntjük, hogy feketére vagy fehérre kell-e színeznünk, majd eszerint jár el a `QPainter` objektum. Minden iterációban rajzolunk egy szürke keretet a cella köré. A cella színezését kitöltéssel végeztük így ott erre nem volt szükség, de mivel itt vonalakat rajzolunk, ezért szükségeltetik a `setPen()` metódussal megváltoztatni a painter színét.
