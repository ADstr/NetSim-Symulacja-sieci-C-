#pragma once
#include <set>
#include "types.hpp"

class Package{
public:
    Package();
    Package(ElementID id);
    Package(const Package&) noexcept;
    Package& operator = (const Package&) noexcept;
    ElementID get_id() const;
    ~Package();

    ElementID id;

    static std::set<ElementID> assigned_ids;
    static std::set<ElementID> freed_ids;
};


