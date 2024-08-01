#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML Works!", sf::Style::Default);
    window.setFramerateLimit(120);

    // Circle
    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color(255, 0, 0, 255));

    // Rectangle
    sf::RectangleShape rect(sf::Vector2f(50.f, 50.f));
    rect.setPosition(sf::Vector2f(200.f, 200.f));
    rect.setFillColor(sf::Color(17, 5, 238, 255));
    rect.setOutlineThickness(10.f);
    rect.setOutlineColor(sf::Color::Cyan);

    // Triangle
    sf::CircleShape triangle;
    triangle.setRadius(70.f);
    triangle.setPointCount(3);
    triangle.setFillColor(sf::Color(0, 255, 0, 255));
    triangle.setPosition(sf::Vector2f(0.f, 300.f));

    // Line
    sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(200.f, 0.f)),
            sf::Vertex(sf::Vector2f(250.f, 333.f)),
        };

    // Convex Shape
    sf::ConvexShape convex;
    // resize it to 5 points
    convex.setPointCount(5);
    // define the points
    convex.setPoint(0, sf::Vector2f(300.f, 300.f));
    convex.setPoint(1, sf::Vector2f(450.f, 310.f));
    convex.setPoint(2, sf::Vector2f(420.f, 390.f));
    convex.setPoint(3, sf::Vector2f(330.f, 400.f));
    convex.setPoint(4, sf::Vector2f(300.f, 350.f));

    convex.setFillColor(sf::Color::Magenta);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // Update

        // Draw
        window.clear();

        // Draw everything
        window.draw(circle);
        window.draw(rect);
        window.draw(triangle);
        window.draw(line, 2, sf::Lines);
        window.draw(convex);

        window.display();
    }

    return 0;
}