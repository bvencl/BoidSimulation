# Rajszimuláció

## A projekt rövid bemutatása

Ez a projekt egy raj (nyáj) mozgásának szimulációját valósítja meg két dimenzióban. A raj tagjai különféle szabályok szerint mozognak, amelyek befolyásolják a gyorsulásukat és így a sebességüket is. A grafikus megjelenítéshez az SFML 2.5.1-es verzót használom. A szimuláció célja a természetben megfigyelhető rajmozgás, rajintelligencia és a különböző viselkedésű rajok modellezése. A rajok egyes egyedei az alábbi négy szabály szerint mozognak:

 1) **Chasing (Üldözés)**: Minden egyed egy közös célpontot, jelen esetben az egérkurzort "kergeti", azaz felé gyorsul.

 2) **Separation (Szeparáció)**: Az egyedek taszító erőt éreznek a többi egyedtől, és próbálnak távolodni, hogy elkerüljék az ütközést.

 3) **Cohesion (Kohézió)**: Az egyedek a közvetlen szomszédaik tömegközéppontja felé gyorsulnak, így összetartóbbá válik a mozgásuk.

 4) **Alignment (Igazodás)**: Az egyedek a közvetlen szomszédaik sebességét próbálják felvenni, így egymáshoz igazodva mozognak.

Az alábbiakban ismeretetem a program használatát, felépítését, az egyes tervezési döntések mögötti okokat és esetleges fennmaradt kérdéseket és problémákat, majd kitérek a jövőbeli fejlesztési és bővítési lehetőségekre.

## Használat

A projekt tartalmaz egy Makefile-t, amely Windows és UNIX alapú operációs rendszereken egyaránt működik (Windows 11-en és Ubuntu 22.04 LTS-en fejlesztettem és teszteltem).

### Fordítás és futtatás

 1) **Fordítás:**
    A Makefile segítségével az alábbi módon egyszerűen fordíthatod:
        cd codes
        make

    Illetve ha debug módban szeretnéd elindítani (nem feltétlenül ajánlott, egy kiválasztott egyed aktuális pozíciója kiíródik minden időlépésben):
        cd codes
        make debug

 2) **A program indítása**:

        cd bin
        .\main.exe param1 param2

    ahol:

    - param1 a megjelenő ablak kívánt szélessége pixelben (alapból 1920)
    - param2 a megjelenő ablak kívánt magassága pixelben (alapból 1080)

 3) **Boid-ok számának megadása**:

    Ezután a terminálban kell megadni a szimulációban részt vevő egyedek számát.  

## Memóriaszivárgás "problémák"

A program az SFML 2.5.1 verzióját használja. Több memóriaszivárgást tesztelő programmal is teszteltem (Memtrace, Dr. Memory, Valgrind), és memóriaszivárgásokat találtam, amelyek az SFML használatából erednek. Ha az SFML-hez kapcsolódó részeket eltávolítjuk, a program nem mutat memóriaszivárgást. A program sehol sem tartalmaz nyers pointerekkel történő dinamikus memóriakezelést, így biztosan nem valós pozitív ezeknek a vizsgáló eszközöknek a kimenete. Az alábbi forrásokat találtam a probléma megértéséhez, bár még nem sikerült teljesen rájönnöm a memóriaszivárgás okára:

