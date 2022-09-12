#pragma once
#include "mepch.h"
#include "StateBase.h"

namespace MiniEngine
{
    class StatefulContext
    {
    public:
        StatefulContext() = default;
        virtual ~StatefulContext() = default;

        virtual StateBase* GetState() = 0;
        void SetState(StateBase& state)
        {
            this->state.reset(&state);
        }

        void ChangeState(StateBase* newState)
        {
            std::cout << "Changing state: " << state->GetName() << "->" << newState->GetName() << std::endl;

            state->ExitActions();

            newState->SetContext(*(state->GetContext()));
            state.reset(newState);

            state->EntryActions();
        }

    protected:
        Scope<StateBase> state;
    };
}