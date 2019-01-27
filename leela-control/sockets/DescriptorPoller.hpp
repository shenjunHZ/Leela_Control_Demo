//
// Created by junshen on 1/24/19.
//

#pragma once
#include <functional>

namespace types
{
    using FileDescriptor = int;
}
namespace sockets
{
class DescriptorPoller
{
public:
    virtual void registerFileDescriptor(types::FileDescriptor, std::function<void()>) = 0;
    virtual void unregisterFileDescriptor(types::FileDescriptor) = 0;
    virtual ~DescriptorPoller() = default;
};
} // namespace sockets
