# Programozás alapjai 2 féléves házi feladat Bódi Vencel VBW5N9

## A programról röviden

A program egy nyáj mozgásának szimulációját valósítja meg két dimenzióban. A nyáj tagjainak csak a gyorsulása van közvetlenül változtatva, az egyes tagok sebessége ezek alapján változik. A nyájban minden egyed négy szabálynak engedelmeskedik:

 1) Chasing: minden egyed egy közös célpontot "kerget", azaz felé gyorsul. Jelen implementációban ez a kurzor.

 2) Separation: minden egyed taszító erőt érez a többi egyedtől, azoktól távolodni próbál, hogy elkerüljék az ütközést.

 3) Cohesion: minden egyed a közvetlen szomszédai (hozzá közel lévő egyedek) tömegközéppontja felé gyorsul, így a nyáj összetartóbban mozog.

 4) Alignment: minden egyed a közvetlen szomszédai (hozzá közel lévő egyedek) sebssségét próbálja felvenni, azaz a többiek sebességét elérő irányba gyorsul.

## Használat

A fájlok között található egy Makefile is, aminek elvileg működnie kellene mind Windows operációs rendszereken, mind UNIX alapú operációs rendszereken is (Windows 11-en és Ubuntu 22.04 lts-en tesztelve).

A program indítása:

    ./main param1 param2    

vagy

    .\main param1 param2

ahol:

- param1 a megjelenő ablak kívánt szélessége pixelben (alapból 1920)
- param2 a megjelenő ablak kívánt magassága pixelben (alapból 1080)

A progam indulás után a terminálban kell megadni a legenerálni kívánt "Boid"-ok számát. Ezután indul is a program ha szerencsések vagyunk. Lévén, hogy a zene eléréséhez nem relatív elérési útvonalra, hanem konkrét elérési útvonalra van szükség, így azt a Makefile-ban kell átállítani (amennyiben van rá igény - a fájlok között mellékelve a *__________________* című száma található).

## Memóriaszivárgás problémák

A program az SFML 2.5.1-es verziót használja. Több memóriaszivárgást tesztelő programmal is teszteltem (Memtrace, Dr. Memory, Valgrind), eddig még mindegyik memóriaszivárgást mutatott ki. Amennyiben sz SFML-hez kapcsolódó részeket nem tartalmazza a program, úgy egyáltalán nincsen memóriaszivárgás, a probléma csak az SFML jelenlétében jelentkezik. Ehhez a problémához az alábbi helyen találtam forrásokat:

- [https://en.sfml-dev.org/forums/index.php?topic=27777.0](https://en.sfml-dev.org/forums/index.php?topic=27777.0)
- [https://github.com/SFML/SFML/issues/1673](https://github.com/SFML/SFML/issues/1673)
