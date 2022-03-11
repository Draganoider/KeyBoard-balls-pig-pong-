#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "windows.h"
#include <math.h> 
#include <cmath>



int main()
{
   
    const int D = 25;

    


  /*  sf::CircleShape shape1(100.f);
    shape1.setFillColor(sf::Color::Black);*/



    bool p = false;
    int resolutionx = 1000;
    int resolutiony = 1000;
    // create the window
    sf::RenderWindow window(sf::VideoMode(resolutionx, resolutiony), "My window");


    int trueresolutionx = resolutionx - D * 2;
    int trueresolutiony = resolutiony - D * 2;

    sf::CircleShape shape;
    int curentx = 500;
    int curenty = 500;
    int newx = 0;
    int newy = 0;
    int dx = 5;
    int dy = 5;









    shape = sf::CircleShape(D);
    shape.setFillColor(sf::Color(150, 50, 250));

    sf::RectangleShape rectangle1(sf::Vector2f(100.f, 15.f));
    rectangle1.setFillColor(sf::Color(255, 0, 0));

    sf::RectangleShape rectangle2(sf::Vector2f(100.f, 15.f));
    rectangle2.setFillColor(sf::Color(0, 0, 255));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Cyan);



        

       
        if (!p)
        {
            
            
                curentx = 500 - D;
                curenty = 500 - D;

                shape.setPosition(curentx, curenty);
                rectangle1.setPosition(450, 885);
                rectangle2.setPosition(450, 115);
            
            p = true;
        }
        sf::FloatRect boundingBox1 = shape.getGlobalBounds();
        sf::FloatRect boundingBox2 = rectangle1.getGlobalBounds();
        sf::FloatRect boundingBox3 = rectangle2.getGlobalBounds();


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            rectangle1.move(-10, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            rectangle1.move(10, 0);
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            rectangle2.move(-10, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            rectangle2.move(10, 0);
        }





        
        if (boundingBox1.intersects(boundingBox2))
        {
            //dx = -dx;
            dy = -dy;
        }

        if (boundingBox1.intersects(boundingBox3))
        {
            //dx = -dx;
            dy = -dy;
        }

        newx = curentx + dx;
        curentx = newx;
        newy = curenty + dy;
        curenty = newy;
        Sleep(10);


        if (newx >= trueresolutionx)
        {
            dx = -dx;
        }

        if (newy >= trueresolutiony)
        {

        }

        if (newx <= 0)
        {
            dx = -dx;
        }

        if (newy <= 0)
        {

        }

        shape.setPosition(newx, newy);


        window.draw(shape);
        window.draw(rectangle1);
        window.draw(rectangle2);

        
        //shape.move(50.f, 50.f);
        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }

    return 0;
}

