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

    Flock flock1;
    Point p(100, height / 8);
    Point p2(width / 1.5, height / 2);

    Vector v1(0.01, 0.0);
    Vector v2(5, 0);
    Vector v3(0, 0);

    BasicBoid boid1(1, p, Vector::nullVector, Vector::nullVector);
    BasicBoid boid2(1, p2, Vector::nullVector, Vector::nullVector);
    flock1.insert(&boid1);
    flock1.insert(&boid2);

    sf::RenderWindow window(sf::VideoMode(width, height), "Boid For The Win");
    sf::CircleShape boid_1(10);
    sf::CircleShape boid_2(10);

    boid_1.setFillColor(sf::Color::Red);
    boid_2.setFillColor(sf::Color::Blue);

    size_t i = 0;

    double omega = M_PI / 100000.0;
    double R = 10000;
    double v = R * omega;
    double a = v * v / R;

    while (window.isOpen())
    {

        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        boid_1.setPosition((sf::Vector2f)(boid1.getPosition()));
        boid_2.setPosition((sf::Vector2f)(boid2.getPosition()));
        window.draw(boid_1);
        window.draw(boid_2);

        window.display();
        flock1.moveFlock();
        cout << flock1[1] << endl;

        boid1.setSpeed(i / 10000.0, cos(i * M_PI / 10000.0)) ;

        // boid2.setSpeed(cos(i * M_PI / 100000.0), sin(i * M_PI / 100000.0));
        // boid1.setSpeed(cos(i * M_PI / 100000.0), sin(i * M_PI / 100000.0));

        i++;
    }

    return 0;
}