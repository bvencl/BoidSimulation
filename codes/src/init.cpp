#include "init.h"

void initFlock(Flock &flock, double width, double height)
{
    int boidCount = 0;
    std::cout << "Please give me the size of the flock" << std::endl;
    std::cin >> boidCount;
    Point center(width / 2, height / 2);
    for (int i = 0; i < boidCount; i++)
    {
        BasicBoid boid(10, width / 2 + 250 * std::cos(i * (2 * M_PI / boidCount)), height / 2 + 250 * std::sin(i * (2 * M_PI / boidCount)), 0, 0, 0, 0);
        flock.insert(boid);
    }
}

void initGraphics(std::vector<sf::CircleShape> &boids, Flock &flock)
{
    for (size_t j = 0; j < flock.flockSize(); j++)
    {
        sf::CircleShape shape(flock[j].getMass());
        shape.setFillColor(sf::Color::Red);
        boids.push_back(shape);
    }
}

void initMusic(sf::Music &music)
{
    if (!music.openFromFile(MUSIC_FILE_PATH))
        throw std::runtime_error("Couldnt open music");
}
