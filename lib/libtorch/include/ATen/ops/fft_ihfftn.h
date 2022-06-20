#pragma once

// @generated by tools/codegen/gen.py from Function.h

#include <ATen/Context.h>
#include <ATen/DeviceGuard.h>
#include <ATen/TensorUtils.h>
#include <ATen/TracerMode.h>
#include <ATen/core/Generator.h>
#include <ATen/core/Reduction.h>
#include <ATen/core/Tensor.h>
#include <c10/core/Scalar.h>
#include <c10/core/Storage.h>
#include <c10/core/TensorOptions.h>
#include <c10/util/Deprecated.h>
#include <c10/util/Optional.h>



#include <ATen/ops/fft_ihfftn_ops.h>

namespace at {


// aten::fft_ihfftn(Tensor self, int[1]? s=None, int[1]? dim=None, str? norm=None) -> Tensor
TORCH_API inline at::Tensor fft_ihfftn(const at::Tensor & self, c10::optional<at::IntArrayRef> s=c10::nullopt, c10::optional<at::IntArrayRef> dim=c10::nullopt, c10::optional<c10::string_view> norm=c10::nullopt) {
    return at::_ops::fft_ihfftn::call(self, s, dim, norm);
}

// aten::fft_ihfftn.out(Tensor self, int[1]? s=None, int[1]? dim=None, str? norm=None, *, Tensor(a!) out) -> Tensor(a!)
TORCH_API inline const at::Tensor & fft_ihfftn_out(const at::Tensor & out, const at::Tensor & self, c10::optional<at::IntArrayRef> s=c10::nullopt, c10::optional<at::IntArrayRef> dim=c10::nullopt, c10::optional<c10::string_view> norm=c10::nullopt) {
    return at::_ops::fft_ihfftn_out::call(self, s, dim, norm, out);
}

// aten::fft_ihfftn.out(Tensor self, int[1]? s=None, int[1]? dim=None, str? norm=None, *, Tensor(a!) out) -> Tensor(a!)
TORCH_API inline const at::Tensor & fft_ihfftn_outf(const at::Tensor & self, c10::optional<at::IntArrayRef> s, c10::optional<at::IntArrayRef> dim, c10::optional<c10::string_view> norm, const at::Tensor & out) {
    return at::_ops::fft_ihfftn_out::call(self, s, dim, norm, out);
}

}
