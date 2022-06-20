#pragma once

// @generated by tools/codegen/gen.py from Operator.h

#include <c10/core/QScheme.h>
#include <tuple>
#include <vector>


// Forward declarations of any types needed in the operator signatures.
// We can't directly include these classes because it will cause circular include dependencies.
// This file is included by TensorBody.h, which defines the Tensor class.
namespace c10 {

template<typename T>
class optional;
template<typename T>
class List;
class Stream;
class Scalar;
struct Storage;
struct TensorOptions;

}

namespace at {

class Tensor;
struct Dimname;
struct Generator;
using TensorList = c10::ArrayRef<Tensor>;
using DimnameList = c10::ArrayRef<Dimname>;
using c10::Stream;
using c10::Storage;
using c10::QScheme;
using c10::Scalar;
using c10::TensorOptions;

namespace _ops {


struct TORCH_API svd_U {
  using schema = ::std::tuple<at::Tensor &,at::Tensor &,at::Tensor &> (const at::Tensor &, bool, bool, at::Tensor &, at::Tensor &, at::Tensor &);
  using ptr_schema = schema*;
  // See Note [static constexpr char* members for windows NVCC]
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(name, "aten::svd")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(overload_name, "U")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(schema_str, "svd.U(Tensor self, bool some=True, bool compute_uv=True, *, Tensor(a!) U, Tensor(b!) S, Tensor(c!) V) -> (Tensor(a!) U, Tensor(b!) S, Tensor(c!) V)")
  static ::std::tuple<at::Tensor &,at::Tensor &,at::Tensor &> call(const at::Tensor & self, bool some, bool compute_uv, at::Tensor & U, at::Tensor & S, at::Tensor & V);
  static ::std::tuple<at::Tensor &,at::Tensor &,at::Tensor &> redispatch(c10::DispatchKeySet dispatchKeySet, const at::Tensor & self, bool some, bool compute_uv, at::Tensor & U, at::Tensor & S, at::Tensor & V);
};

struct TORCH_API svd {
  using schema = ::std::tuple<at::Tensor,at::Tensor,at::Tensor> (const at::Tensor &, bool, bool);
  using ptr_schema = schema*;
  // See Note [static constexpr char* members for windows NVCC]
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(name, "aten::svd")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(overload_name, "")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(schema_str, "svd(Tensor self, bool some=True, bool compute_uv=True) -> (Tensor U, Tensor S, Tensor V)")
  static ::std::tuple<at::Tensor,at::Tensor,at::Tensor> call(const at::Tensor & self, bool some, bool compute_uv);
  static ::std::tuple<at::Tensor,at::Tensor,at::Tensor> redispatch(c10::DispatchKeySet dispatchKeySet, const at::Tensor & self, bool some, bool compute_uv);
};

}} // namespace at::_ops