#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
Texture texture;
Sprite sprite[4];
bool arrastrando[4] = {false, false, false, false};
Vector2f mouseOffset[4];
int main() {
	texture.loadFromFile("rcircle.png");
	for (int i = 0; i < 4; i++) {
		sprite[i].setTexture(texture);
		sprite[i].setScale(0.4, 0.4);
	}
	sprite[0].setPosition(0, 0);
	sprite[1].setPosition(800 - (sprite[1].getTexture()->getSize().x * sprite[1].getScale().x), 0);
	sprite[2].setPosition(800 - (sprite[2].getTexture()->getSize().x * sprite[2].getScale().x), 600 - (sprite[2].getTexture()->getSize().y * sprite[2].getScale().y));
	sprite[3].setPosition(0, 600 - (sprite[3].getTexture()->getSize().y * sprite[3].getScale().y));
	sf::RenderWindow App(sf::VideoMode(800, 600, 32),
		"Actividad 2 - Drag");
	// Loop principal
    while (App.isOpen()) {
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed) {
                App.close();
            }
            else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                for (int i = 0; i < 4; i++) {
                    FloatRect bounds = sprite[i].getGlobalBounds();
                    Vector2f mousePos = Vector2f(event.mouseButton.x, event.mouseButton.y);
                    if (bounds.contains(mousePos)) {
                        arrastrando[i] = true;
                        mouseOffset[i] = mousePos - sprite[i].getPosition(); //Se almacena la posicion relativa entre el mouse y el sprite*
                    }
                }
            }
            else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
                for (int i = 0; i < 4; i++) {
                    arrastrando[i] = false;
                }
            }
            else if (event.type == Event::MouseMoved) {
                Vector2f mousePos = Vector2f(event.mouseMove.x, event.mouseMove.y);
                for (int i = 0; i < 4; i++) {
                    if (arrastrando[i]) {
                        sprite[i].setPosition(mousePos - mouseOffset[i]); //*Esto es útil para arrastrar el objeto desde donde se clickeó y que no aparezca justo debajo del cursor
                    }
                }
            }
        }
        App.clear();
        for (int i = 0; i < 4; i++) {
            App.draw(sprite[i]);
        }
        App.display();
    }
    return 0;
}