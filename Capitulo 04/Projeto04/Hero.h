#pragma once
#include <SFML/Graphics.hpp>

class Hero
{
public:
	Hero();
	~Hero();
	void init(std::string texture, sf::Vector2f position, float mass);
	void update(float deltaTime);
	void jump(float force);
	sf::Sprite getSprite();
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
	int jumpCount = 0;
	float m_force;
	float m_mass;
	const float m_gravity = 9.8f;
	bool m_grounded;
};