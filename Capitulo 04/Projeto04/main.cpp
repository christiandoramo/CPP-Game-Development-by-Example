#include <SFML/Graphics.hpp>
#include "Hero.h";
#include "Enemy.h";
#include <vector>
#include "Rocket.h";



sf::Vector2f viewSize(1366, 768);
sf::VideoMode videoMode(viewSize.x, viewSize.y);
sf::RenderWindow window(videoMode, "Janela usando SFML", sf::Style::Default);
//bool playerMoving = false;
std::vector<Rocket*> rockets;
std::vector<Enemy*> enemies;
sf::Texture skyTexture;
sf::Sprite skySprite;
sf::Texture bgTexture;
sf::Sprite bgSprite;
Hero hero;
float prevTime = 0.0f;
float currentTime;

bool checkCollision(sf::Sprite sprite1, sf::Sprite sprite2) {
	sf::FloatRect shape1 = sprite1.getGlobalBounds(); // retorna a area ocupada pela translation, rotation, scale de cada sprite para o retangulo
	sf::FloatRect shape2 = sprite2.getGlobalBounds();
	if (shape1.intersects(shape2)) {
		return true;
	}
	return false;

}

void shoot() {
	Rocket* rocket = new Rocket();
	sf::Vector2f positionHero = hero.getSprite().getPosition();
	rocket->init("C:/Recursos/Assets/graphics/rocket.png", positionHero, 400.0f);
	rockets.push_back(rocket);
}

void spawnEnemy() {
	int randLoc = rand() % 3;
	sf::Vector2f enemyPos;
	float speed = 0;
	if (randLoc == 0) {
		enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.75f);
		speed = -400;
	}
	else if (randLoc == 1) {
		enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.6f);
		speed = -550;
	}
	else if (randLoc == 2) {
		enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.4f);
		speed = -650;
	}
	else {
		printf("Valor de y incorreto");
	}
	Enemy* enemy = new Enemy();
	enemy->init("C:/Recursos/Assets/graphics/enemy.png", enemyPos, speed);
	enemies.push_back(enemy);
};

void update(float deltaTime) {
	//if (playerMoving) {
	//	heroSprite.move(50.0f * deltaTime, 0);
	//}
	hero.update(deltaTime);
	currentTime += deltaTime;
	if (currentTime >= prevTime + 1.125f) {
		spawnEnemy();
		prevTime = currentTime;
	};
	// apagando os inimigos que passam da tela a esquerda
	for (int i = 0; i < enemies.size(); i++) {
		Enemy* enemy = enemies[i];
		enemy->update(deltaTime);
		float enemyX = enemy->getSprite().getPosition().x;
		if (enemyX < 0) {
			enemies.erase(enemies.begin() + i); // eliminando objeto do vetor
			delete(enemy); // eliminando objeto chamando o destrutor
		}
	}
	// apagando os torpedos que passam da tela a direita
	for (int i = 0; i < rockets.size(); i++) {
		Rocket* rocket = rockets[i];
		rocket->update(deltaTime);
		float rocketX = rocket->getSprite().getPosition().x;
		if (rocketX > viewSize.x) {
			rockets.erase(rockets.begin() + i);
			delete(rocket);
		}
	}
	for (int i = 0; i < rockets.size(); i++) {
		for (int j = 0; j < enemies.size(); j++) {
			Rocket* rocket = rockets[i];
			Enemy* enemy = enemies[j];

			if (checkCollision(rocket->getSprite(), enemy->getSprite())) {
				rockets.erase(rockets.begin() + i);
				enemies.erase(enemies.begin() + j);
				delete(rocket);
				delete(enemy);
				printf(" Rocket colidiu com Enemy\n");
			}

		}
	}

}

void updateInput() {
	sf::Event event;
	sf::Keyboard::Key esc = sf::Keyboard::Escape;
	sf::Event::EventType closeX = sf::Event::Closed;
	//sf::Keyboard::Key right = sf::Keyboard::Right;
	//sf::Event::EventType Despressionada = sf::Event::KeyReleased;
	while (window.pollEvent(event)) {
		if (event.key.code == esc || event.type == closeX) {
			window.close();
		}
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				hero.jump(750.0f);
			}
			if (event.key.code == sf::Keyboard::Space) {
				shoot();
			}
		}
		//if (event.key.code == right && event.type == Pressionada) {
		//	playerMoving = true;
		//}
		//if (event.key.code == right && event.type == Despressionada) {
		//	playerMoving = false;
		//}
	}
}

void draw() {
	window.draw(skySprite);
	window.draw(bgSprite);
	window.draw(hero.getSprite());
	for (Enemy* enemy : enemies) {
		window.draw(enemy->getSprite());
	}
	for (Rocket* rocket : rockets) {
		window.draw(rocket->getSprite());
	}
};

void init() {
	skyTexture.loadFromFile("C:/Recursos/Assets/graphics/sky.png");
	skySprite.setTexture(skyTexture);
	bgTexture.loadFromFile("C:/Recursos/Assets/graphics/bg.png");
	bgSprite.setTexture(bgTexture);
	sf::Vector2f playerPosition = sf::Vector2f(viewSize.x * 0.25f, viewSize.y * 0.5f);
	bool playerMoving = false;
	float mass = 200.0f;
	hero.init("C:/Recursos/Assets/graphics/hero.png", playerPosition, mass);
	//heroSprite.setOrigin(heroTexture.getSize().x / 2, heroTexture.getSize().y / 2);

	srand((int)time(0));
}

int main()
{
	sf::Clock clock;
	init();
	while (window.isOpen()) {
		updateInput();
		sf::Time deltaTime = clock.restart();
		//update(deltaTime.asSeconds());
		update(deltaTime.asSeconds());
		window.clear(sf::Color::Black);
		draw();
		window.display();
	}
	return 0;
}