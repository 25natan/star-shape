# StarShape implementation in sfml
A star shape implementation in sfml, inheriting from sf::Shape object
and implementing the `getPointCount` and `getPoint`.
This class allows to create object representing a star shape with n points
and lines connecting every 2 points with k distance

A nice example of it:
```cpp
#include <SFML/Graphics.hpp>
#include "StarShape.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    sf::StarShape star(200, 30, 2);
    star.setFillColor(sf::Color::Cyan);
    star.setOrigin({200, 200});
    star.setPosition({200, 200});
    sf::Clock clock;
    float deltaTimeMs = 100;
    float rotationAngle = 90 / M_PI;
    u_short connectDistance = 14;
    u_short connectDistanceDiff;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(star);
        window.display();

        if(clock.getElapsedTime().asMilliseconds() > deltaTimeMs){
            if(connectDistance == 14)
                connectDistanceDiff = -1;
            else if(connectDistance == 2)
                connectDistanceDiff = 1;
            connectDistance += connectDistanceDiff;
            star.rotate(rotationAngle);
            star.setConnectDistance(connectDistance);
            clock.restart();
        }
    }
    return 0;
}
```

In the above example a star with fixed radius is created, then being rotated.
While rotating it, its 2 points connection distance is being change from smaller to greater.
This will look something like that:

![star-animation](https://github.com/25natan/star-shape/assets/73939462/5dc51205-f492-4964-85be-c73ef2f7bcba)




https://fecloud4136369.jfrogdev.org/ui/packages?ref_job_id=31650&ref_section=packages




