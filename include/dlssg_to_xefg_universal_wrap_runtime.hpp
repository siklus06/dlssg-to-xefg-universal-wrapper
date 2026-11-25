#pragma once
#include <cstdint>

namespace dlssg_to_xefg_universal_wrap {
inline constexpr const char* kModuleName = "dlssg-to-xefg-universal-wrapper";
inline constexpr const char* kBuildSalt = "619329c9dd097830";
struct RuntimeConfig {
    uint32_t target_fps = 144;
    float fov_radius = 65.0f;
    float smooth_factor = 1.45f;
    bool draw_bounds = true;
};
} // namespace dlssg_to_xefg_universal_wrap
