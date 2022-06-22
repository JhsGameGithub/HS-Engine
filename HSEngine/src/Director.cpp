#include "../header/Director.h"
#include "../header/Game.h"

Director::Director() :pGame(nullptr)
{

}

void Director::ChangeScene(std::string name)
{
	pGame->ChangeScene(name);
}

void Director::SetGame(Game* game)
{
	pGame = game;
}
