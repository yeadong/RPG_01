#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include <cocos2d.h>
#include <cocos-ext.h>
#include "ui\CocosGUI.h"

#include "editor-support/cocostudio/CCSGUIReader.h"
#include "cocostudio/CocoStudio.h"


#include "Chapter_3_Scene.h"
#include "../../CommonClass/Util.h"
#include "../PathManager.h"
#include "../SceneManager.h"
#include "../Controller.h"
#include "../Config.h"

#include "MainLogic.h"

USING_NS_CC;
using namespace cocos2d::ui;

#define _USE_PC_

RPG_01_BEGIN


Scene* Chapter_3_Scene::createScene()
{
	auto scene = Scene::create();

	auto layer = Chapter_3_Scene::create();

	scene->addChild(layer);

	return scene;
}
Chapter_3_Scene::Chapter_3_Scene()
{

}

Chapter_3_Scene::~Chapter_3_Scene()
{

}

bool Chapter_3_Scene::init()
{

	if ( !BaseScene::init() )
	{
		return false;
	}

	Game()->GetSceneManager()->SetCurrentScene(this);

	return true;
}


void Chapter_3_Scene::LoadBackground()
{

	/*TMXTiledMap* pMap = TMXTiledMap::create("LFR/other/map/map3.tmx");
	m_pBackgroundLayer->addChild(pMap);*/
	auto pUI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile(Game()->GetConfig()->GetMap3FileName().c_str());
	pUI->setPosition(Point(0, 0));
	m_pBackgroundLayer->addChild(pUI);
}

void Chapter_3_Scene::update(float delta)
{
	Game()->LoopGame(delta);
}
RPG_01_END