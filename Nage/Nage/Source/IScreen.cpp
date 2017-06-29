#include "Includes/IScreen.h"
#include "Includes/Engine.h"

IScreen::IScreen(Engine& eng, bool transparant) : isTransparant(transparant), engine(eng), gui(std::make_unique<tgui::Gui>(eng.GetWindow())) {}
const bool IScreen::IsTransparant() const { return isTransparant; }
