#ifndef Database_H_
#define Database_H_
#include "MasterHeader.h"
#include "CPEOPLE.h"
#include "CCAR.h"
#include "CTRUCK.h"
#include "CBIRD.h"
#include "CDINOSAUR.h"

#define SAVE_PATH "./save.dat"


class Database final
{
	Database() = delete;
	~Database() = delete;

	void static loadVehicles(std::ifstream & saveFile, int objCount, std::vector<CVEHICLE*> & vehicleList);
	void static loadAnimals(std::ifstream & saveFile, int objCount, std::vector<CANIMAL*> & animalList);
	void static loadStatuses(std::ifstream & saveFile, std::array<bool, 4> & trafficLightStatus,
		std::array<bool, 4> & reverseLaneStatus, int & gameSpeed);
public:
	void static saveGame(std::vector<CVEHICLE*> & vehicleList, std::vector<CANIMAL*> & animalList,
		CPEOPLE& player, std::array<bool, 4> trafficLightStatus, std::array<bool, 4> reverseLaneStatus, int & gameSpeed);
	void static loadGame(std::vector<CVEHICLE*> & vehicleList, std::vector<CANIMAL*> & animalList,
		CPEOPLE& player, std::array<bool, 4> & trafficLightStatus, std::array<bool, 4> & reverseLaneStatus, int & gameSpeed);
};

#endif Database_H_



 