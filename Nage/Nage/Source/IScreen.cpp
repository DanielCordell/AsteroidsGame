#include "Includes/IScreen.h"
#include "Includes/Engine.h"

IScreen::IScreen(Engine& eng, bool transparant) : isTransparant(transparant), engine(eng), gui(engine.getWindow()) {}
const bool IScreen::IsTransparant() const { return isTransparant; }
