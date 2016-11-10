# Exploring OpenGL 2 and OpenGL ES
For running building UI on WebGL (OpenGL ES) as well as 'embedded' Linux using SDL + OpenGL 2.
OpenGL 3 is a departure from previous versions, including WebGL, so we'll focus on the older GL.

##Setup Instructions
###OSX
* Download SDL development libraries: [https://www.libsdl.org/download-2.0.php#source](https://www.libsdl.org/download-2.0.php#source)
* Copy SDL2.framework to /Library/Frameworks
* The framework may need to be resigned. `cd /Library/Frameworks/SDL2.framework/; codesign -f -s - SDL2;`
* This might also work but is untested: `brew install sdl2`

###Linux
* `apt-get install libsdl2-dev`

##Dev Instrucitons
* Modify app.cpp
* `make`
* `./app`

##Modern
```
git clone https://github.com/nigels-com/glew.git glew
cd glew/auto
make
cd ..
sudo make install
make clean
```
