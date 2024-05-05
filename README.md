# Programozás alapjai 2 féléves házi feladat Bódi Vencel VBW5N9

## Rajzásszimuláció

A rajban mozgás a természetben gyakran megfigyelhető denevérrajok, birkanyájak stb esetében. A mozgás jellemzője, hogy nincs vezéregyed, minden egyed azonos szabályokat követve, a közvetlen környezetét érzékelve mozog.

Készíts szimulációt, melyben kezdetben véletlenszerű pozícióban elhelyezkedő egyedek mozgását követed.

Minden egyed négy szabálynak engedelmeskedik:

1) Separation: Amennyiben közel kerül szomszédaihoz, azok erős taszító erőhatást gyakorolnak rá (pl távolság négyzetének inverzével arányos taszító erő)

2) Alignment: Minden egyed észeleli közvetlen környezete átlagos sebességét, és ebbe az irányba ható gyorsulással reagál

3) Cohesion: Minden egyed közvetlen szomszédai tömegközéppontja felé is gyorsul

4) Chasing: Minden egyed egy meghatározott cél felé is gyorsul

Készíts programot, melyben beállítható a négy gyorsuláskomponens aránya, fizikája (távolsággal, annak valamely hatványával arányos gyorsulás), és a képernyőn ábrázolja a raj mozgását. Az egyszerűség kedvéért a raj kövesse az egérkurzort, de közben engedelmeskedjen az 1-3 szabályoknak is.
A mozgás kinematikáját könnyű számítani. A szabályok alapján minden időlépésben kiszámítható minden egyed gyorsulásvektora. A gyorsulásvektor alapján számítható sebességvektorának egy időegységre eső változása. Végül a sebességvektor alapján számítható minden egyed következő időpontbeli pozíciója.

A szép OOP megoldás az, ha a szabályokat közös ősből származó szabály-osztályok valósítják meg, melyek példányait a rajra alkalmazva, meghatározzák az i-edik egyed gyorsuláskomponensét.

A grafikus megjelenítést könnyen végezheted az SFML könyvtárral.


(nagyot mennek a commit üzenetek :D)
