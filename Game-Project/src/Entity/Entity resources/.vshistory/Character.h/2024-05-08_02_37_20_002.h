#pragma once
#include "Resources/Loader.h"
#include "Resources/InitSprites.h"
#include <vector>

class Characters
{
public:

// 	sf::Sprite GetPlayer() const;
// 	sf::Sprite GetEnemy()const;
// 	sf::Sprite GetFriend()const;
// 	sf::Sprite GetWorld()const;

	void Init();
	void InitPlayer();
	void InitEnemy();
	void InitFriend();
	void InitWorld();
	void InitArrow();

	Characters();
	~Characters();
	
public:

	// Walking Entities
	sf::Texture m_FriendText;
	sf::Texture m_PlayerText;
	sf::Texture m_FoeText;
	sf::Texture m_WorldText;

	sf::Sprite m_Player;
	sf::Sprite m_Friend;
	sf::Sprite m_Foe;
	sf::Sprite m_World;
	sf::Sprite m_Globe;

	// Projectile Types
	sf::Texture m_ArrowText;


	
	//Utilities
	Loader m_Loader;
	InitSprites m_Init;
};
