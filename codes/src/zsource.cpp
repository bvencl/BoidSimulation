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

    if (DEBUG_IS_ON)
    {
        //     cout << "debug mode is on" << endl;

        //     // Vektorok létrehozása
        //     Vector v1(3.0, 4.0);
        //     Vector v2(1.0, 2.0);

        //     // Alapértelmezett konstruktorral létrehozott vektor
        //     Vector v3;
        //     Vector v4(v1);

        //     // Vektorok kiíratása
        //     std::cout << "Vektor 1: " << v1 << std::endl;
        //     std::cout << "Vektor 2: " << v2 << std::endl;
        //     std::cout << "Vektor 3 (alapértelmezett): " << v3 << std::endl;
        //     std::cout << "Vektor 4 (v1 alapján): " << v4 << std::endl;

        //     // Vektorok összeadása
        //     Vector vSum = v1 + v2;
        //     std::cout << "V1 + V2 = " << vSum << std::endl;

        //     // Vektorok kivonása
        //     Vector vDiff = v1 - v2;
        //     std::cout << "V1 - V2 = " << vDiff << std::endl;

        //     // Vektor negálása
        //     Vector vNeg = -v1;
        //     std::cout << "-V1 = " << vNeg << std::endl;

        //     // Vektor forgatása 90 fokkal (π/2 radián)
        //     Vector vRotated = v1.rotate(M_PI / 2);
        //     std::cout << "V1 forgatva 90 fokkal: " << vRotated << std::endl;

        //     // Skalárral szorzás
        //     Vector vScaled = v2 * 3;
        //     std::cout << "V2 * 3 = " << vScaled << std::endl;

        //     // Vektor hosszának ellenőrzése
        //     std::cout << "V1 hossza: " << v1.getLength() << std::endl;
        //     std::cout << "V2 hossza: " << v2.getLength() << std::endl;

        //     // Vektorok szögének ellenőrzése
        //     double angle = v1.angleWith(v2);
        //     std::cout << "V1 és V2 közötti szög (radiánban): " << angle << std::endl;

        //     // Projekció ellenőrzése
        //     Vector vProjection = v1.projectionOnto(v2);
        //     std::cout << "V1 vetülete V2-re: " << vProjection << std::endl;
    }

    Flock flock1(1, 1, 3, 1);
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

    sf::RenderWindow window(sf::VideoMode(width, height), "Boid For The Win");
    // sf::CircleShape boid_1(boid1.getMass());
    // sf::CircleShape boid_2(boid2.getMass());
    // sf::CircleShape boid_3(boid3.getMass());
    // sf::CircleShape boid_4(boid4.getMass());
    // sf::CircleShape boid_5(boid5.getMass());
    // sf::CircleShape boid_6(boid6.getMass());
    // sf::CircleShape boid_7(boid7.getMass());
    // sf::CircleShape boid_8(boid8.getMass());
    // sf::CircleShape boid_9(boid9.getMass());
    // sf::CircleShape boid_10(boid10.getMass());

    // boid_1.setFillColor(sf::Color::Red);
    // boid_2.setFillColor(sf::Color::Blue);
    // boid_3.setFillColor(sf::Color::Green);
    // boid_4.setFillColor(sf::Color::Yellow);
    // boid_5.setFillColor(sf::Color::White);
    // boid_6.setFillColor(sf::Color::Magenta);
    // boid_7.setFillColor(sf::Color::Cyan);
    // boid_8.setFillColor(sf::Color::Red);
    // boid_9.setFillColor(sf::Color::Green);
    // boid_10.setFillColor(sf::Color::White);

    // Inicializáld a grafikus objektumokat
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

        // boid_1.setPosition((sf::Vector2f)(boid1.getPosition()));
        // boid_2.setPosition((sf::Vector2f)(boid2.getPosition()));
        // boid_3.setPosition((sf::Vector2f)(boid3.getPosition()));
        // boid_4.setPosition((sf::Vector2f)(boid4.getPosition()));
        // boid_5.setPosition((sf::Vector2f)(boid5.getPosition()));
        // boid_6.setPosition((sf::Vector2f)(boid6.getPosition()));
        // boid_7.setPosition((sf::Vector2f)(boid7.getPosition()));
        // boid_8.setPosition((sf::Vector2f)(boid8.getPosition()));
        // boid_9.setPosition((sf::Vector2f)(boid9.getPosition()));
        // boid_10.setPosition((sf::Vector2f)(boid10.getPosition()));

        for (size_t j = 0; j < boids.size(); j++)
        {
            boids[j].setPosition((sf::Vector2f)(flock1[j].getPosition()));
            window.draw(boids[j]);
        }

        flock1.moveFlock(dT, mousePosition);
        cout << flock1[0] << endl;

        // window.draw(boid_1);
        // window.draw(boid_2);
        // window.draw(boid_3);
        // window.draw(boid_4);
        // window.draw(boid_5);
        // window.draw(boid_6);
        // window.draw(boid_7);
        // window.draw(boid_8);
        // window.draw(boid_9);
        // window.draw(boid_10);

        window.display();

        i++;
    }

    return 0;
}