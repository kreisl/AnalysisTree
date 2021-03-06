#ifndef ANALYSISTREE_FILLTASK_H_
#define ANALYSISTREE_FILLTASK_H_

#include "Configuration.hpp"
#include "DataHeader.hpp"

#include "TChain.h"
#include "TTree.h"

namespace AnalysisTree {

class FillTask {

 public:
  FillTask() = default;
  virtual ~FillTask() = default;

  virtual void Init(std::map<std::string, void *> &) = 0;
  virtual void Exec() = 0;
  virtual void Finish() = 0;

  void SetInChain(TChain *in_chain) {
    in_chain_ = in_chain;
  }

  void SetInConfiguration(Configuration *config) {
    config_ = config;
  }

  void SetOutTree(TTree *out_tree) {
    out_tree_ = out_tree;
  }

  void SetOutConfiguration(Configuration *config) {
    out_config_ = config;
  }
  void SetDataHeader(DataHeader *data_header) {
    data_header_ = data_header;
  }

  void SetInputBranchNames(const std::vector<std::string> &br) { in_branches_ = br; }
  void SetOutputBranchName(const std::string &br) { out_branch_ = br; }

  const std::vector<std::string> &GetInputBranchNames() const { return in_branches_; }

 protected:
  TChain *in_chain_{nullptr};
  Configuration *config_{nullptr};
  DataHeader *data_header_{nullptr};

  TTree *out_tree_{nullptr};
  Configuration *out_config_{nullptr};

  std::vector<std::string> in_branches_{};
  std::string out_branch_{};
};

}// namespace AnalysisTree

#endif//ANALYSISTREE_FILLTASK_H_
