#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
int main() {
    RenderWindow window(VideoMode(800, 600), "Actividad 5 - Adaptación", Style::Default);
    window.setVerticalSyncEnabled(true);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::Resized) {
                //Obtener el nuevo tamaño al redimensionar
                Vector2u newSize(event.size.width, event.size.height);
                //Setear el tamaño a estos limites si se quiere redimensionar por debajo o encima de los mismos
                if (newSize.x <= 100) newSize.x = 100;
                if (newSize.y <= 100) newSize.y = 100;
                if (newSize.x >= 1000) newSize.x = 1000;
                if (newSize.y >= 1000) newSize.y = 1000;
                window.setSize(newSize);
                std::cout << "Tamanio de ventana ajustado a: " << newSize.x << "x" << newSize.y << std::endl;
            }
        }
        window.clear(Color::White);
        window.display();
    }
    return 0;
}