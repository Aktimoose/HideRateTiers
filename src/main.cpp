#include <Geode/Geode.hpp>
#include <Geode/modify/GJDifficultySprite.hpp>

using namespace geode::prelude;

namespace {

    GJFeatureState getTierOverride() {
        auto tier = Mod::get()->getSettingValue<std::string>("tier-override");

        if (tier == "Featured") {
            return GJFeatureState::Featured;
        }
        if (tier == "Epic") {
            return GJFeatureState::Epic;
        }
        if (tier == "Legendary") {
            return GJFeatureState::Legendary;
        }
        if (tier == "Mythic") {
            return GJFeatureState::Mythic;
        }

        return GJFeatureState::None;
    }
}

struct TierOverride : Modify<TierOverride, GJDifficultySprite> {
    void updateFeatureState(GJFeatureState state) {
        GJDifficultySprite::updateFeatureState(getTierOverride());
    }
};