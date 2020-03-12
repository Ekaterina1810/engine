#include <SFML/Graphics.hpp>
#include "DataStorage.h"
#include "GraphicsManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Some game");
    DataStorage data_storage;
    GraphicsManager graphics_manager;

    GameObject player;
    player.addComponent<Renderer>();
    player.getComponent<Renderer>().loadTexture("image.png");
    player.getComponent<Renderer>().makeSprite();

    data_storage.addObject(player);

    graphics_manager.draw_all(window);
    window.display();

    sf::Event event;
    while (window.isOpen())
	{
        while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				window.close();
			}	   
		}
    }

    return 0;
}