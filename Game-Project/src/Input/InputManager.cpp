#include "Input/InputManager.h"

void InputManager::Clear()
{
	clear.ClearByte();
}
void InputManager::Update()
{
	lastFrameKeys.SetMask(thisFrameKeys);

	thisFrameKeys.SetBit((int)Key::Left,
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) ||
		(sf::Keyboard::isKeyPressed(sf::Keyboard::A)));
	
	thisFrameKeys.SetBit((int)Key::Right,
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) ||
		(sf::Keyboard::isKeyPressed(sf::Keyboard::D)));

	thisFrameKeys.SetBit((int)Key::Up,
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) ||
		(sf::Keyboard::isKeyPressed(sf::Keyboard::W)));

	thisFrameKeys.SetBit((int)Key::Down,
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) ||
		(sf::Keyboard::isKeyPressed(sf::Keyboard::S)));
			
	thisFrameKeys.SetBit((int)Key::E,
		(sf::Keyboard::isKeyPressed(sf::Keyboard::E)));

	thisFrameKeys.SetBit((int)Key::Click,
		(sf::Mouse::isButtonPressed(sf::Mouse::Left)));
}

// Return true if key is pressed - A key:  1 << Position A.
bool InputManager::IsKeyPressed(Key keycode)
{
	return thisFrameKeys.GetBit((int)keycode);
}
bool InputManager::IsKeyDown(Key keycode)
{
	bool lastFrame = lastFrameKeys.GetBit((int)keycode);
	bool thisFrame = thisFrameKeys.GetBit((int)keycode);
	return thisFrame && !lastFrame;
}
bool InputManager::IsKeyUp(Key keycode)
{
	bool lastFrame = lastFrameKeys.GetBit((int)keycode);
	bool thisFrame = thisFrameKeys.GetBit((int)keycode);
	return !thisFrame && lastFrame;
}








