#pragma once
#include "Framework/Animation.h"
#include "Framework/GameObject.h"

class Zombie : public GameObject {
public:
	Zombie(Input* input);
	~Zombie();

	void update(float dt);
	void handleInput(float dt) override;

protected:
	sf::Texture walkSpriteSheet;
	Animation walkAnimation;
	Animation* curAnimation;
};