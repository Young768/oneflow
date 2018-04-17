#include "oneflow/core/operator/copy_comm_net_op.h"

namespace oneflow {

void CopyCommNetOp::InitFromOpConf() {
  EnrollInputBn("in", false);
  EnrollOutputBn("out", false);
}

const PbMessage& CopyCommNetOp::GetCustomizedConf() const {
  return op_conf().copy_comm_net_conf();
}

LogicalBlobId CopyCommNetOp::obn2lbi(const std::string& output_bn) const {
  return GenPackedLbi();
}

LogicalBlobId CopyCommNetOp::ibn2lbi(const std::string& input_bn) const {
  return GenPackedLbi();
}

REGISTER_OP(OperatorConf::kCopyCommNetConf, CopyCommNetOp);

}  // namespace oneflow
