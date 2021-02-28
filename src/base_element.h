#pragma once

#include "visitors/visitor.h"

class BaseElement {
public:
    virtual void accept(Visitor* visitor) = 0;
    virtual ~BaseElement() = default;
};