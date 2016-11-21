#include <SDL.h>
#include <SDL_opengles2.h>
#include <iostream>

void print_gl_string(GLenum name)
{
  const GLubyte* ret = glGetString(name);
  if (ret == 0)
  {
    std::cerr << "error getting string: " << name << std::endl;
  }
  else
  {
    std::cerr << name << ": " << ret << std::endl;
  }
}

void set_gl_attribute(SDL_GLattr attr, int value)
{
  if (SDL_GL_SetAttribute(attr, value) != 0)
  {
    std::cerr << "SDL_GL_SetAttribute(" << attr << ", " << value << ") failed: " << SDL_GetError() << std::endl;
  }
}

int main()
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    std::cerr << "SDL_Init() failed: " << SDL_GetError() << std::endl;
    exit(EXIT_FAILURE);
  }

  SDL_DisplayMode videomode;
  if (SDL_GetCurrentDisplayMode (0, &videomode) != 0)
  {
    std::cerr << "Error getting current display mode: " << SDL_GetError() << std::endl;
    exit(EXIT_FAILURE);
  }

  std::cout << "Current screen mode: " << videomode.w << "x" << videomode.h << std::endl;

  set_gl_attribute(SDL_GL_RED_SIZE, 5);
  set_gl_attribute(SDL_GL_GREEN_SIZE, 6);
  set_gl_attribute(SDL_GL_BLUE_SIZE, 5);
  //set_gl_attribute(SDL_GL_DEPTH_SIZE, 8);
  set_gl_attribute(SDL_GL_DOUBLEBUFFER, 1);

  set_gl_attribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
  set_gl_attribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
  set_gl_attribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);

  SDL_Window* window = SDL_CreateWindow("Minimal SDL2 Example",
                                        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                        720, 576,
                                        SDL_WINDOW_OPENGL);
  if (!window)
  {
    std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
    exit(EXIT_FAILURE);
  }

  SDL_GLContext gl_context = SDL_GL_CreateContext(window);

  print_gl_string(GL_RENDERER);
  print_gl_string(GL_SHADING_LANGUAGE_VERSION);
  print_gl_string(GL_VERSION);
  print_gl_string(GL_EXTENSIONS);

  glClearColor(1.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  SDL_GL_SwapWindow(window);

  SDL_Delay(5000);

  SDL_GL_DeleteContext(gl_context);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
