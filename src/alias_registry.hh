#ifndef alias_registry_hh_INCLUDED
#define alias_registry_hh_INCLUDED

#include "safe_ptr.hh"
#include "string.hh"

#include <unordered_map>

namespace Kakoune
{

class AliasRegistry : public SafeCountable
{
public:
    AliasRegistry(AliasRegistry& parent) : m_parent(&parent) {}
    void add_alias(String alias, String command);
    void remove_alias(const String& alias);
    StringView operator[](const String& name) const;

    std::vector<StringView> aliases_for(StringView command) const;

private:
    friend class Scope;
    AliasRegistry() {}

    safe_ptr<AliasRegistry> m_parent;
    std::unordered_map<String, String> m_aliases;
};

}

#endif // alias_registry_hh_INCLUDED
