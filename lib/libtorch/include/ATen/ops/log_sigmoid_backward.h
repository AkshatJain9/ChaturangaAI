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



#include <ATen/ops/log_sigmoid_backward_ops.h>

namespace at {


// aten::log_sigmoid_backward.grad_input(Tensor grad_output, Tensor self, Tensor buffer, *, Tensor(a!) grad_input) -> Tensor(a!)
TORCH_API inline at::Tensor & log_sigmoid_backward_out(at::Tensor & grad_input, const at::Tensor & grad_output, const at::Tensor & self, const at::Tensor & buffer) {
    return at::_ops::log_sigmoid_backward_grad_input::call(grad_output, self, buffer, grad_input);
}

// aten::log_sigmoid_backward.grad_input(Tensor grad_output, Tensor self, Tensor buffer, *, Tensor(a!) grad_input) -> Tensor(a!)
TORCH_API inline at::Tensor & log_sigmoid_backward_outf(const at::Tensor & grad_output, const at::Tensor & self, const at::Tensor & buffer, at::Tensor & grad_input) {
    return at::_ops::log_sigmoid_backward_grad_input::call(grad_output, self, buffer, grad_input);
}

// aten::log_sigmoid_backward(Tensor grad_output, Tensor self, Tensor buffer) -> Tensor
TORCH_API inline at::Tensor log_sigmoid_backward(const at::Tensor & grad_output, const at::Tensor & self, const at::Tensor & buffer) {
    return at::_ops::log_sigmoid_backward::call(grad_output, self, buffer);
}

}
