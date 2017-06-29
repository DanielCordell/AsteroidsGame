#include "IScreen.h"
#include "Player.h"

class ScreenGame : public IScreen {
private:
	Player player;
public:
	ScreenGame(Engine& eng);
	//Setup and Destroy
	void Init() override;
	void Cleanup() override;

	//Main Functions
	void HandleEvents() override;
	void Update() override;
	void Draw() override;
};
