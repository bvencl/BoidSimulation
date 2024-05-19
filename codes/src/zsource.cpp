#include "init.h"

using std::cout;
using std::endl;
using std::cerr;

int main(int argc, char *argv[])
{

    int width = 1920;
    int height = 1080;
    if (argc == 3)
    {
        sscanf(argv[1], "%d", &width);
        sscanf(argv[2], "%d", &height);
    }

    Flock flock;
    
    std::vector<sf::CircleShape> boids;
    sf::Clock engineTime;
    sf::Music music;

    initFlock(flock, width, height);
    initGraphics(boids, flock);

    /*Memoriaszivargas a window letrehozasakor*/
    // Amennyiben az sfml és a memtrace egyszerre van benne a programban, úgy a window generálásánál a program leáll!
    sf::RenderWindow window(sf::VideoMode(width, height), "Mars ter");
    try
    {
        initMusic(music);
        music.play();
    }
    catch (std::runtime_error &musicerror)
    {
        cerr << musicerror.what() << endl;
    }

    double dT = 0.0;
    while (window.isOpen())
    {
        dT = engineTime.restart().asSeconds();

        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();
        }
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        window.clear();

        for (size_t j = 0; j < boids.size(); j++)
        {
            boids[j].setPosition((sf::Vector2f)(flock[j].getPosition()));
            window.draw(boids[j]);
        }

        flock.moveFlock(dT, mousePosition);

        cout << flock[5] << endl;

        window.display();
    }

    return 0;
}
