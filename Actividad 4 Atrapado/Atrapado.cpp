#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
int main() {
    RenderWindow window(VideoMode(800, 600), "Actividad 5 - Atrapado");
    Texture textureCuadrado, textureCirculo;
    textureCuadrado.loadFromFile("cuad_yellow.png");
    textureCirculo.loadFromFile("rcircleg.png");
    Sprite shape;
    shape.setTexture(textureCuadrado);
    shape.setPosition(400, 300);
    shape.setScale(0.2, 0.2);
    float moveSpeed = 0.1f; // Velocidad de movimiento
    bool esCuadrado = true;
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            if (shape.getPosition().x > 0) //Verificar que no salga del borde izquierdo
                shape.move(-moveSpeed, 0); //Agrega valores a la posicion actual, en vez de sobreescribirla como en setPosition
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            if (shape.getPosition().x + shape.getGlobalBounds().width < window.getSize().x)
                shape.move(moveSpeed, 0);
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            if (shape.getPosition().y > 0)
                shape.move(0, -moveSpeed);
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            if (shape.getPosition().y + shape.getGlobalBounds().height < window.getSize().y)
                shape.move(0, moveSpeed);
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            if (esCuadrado) {
                shape.setTexture(textureCirculo);
                shape.setScale(0.8, 0.8);
                esCuadrado = false;
            }
            else {
                shape.setTexture(textureCuadrado);
                shape.setScale(0.2, 0.2);
                esCuadrado = true;
            }
            //Por algun motivo, al cambiar de forma a circulo, el espacio para moverlo se reduce, como si los bounds del sprite chocaran antes con los bounds de la ventana
            //Sin embargo esto no sucede si uso el cuadrado. El sprite del circulo esta reescalado para que coincida con el del cuadrado.
            //Los espacios transparentes del circulo tampoco son mayores a los limites del sprite cuadrado, aún así este error ocurre. Seguiré investigando como solucionarlo
            //De momento cumple con la consigna de no salirse del espacio visible
            Vector2f position = shape.getPosition();
            if (position.x < 0) position.x = 0;
            if (position.y < 0) position.y = 0;
            if (position.x + shape.getGlobalBounds().width > window.getSize().x)
                position.x = window.getSize().x - shape.getGlobalBounds().width;
            if (position.y + shape.getGlobalBounds().height > window.getSize().y)
                position.y = window.getSize().y - shape.getGlobalBounds().height;

            shape.setPosition(position);
        }
        window.clear(Color::Black);     
        window.draw(shape);
        window.display();
    }
    return 0;
}