class Crosshair {
public:
    Sprite sprite;

    Crosshair(Texture& texturaMira) {
        sprite.setTexture(texturaMira);
        sprite.setScale(0.2, 0.2);
    }
    void updatePosition(Vector2f mousePos) {
        sprite.setPosition(mousePos.x - sprite.getGlobalBounds().width / 2, mousePos.y - sprite.getGlobalBounds().height / 2);
    }
};