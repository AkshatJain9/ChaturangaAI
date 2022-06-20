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



#include <ATen/ops/_det_lu_based_helper_backward_helper_ops.h>

namespace at {


// aten::_det_lu_based_helper_backward_helper(Tensor det_grad, Tensor det, Tensor self, Tensor lu, Tensor pivs) -> Tensor
TORCH_API inline at::Tensor _det_lu_based_helper_backward_helper(const at::Tensor & det_grad, const at::Tensor & det, const at::Tensor & self, const at::Tensor & lu, const at::Tensor & pivs) {
    return at::_ops::_det_lu_based_helper_backward_helper::call(det_grad, det, self, lu, pivs);
}

}
