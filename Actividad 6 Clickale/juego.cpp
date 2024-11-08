#include "juego.h"
#include "utils.h"

Juego::Juego() : window(VideoMode(1024, 768), "Actividad 6 - Clickale"), crosshair(texturaMira), enemigosDerrotados(0) {
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);//Ocultar cursor del mouse
    srand(static_cast<unsigned int>(time(nullptr)));//nullptr se usa para que time() no guarde el tiempo en una variable, sino que lo devuelva. Luego static_cast para convertir
    //a entero sin signo asi se pueda usar como semilla para randomizar en la próxima ejecución.
    texturaEnemy.loadFromFile("et.png");
    texturaMira.loadFromFile("crosshair.png");
    for (int i = 0; i < 5; i++) {
        enemies.emplace_back(texturaEnemy);//emplace_back para crear el nuevo elemento del vector al final de la lista, sin necesidad de hacer una copia como hacemos con push_back
    }
    crosshair = Crosshair(texturaMira);
}

//Método principal para correr el juego
void Juego::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}
//Procesar eventos, en este caso, los eventos de cierre de ventana o de click izquierdo
void Juego::processEvents() {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed)
            window.close();
        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
            disparo(mousePos);
        }
    }
}

void Juego::update() {
    if (enemigosDerrotados >= 5) {
        std::cout << "Todos los enemigos derrotados. Sos buenisimo!" << std::endl;
        window.close();
    }
    //Actualizar la posición de la mira
    Vector2i pixelPos = Mouse::getPosition(window);
    Vector2f worldPos = window.mapPixelToCoords(pixelPos);
    crosshair.updatePosition(worldPos);
}

void Juego::render() {
    window.clear(Color::Black);
    for (const auto& enemy : enemies) {
        if (enemy.enemigoActivo) {
            window.draw(enemy.sprite);
        }
    }
    window.draw(crosshair.sprite);
    window.display();
}
//Metodo para desaparecer enemigos clickeando
void Juego::disparo(Vector2f mousePos) {
    for (auto& enemy : enemies) {
        if (enemy.esClickeado(mousePos)) {
            enemy.enemigoActivo = false; //Desactivar al enemigo
            enemigosDerrotados++;
            break; //Salir del bucle si un enemigo es derrotado
        }
    }
}
