#include "Application.h"
#include "Window.h"

#include "Math/Vector2D.h"

using namespace Amuse::App;
using namespace Amuse::Core;

int main()
{
    // 원래는 메타 데이터를 런타임에 주입시키는 게 아님.
	// 이건 메타 데이터 테스트를 위한 임시 코드임.
    Application::MetaData metaData;
    metaData.productName = "Sample Application";
    metaData.companyName = "Sample Company";
    metaData.version     = "1.0.0";
    metaData.identifier  = "com.samplecompany.sampleapplication";

    Application::Specification specification;
    specification.presentaion = Math::Vector2D<int>(1024, 768);
    specification.resolution  = Math::Vector2D<int>( 800, 600);

    Application app(metaData, specification);
    return app.Run();
}