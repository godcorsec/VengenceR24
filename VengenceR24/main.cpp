#include <iostream>
#include "./src/Vengence/Core/vEngine.h"

int main()
{
	VengenceEngine* engine = new VengenceEngine();
	engine->Initialize();

	while (!engine->ShouldClose())
	{
		engine->Render();
		
	}
	return 0;

}