#pragma once

#include "../../../isEngine/system/display/GameDisplay.h"
#include "../../objects/tmxExample/TMXLiteExample.h"

class HelloScene : public is::GameDisplay
{
public:
    HelloScene(sf::RenderWindow &window, sf::View &view, sf::RenderTexture &surface, is::GameSystemExtended &gameSysExt):
        GameDisplay(window, view, surface, gameSysExt, sf::Color::Black /* => scene color*/) {}

    void loadResources()
    {
        m_gameSysExt.m_gameLanguage = is::lang::ENGLISH; // set default game language

        // uncomment to change English language in French
        // m_gameSysExt.m_gameLanguage = is::lang::FRANCAIS;

        // load font and texture
        GameDisplay::loadParentResources(); // allows to load system resource (very important never forgot to call him)

        SDMaddSceneObject(std::make_shared<TMXLiteExample>(this));
    }
};
