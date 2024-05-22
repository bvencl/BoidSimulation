#include "init.h"

/**
 * @file main.cpp
 * @brief A program main fájlja.
 * @author Bódi Vencel VBW5N9
 */

int main(int argc, char *argv[])
{

    // A felhasználó beállíthatja a kívánt ablakméretet kijelzője szerint, amennyiben nem állít be semmit, úgy 1920*1080-as képernyőt feltételezek
    int width = 1920;
    int height = 1080;
    if (argc == 3)
    {
        sscanf(argv[1], "%d", &width);
        sscanf(argv[2], "%d", &height);
    }

    Flock flock(1, 5, 0, 0); // egy flock példányosítása

    std::vector<sf::CircleShape> boids; // a flockhoz tartozó grafikus objektumokat tároló std::vector példányosítása
    sf::Music music;                    // A zenéért felelős objetum létrehozása

    initFlock(flock, width, height); // A flock inicializálása, feltöltése boidokkal, amelyek kezdetben egy, a képernyő közepén lévő körben helyezkednek el
    initGraphics(boids, flock, sf::Color::Red);

    // Itt történik az ablak létrehozása a megadott szélességgel és magassággal.
    sf::RenderWindow window(sf::VideoMode(width, height), "Ugye milyen szepek?");

    sf::Clock engineTime;
    double dT = 0.0;

    // Gameloop, addig tart a program futása, amíg a felhasználó be nem zárja az ablakot.
    // Eléggé minimális ez a rész, de a projekt fókusza nem a megjelenítés tökéletesítésén volt
    while (window.isOpen())
    {
        dT = engineTime.restart().asSeconds(); // Minden ciklus elején nullázzuk az órát, így a számolás a ténylegesen eltelt időt veszi figyelembe, nem pedig egy konstans értékkel számol

        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed) // Itt érzékeljük, hogy a felhasználóü becsukta-e az ablakot
                window.close();
        }
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window); // Lekérjuk az egér pozícióját az ablakhoz képest
        window.clear();                                              // Az ablak tisztítása

        for (size_t j = 0; j < boids.size(); j++) // Egy ciklusban kirajzoljuk a Boidokat a képernyőres
        {
            boids[j].setPosition((sf::Vector2f)(flock[j].getPosition())); // a Boid pozíciójat sf::Vector2f-re konvertáljuk a saját Vector osztályról.
            window.draw(boids[j]);                                        // A boidok tényleges kiraéyzolása
        }

        flock.moveFlock(dT, mousePosition); // A nyáj mozgatása itt történik, minden ciklus végén, így a kezőállapotot is felveszik a képernyőn a Boidok
        window.display();
    }

    return 0;
}
