#pragma once

#include <Common.hpp>
#include <Namespace.hpp>
#include <TranslationUnit.hpp>

namespace friday::inline api::inline pipeline {
  
  struct CompilationContext final {
    rc<Namespace> global;
    map<string, rc<Namespace>> namespaces;
    vector<rc<TranslationUnit>> units;
  };
}