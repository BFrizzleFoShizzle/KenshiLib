#pragma once

#include <ogre/OgreQuaternion.h>

class Item;
class GameWorld;
class GlobalConstants;
class InputHandler;
class OptionsHolder;
class GameData;
class GameDataContainer;
class ForgottenGUI;

// TODO
namespace FoliageSystem
{
	class EntData;
}

void  showErrorMessage();// RVA = 0x5CC110
float modMedicalSkill(float skill, Item* equipment, float frameTIME);// RVA = 0x4FC9E0
void getFoliageRotation(FoliageSystem::EntData* data, float x, float z, Ogre::Quaternion& rotation);// RVA = 0x6CB8A0
GameData* getBuildingCollection(GameDataContainer& c);// RVA = 0x385380
void increaseStat(float& stat, float amount, float UPPER_LIMIT);// RVA = 0x8C4640

__declspec(dllimport) GameWorld* ou;
__declspec(dllimport) GlobalConstants* con;
__declspec(dllimport) InputHandler* key;
__declspec(dllimport) OptionsHolder* options;
__declspec(dllimport) ForgottenGUI* gui;