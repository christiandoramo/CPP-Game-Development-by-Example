#include "Hero.h"
Hero::Hero() {}
Hero::~Hero() {}
void Hero::init(std::string texture, sf::Vector2f position, float mass) {
	m_position = position;
	m_mass = mass;
	m_grounded = false;
	m_texture.loadFromFile(texture.c_str());// converte a string para um array de char no formato de C
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
}
void Hero::update(float deltaTime) {
	m_force -= m_mass * m_gravity * deltaTime;
	m_position.y -= m_force * deltaTime;
	m_sprite.setPosition(m_position);
	if (m_position.y >= 768 * 0.75f) {
		m_position.y = 768 * 0.75f;
		m_force = 0;
		m_grounded = true;
		jumpCount = 0;
	}
}
void Hero::jump(float force) {
	if (jumpCount < 2) {
		jumpCount++;
		m_force = force;
		m_grounded = false;
	}
}

sf::Sprite Hero::getSprite() {
	return m_sprite;
}