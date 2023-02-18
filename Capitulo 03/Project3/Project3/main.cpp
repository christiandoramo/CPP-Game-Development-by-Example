#include <SFML/Graphics.hpp> // replace quotes with less than and greater than symbols

//	Bandeira do Brasil
//#########################################################################################
//sf::RectangleShape rect(sf::Vector2f(600.0f, 400.0f));
//rect.setFillColor(sf::Color::Green);
//rect.setPosition(viewSize.x / 2, viewSize.y / 2);
//rect.setOrigin(sf::Vector2f(rect.getSize().x / 2, rect.getSize().y / 2));
//sf::CircleShape circle(100);
//circle.setFillColor(sf::Color::Blue);
//circle.setPosition(viewSize.x / 2, viewSize.y / 2);
//circle.setOrigin(sf::Vector2f(circle.getRadius(),
//	circle.getRadius()));
//sf::ConvexShape losang;
//losang.setPointCount(4);
//losang.setPoint(0, sf::Vector2f(-250, 0));
//losang.setPoint(1, sf::Vector2f(0, -150));
//losang.setPoint(2, sf::Vector2f(250, 0));
//losang.setPoint(3, sf::Vector2f(0, 150));
//losang.setFillColor(sf::Color(255, 255, 0, 255));
//losang.setPosition(viewSize.x / 2, viewSize.y / 2);
//#########################################################################################

// Montando a janela
sf::Vector2f viewSize(1366, 768); //tamanho do meu sprite de fundo
sf::VideoMode videoMode(viewSize.x, viewSize.y);
sf::RenderWindow window(videoMode, "Janela usando SFML", sf::Style::Default);

sf::Texture skyTexture;
sf::Sprite skySprite;
sf::Texture bgTexture;
sf::Sprite bgSprite;
sf::Texture heroTexture;
sf::Sprite heroSprite;
sf::Vector2f playerPosition;
bool playerMoving = false;

void update(float deltaTime) {
	if (playerMoving) {
		heroSprite.move(50.0f * deltaTime, 0);
	}
}

void updateInput() {
	sf::Event event;
	sf::Keyboard::Key esc = sf::Keyboard::Escape;
	sf::Event::EventType closeX = sf::Event::Closed;
	sf::Keyboard::Key right = sf::Keyboard::Right;
	sf::Event::EventType Pressionada = sf::Event::KeyPressed;
	sf::Event::EventType Despressionada = sf::Event::KeyReleased;
	while (window.pollEvent(event)) {
		if (event.key.code == esc || event.type == closeX) {
			window.close();
		}
		if (event.key.code == right && event.type == Pressionada) {
			playerMoving = true;
		}
		if (event.key.code == right && event.type == Despressionada) {
			playerMoving = false;
		}
	}
}

void draw() {
	window.draw(skySprite);
	window.draw(bgSprite);
	window.draw(heroSprite);
}

void init() {
	//Carrega a textura de sky.png em skyTexture
	skyTexture.loadFromFile("Assets/graphics/sky.png");
	//seta e anexa a textura ao sprite
	skySprite.setTexture(skyTexture);

	bgTexture.loadFromFile("Assets/graphics/bg.png");
	bgSprite.setTexture(bgTexture);
	heroTexture.loadFromFile("Assets/graphics/hero.png");
	heroSprite.setTexture(heroTexture);
	heroSprite.setPosition(sf::Vector2f(viewSize.x / 2, viewSize.y / 2));
	// origem/ pivot do sprite é o centro da propria textura
	heroSprite.setOrigin(heroTexture.getSize().x / 2, heroTexture.getSize().y / 2);

}

int main()
{
	sf::Clock clock; // relogio do sistema a ser usado para ajusta o movimento em 
	//relação ao tempo e não a velocidade de passagem de frames do PC
	init();
	while (window.isOpen()) {
		updateInput();
		sf::Time deltaTime = clock.restart(); // retorna o tempo passado desde o ultimo start do clock
		update(deltaTime.asSeconds()); // passa o tempo medio gasto para correr 60 frames durante esse tempo
		//  nessa máquina no tempo que foi passado
		window.clear(sf::Color::Black);
		// Render Game Objects
		//window.draw(rect);
		//window.draw(losang);
		//window.draw(circle);
		draw();
		window.display();
	}
	return 0;
}