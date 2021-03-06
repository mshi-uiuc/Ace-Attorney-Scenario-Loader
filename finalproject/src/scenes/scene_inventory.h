#pragma once
#include "base.h"
#include "scenemanager.h"
#include "../libs/json.hpp"

using nlohmann::json;

namespace finalproject {

	class Scene_Inventory : public Scene {
		std::vector<InventoryItem> inventory;
		bool can_present = false;

		ofImage bg;
		ofImage item;

		int sel_index = 0;

		const int kRows = 2;
		const int kCols = 4;

		const int kInputX = 113;
		const int kInputY = 125;
		const int kInputWidth = 858;
		const int kInputHeight = 65;

		const int kItemX = 155;
		const int kItemY = 235;
		const int kItemWidth = 161;
		const int kItemHeight = 155;

		const int kItemXPad = 41;
		const int kItemYPad = 40;
		const int kBorderWidth = 4;

		const std::string kNormalBG = "inventory_bg.png";
		const std::string kPresentBG = "inventory_bg_present.png";
		const std::string kSelectRect = "rect.png";

		const int kItemsPerPage = 8;

		bool pressedOK(int key);
		bool pressedCancel(int key);
		bool pressedPresent(int key);

		void drawItems();
		void processScroll(int key);

	public:
		Scene_Inventory(const std::vector<InventoryItem> &i, bool present_ok = false);

		void update();
		void draw();
		void processKey(int key);
	};

} //namespace finalproject