#include "mepch.h"
#include "RenderCommand.h"
#include "../Core/Core.h"
#include "RenderAPI.h"

namespace MiniEngine
{
    Scope<RenderAPI> RenderCommand::renderAPI = RenderAPI::Create();

}