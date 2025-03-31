#include <Geode/Geode.hpp>
#include <random>
using namespace geode::prelude;

#include <Geode/modify/CCMenuItemSpriteExtra.hpp>


class $modify(CCMenuItemSpriteExtra) {
	void selected() {
		CCMenuItemSpriteExtra::selected();
		float randomRot = rand() % 360;
		float currRot = this->getRotation();
		if (Mod::get()->getSettingValue<bool>("supermode")){
			this->runAction(cocos2d::CCEaseInOut::create(cocos2d::CCRotateTo::create(Mod::get()->getSettingValue<double>("time"),randomRot + (360 * Mod::get()->getSettingValue<int64_t>("supermode-speed"))),2.0f));
		}else {this->runAction(cocos2d::CCEaseInOut::create(cocos2d::CCRotateTo::create(Mod::get()->getSettingValue<double>("time"),randomRot),2.0f));
		};
		
	};
};