#include "Application.h"
#include "Window.h"

#include "Math/Vector2D.h"

using namespace Amuse::Core;
using namespace Amuse::Core::Math;

int main()
{
    Application::MetaData metaData;
    metaData.productName = "Sample Application";
	metaData.companyName = "Sample Company";
	metaData.version     = "1.0.0";
	metaData.identifier  = "com.samplecompany.sampleapplication";

    Application::Specification specification;
    specification.presentaion = Vector2D<int>(1024, 768);
    specification.resolution  = Vector2D<int>(800, 600);

    Application app(metaData, specification);
    return app.Run();
}