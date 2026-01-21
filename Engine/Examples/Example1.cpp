#include "Application.h"
#include "Window.h"

using namespace Amuse::Core;

int main()
{
    Window::Specification windowSpec;
    windowSpec.title    = "Sample Window";
    windowSpec.size     = {1024, 768};
    windowSpec.position = {100, 100};

    Application::Specification appSpec;
    appSpec.name       = "Sample Application";
    appSpec.windowSpec = windowSpec;

    Application app(appSpec);
    return app.Run();
}