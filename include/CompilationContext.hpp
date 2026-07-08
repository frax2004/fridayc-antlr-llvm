#pragma once

#include <Common.hpp>
#include <Namespace.hpp>
#include <TranslationUnit.hpp>

namespace friday::inline api::inline pipeline {
  
  struct CompilationContext {
    rc<Namespace> global;
    map<string, rc<Namespace>> namespaces;
    vector<rc<TranslationUnit>> units;
  };
}