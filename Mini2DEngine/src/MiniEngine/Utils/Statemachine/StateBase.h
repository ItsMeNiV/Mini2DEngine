#pragma once
#include "mepch.h"

namespace MiniEngine
{
    class StatefulContext;

    class StateBase
    {
    public:
        StateBase(std::string&& name) : name(name), context(nullptr) {}
        virtual ~StateBase() = default;

        virtual void EntryActions() = 0;
        virtual void ExitActions() = 0;

        std::string& GetName() { return name; }
        StatefulContext* GetContext() { return context; }
        void SetContext(StatefulContext* context)
        {
            this->context = context;
        }

    private:
        std::string name;
        StatefulContext* context;
    };
}