- [SFML Issue #1673](https://github.com/SFML/SFML/issues/1673)
- [SFML Fórum](https://en.sfml-dev.org/forums/index.php?topic=27777.0)

### Memóriaszivárgáshoz kapcsolódóan

Amennyiben a Memtrace mellett szeretnénk elindítani a programot, az a *window* generálásánál egyből kidob, a problémán jelenleg dolgozom még.

## A programról

### Osztályok, jelentésük, használatuk

#### Vector osztály

Az általam definiált Vector osztály egy kétdimenziós vektort valósít meg. Matematikai műveletek elvégzéséhez deiniáltam ezt az osztályt, ugyanis erre nincsen külön STL-beli előre definiált osztály. A programban mindenhol használom ezt az osztályt, ugyanis a szimulációnál a számítások túlnyomó része a vektoralgebra területéhez tartozik.

#### BasicBoid osztály

A Boid elnevezés Craig Reynolds 1986-os Boids névvel ellátott mesterséges élet projektjéből származik. A Boidok aktuális álllapotát négy változóval modellezem:

- **speed**: A Boidok sebességét tároló *Vector*, amely alapján a Boid pozícióját számolom.
- **acceleration**: A Boidok gyorsulását tároló *Vector*, amely alapjén a Boid sebességét számolom.
- **currentPosition**: A Boidok aktuális pozícióját tároló *Vector*. Ennek *sf::Vector2f* típusra való kasztolásával tudom megjeleníteni a Boidokat.
- **mass**: A Boidok tömegét tároló *double* érték. Ugyan ezzel a számértékkel inicializálom az egyes Boidokhoz tartozó alakzatokat is, így a nagyobb Boidokhoz nagyobb mértet is tudunk rendelni.

Ezzel a négy változóval teljesen leírható a Boidok minden időpillanatban vett aktuális állapota. A Boidok mozgásánál a koncepcióm az volt, hogy az egyedek szabadon váktoztathatják gyorsulásukat, ugyanakkor a sebességük csak és kizárólag a gyorsulásukon keresztül változtatható, azaz nem felülírható sebességük az erre kijelült metóduson kívül sehol. A Boidok mozgatását a MyTurn metódussal végzem. Ez egyszerűen a paraméterül kapott gyorsulással felülírja a Boid aktuális gyorsulását, majd kiszámítja a "pillanatnyi sebességét" és ez alapján meghatározza a Boid pillanatnyi pozícióját. Kísérletezés képpen néhány szabálynál (a szabályokról később írok részletesebben) figyelembe vettem, hogy a Boidoknak van "látótere". A látótér közepének a sebességet vettem, azaz minden egyed a sebességével folyamatosan egy irányba néz. Ebből adódóan kellő távon kívül csak olyan más egyedeket képesek észlelni, amelyek benne vannak a látóterükben. (Ilyen például a SeparationRule. A gyakorlatban talán ez azt jelenthetné, hogy azt a társát nem fogja megpróbálni kikerülni, amelyikről nem tud, azaz a másik fog csak lelassítani, amelyik észleli a vele szemben lévő egyedet. Bizonyos távolságban ugyanakkor mindenképpen észlelik a környezetükben lévő társaikat, ezt akár felfoghatjuk úgy is, hogy "meghallják" társaikat.)

#### Flock osztály

A Flock osztály a Boidokból álló rajt hivatott reprezentálni. Az egy rajba rendezett egyedek tudnak egymásra reagálni, más rajokkal egyelőre nem képesek interaktálni, ugyanakkor van lehetőség több raj létrehozására. A Boidokat jelen megvalósításban egy std::vector-ban tárolom, ugyanakkor minden metódus úgy van implementálva, hogy ezt másféle STL-kompatibilis konténerrel is végezhetnénk.
A raj szabályainak szabály-erősségét jelenleg annak példányosításakor lehet beállítani, ugyanis a raj tartalmazza a rajta értelmezett szabály-példányokat (ezt a jövőben szeretném még átalakítani).
A Flock legfőbb metódusa a moveFlock, ez felel a raj szabályainak alkalmazásáról, itt számolódik minden Boid pillanatbeli gyorsulás értéke, és ezt adja tovább a Boidok MyTurn függvényének (az engineTime aktuális értékével együtt).

#### Rule osztály

A Rule osztály a három Boidok között ható szabály-osztály ősosztálya. Az osztály a CRTP (Curiously Recrring Template Pattern) tervezési minta szerint lett tervezve, aminek lényege, hogy az ősosztály paraméterben megkaphatja a belőle származtatott osztályt. Ez a minta teszi lehetővé, hogy az ősosztályban definiáljunk olyan metódsukoat, amelyek a szűrmaztatott osztály metódusait képesek meghívni. Erre a tervezési mintára jelen esetben azért van szükség, mert ha szerenénk a Flock osztályban más fajta STL kompatibilis tárolóban tárolni a BasicBoid objektumainkat, akkor így nem kell módosítanunk semmit sem a szabályok implementációján, teljesen függetlenek a kapott tároló fajtájától.
Ezeken felül a Rule osztály koherens interfészt szolgáltat a három olyan szabálnyak, amelyek a Boidok között hatnak (ezek a Separation, Cohesion és Alignment). A Chasing szabály azért nem ebből az osztályból származik, mert ugyan hasonló interfésze van a többi szabályhoz, ugyanakkor csupán az aktuálisan vizsgált egyedre, és a kurzor pozíciójára van szüksége a számytásokhoz, nem igényli az egész raj ismeretét.

#### ChasingRule osztály

A Chasing ("Üldözés") szabály mevalósításáért felelős osztály. A kurzor és a paraméterül kapott Boid pozíciójából számolja a gyorsulást, amellyel a Boid a kurzor felé fog gyorsulni az adott időpillanatban. Erre a szabályra fektettem a legnagyobb hangsúlyt, ugyanis szerintem ez a leglátványosabb a szabályok között, ugyanakkor még mindig nem vagyok teljesen elégedett vele, szeretnék még finomítani rajta. A szabályt a következő képletekkel számolom:

1) Alapesetben:

    $$
    \vec{a} = \left( \vec{d} \cdot d \right) \cdot S
    $$

2) Ha az irányvektor ($\vec{d}$) és a Boid sebességének ($\vec{v}$) skaláris szorzata negatív, akkor a gyorsulás az irányvektor, és egy empirikusan meghatározott korrekciós tényező ($breakinForce$) szorzatára módosul:

    $$
    \vec{d} \cdot \vec{v} < 0 \quad \Rightarrow \quad \vec{a} = \vec{d} \cdot breakingForce \cdot S
    $$

