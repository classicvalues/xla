#include "torch_xla/csrc/ir.h"
#include "torch_xla/csrc/ops/infer_output_shape.h"

namespace torch_xla {

xla::Shape AbsOutputShape(const torch::lazy::Value& input);

xla::Shape AcosOutputShape(const torch::lazy::Value& input);

xla::Shape AcoshOutputShape(const torch::lazy::Value& input);

xla::Shape AdaptiveAvgPool2dOutputShape(const torch::lazy::Value& input,
                                        absl::Span<const int64_t> output_size);

xla::Shape AdaptiveAvgPool2dBackwardOutputShape(
    const torch::lazy::Value& grad_output, const torch::lazy::Value& input);

xla::Shape AsinOutputShape(const torch::lazy::Value& input);

xla::Shape AsinhOutputShape(const torch::lazy::Value& input);

xla::Shape AtanOutputShape(const torch::lazy::Value& input);

xla::Shape AtanhOutputShape(const torch::lazy::Value& input);

xla::Shape CeilOutputShape(const torch::lazy::Value& input);

xla::Shape CosOutputShape(const torch::lazy::Value& input);

xla::Shape CoshOutputShape(const torch::lazy::Value& input);

xla::Shape ErfOutputShape(const torch::lazy::Value& input);

xla::Shape ErfcOutputShape(const torch::lazy::Value& input);

xla::Shape ErfinvOutputShape(const torch::lazy::Value& input);

xla::Shape ExpOutputShape(const torch::lazy::Value& input);

xla::Shape Expm1OutputShape(const torch::lazy::Value& input);

xla::Shape FloorOutputShape(const torch::lazy::Value& input);

xla::Shape HardsigmoidOutputShape(const torch::lazy::Value& input);

xla::Shape HardsigmoidBackwardOutputShape(const torch::lazy::Value& grad_output,
                                          const torch::lazy::Value& input);

xla::Shape HardswishOutputShape(const torch::lazy::Value& input);

xla::Shape HardswishBackwardOutputShape(const torch::lazy::Value& grad_output,
                                        const torch::lazy::Value& input);

xla::Shape InverseOutputShape(const torch::lazy::Value& input);

xla::Shape IsnanOutputShape(const torch::lazy::Value& input);

xla::Shape LogdetOutputShape(const torch::lazy::Value& input);

xla::Shape LogicalAndOutputShape(const torch::lazy::Value& input,
                                 const torch::lazy::Value& other);

xla::Shape LogicalNotOutputShape(const torch::lazy::Value& input);

xla::Shape LogicalOrOutputShape(const torch::lazy::Value& input,
                                const torch::lazy::Value& other);

xla::Shape LogicalXorOutputShape(const torch::lazy::Value& input,
                                 const torch::lazy::Value& other);

xla::Shape LogSigmoidForwardOutputShape(const torch::lazy::Value& input);

xla::Shape LogSigmoidBackwardOutputShape(const torch::lazy::Value& grad_output,
                                         const torch::lazy::Value& input,
                                         const torch::lazy::Value& buffer);

xla::Shape MaximumOutputShape(const torch::lazy::Value& input,
                              const torch::lazy::Value& other);

xla::Shape MinimumOutputShape(const torch::lazy::Value& input,
                              const torch::lazy::Value& other);

xla::Shape ReciprocalOutputShape(const torch::lazy::Value& input);

xla::Shape RoundOutputShape(const torch::lazy::Value& input);

xla::Shape RsqrtOutputShape(const torch::lazy::Value& input);

xla::Shape SeluOutputShape(const torch::lazy::Value& input);

xla::Shape SgnOutputShape(const torch::lazy::Value& input);

xla::Shape SignOutputShape(const torch::lazy::Value& input);

xla::Shape SiluOutputShape(const torch::lazy::Value& input);

xla::Shape SiluBackwardOutputShape(const torch::lazy::Value& grad_output,
                                   const torch::lazy::Value& input);

xla::Shape SinOutputShape(const torch::lazy::Value& input);

xla::Shape SinhOutputShape(const torch::lazy::Value& input);

/* Blocked on https://github.com/pytorch/xla/issues/3596 */
// xla::Shape SlogdetOutputShape(const torch::lazy::Value& input);

xla::Shape TanOutputShape(const torch::lazy::Value& input);

xla::Shape TanhOutputShape(const torch::lazy::Value& input);

xla::Shape TrilOutputShape(const torch::lazy::Value& input);

xla::Shape TriuOutputShape(const torch::lazy::Value& input);

}  // namespace torch_xla
