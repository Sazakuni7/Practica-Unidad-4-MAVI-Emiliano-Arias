#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
Texture texture;
Sprite sprite;
int main() {
	sf::RenderWindow App(sf::VideoMode(800, 600, 32),
		"Actividad 1 - Crosshair");
	texture.loadFromFile("assets/crosshair.png");
	sprite.setTexture(texture);
	sf::Vector2u windowSize = App.getSize();
	sf::Vector2u textureSize = texture.getSize();
	float posX = (windowSize.x - textureSize.x) / 2.0f;
	float posY = (windowSize.y - textureSize.y) / 2.0f;
	sprite.setPosition(posX, posY);

	while (App.isOpen())
	{
		App.clear();
		App.draw(sprite);
		App.display();
	}
	return 0;
}
