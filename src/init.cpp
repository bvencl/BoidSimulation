#include "init.h"

// A szimuláció elkezdését segítő fájl

void initFlock(Flock &flock, double width, double height)
{
    int boidCount = 0;
    std::cout << "Please give me the size of the flock" << std::endl;
    std::cin >> boidCount;
    Vector center(width / 2, height / 2);
    for (int i = 0; i < boidCount; i++) // Itt a Boidokat egy 100 pixel sugarú körben helyezzük el, függetlenül a számuktól
    {
        // Boidokat hozunk létre 10-es tömeggel, a függvény által kiszámolt koordinátákkal, nulla kezdősebességgel, illetve nulla kezdeti gyorsulással
        BasicBoid boid(10, width / 2 + 100 * std::cos(i * (2 * M_PI / boidCount)), height / 2 + 100 * std::sin(i * (2 * M_PI / boidCount)), 0, 0, 0, 0);
        flock.insert(boid); // A létrejött Boidot "be is töltjük" a nyájba
    }
}

// A Boidok megjeleníthető részének inicializálását végző függvény. Az sf::shape objektumokat egy std::vectorban tároljuk annak flexibilitása miatt.
// Mindenképpen a flock inicializálása és feltültése után kell következnie
void initGraphics(std::vector<sf::CircleShape> &boids, Flock &flock, sf::Color color)
{
    for (size_t j = 0; j < flock.flockSize(); j++) // Végigmegy a flockon és minden Boidhoz rendel egy sf::shape objektumot a megjeleníthetőségért
    {

        sf::CircleShape shape(flock[j].getMass()); // Itt megfigyelhető, hogy a Boidok mérete arányos tömegükkel.
        shape.setFillColor(color);
        boids.push_back(shape);
    }
}

// A zene inicializálásáért felelős függvény.
void initMusic(sf::Music &music)
{
    if (!music.openFromFile(MUSIC_FILE_PATH)) // Amennyiben nem találja a zenét, vagy az nem támogatott az sfml által nem áll le a program, hanem hibát dob.
        throw std::runtime_error("Couldnt open music");
}
