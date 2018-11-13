#include "scenemanager.h"

namespace finalproject {
	SceneManager scenes;

	void SceneManager::add(Scene* scene) {
		add(ScenePtr(scene));
	}

	void SceneManager::add(ScenePtr scene) {
		scene_list.push_back(scene);
	}

	void SceneManager::pop() {
		scene_list.pop_back();
	}

	void SceneManager::update() {
		if (empty()) {
			return;
		}
		// update only the last scene
		scene_list.back()->update();
	}

	void SceneManager::draw() {
		for (int i = 0; i < scene_list.size(); i++)	{
			scene_list[i]->draw();
		}
	}

	void SceneManager::processKey(int key) {
		// send mouse info to the last scene only
		scene_list.back()->processKey(key);
	}

	bool SceneManager::empty() {
		return scene_list.empty();
	}
}