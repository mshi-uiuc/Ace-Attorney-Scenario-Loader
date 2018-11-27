#include "scene_story.h"

namespace finalproject {
	void Scene_Story::loadResources() {
		font.load(constants::kFontFile, constants::kFontSize);
	}

	Scene_Story::Scene_Story(const json &story_file) {
		file = story_file;
		for (auto& item : file["inventory"]) {
			inventory.push_back(InventoryItem(item["name"], item["desc"]));
		}

		//loadResources();
	}


	void Scene_Story::update() {
		const auto &line = file["story"].at(current_index);
		if (line.find("bg") != line.end()) {
			bg.load(line["bg"].get<std::string>());
		}
	}

	void Scene_Story::draw() {
		bg.draw(0, 0);

	}

	void Scene_Story::processKey(int key) {
		if (current_index < file["story"].size() - 2) {
			current_index++;
		}
	}

}
