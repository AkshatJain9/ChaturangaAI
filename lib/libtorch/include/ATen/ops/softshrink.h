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



#include <ATen/ops/softshrink_ops.h>

namespace at {


// aten::softshrink.out(Tensor self, Scalar lambd=0.5, *, Tensor(a!) out) -> Tensor(a!)
TORCH_API inline at::Tensor & softshrink_out(at::Tensor & out, const at::Tensor & self, const at::Scalar & lambd=0.5) {
    return at::_ops::softshrink_out::call(self, lambd, out);
}

// aten::softshrink.out(Tensor self, Scalar lambd=0.5, *, Tensor(a!) out) -> Tensor(a!)
TORCH_API inline at::Tensor & softshrink_outf(const at::Tensor & self, const at::Scalar & lambd, at::Tensor & out) {
    return at::_ops::softshrink_out::call(self, lambd, out);
}

// aten::softshrink(Tensor self, Scalar lambd=0.5) -> Tensor
TORCH_API inline at::Tensor softshrink(const at::Tensor & self, const at::Scalar & lambd=0.5) {
    return at::_ops::softshrink::call(self, lambd);
}

}
