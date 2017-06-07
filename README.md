# NAGE
NAGE: Not A Good Engine. Written by a first year university student. Hence the title.
NOTE: Not really an engine, more of a framework, but I like the name and who really cares?

Credit: https://github.com/monotron for the logging class foundation (which I had to change a bit, sorry!).
## Current features
  * Resource Handlers for Music/Textures/Sound/Shaders/Fonts
  * Default Texture/Font/Shader handling if any files are missing (music and sound just won't play).
  * DnD-inspired random number generator.
  
## Planned features
  * 2D top-down tile-based perspective.
  * Trivial development for the budding game developer.

### Dependencies
  * SFML 2.4.2 (32-bit) - the project technically links to SFML statically but you can use dynamic if you like (be sure to change the project files to reflect this).
  * A recent version of Visual Studio (currently using VS 2017, but 2015 and earlier should work fine.)

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

