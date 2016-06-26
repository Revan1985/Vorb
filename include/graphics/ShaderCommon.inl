//
// ShaderCommon.inl
// Vorb Engine
//
// Created by Benjamin Arnold on 25 Jun 2016
// Copyright 2014 Regrowth Studios
// All Rights Reserved
//

/*! \file ShaderCommon.inl
* @brief Common shader code to be reused.
*
*
*/

#pragma once

#ifndef Vorb_ShaderCommon_inl__
//! @cond DOXY_SHOW_HEADER_GUARDS
#define Vorb_ShaderCommon_inl__
//! @endcond

#ifndef VORB_USING_PCH
#include "types.h"
#endif // !VORB_USING_PCH

namespace vorb {
namespace graphics {
namespace shadercommon {

    /// For just passing UV through the vertex shader
    const cString PASSTHROUGH_VERT_SRC = R"(
// Input
in vec2 vPosition; // Position in screen space

// Output
out vec2 fUV;

void main() {
  fUV = (vPosition + 1.0) / 2.0;
  gl_Position =  vec4(vPosition, 0, 1);
})";

}
}
}
namespace vg = vorb::graphics;

#endif // !Vorb_ShaderCommon_inl__
