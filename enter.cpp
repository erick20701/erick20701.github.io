#include <SFML/Graphics.hpp>

#include "enter.h"

using namespace sf;
wds::wds(){};
void wds::crwindow(){
   RenderWindow ap(VideoMode(600, 600), "Boommo!");
	Texture enter;
	enter.loadFromFile("images/12.png");
	Sprite spB;
	spB.setTexture(enter);
	spB.setPosition(0, 0);
	while (ap.isOpen()){
   		Event event;
    	
        while (ap.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                ap.close();
            if (event.type == Event::MouseButtonPressed) 
				ap.close();
        }
		ap.clear();
		ap.draw(spB);
		ap.display();
	}
};
