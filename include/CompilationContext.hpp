#pragma once

#include <Common.hpp>
#include <Namespace.hpp>
#include <TranslationUnit.hpp>

namespace friday::inline api::inline pipeline {
  
  struct CompilationContext {
    box<Namespace> global;
    map<string, box<Namespace>> namespaces;
    vector<box<TranslationUnit>> units;
  };
}