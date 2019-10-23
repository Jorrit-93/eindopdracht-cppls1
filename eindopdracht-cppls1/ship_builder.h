#pragma once
#include "ship_type.h"
#include "i_ship.h"
#include "array.h"
#include "ship_trait.h"
#include "ship_struct.h"

class ShipBuilder {
private:
	ShipType type_def = ShipType::Pinnace;
	int price_def = 1;
	int cargo_space_def = 1;
	int cannon_amount_def = 1;
	int hp_def = 1;
	Array<ShipTrait>* attributes_def = new Array<ShipTrait>(0);

	List<ShipStruct*>* ship_structs;
	
public:
	ShipBuilder();
	~ShipBuilder();

	IShip* createShip(ShipType type);

private:
	ShipBuilder& setType(ShipType type);
	ShipBuilder& setPrice(int price);
	ShipBuilder& setCargoSpace(int cargo_space);
	ShipBuilder& setCannonAmount(int cannon_amount);
	ShipBuilder& setHP(int hp);
	ShipBuilder& setAttributes(Array<ShipTrait>* attributes);

	IShip* build() const;
};
