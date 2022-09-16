#include "mepch.h"
#include "MiniEngine/Rendering/RenderCommand.h"

#include "MiniEngine/Core/Core.h"
#include "MiniEngine/Rendering/RenderAPI.h"

namespace MiniEngine
{
    Scope<RenderAPI> RenderCommand::renderAPI = RenderAPI::Create();

}