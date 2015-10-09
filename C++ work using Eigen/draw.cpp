#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1440, 738), "Map");
    //sf::CircleShape shape(1000, 700,5);
	
    sf::Image background;
    if (!background.loadFromFile("first.jpg"))
    	return -1;
    sf::Image image;
    image.create(1600, 800, sf::Color::Black);
    image.copy(background, 1430, 720);
    sf::Color color = image.getPixel(100,700);
    color.a = 0;
    image.setPixel(100, 700, color);
   
    if (!image.saveToFile("test.png"))
	return -1;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
       //window.draw(shape);
	//window.draw(image);
        window.display();
    }

    return 0;
}
