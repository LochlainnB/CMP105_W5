#include "Zombie.h"

Zombie::Zombie(Input* input) {
	walkSpriteSheet.loadFromFile("gfx/animZombie.png");
	for (int i = 0; i < 8; i++) {
		walkAnimation.addFrame(sf::IntRect(i * 55, 0, 55, 108));
	}
	walkAnimation.setFrameSpeed(0.1);
	walkAnimation.setLooping(true);
	walkAnimation.setPlaying(false);
	setTexture(&walkSpriteSheet);
	curAnimation = &walkAnimation;
	curAnimation->reset();
	setTextureRect(curAnimation->getCurrentFrame());

	setSize(sf::Vector2f(55, 108));
	setInput(input);
}

Zombie::~Zombie() {

}

void Zombie::update(float dt) {
	setPosition(getPosition() + getVelocity() * dt);

	curAnimation->animate(dt);
	setTextureRect(curAnimation->getCurrentFrame());
}

void Zombie::handleInput(float dt) {
	setVelocity(0, 0);
	curAnimation->setPlaying(false);

	if (input->isKeyDown(0)) {
		setVelocity(-100, getVelocity().y);
		curAnimation->setFlipped(true);
		curAnimation->setPlaying(true);
	}
	else if (input->isKeyDown(3)) {
		setVelocity(100, getVelocity().x);
		curAnimation->setFlipped(false);
		curAnimation->setPlaying(true);
	}
}