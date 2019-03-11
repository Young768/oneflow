#ifndef ONEFLOW_CORE_KERNEL_REDUCE_SUM_KERNEL_H_
#define ONEFLOW_CORE_KERNEL_REDUCE_SUM_KERNEL_H_

#include "oneflow/core/kernel/kernel.h"

namespace oneflow {

template<DeviceType device_type, typename T>
class ReduceSumKernel final : public KernelIf<device_type> {
 public:
  OF_DISALLOW_COPY_AND_MOVE(ReduceSumKernel);
  ReduceSumKernel() = default;
  ~ReduceSumKernel() = default;

 private:
  void ForwardDataContent(const KernelCtx& ctx,
                          std::function<Blob*(const std::string&)> BnInOp2Blob) const override;
  void BackwardDataContent(const KernelCtx& ctx,
                           std::function<Blob*(const std::string&)> BnInOp2Blob) const override;
  void ForwardDim0ValidNum(const KernelCtx& ctx,
                           std::function<Blob*(const std::string&)> BnInOp2Blob) const override;
  void BackwardInDiffDim0ValidNum(
      const KernelCtx& ctx, std::function<Blob*(const std::string&)> BnInOp2Blob) const override;
  bool NeedForwardIfBlobEmpty() const override { return true; }
  bool NeedBackwardIfBlobEmpty() const override { return true; }
};

}  // namespace oneflow

#endif  // ONEFLOW_CORE_KERNEL_REDUCE_SUM_KERNEL_H_
