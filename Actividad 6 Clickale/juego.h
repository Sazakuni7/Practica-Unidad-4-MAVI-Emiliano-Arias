#ifndef JUEGO_H
#define JUEGO_H

#include "Enemy.h"
#include "Crosshair.h"
#include "utils.h"

class Juego {
public:
    Juego();
    void run();
private:
    sf::RenderWindow window;
    std::vector<Enemy> enemies;
    Texture texturaEnemy, texturaMira;
    Crosshair crosshair;
    int enemigosDerrotados;

    void processEvents();
    void update();
    void render();
    void disparo(sf::Vector2f mousePos);
};
#endif // JUEGO_H
