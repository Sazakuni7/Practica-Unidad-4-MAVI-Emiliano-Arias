#include "utils.h"

class Enemy {
public:
    Sprite sprite;
    bool enemigoActivo;

    Enemy(Texture& texturaEnemy) {
        sprite.setTexture(texturaEnemy);
        sprite.setScale(0.1, 0.1);
        enemigoActivo = true;
        posicionAleatoria();
    }

    void posicionAleatoria() {
        int x = rand() % (800 - static_cast<int>(sprite.getGlobalBounds().width));
        int y = rand() % (600 - static_cast<int>(sprite.getGlobalBounds().height));
        sprite.setPosition(x, y);
    }

    bool esClickeado(Vector2f mousePos) {
        return enemigoActivo && sprite.getGlobalBounds().contains(mousePos);
    }
};

