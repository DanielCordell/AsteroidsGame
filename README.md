# NAGE
NAGE: Not A Good Engine. Written by a first year university student. Hence the title.
Credit: @Toby Jones for creating the base for the Logging Class
## Current features
  * Resource Handlers for Music/Textures/Sound/Shaders/Fonts
  * Default Texture/Font/Shader handling if any files are missing (music and sound just won't play).
  * DnD-inspired random number generator.
  
## Planned features
  * 2D top-down tile-based perspective.
  * Trivial development for the budding game developer.

### Dependencies
  * SFML 2.4.2 (32-bit) - make sure you have the static libs.
  * A recent version of Visual Studio (we're using 2017, but 2015 and earlier should work fine)

### Building on Visual Studio
  * Clone the project however you desire (using GitHub for Visual Studio is the easiest way)
  * Open the solution within the NAGE folder.
  * In the project folder (where the `*.vcxproj` files are) copy your SFML distribution so that your file structure looks like this:
  ```
  Nage\
  -- SFML-2.x.x
  ---- lib
  ---- include
  ---- [...]
  -- Nage.vcxproj
  -- [...]
  ```
  * Press F5 and cross your fingers.

