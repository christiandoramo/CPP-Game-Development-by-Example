#include "Enemy.h";

Enemy::Enemy() {};
Enemy::~Enemy() {};

void Enemy::init(std::string texture, sf::Vector2f position, float _speed) {
	m_speed = _speed;
	m_position = position;
	m_texture.loadFromFile(texture.c_str());
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	sf::Vector2f origin = sf::Vector2f(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
	m_sprite.setOrigin(origin);
}
void Enemy::update(float deltaTime) {
	m_sprite.move(m_speed * deltaTime, 0);
}
sf::Sprite Enemy::getSprite() {
	return m_sprite;
}
