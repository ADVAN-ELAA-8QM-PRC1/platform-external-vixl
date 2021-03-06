// Copyright 2016, VIXL authors
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//   * Neither the name of ARM Limited nor the names of its contributors may be
//     used to endorse or promote products derived from this software without
//     specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef VIXL_MACRO_ASSEMBLER_INTERFACE_H
#define VIXL_MACRO_ASSEMBLER_INTERFACE_H

#include "assembler-base-vixl.h"

namespace vixl {

class MacroAssemblerInterface {
 public:
  virtual internal::AssemblerBase* AsAssemblerBase() = 0;

  virtual ~MacroAssemblerInterface() {}

  virtual bool AllowMacroInstructions() const = 0;
  virtual bool ArePoolsBlocked() const = 0;

 protected:
  virtual void SetAllowMacroInstructions(bool allow) = 0;

  virtual void BlockPools() = 0;
  virtual void ReleasePools() = 0;
  virtual void EnsureEmitPoolsFor(size_t size) = 0;

  // The following scopes need access to the above method in order to implement
  // pool blocking and temporarily disable the macro-assembler.
  friend class ExactAssemblyScope;
  friend class EmissionCheckScope;
};

}  // namespace vixl

#endif  // VIXL_MACRO_ASSEMBLER_INTERFACE_H
