#include "includes.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{

    int width = 1920;
    int height = 1080;

    if (argc == 3)
    {
        sscanf(argv[1], "%d", &width);
        sscanf(argv[2], "%d", &height);
    }

    Flock flock1(1, 1, 1, 1);
    Point p(1260.0, 540.0);
    Point q(1202.7050983124843, 716.335575687742);
    Point r(1052.7050983124843, 825.316954888546);
    Point s(867.2949016875158, 825.3169548885461);
    Point t(867.2949016875157, 254.68304511145396);
    Point u(717.2949016875157, 363.6644243122581);
    Point v(660.0, 540.0);
    Point w(1202.705098312484, 363.664424312258);
    Point x(1052.705098312484, 254.6830451114539);
    Point y(717.2949016875158, 716.335575687742);

    BasicBoid boid1(15, p, Vector::nullVector, Vector::nullVector);
    BasicBoid boid2(10, q, Vector::nullVector, Vector::nullVector);
    BasicBoid boid3(10, r, Vector::nullVector, Vector::nullVector);
    BasicBoid boid4(10, s, Vector::nullVector, Vector::nullVector);
    BasicBoid boid5(10, t, Vector::nullVector, Vector::nullVector);
    BasicBoid boid6(10, u, Vector::nullVector, Vector::nullVector);
    BasicBoid boid7(10, v, Vector::nullVector, Vector::nullVector);
    BasicBoid boid8(10, w, Vector::nullVector, Vector::nullVector);
    BasicBoid boid9(10, x, Vector::nullVector, Vector::nullVector);
    BasicBoid boid10(10, y, Vector::nullVector, Vector::nullVector);

    flock1.insert(&boid1);
    flock1.insert(&boid2);
    flock1.insert(&boid3);
    flock1.insert(&boid4);
    flock1.insert(&boid5);
    flock1.insert(&boid6);
    flock1.insert(&boid7);
    flock1.insert(&boid8);
    flock1.insert(&boid9);
    flock1.insert(&boid10);

    /*ITT VAN A MEMÓRIASZIVÁRGÁS!!!!!---------->>>>*/
    sf::RenderWindow window(sf::VideoMode(width, height), "Boid For The Win");
    std::vector<sf::CircleShape> boids;
    for (int j = 0; j < 10; j++)
    {
        sf::CircleShape shape(10);          // Állítsd be a megfelelő méretet
        shape.setFillColor(sf::Color::Red); // Vagy bármilyen szín
        boids.push_back(shape);
    }

    size_t i = 0;
    sf::Clock COCK;
    double dT = 0.0;
    while (window.isOpen())
    {
        dT = COCK.restart().asSeconds();

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
            boids[j].setPosition((sf::Vector2f)(flock1[j].getPosition()));
            window.draw(boids[j]);
        }

        flock1.moveFlock(dT, mousePosition);
        cout << flock1[0] << endl;

        window.display();

        i++;
    }

    flock1.remove(&boid1);
    flock1.remove(&boid2);
    flock1.remove(&boid3);
    flock1.remove(&boid4);
    flock1.remove(&boid5);
    flock1.remove(&boid6);
    flock1.remove(&boid7);
    flock1.remove(&boid8);
    flock1.remove(&boid9);
    flock1.remove(&boid10);

    return 0;
}