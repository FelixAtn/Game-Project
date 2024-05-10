#include "Player.h"

Player::Player(Window& window, InputManager& m_Input) : m_Input(m_Input), m_Window(window), m_DeltaTime(m_DeltaTime), Character(&m_Player)
{
	Init();
	sf::Vector2f pos = Character::GetPlayerPostition();
	std::cout << pos.x;
}
Player::~Player()
{

}

void Player::Init()
{
	isInit = true;
	if (isInit)
	{
		m_Loader.Load(m_PlayerText, "mobss.png");
		m_Player.setTexture(m_PlayerText);
		m_Player.setPosition(600, 200);
		m_Player.setTextureRect(sf::IntRect(0, 0, 80, 80));
		m_Player.setScale(1, 1);
	}
}

void Player::Update(float deltaTime)
{
	m_DeltaTime = deltaTime;
	Input();
	ValidateMove();
}

void Player::Draw(Window& window)
{
	Character::Draw(window);
}

void Player::Input()
{
	m_Move.x = 0.f;
	m_Move.y = 0.f;
	// Control Player X / Y axis 
	m_WalkSpeed = 500;
	if (m_Input.IsKeyPressed(Key::Right))
	{
		m_Move.x = +m_WalkSpeed;
	}
	else if (m_Input.IsKeyPressed(Key::Left))
	{
		m_Move.x = -m_WalkSpeed;
	}
	if (m_Input.IsKeyPressed(Key::Down))
	{
		m_Move.y = +m_WalkSpeed;
	}
	else if (m_Input.IsKeyPressed(Key::Up))
	{
		m_Move.y = -m_WalkSpeed;
	}

	m_Move *= m_DeltaTime;
	sf::Vector2f m_NewPosition = m_CurrentPosition + sf::Vector2f(m_Move);
	m_Player.setPosition(m_NewPosition);

	//ValidateMove();
//	m_Input.Clear();
}

void Player::ValidateMove()
{

/*
	// Collision
	if (!m_Check.IsColliding(m_Play, m_Friend) &&
		(!m_Check.IsColliding(m_Player, m_Foe) &&
			(!m_Check.IsColliding(m_Player, m_Foe))))
	{
		m_Player.setPosition(m_NewPosition);
	}
	else
	{
		m_Player.setPosition(m_NewPosition - m_Move);
	}
	*/
}


