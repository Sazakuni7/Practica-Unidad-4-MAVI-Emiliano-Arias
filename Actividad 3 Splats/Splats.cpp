#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
int main() {
    RenderWindow window(VideoMode(800, 600), "Actividad 3 - Splats");
    Texture redTexture, blueTexture;
    redTexture.loadFromFile("assets/rcircle.png");
    blueTexture.loadFromFile("assets/rcircleb.png");
    //Vector para almacenar los sprites
    std::vector<Sprite> sprites;
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed) {
                Sprite sprite;
                sprite.setScale(0.3, 0.3);
                sprite.setPosition(event.mouseButton.x, event.mouseButton.y);
                sprite.setOrigin(128 / 2.0f, 128 / 2.0f); //Para que se genere el sprite centrado en la posicion del cursor al clickear
                if (event.mouseButton.button == Mouse::Left) {
                    sprite.setTexture(redTexture);
                    sprites.push_back(sprite); //el metodo push_back guarda en la lista dinamica "sprites" cada sprite generado por click, para que puedan ser dibujados
                                               //en cada iteración del bucle y no se borren los anteriores
                }
                else if (event.mouseButton.button == Mouse::Right) {
                    sprite.setTexture(blueTexture);
                    sprites.push_back(sprite);
                }
            }
        }
        for (const auto& sprite : sprites) {
            window.draw(sprite);
        }
        window.display();
    }
    return 0;
}
