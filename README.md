# Programozás alapjai 2 féléves házi feladat Bódi Vencel VBW5N9

## A programról röviden

Ez a projekt egy raj (nyáj) mozgásának szimulációját valósítja meg két dimenzióban. A nyáj tagjai különféle szabályok szerint mozognak, amelyek befolyásolják a gyorsulásukat és így a sebességüket is. A szimuláció célja a természetben megfigyelhető viselkedés modellezése.

 1) **Chasing (Üldözés)**: Minden egyed egy közös célpontot, jelen esetben az egérkurzort "kergeti", azaz felé gyorsul.

 2) **Separation (Szeparáció)**: Az egyedek taszító erőt éreznek a többi egyedtől, és próbálnak távolodni, hogy elkerüljék az ütközést.

 3) **Cohesion (Kohézió)**: Az egyedek a közvetlen szomszédaik tömegközéppontja felé gyorsulnak, így összetartóbbá válik a mozgásuk.

 4) **Alignment (Igazodás)**: Az egyedek a közvetlen szomszédaik sebességét próbálják felvenni, így egymáshoz igazodva mozognak.

## Használat

A projekt tartalmaz egy Makefile-t, amely Windows és UNIX alapú operációs rendszereken (Windows 11 és Ubuntu 22.04 LTS) egyaránt működik.

### Fordítás és futtatás

 1) **Fordítás:**
    A Makefile segítségével az alábbi módon egyszerűen fordíthatod:

        make

    Illetve ha debug módban szeretnéd elindítani (nem ajánlott, ilyenkor minden konstruktor illetve destruktor kiír a konzolra, illetve az egyedek aktuális pozíciója is kiíródik minden időlépésben):

        make debug

 2) **A program indítása**:

        ./main param1 param2    

    vagy

        .\main param1 param2

    ahol:

    - param1 a megjelenő ablak kívánt szélessége pixelben (alapból 1920)
    - param2 a megjelenő ablak kívánt magassága pixelben (alapból 1080)

 3) **Boid-ok számának megadása**:

    Ezután a terminálban kell megadni a szimulációban részt vevő egyedek számát.  

### Zene útvonal megadás

A zenefájl elérési útvonalát a Makefile-ban kell megadni. Mivel a program konkrét elérési útvonalat igényel, ezt manuálisan kell megadni a következő módon:

    MUSICF = path/to/your/favourite/musicfile.ogg

## Memóriaszivárgás problémák

A program az SFML 2.5.1-es verziót használja. Több memóriaszivárgást tesztelő programmal is teszteltem (Memtrace, Dr. Memory, Valgrind), eddig még mindegyik memóriaszivárgást mutatott ki. Amennyiben sz SFML-hez kapcsolódó részeket nem tartalmazza a program, úgy egyáltalán nincsen memóriaszivárgás, a probléma csak az SFML jelenlétében jelentkezik. Ehhez a problémához az alábbi helyen találtam forrásokat:

- [SFML Issue #1673](https://github.com/SFML/SFML/issues/1673)
- [SFML Fórum](https://en.sfml-dev.org/forums/index.php?topic=27777.0)
