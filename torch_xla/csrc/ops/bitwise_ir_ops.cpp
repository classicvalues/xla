#include "torch_xla/csrc/ops/bitwise_ir_ops.h"

#include "torch_xla/csrc/helpers.h"
#include "torch_xla/csrc/lowering_context.h"
#include "torch_xla/csrc/ops/infer_output_shape.h"
#include "torch_xla/csrc/ops/ops.h"

namespace torch_xla {

torch::lazy::Value BitwiseAnd(const torch::lazy::Value& node1,
                              const torch::lazy::Value& node2) {
  auto lower_fn = [](const XlaNode& node,
                     LoweringContext* loctx) -> XlaOpVector {
    xla::XlaOp op0 = loctx->GetOutputOp(node.operand(0));
    xla::XlaOp op1 = loctx->GetOutputOp(node.operand(1));
    xla::XlaOp result = XlaHelpers::PromotedBinaryOp(
        op0, op1, [](xla::XlaOp lhs, xla::XlaOp rhs) { return lhs & rhs; });
    return node.ReturnOp(result, loctx);
  };
  auto shape_fn = [&](absl::Span<const xla::XlaOp> operands) -> xla::XlaOp {
    return XlaHelpers::PromotedBinaryOp(
        operands[0], operands[1],
        [](xla::XlaOp lhs, xla::XlaOp rhs) { return lhs & rhs; });
  };
  return GenericOp(torch::lazy::OpKind(at::aten::__and__), {node1, node2},
                   [&]() {
                     return InferOutputShape(
                         {GetXlaShape(node1), GetXlaShape(node2)}, shape_fn);
                   },
                   std::move(lower_fn));
}

torch::lazy::Value BitwiseOr(const torch::lazy::Value& node1,
                             const torch::lazy::Value& node2) {
  auto lower_fn = [](const XlaNode& node,
                     LoweringContext* loctx) -> XlaOpVector {
    xla::XlaOp op0 = loctx->GetOutputOp(node.operand(0));
    xla::XlaOp op1 = loctx->GetOutputOp(node.operand(1));
    xla::XlaOp result = XlaHelpers::PromotedBinaryOp(
        op0, op1, [](xla::XlaOp lhs, xla::XlaOp rhs) { return lhs | rhs; });
    return node.ReturnOp(result, loctx);
  };
  auto shape_fn = [&](absl::Span<const xla::XlaOp> operands) -> xla::XlaOp {
    return XlaHelpers::PromotedBinaryOp(
        operands[0], operands[1],
        [](xla::XlaOp lhs, xla::XlaOp rhs) { return lhs | rhs; });
  };
  return GenericOp(torch::lazy::OpKind(at::aten::__or__), {node1, node2},
                   [&]() {
                     return InferOutputShape(
                         {GetXlaShape(node1), GetXlaShape(node2)}, shape_fn);
                   },
                   std::move(lower_fn));
}

torch::lazy::Value BitwiseXor(const torch::lazy::Value& node1,
                              const torch::lazy::Value& node2) {
  auto lower_fn = [](const XlaNode& node,
                     LoweringContext* loctx) -> XlaOpVector {
    xla::XlaOp op0 = loctx->GetOutputOp(node.operand(0));
    xla::XlaOp op1 = loctx->GetOutputOp(node.operand(1));
    xla::XlaOp result = XlaHelpers::PromotedBinaryOp(
        op0, op1, [](xla::XlaOp lhs, xla::XlaOp rhs) { return lhs ^ rhs; });
    return node.ReturnOp(result, loctx);
  };
  auto shape_fn = [&](absl::Span<const xla::XlaOp> operands) -> xla::XlaOp {
    return XlaHelpers::PromotedBinaryOp(
        operands[0], operands[1],
        [](xla::XlaOp lhs, xla::XlaOp rhs) { return lhs ^ rhs; });
  };
  return GenericOp(torch::lazy::OpKind(at::aten::__xor__), {node1, node2},
                   [&]() {
                     return InferOutputShape(
                         {GetXlaShape(node1), GetXlaShape(node2)}, shape_fn);
                   },
                   std::move(lower_fn));
}

}  // namespace torch_xla
