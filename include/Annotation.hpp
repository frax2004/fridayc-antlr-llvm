#pragma once
#include <FridayParser.h>
#include <VisibilityModifier.hpp>
#include <Type.hpp>



namespace friday::inline api::inline pipeline {

  struct TypeAnnotation {
    Type* type;
  };

  struct VarAnnotation {
    Type*              type;
    VisibilityModifier visibility;
    bool               isConst;
  };

  struct FuncAnnotation {
    Type*              type;
    VisibilityModifier visibility;
    bool               isStatic;
    bool               isNative;
  };

  using Annotation = variant<
    TypeAnnotation,
    VarAnnotation,
    FuncAnnotation,
  >;

  using AnnotationMap = unordered_map<
    ant::ParserRuleContext*, 
    Annotation
  >;

}