3) Ha a Boid sebességének harmada nagyobb, mint a célponttól való távolság ($d$), és az irányvektor és a sebesség skaláris szorzata pozitív, akkor a gyorsulás egy másik korrekciós tényezővel módosul, amelyet a sebesség és az irányvektor vetülete alapján számolunk ki:

    $$
    \frac{|\vec{v}|}{3} > d \quad \text{és} \quad \vec{d} \cdot \vec{v} > 0
    $$

    $$
    \Rightarrow
    $$

    $$
    correctionFactor = - ( breakingForce \cdot |\vec{v}|)
    $$

    $$
    \vec{a} = \vec{d}.proj(\vec{v})  \cdot  correctionFactor
    $$

ahol:

- $d$ a célpont és a Boid közötti távolság (distance),
- $\vec{d}$ az irányvektor (direction),
- $\vec{v}$ a sebesség (speed),
- $\vec{a}$ a gyorsulás (acceleration),
- $S$ a szabály erőssége (ruleStrength)
- $breakingForce$ = 30, ez egy empirikusan meghatározott konstans.

#### SeparationRule osztály

A Separation ("Szeparáció") szabály megvalósításáért felelős osztály. A Rule osztályból származtatom, így megkapta annak interfészét is. A szabály által szolgáltatott gyorsulás komponens számolásáért a *calculateRuleForIndividualImpl* függvény felelős, ezt a CRTP tervezés miatt a *calcualateRuleForIndividual* függvény hívja meg. Ezt a szabályt tartom a második legfontosabbnak, ugyanis szerintem a kurzor üldözése mellett a másik legfontosabb dolga a Boidoknak, hogy ne ütközzenek össze. A tömegük azért szerepel ebben az egyenletben, mert ez arányos az őket reprezentáló körökkel, így a képernyőn lévő méretükkel. A szabályt a következő képletekkel számolom (a $scalingFactor$ számolása a lényeges):

 1) Amennyiben a Boidok nagyon közel vannak egymáshoz:

    $$
    \text{}\newline
    distance < M_i + M_o + \frac{desiredMinimalDistance}{3} \quad \Rightarrow  \quad scalingFactor = empiricScalingValue
    \text{}\newline
    $$

 2) Amennyiben a kívánt távolságnál közelebb, de a fentebbinél távolabb helyezkednek el:

    $$
    \text{}\newline
    M_i + M_o+ \frac{desiredMinimalDistance}{3} \leq distance \leq M_i + M_o + desiredMinimalDistance
    \Rightarrow
    scalingFactor = \frac{1}{distance - (M_i + M_o)}
    \text{}\newline
    $$
 3) Amennyiben a kívánt határon kívül helyezkednek el, és a vizsgált Boid látóterében van a másik Boid:

    $$
    \text{}\newline
    M_i + M_o+ desiredMinimalDistance \ge distance \quad \text{és} \quad \vec{d}.angleWith(\vec{v}) \leq \frac{\pi}{3} \quad \Rightarrow \quad scalingFactor = \frac{M_i + M_o}{distance^2}
    $$
    $$
    \text{}\newline
    \text{Így a szabály által visszaadott gyorsulás komponens: }
    $$
    $$
    \vec{d} \cdot scalingFactor \cdot S
    $$

    ahol:

- $M_i$: A vizsgált Boid tömege (individual.getMass()),
- $M_o$: A másik Boid, amelyikkel éppen vizsgáljuk a vizsgált egyedünket (currentFlockMembergetMass()),
- $scalingFactor$: A skálázó faktor, amellyel az irányvektort szorozni fogjuk,
- $\vec{d}$: Az irányvektor (direction)
- $distance$: A két Boid közötti távolság (distance)
- $desiredMinimalDistance$ = 150 [pixel]
- $empiricScalingValue$ = 500
- $S$: Szabály erőssége (ruleStrength)

#### CohesionRule osztály

