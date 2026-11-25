#include "../include/dlssg_to_xefg_universal_wrap_runtime.hpp"
#include <windows.h>
#include <atomic>

namespace dlssg_to_xefg_universal_wrap {
static std::atomic<bool> g_running{true};
void PollHotkeys(bool& menu_open) noexcept {
    if (GetAsyncKeyState(VK_INSERT) & 1) menu_open = !menu_open;
    if (GetAsyncKeyState(VK_END) & 1) g_running.store(false, std::memory_order_relaxed);
}
} // namespace dlssg_to_xefg_universal_wrap

int main() {
    bool menu_open = true;
    while (dlssg_to_xefg_universal_wrap::g_running.load(std::memory_order_relaxed)) {
        dlssg_to_xefg_universal_wrap::PollHotkeys(menu_open);
        Sleep(6);
    }
    return 0;
}
